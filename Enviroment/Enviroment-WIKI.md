The purpose of this file is to describe in detail the Enviromental functions (i.e. pollution calculations, Enviroment logic).

-------------------------------------------------
-------------------------------------------------

### Overview:
the Environment class wich is part of our sim city growth simulation is responsible for managing environmental effects such as tree and waterway generation, pollution calculation, and air quality monotiring within a city.

-------------------------------------------------
-------------------------------------------------

### File Management:
'Environment.cpp' has the implementation of the "Environment" class methods.

'Environment.h' is the header file for the "Environment" class declaring all the methods and private attributes.

'Zone.cpp' had to be updated to inlcude environment effects. It now helps to simulate different zone types within a city such as commercial or industrial.

-------------------------------------------------
-------------------------------------------------

## void spawnEnvironment(vector<vector<char>>& mapLayout):
populates the map with initial random placements of trees "Y" and waterways "W".

-------------------------------------------------
-------------------------------------------------

## void insertEnvironmentalEffects(vector<vector<char>>& mapLayout, int& pollution):
calculates the reduction of pollution due to the number of trees and waterways, and makes sure that pollution never goes below zero.

-------------------------------------------------
-------------------------------------------------

## string checkAirQuality(int pollution):
this returns a string that describes the air quality based on the current pollution levels (Good-DANGER).

-------------------------------------------------
-------------------------------------------------

## int calculateTotalPollution(Zone** city, int cityRows, int cityCols):
this computes the total pollution for the city by adding all the pollution values of individual zones.

-------------------------------------------------
-------------------------------------------------

## void spawnTree(vector<vector<char>>& mapLayout):
this attempts to place a tree in a random valid location on the map where currently there is an empty space ' '.

-------------------------------------------------
-------------------------------------------------

## void spawnWaterway(vector<vector<char>>& mapLayout):
this attempts to place a waterway in a random valid location on the map where currently there is an empty space ' '.

-------------------------------------------------
-------------------------------------------------

## vector<pair<int, int>> findValidLocations(const vector<vector<char>>& mapLayout, char targetType):
this identifies and returns all coordinates on the map that match the target type.

-------------------------------------------------
-------------------------------------------------

## WHAT is the zone providing?:
the zone class gives 'Environment' class the pollution calculations and responds to the enviromental changes.

-------------------------------------------------
-------------------------------------------------

## COMPILING AND RUNNING:
make sure to compile every header file and .cpp file in this project for this functionality to run.

EX: ('g++ *.cpp *.h')


