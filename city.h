#ifndef CITY_H
#define CITY_H
#include "location.h"
#include "cityname.h"

class city : public location, public cityName {
    public: 
        city(int inID = 0, double inLat = 0, double inLon = 0, char * inName = nullptr);
        void display(int size);
};
#endif