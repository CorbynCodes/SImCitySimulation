#include "Landfill.h"
#include <iostream>

using namespace std;

Landfill::Landfill(double cap) : currTrash(0), maxCap(cap)
{

}

bool Landfill::acceptTrash(double amount){
	if (currTrash + amount <= maxCap){
		currTrash += amount;
		return true;
	}
	else{
		cout << "Landfill full." << endl;
	}
	return false;
}

double Landfill::getCurrTrash() const{
	return currTrash;
}

void Landfill::genTrash(int resPopul, int comPopul, int indPopul, int hosPopul, int day){

	const double resRate = 1.00;
	const double comRate = 1.50;
	const double indRate = 2.00;
	const double hosRate = 1.75;
	double totTrashGen;

	for (int i = 1; i < day; i++){
		totTrashGen = i*((resPopul * resRate) + (comPopul * comRate) + (indPopul * indRate) + (hosPopul * hosRate));
		cout << "Day #" << i << "trash collected: ";
		cout << totTrashGen << "lbs." << endl;
	}

	if (acceptTrash(totTrashGen)){
		cout << "Trash Transported." << endl;
		cout << "Updated landfill capacity: " << getCurrTrash() << "lbs.";
	}
	else{
		cout << "Trash NOT transported. Landfill Full." << endl;
	}
}

