#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

#include "Zone.h"
#include <vector>

class Industrial : public Zone {
public:
    Industrial();
    Industrial(int population, char zoneType, int row, int column);
    void refresh(std::vector<Zone> surroundingZones, int *laborers, int *products) override;

private:
};

#endif