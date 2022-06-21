#include <string>
#include "Planet.h"

using namespace std;

//Constructors
	//Used when finding which planet has the highest population. It comes into play 
	//by initializing an instance of a Planet to set the Planet with the highest 
	//population to as the loop in getMostPopulatedPlanet() progresses.
Planet::Planet() {
	name = "";
	madeOf = "";
	alienPopulation = 0;
}
//Used when a new planet needs to be built. Has errors thrown if strings are 
//empty or integers are negative.
Planet::Planet(string n, string m, int a) {
	if (n == "")
		throw EmptyName();
	else
		name = n;
	if (m == "")
		throw EmptyMadeOf();
	else
		madeOf = m;
	if (a < 0)
		throw NegativePopulation();
	else
		alienPopulation = a;
}
//Getters
	//Used to get the name of a specified Planet
string Planet::getName() {
	return name;
}
//Used to get the madeOf of a specified Planet
string Planet::getMadeOf() {
	return madeOf;
}
//Used to get the alienPopulation of a specified Planet
int Planet::getAlienPopulation() {
	return alienPopulation;
}