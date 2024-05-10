#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "Zone.h"
#include <vector>

class Hospital : public Zone
{
public:
    Hospital();
    Hospital(int popul, char type, int row, int col);
    void refresh(vector<Zone> sector, int* workers, int* house) override;

private:
};

#endif 