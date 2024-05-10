#ifndef LANDFILL_H
#define LANDFILL_H

#include "Zone.h"
#include <string>
#include <vector>

class Landfill {
public:
	Landfill(double cap);
	bool acceptTrash(double amount);
	double getCurrTrash() const;
	void genTrash(int resPopul, int comPopul, int indPopul, int hosPopul, int day);

private:
	double currTrash;
	double maxCap;
};

#endif
