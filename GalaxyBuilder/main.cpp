#include <iostream>
#include <string>
#include "Planet.h"
#include "Planets.h"

using namespace std;

int prompt();
void choices(Planets&, int);
void buildPlanet(Planets&, int);
string setName();
string setMadeOf();
int setAlienPopulation();
void mostPopulated(Planets&);
void number(Planets&);
int getPopulation(Planets&);
void printPopulation(Planets&, int);
bool quit();

int main() {
	Planets p;
	int option = prompt();
	while (option < 9) {
		choices(p, option);
		option = prompt();
	}
	quit();
}

//Prompt for choices
int prompt() {
	int option = 0;
	cout << "1. Build Planet\n2. Most Populated Planet.\n3. Number of planets\n4. Population of a planet.\n"
		<< "5. Add to beginning. \n6. Remove first planet.\n7. Remove last Planet.\n8. Clear Solar System.\n"
		<< "9. Quit.\nChoice (number only): ";
	cin >> option;
	cout << endl;
	return option;
}
//Choices!
void choices(Planets& p, int choice) {
	if (choice == 1)
		buildPlanet(p, choice);
	else if (choice == 2)
		mostPopulated(p);
	else if (choice == 3)
		number(p);
	else if (choice == 4)
		printPopulation(p, getPopulation(p));
	else if (choice == 5)
		buildPlanet(p, choice);
	else if (choice == 6)
		p.deleteFirst();
	else if (choice == 7)
		p.deleteLast();
	else if (choice == 8)
		p.deleteAll();
}

//1. Build Your Planet (with error messages)
void buildPlanet(Planets& p, int choice) {
	try {
		string name = setName(),
			madeOf = setMadeOf();
		int population = setAlienPopulation();
		Planet new_planet(name, madeOf, population);
		if (choice == 1)
			p.addPlanetBack(new_planet);
		else
			p.addPlanetFront(new_planet);
	}
	catch (Planet::EmptyName) {
		cout << "Error: No name given." << endl;
	}
	catch (Planet::EmptyMadeOf) {
		cout << "Error: No main element given." << endl;
	}
	catch (Planet::NegativePopulation) {
		cout << "Error: Negative population given." << endl;
	}
	cout << endl;
}
string setName() {
	string name;
	cout << "Planet name: ";
	cin >> name;
	return name;
}
string setMadeOf() {
	string madeOf;
	cout << "Main element of planet: ";
	cin >> madeOf;
	return madeOf;
}
int setAlienPopulation() {
	int population;
	cout << "Population of planet: ";
	cin >> population;
	return population;
}

//2. Most Populated Planet in System
void mostPopulated(Planets& p) {
	cout << p.getMostPopulatedPlanet().getName() << " with "
		<< p.getMostPopulatedPlanet().getAlienPopulation()
		<< " aliens that is made of " << p.getMostPopulatedPlanet().getMadeOf() << "." << endl << endl;
}

//3. Number of Planets in System
void number(Planets& p) {
	cout << "Number of Planet(s): " << p.getCount() << endl << endl;
}

//4. Population of Specified Planet
int getPopulation(Planets& p) {
	int num;
	for (int i = 0; i < p.getCount(); i++)
		cout << (i + 1) << ". " << p.get(i).getName() << endl;
	cout << "Which planet? (number only): ";
	cin >> num;
	cout << endl;
	return num - 1;
}
void printPopulation(Planets& p, int num) {
	cout << "The population of planet " << p.get(num).getName()
		<< " is: " << p.get(num).getAlienPopulation() << endl << endl;
}

//5. End Program
bool quit() {
	exit(0);
}