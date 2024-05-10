#include <array>
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <tuple>
#include <unistd.h>
#include <vector>

#include "Commercial.h"
#include "Enviroment.h"
#include "Hospital.h"
#include "Industrial.h"
#include "Landfill.h"
#include "Residential.h"
#include "Zone.h"
#include "godzilla.h"
using namespace std;

vector<vector<char>> readConfig(int &, int &);
vector<Zone> getNeighbor(int, int, int, int, Zone **);
void godzillaMove(Godzilla *, int, int, Zone ***);
void updateCity(char, int, int, Zone **, Zone **, int *, int *);
void createCity(vector<vector<char>>, Zone **, int, int);
void printCity(Zone **, int, int);
void printFinalPop(int, int, Zone **);
void createTempCity(Zone **, Zone **, int, int);
int resCheck(int, int, Zone **); // check residential units, store value.

int main() {
  // variables for file input
  string userFile = " ";
  string userText = " ";
  char textCheck;
  ifstream userInput;
  int fileSearch;

  // Simulation parameters
  string region = " ";
  int timeLimit = 0;
  int refreshRate = 0;

  int *workers; // pointer for number of workers
  int *goods;   // pointer for number of goods
  int tempWorkers = 0;
  int tempGoods = 0;
  workers = &tempWorkers;
  goods = &tempGoods;
  int rAvail = 0; // Parameter for hospital, will check how many residential
                  // units have 2 or more pop
  int *rPass = &rAvail; // pointer to pass to hospital

  // Introduction block
  cout << "+-----------------------------------+" << endl;
  cout << "|        Project 2: Sim City        |" << endl;
  cout << "+-----------------------------------+" << endl;

  Godzilla *godzilla = new Godzilla();

  vector<vector<char>> cityMap = readConfig(timeLimit, refreshRate);

  int cityRows = cityMap.size();
  int cityCols = cityMap.at(0).size();

  Zone *city[cityRows][cityCols];     // main city
  Zone *tempCity[cityRows][cityCols]; // temp city with values from previous
                                      // time step to prevent from errors
  createCity(cityMap, *city, cityRows, cityCols);

  cout << "INITIAL STATE" << endl;
  printCity(*city, cityRows, cityCols);

  /*	~For Enviroment part 2 UPDATED MAIN~
  Environment env;
  env.spawnEnvironment(cityMap);  // Populate the initial amount of trees and
  waterways int pollution = 0;
  */

  for (int time = 1; time <= timeLimit; time++) {

    createTempCity(*city, *tempCity, cityRows, cityCols);
    rAvail = resCheck(cityRows, cityCols,
                      *tempCity); // check how many residential units have 2+
                                  // popul and returns that number
    updateCity('C', cityRows, cityCols, *tempCity, *city, workers, goods);
    updateCity('I', cityRows, cityCols, *tempCity, *city, workers, goods);
    updateCity('R', cityRows, cityCols, *tempCity, *city, workers, goods);
    updateCity('H', cityRows, cityCols, *tempCity, *city, workers, rPass);

    // godzillaMove(godzilla, cityRows, cityCols, *tempCity);
    godzilla->move(cityRows, cityCols);

    tempCity[godzilla->row][godzilla->col]->setPopul(0);
    tempCity[godzilla->row][godzilla->col]->setDestroyed(true);

    /* ENVIROMENT POLLUTION AND AIR QUALITY:
    pollution = env.calculateTotalPollution(*city, cityRows, cityCols);
    env.insertEnvironmentalEffects(cityMap, pollution);
    string airQuality = env.checkAirQuality(pollution);

    cout << "Time Step: " << time << " - Pollution: " << pollution
        << ", Air Quality: " << airQuality << endl;
    */

    bool changed = false;
    for (int i = 0; i < cityRows; i++) {
      for (int j = 0; j < cityCols; j++) {
        if (tempCity[i][j]->getPopul() != city[i][j]->getPopul()) {
          changed = true;
        }
        city[i][j]->setPopul(tempCity[i][j]->getPopul());
        city[i][j]->setValue(tempCity[i][j]->getValue());
        if (tempCity[i][j]->getType() == 'G') {
          city[i][j]->setDestroyed(true);
        }
      }
    }

    if (time % refreshRate == 0) {
      cout << endl << "City Map at timestep " << time << ": " << endl;
      printCity(*city, cityRows, cityCols);
      cout << "Available Workers: " << *workers << endl;
      cout << "Available Goods: " << *goods << endl;
    }

    if (!changed) {
      cout << "No change from previous timestep, ending simulation." << endl;
      break;
    }
  }

  printCity(*city, cityRows, cityCols);

  printFinalPop(cityRows, cityCols, *city);
  int resPopul = 0;
  int comPopul = 0;
  int indPopul = 0;
  int hosPopul = 0;

  for (int i = 0; i < cityRows; i++) {
    for (int j = 0; j < cityCols; j++) {
      if (city[i][j]->getType() == 'R') {
        resPopul += city[i][j]->getPopul();
      } else if (city[i][j]->getType() == 'C') {
        comPopul += city[i][j]->getPopul();
      } else if (city[i][j]->getType() == 'I') {
        indPopul += city[i][j]->getPopul();
      } else if (city[i][j]->getType() == 'H') {
        hosPopul += city[i][j]->getPopul();
      }
    }
  }

  cout << "LANDFILL" << endl;

  double landfillCapacity = 5000.0;

  Landfill landfill = Landfill(landfillCapacity);

  landfill.genTrash(resPopul, comPopul, indPopul, hosPopul, 7);

  return 0;
}

