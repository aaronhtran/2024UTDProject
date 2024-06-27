#ifndef LOCATION_H
#define LOCATION_H
#include <iostream>

class location {
    int ID;
    double lat;
    double lon;
public:
    location(int inID = 0, double inLat = 0, double inLon = 0);

    int getID();
    double getLat();
    double getLon();

    void setID(int inID);
    void setLat(double inLat);
    void setLon(double inLon);
};
#endif