#include "Planets.h"

using namespace std;

//Adds planet to back of list.
void Planets::addPlanetBack(Planet planet) {
	planets.push_back(planet);
}
//Adds planet to front of list.
void Planets::addPlanetFront(Planet planet) {
	planets.push_front(planet);
}
//Deletes first planet in list.
void Planets::deleteFirst() {
	planets.pop_front();
}
//Deletes last planet in list.
void Planets::deleteLast() {
	planets.pop_back();
}
//Deletes all planets from list.
void Planets::deleteAll() {
	planets.clear();
}

//Getters

//Gets the number of Planets in the 'planets' vector
int Planets::getCount() {
	return planets.size();
}
//Calculates which planet has the highest population
//out of the vector 'planets'
Planet Planets::getMostPopulatedPlanet() {
	Planet highest_pop;
	for (int i = 0; i != planets.size(); i++) {
		if (planets.get(i).getAlienPopulation() > highest_pop.getAlienPopulation())
			highest_pop = planets.get(i);
	}
	return highest_pop;
}
//Used to specify a place in the 'planets' vector
Planet Planets::get(int i) {
	return planets.get(i);
}