vector<vector<char>> readConfig(int &timeLimit, int &refreshRate) {
  string configFile;
  vector<vector<char>> cityMap;
  bool found = false;

  // User will be prompted to enter in a file name, program will store the
  // values, set the parameters, and load the layout
  cout << "Please enter the name of the config file you wish to simulate: "
       << endl;
  cin >> configFile;

  // error output block
  while (!found) {
    if (configFile.find(".txt") == string::npos) {
      cout << "ERROR: config name must be a .txt file" << endl;
      cout << "Please enter the name of the config file you wish to simulate: "
           << endl;
      cin >> configFile;
    } else {
      found = true;
    }
  }

  ifstream config(configFile);
  if (config.fail()) {
    cout << "ERROR: File not found, program will exit";
    exit(0);
  }

  string line;
  string cityFile;

  if (config.is_open()) {
    getline(config, line);
    cityFile = line.substr(line.find(":") + 1, line.size());
    getline(config, line);
    timeLimit = stoi(line.substr(line.find(":") + 1, line.size()));
    getline(config, line);
    refreshRate = stoi(line.substr(line.find(":") + 1, line.size()));
  } else {
    cout << "Error opening config file.";
    return cityMap;
  }

  ifstream cityLayout(cityFile);

  if (cityLayout.is_open()) {
    while (getline(cityLayout, line)) {
      vector<char> zoneRow;
      stringstream s(line);
      string substr;
      while (getline(s, substr, ',')) {
        zoneRow.push_back(substr.at(0));
      }
      cityMap.push_back(zoneRow);
    }
  }
  return cityMap;
}

vector<Zone> getNeighbors(int i, int j, int maxI, int maxJ, Zone **cityMap) {

  vector<Zone> vNeighbors;
  tuple<int, int> midleft = make_tuple(0, -1);
  tuple<int, int> midright = make_tuple(0, 1);
  tuple<int, int> topcenter = make_tuple(-1, 0);
  tuple<int, int> bottomcenter = make_tuple(1, 0);
  tuple<int, int> topleft = make_tuple(-1, -1);
  tuple<int, int> topright = make_tuple(-1, 1);
  tuple<int, int> bottomleft = make_tuple(1, -1);
  tuple<int, int> bottomright = make_tuple(1, 1);

  tuple<int, int> likelyNeighbors[] = {midleft,      midright,   topcenter,
                                       bottomcenter, topleft,    topright,
                                       bottomleft,   bottomright};

  for (tuple<int, int> neighbor : likelyNeighbors) {
    int iChange = get<0>(neighbor);
    int jChange = get<1>(neighbor);

    int iNeighbor = i + iChange;
    int jNeighbor = j + jChange;

    if (iNeighbor >= 0 && jNeighbor >= 0 && iNeighbor <= maxI - 1 &&
        jNeighbor <= maxJ - 1) {
      Zone vNeighbor = *cityMap[iNeighbor * maxJ + jNeighbor];
      vNeighbors.push_back(vNeighbor);
    }
  }

  return vNeighbors;
}

