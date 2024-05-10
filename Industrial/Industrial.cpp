#include "Industrial.h"
#include <iostream>

using namespace type;

Industrial::Industrial()
    : Zone()
{
    
}

Industrial::Industrial(int pop, char t, int r, int c)
    : Zone(pop, t, r, c)
{

}

void Industrial::refresh(vector<Zone> sector, int *workers, int *goods) {
    if (getPopul() == 0) {
        for (Zone neighbor : sector) { // check for neighbor with population 1 or powerline
            if ((neighbor.getPopul() >= 1 || neighbor.getType() == powerline || neighbor.getType() == powerlineRoad || neighbor.getType() == powerPlant) && *workers >= 2) {
                setPopul(getPopul() + 1);
                (*workers) -= 2;
                (*goods)++;
                break;
            }
        }
    } else if (getPopul() == 1) {
        int numPopOne = 0;
        for (Zone neighbor : sector) {
            if (neighbor.getPopul() >= 1) {// sum up neighbor zones of population 1
                numPopOne++;
            }
        }
        if (numPopOne >= 2 && *workers >= 2) { // check if enough workers and population
            setPopul(getPopul() + 1); // add to population if enough population
            if (getValue() > 10) { // check if high-value property, if so, modify growth rules
                (*workers) -= 1;
                (*goods)++;
            } else {
                (*workers) -= 2;
                (*goods)++;
            }
        }
    } else if (getPopul() == 2) {
        int numPopTwo = 0;
        for (Zone neighbor : sector) {
            if (neighbor.getPopul() >= 2) { // sum up neighbor zones of population 2
                numPopTwo++;
            }
        }
        if (numPopTwo >= 4 && *workers >= 2) { // check if enough workers and Population
            setPopul(getPopul() + 1); // add to population if enough population
            if (getValue() > 20) { // check if high-value property, if so, modify growth rules
                (*workers) -= 1;
                (*goods)++;
            } else {
                (*workers) -= 2;
                (*goods)++;
            }
        }
    }
}
