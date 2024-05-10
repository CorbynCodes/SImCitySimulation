#include "godZilla.h" // region file.
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

Godzilla::Godzilla() {}

// Parsing through the region.csv file to get the coordinates of the Godzilla
void Godzilla::move(const int rowSize, const int colSize) {
  // Spawn Godzilla at a random location

  srand(time(NULL));
  int row = rand() % rowSize;
  int col = rand() % colSize;

  cout << "Godzilla spawn: " << col << " " << row << endl;

  this->row = row;
  this->col = col;

  // regionLayout[row][col] = 'G';
  // cout << "Godzilla spawn: " << x << " " << y << endl;
}

// reding the csv file to get the region layout
// vector<vector<char>> Godzilla::readcsvFile(const string &filename) {

//   ifstream csvFile(filename);
//   vector<vector<char>> lineData;

//   if (!csvFile.is_open()) {
//     cerr << "Error: Could not find the config file." << endl;
//     return lineData;
//   }

//   string line;
//   regionLayout.clear();

//   while (getline(csvFile, line)) {
//     stringstream ss(line);
//     vector<char> row;
//     string cell;
//     while (getline(ss, cell, ' ')) {
//       if (!cell.empty()) {
//         row.push_back(cell[0]);
//       }
//     }
//     lineData.push_back(row);
//   }
//   csvFile.close();
//   return lineData;
// }

// destroying the buildings in the region
// void Godzilla::destroy(vector<vector<char>> &regionLayout, int row, int col)
// {
//   // Destroy the Residential, Commercial, Industrial, Powerplant buildings in
//   // the region
//   // Destroy the Godzilla building in the region

//   // for (int i = 0; i < regionLayout.size(); i++) {
//   //   for (int j = 0; j < regionLayout[i].size(); j++) {
//   switch (regionLayout[row][col]) {
//   case 'R':
//   case 'C':
//   case 'I':
//   case 'P':
//   case 'W':
//   case 'T':
//   case '-':
//   case '|':
//     regionLayout[row][col] = 'G';
//     break;
//   case 'G':
//     cout << "Destroying buildings at: " << row << ", " << col << endl;
//     regionLayout[row][col] = ' ';
//   default:
//     break;
//   }
//   //   }
//   // }
// }

// TO_DO LISTTTTTTTT!!!!
// Destroy the Godzilla building in the region
// Destroy the Residential, Commercial, Industrial, Powerplant buildings in
// the Region

// void Godzilla::move(vector<vector<char>> &regionLayout) {
//   // Move Godzilla to a new location
//   // Destroy the buildings in the new location
//   // Destroy the buildings in the old location
//   // Update the regionLayout
//   srand(static_cast<unsigned int>(time(nullptr)));
//   // int direction = rand() % 8;
//   // cout << "Godzilla move: " << direction << endl;
//   // 0 = up-left, 1 = up, 2 = up-right, 3 = left, 4 = right, 5 = down-left, 6
//   =
//   // down, 7 = down-right
//   // Pick a number less than rows and cols

//   const int colSize = regionLayout.size();
//   const int rowSize = regionLayout[row].size();

//   const int randCol = rand() % colSize;
//   const int randRow = rand() % rowSize;

//   godzilla.destroy(regionLayout, randRow, randCol);
//   // int randomNumer = rand() % 8;
//   // // move horizontal to a value less than row.length
//   // moveHorizontal = rand() % row;

//   // switch (direction) {
//   // case 0:
//   //   // move on regionLayout to the new location (moveVertical,
//   //   moveHorizontal) for (int i = 0; i < moveHorizontal; i++) {
//   //     for (int j = 0; j < moveVertical; j++) {
//   //       godzilla.destroy(regionLayout[i][j]);
//   //     }
//   //   }
//   //   cout << "Case 0: " << moveVertical << " " << moveHorizontal << endl;
//   //   break;
//   // case 1:
//   //   // move on regionLayout to the new location (moveVertical,
//   //   moveHorizontal)

//   //   cout << "Case 1: " << moveVertical << " " << moveHorizontal << endl;
//   //   break;
//   // case 2:
//   //   for (int i = 0; i < moveHorizontal; i++) {
//   //     for (int j = 0; j < moveVertical; j++) {
//   //       godzilla.destroy(regionLayout[i][j]);
//   //     }
//   //   }
//   //   cout << "Case 2: " << moveVertical << " " << moveHorizontal << endl;
//   //   break;
//   // case 3:
//   //   // move horizontal to a value less than row.length
//   //   moveHorizontal = rand() % row;
//   //   cout << "Case 3: " << moveVertical << " " << moveHorizontal << endl;
//   //   break;
//   // case 4:
//   //   // move horizontal to a value less than row.length
//   //   // row stays the same

//   //   for (int colIndex = col; colIndex < colSize; colIndex++) {
//   //       godzilla.destroy(regionLayout, row, colIndex);
//   //   }
//   //   moveHorizontal = rand() % row;
//   //   cout << "Case 4: " << moveVertical << " " << moveHorizontal << endl;
//   //   break;
//   // case 5:
//   //   for (int i = 0; i < moveHorizontal; i++) {
//   //     for (int j = 0; j < moveVertical; j++) {
//   //       godzilla.destroy(regionLayout[i][j]);
//   //     }
//   //   }
//   //   cout << "Case 5: " << moveVertical << " " << moveHorizontal << endl;
//   //   break;
//   // case 6:
//   //   // move vertical to a value less than col.length
//   //   moveVertical = rand() % col;
//   //   cout << "Case 6: " << moveVertical << " " << moveHorizontal << endl;
//   //   break;
//   // case 7:
//   //   for (int i = 0; i < moveHorizontal; i++) {
//   //     for (int j = 0; j < moveVertical; j++) {
//   //       godzilla.destroy(regionLayout[i][j]);
//   //     }
//   //   }
//   //   cout << "Case 7: " << moveVertical << " " << moveHorizontal << endl;
//   //   break;
//   // default:
//   //   break;
//   // }
// };

// void Godzilla::updateGodzilla(const string &writeCsv,
//                               vector<vector<char>> &regionLayout) {
//   ofstream file(writeCsv);
//   if (!file.is_open()) {
//     cerr << "Error: Could not find the config file." << endl;
//     return;
//   }
//   for (int i = 0; i < regionLayout.size(); i++) {
//     for (int j = 0; j < regionLayout[i].size(); j++) {
//       file << regionLayout[i][j];
//       if (j != regionLayout[i].size() - 1) {
//         file << ' '; //  adding a delimter to the csv file to see if it helps
//                      //  with creating spaces more consistently
//       }
//     }
//     file << endl;
//   }
//   file.close();
// }
