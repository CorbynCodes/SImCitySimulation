#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include "Zone.h"
#include <vector>

class Residential : public Zone {
public:
    Residential();
    Residential(int popul, char type, int row, int col);
    void refresh(vector<Zone> sector, int* workers, int* goods) override;

private:

};

#endif 