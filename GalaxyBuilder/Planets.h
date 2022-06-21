#ifndef PLANETS_H
#define PLANETS_H
#include "LinkedList.h"
#include "Planet.h"

using namespace std;

class Planets {
private:
	//Solar System as a vector
	LinkedList<Planet> planets;
public:
	//Adds planet to back of list.
	void addPlanetBack(Planet planet);
	//Adds planet to front of list.
	void addPlanetFront(Planet planet);
	//Deletes first planet in list.
	void deleteFirst();
	//Deletes last planet in list.
	void deleteLast();
	//Deletes all planets from list.
	void deleteAll();

	//Getters

	//Gets the number of Planets in the 'planets' vector
	int getCount();
	//Calculates which planet has the highest population out of the vector 'planets'
	Planet getMostPopulatedPlanet();
	//Used to specify a place in the 'planets' vector
	Planet get(int);
};
#endif