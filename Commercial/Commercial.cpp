#include "Commercial.h"
#include <iostream>

using namespace type;

Commercial::Commercial()
    : Zone()
{
}

Commercial::Commercial(int popul, char type, int row, int col)
    : Zone(popul, type, row, col)
{
}

void Commercial::refresh(vector<Zone> sector, int *workers, int *goods)
{
    bool connectsPowerline = false;                      // True if neighbor is a powerline, false otherwise.
    bool workersAvail = *workers > 0 ? true : false; // checks if workers are available
    bool goodsAvail = *goods > 0 ? true : false;     // checks if goods are available
    int popul = getPopul();

    int numNeighbors = 0; // number of neighbors who have populated at least once

    // check neighbor popul size and zone type
    for (Zone neighbor : sector)
    {
        if (neighbor.getPopul() >= 1)
            numNeighbors++;
        if (neighbor.getType() == 'T')
            connectsPowerline = true;
    }

    // If no workers or goods present method returns withouth updating anything
    if (!workersAvail || !goodsAvail)
        return;

    // Check if the zone is adjacent to powerline or to atleast one zone having popul > =1
    else if (popul == 0 && (connectsPowerline || numNeighbors > 0)) 
    {
        popul++;
        setPopul(popul); // add popul
        (*workers)--;
        (*goods)--;
        return;
    }
    // If the zone has popul=1 and is adjacent to at least two zones with popul >=1
    else if (popul == 1 && numNeighbors >= 2)
    {
        if(getValue()>10){ // check if high value property and adjust growth rules
            popul+=2;
            setPopul(popul); // add popul
        }else{
            popul++;
            setPopul(popul); // add popul
        }
        (*workers)--;
        (*goods)--;
        return;
    }
    return;
}