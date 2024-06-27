#include "city.h"
#include <iostream>
using namespace std;

city::city(int inID, double inLat, double inLon, char * inName): location(inID, inLat, inLon), cityName(inID, inName) {}

void city::display(int size) {
    cout << location::getID() << '\t' << location::getLat() << '\t' << location::getLon() << '\t' << cityName::getName() << endl;
}