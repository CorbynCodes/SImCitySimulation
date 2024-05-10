#include "Zone.h"
#include <iostream>

using namespace type;

Zone::Zone() {
  popul = 0;
  type = emptyZone;
  destroyed = false;
}

Zone::Zone(int popul, char type, int row, int col) // constructor
    : popul(popul), type(type), row(row), col(col) {}

void Zone::refresh() // refresh when updating zones each time step
{}
void Zone::refresh(vector<Zone> sector, int *workers, int *goods) {}
void Zone::setPopul(int pop) { popul = pop; }
int Zone::getPopul() { return popul; }
string Zone::print() { return to_string(getType()); }
char Zone::getType() {
  if (this->destroyed) {
    return 'G';
  }

  return type;
}
void Zone::setPollu(int pol) { pollu = pol; }
// Pollution
int Zone::getPollu() const { return pollu; }
int Zone::getRow() { return row; }
int Zone::getCol() { return col; }

void Zone::setDestroyed(bool des) { this->destroyed = des; }

/*double Zone::appraise( int pollu){ // calculate property value
    double value = 0;
    double scenery = 0;
    double pol = 0.0+pollu;
    double noise = 0;
    for(Zone* z: getNeighbors()){   // adding scenery, noise, and pollution
        if(z->getType()==emptyZone){
            scenery+=1;
        }else if(z->getType()==powerPlant){
            scenery-=1;

        }else if(z->getType()==powerline){
            scenery-=1;
        }else if(z->getType()==industrial){
            scenery-=1;
        }else if(z->getType()==road||z->getType()==industrial){
            noise+=1;
        }
    }
    value = popul*10 + scenery - pol - noise; // calculate property value
    setValue(value);
    return value;
}*/ //This is for part2. Not sure if I did right

double Zone::getValue() { return value; }

void Zone::setValue(double val) { this->value = val; }
void Zone::setNeighbors(Zone *neb) { neighbors.push_back(neb); }
vector<Zone *> Zone::getNeighbors() { return neighbors; }

void Zone::setType(char type) {
  this->type = type;
  updatePollution(); // pollution
}

int Zone::calculatePollution() const {
  switch (type) {
  case industrial:
    return 5;
  case residential:
    return 1;
  case commercial:
    return 2;
  case tree:
  case waterWays:
    return -1;
  default:
    return 0; // No pollution from empty zones, roads, etc.
  }
}

void Zone::updatePollution() { pollu = calculatePollution(); }
