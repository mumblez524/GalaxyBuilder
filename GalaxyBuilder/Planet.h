#ifndef PLANET_H
#define PLANET_H
#include <string>
using namespace std;

class Planet {
private:
	string name;
	string madeOf;
	int alienPopulation;
public:
	//In case of errors
		//In case of empty string entered into name
	class EmptyName {};
	//In case of empty string entered into madeOf
	class EmptyMadeOf {};
	//In case of negative population entered into alienPopulation
	class NegativePopulation {};
	//Constructor
		//Used when finding which planet has the highest population. It comes into play 
		//by initializing an instance of a Planet to set the Planet with the highest 
		//population to as the loop in getMostPopulatedPlanet() progresses.
	Planet();
	//Used when a new planet needs to be built. Has errors thrown if strings are 
	//empty or integers are negative.
	Planet(string, string, int);
	//Getters
		//Used to get the name of a specified Planet
	string getName();
	//Used to get the madeOf of a specified Planet
	string getMadeOf();
	//Used to get the alienPopulation of a specified Planet
	int getAlienPopulation();
};
#endif