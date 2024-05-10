/* Author: Kevin Licitis
*  Date: 4/14/2024
*  Description: Hospital function, The hospital zone will search for all available residential housing with 2 or more population.
*   When this criteria is met, the function will use random number generation to create a 5% chance of increasing population by 1, representing a new birth.
*   This new population will not impact the available workers, since its a baby.
*/

#include<iostream>
#include<stdlib.h>
#include "Hospital.h"
#include "Zone.h"
#include <time.h>
#include <ctime>
using namespace std;

Hospital::Hospital()
    :Zone()
{
}

Hospital::Hospital(int popul, char type, int row, int col)
    : Zone(popul, type, row, col)
{
}

void Hospital::refresh(vector<Zone> sector, int* workers, int* house)
{
    int availWorkers = 0; //Must reach 10 before capable of working
    int popul = getPopul(); //Will represent new births/will not add to workers
    int availHouse = *house; //Check households with 2>= popul, and will be able to generate popul once criteria is met
    int numStore = 0; //stores the randomly generated int, to check if RNG has been met

    //If residential unit is found, will randomly generate a number 1-100. <=5 will generate population(5% chance to increase population,representing birth)

    for (int i = 0; i < availHouse; i++)
    {
        numStore = (rand() % 99 + 1);
        if (numStore <= 5)
        {
            popul++;
            setPopul(popul);
        }
    }

    return;
}