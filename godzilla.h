#ifndef GODZILLA_H
#define GODZILLA_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Godzilla {
public:
  Godzilla();
  // Godzilla(int numRows, int numCols);
  // void spawn(int row, int col, vector<vector<char>> &spawnLocation);
  // void updateGodzilla(const string &writeCsv,
  //                     vector<vector<char>> &regionLayout);
  // void destroy(vector<vector<char>> &regionLayout, int row, int col);
  void move(const int rowSize, const int colSize);
  // vector<vector<char>> readcsvFile(const string &fileName);
  int col;
  int row;

  // private:
  //   vector<vector<char>> regionLayout;
};

#endif // GODZILLA_H
