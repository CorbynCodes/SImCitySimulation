#ifndef ZONE_H
#define ZONE_H

#include <string>
#include <vector>

using namespace std;

class Zone {
public:
  Zone();
  Zone(int popul, char type, int row, int col);
  void refresh();
  virtual void refresh(vector<Zone> sector, int *workers,
                       int *goods); // update zones
  void setPopul(int popul);
  void setNeighbors(Zone *neighbor);
  int getPopul();
  string print();
  char getType();
  void setType(char type);
  void setPollu(int pollu);
  int getPollu() const;
  void updatePollution(); // Update pollution level based on the zone type
  int calculatePollution() const; // Calculate pollution based on zone type

  int getRow();
  int getCol();
  // reminder for part2 virtual double appraise( int pollu); // calculate
  // property value
  double getValue();
  void setValue(double value);
  vector<Zone *> getNeighbors();
  void setDestroyed(bool);

private:
  char type;
  int popul;
  int pollu; // pollution level
  int row;
  int col;
  bool destroyed = false;
  double value;
  vector<Zone *> neighbors;

  // int availablePopulation; ??
};

namespace type {
const char emptyZone = ' ';
const char road = '-';
const char powerline = 'T';
const char commercial = 'C';
const char residential = 'R';
const char industrial = 'I';
const char hospital = 'H';
const char powerlineRoad = '#';
const char powerPlant = 'P';
// Enviroemnt:
const char tree = 'Y';
const char waterWays = 'W';

}; // namespace type

#endif
