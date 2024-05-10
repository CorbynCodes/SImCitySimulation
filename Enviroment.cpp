    #include "Enviroment.h"

    using namespace std;

    // To spawn random trees and waterways:
    void Environment::spawnEnvironment(vector<vector<char>> &mapLayout) {
        srand(time(NULL)); // Seed for random generation
        spawnTree(mapLayout);
        spawnWaterway(mapLayout);
    }

    // Function for spawning trees in null locations:
    void Environment::spawnTree(vector<vector<char>> &mapLayout) {
        auto validLocations = findValidLocations(mapLayout, ' ');
        if (!validLocations.empty()) {
            int index = rand() % validLocations.size();
            pair<int, int> spawnPoint = validLocations[index];
            mapLayout[spawnPoint.first][spawnPoint.second] = 'Y'; // 'Y' for Tree
        }
    }

    // Function for spawning waterways in null locations:
    void Environment::spawnWaterway(vector<vector<char>> &mapLayout) {
        auto validLocations = findValidLocations(mapLayout, ' ');
        if (!validLocations.empty()) {
            int index = rand() % validLocations.size();
            pair<int, int> spawnPoint = validLocations[index];
            mapLayout[spawnPoint.first][spawnPoint.second] = 'W'; // 'W' for Waterway
        }
    }

    // The environmental effects:
    void Environment::insertEnvironmentalEffects(vector<vector<char>> &mapLayout, int& pollution) {
        int treeAndWaterwayCount = 0;
        for (auto& row : mapLayout) {
            for (auto& zone : row) {
                if (zone == 'T' || zone == 'W') {
                    treeAndWaterwayCount++;
                }
            }
        }
        pollution -= treeAndWaterwayCount;
        pollution = max(0, pollution);
    }

    // Is the air safe to breathe?:
    string Environment::checkAirQuality(int pollution) {
        if (pollution < 5) return "Good";
        if (pollution < 10) return "Moderate";
        if (pollution < 15) return "Unhealthy";
        return "DANGER";
    }

    // Is the spawn location valid?:
    vector<pair<int, int>> Environment::findValidLocations(const vector<vector<char>> &mapLayout, char targetType) {
        vector<pair<int, int>> validLocations;
        for (int i = 0; i < mapLayout.size(); i++) {
            for (int j = 0; j < mapLayout[i].size(); j++) {
                if (mapLayout[i][j] == targetType) {
                    validLocations.push_back(make_pair(i, j));
                }
            }
        }
        return validLocations;
    }
    // Calculate pollution:
    int Environment::calculateTotalPollution(Zone** city, int cityRows, int cityCols) {
    int totalPollution = 0;
    for (int i = 0; i < cityRows; i++) {
        for (int j = 0; j < cityCols; j++) {
            city[i][j].updatePollution();
            totalPollution += city[i][j].getPollu();
        }
    }
    return totalPollution;
}

