#include "location.h"
#include <iostream>
using namespace std;


int location::getID() { return ID; }
double location::getLat() { return lat; }
double location::getLon() { return lon; }

void location::setID(int inID) { ID = inID; }
void location::setLat(double inLat) { lat = inLat; }
void location::setLon(double inLon) { lon = inLon; }

location::location(int inID, double inLat, double inLon) {
    ID = inID;
    lat = inLat;
    lon = inLon;
}   