void createCity(vector<vector<char>> cityMap, Zone **city, int cityRows,
                int cityCols) {

  for (int i = 0; i < cityRows; i++) {
    for (int j = 0; j < cityCols; j++) {
      switch (cityMap.at(i).at(j)) {
      case 'T':
      case '#':
      case 'P':
      case '-':
      case ' ':
        city[i * cityCols + j] = new Zone(0, cityMap.at(i).at(j), i, j);
        break;
      case 'R':
        city[i * cityCols + j] = new Residential(0, cityMap.at(i).at(j), i, j);
        break;
      case 'C':
        city[i * cityCols + j] = new Commercial(0, cityMap.at(i).at(j), i, j);
        break;
      case 'I':
        city[i * cityCols + j] = new Industrial(0, cityMap.at(i).at(j), i, j);
        break;
      case 'H':
        city[i * cityCols + j] = new Hospital(0, cityMap.at(i).at(j), i, j);
        break;
      }
    }
  }
}

void printCity(Zone **city, int cityRows, int cityCols) {
  for (int i = 0; i < cityRows; i++) {
    for (int j = 0; j < cityCols; j++) {
      if (city[i * cityCols + j]->getPopul() == 0) {
        cout << city[i * cityCols + j]->getType() << " ";
        // city[i * cityCols + j]->setDestroyed(false);
      } else {
        cout << to_string(city[i * cityCols + j]->getPopul()) << " ";
      }
    }
    cout << endl;
  }
}

void createTempCity(Zone **city, Zone **tempCity, int cityRows, int cityCols) {
  for (int i = 0; i < cityRows; i++) {
    for (int j = 0; j < cityCols; j++) {
      char zoneType = city[i * cityCols + j]->getType();
      switch (zoneType) {
      case 'T':
      case '#':
      case 'P':
      case '-':
      case ' ':
        tempCity[i * cityCols + j] = new Zone(0, zoneType, i, j);
        break;
      case 'R': // utilizes inheritance to create residential zone
        tempCity[i * cityCols + j] = new Residential(0, zoneType, i, j);
        break;
      case 'C': // utilizes inheritance to create commercial zone
        tempCity[i * cityCols + j] = new Commercial(0, zoneType, i, j);
        break;
      case 'I': // utilizes inheritance to create industrial zone
        tempCity[i * cityCols + j] = new Industrial(0, zoneType, i, j);
        break;
      case 'H':
        tempCity[i * cityCols + j] = new Hospital(0, zoneType, i, j);
        break;
        // cout<<tempCity[i * numCols + j]->getType()<<" ";
      }
      tempCity[i * cityCols + j]->setPopul(city[i * cityCols + j]->getPopul());
    }
  }
}

void updateCity(char zoneType, int cityRows, int cityCols, Zone **tempCity,
                Zone **city, int *tempworkers1, int *tempgoods1) {
  for (int i = 0; i < cityRows; i++) {
    for (int j = 0; j < cityCols; j++) {
      if (tempCity[i * cityCols + j]->getType() == zoneType) {
        vector<Zone> neighbors;
        neighbors = getNeighbors(i, j, cityRows, cityCols, city);
        tempCity[i * cityCols + j]->refresh(neighbors, tempworkers1,
                                            tempgoods1);
      }
    }
  }
}

void printFinalPop(int cityRows, int cityCols, Zone **city) {
  int residentialPop = 0;
  int commercialPop = 0;
  int industrialPop = 0;
  int hospitalPop = 0;

  for (int i = 0; i < cityRows; i++) {
    for (int j = 0; j < cityCols; j++) {
      if (city[i * cityCols + j]->getType() == 'R') {
        residentialPop += city[i * cityCols + j]->getPopul();
      } else if (city[i * cityCols + j]->getType() == 'C') {
        commercialPop += city[i * cityCols + j]->getPopul();
      } else if (city[i * cityCols + j]->getType() == 'I') {
        industrialPop += city[i * cityCols + j]->getPopul();
      } else if (city[i * cityCols + j]->getType() == 'H') {
        hospitalPop += city[i * cityCols + j]->getPopul();
      }
    }
  }
  cout << endl
       << "Final Residential Population: " << residentialPop
       << endl; // print final city residential population
  cout << endl
       << "Final Industrial Population: " << industrialPop
       << endl; // print final city industrial population
  cout << endl
       << "Final Commercial Population: " << commercialPop
       << endl; // print final city commercial population
  cout << endl
       << "Total new births: " << hospitalPop
       << endl; // print's the amount of random new births
}

int resCheck(int cityRows, int cityCols, Zone **city) {
  int store = 0;
  for (int i = 0; i < cityRows; i++) {
    for (int j = 0; j < cityCols; j++) {
      if (city[i * cityCols + j]->getType() == 'R') {
        if (city[i * cityCols + j]->getPopul() >= 2) {
          store++;
        }
      }
    }
  }
  return store;
}
