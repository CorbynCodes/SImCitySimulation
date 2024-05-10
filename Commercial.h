#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Zone.h"
#include <vector>

class Commercial : public Zone{
    public: 
    Commercial();
    Commercial(int popul, char type, int row, int col);
    void refresh(vector<Zone> sector, int *workers, int *goods) override;

    private:

};

#endif 