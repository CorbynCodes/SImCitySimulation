#include<iostream>
#include "Residential.h"
#include "Zone.h"

using namespace std;

Residential::Residential()
    :Zone()
{
}

Residential::Residential(int popul, char type, int row, int col)
    :Zone(popul, type, row, col)
{
}

void Residential::refresh(vector<Zone> sector, int* workers, int* goods)
{
    bool connectsPowerline = false; // True if neighbor is a powerline, false otherwise.
    int availWorkers = 0; // number of workers = to popul
    int popul = getPopul();
    int neighbors = 0; //number of neighbors
    // check neighbor popul size and zone type

    //check each neighbor
    for (Zone neighbor : sector)
    {
        neighbors = (neighbors + neighbor.getPopul());
        if (neighbor.getType() == 'T')
        {
            connectsPowerline = true;
        }


        //Population of 0, will increase by 1 if popul is 0 and connected to a powerline or has a neighbor
        if (popul == 0 && (connectsPowerline || neighbors == 1))
        {
            popul++;
            setPopul(popul);
            availWorkers = popul;
            return;
        }
        //Population increases by 1 if popul = 1 and adjacent to two cells with pop of 1
        else if (popul == 1 && neighbors >= 2)
        {
            popul++;
            setPopul(popul);
            availWorkers = popul;
            return;
        }
        //Population increases by 1 if popul = 2 and adjacent to four cells with pop of 2
        else if (popul == 2 && neighbors >= 4)
        {
            popul++;
            setPopul(popul);
            availWorkers = popul;
            return;
        }
        //Population increases by 1 if popul = 3 and adjacent to six cells with pop of 2
        else if (popul == 3 && neighbors >= 6)
        {
            popul++;
            setPopul(popul);
            availWorkers = popul;
            return;
        }
        //Population increases by 1 if popul = 4 and adjacent to eight cells with pop of 2
        else if (popul == 4 && neighbors >= 8)
        {
            popul++;
            setPopul(popul);
            availWorkers = popul;
            return;
        }
    }
    return;
}