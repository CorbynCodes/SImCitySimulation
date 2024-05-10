#ifndef ENVIROMENT_H
#define ENVIROMENT_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Zone.h"

class Environment {
public:
    void spawnEnvironment(std::vector<std::vector<char>>& mapLayout);
    void insertEnvironmentalEffects(std::vector<std::vector<char>>& mapLayout, int& pollution);
    std::string checkAirQuality(int pollution);
    int calculateTotalPollution(Zone** city, int cityRows, int cityCols);


private:
    void spawnTree(std::vector<std::vector<char>>& mapLayout);
    void spawnWaterway(std::vector<std::vector<char>>& mapLayout);
    std::vector<std::pair<int, int>> findValidLocations(const std::vector<std::vector<char>>& mapLayout, char targetType);
};

#endif
