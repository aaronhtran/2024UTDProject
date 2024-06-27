#include "cityname.h"
#include <iostream>
using namespace std;


int cityName::getID() { return ID; }
char * cityName::getName() { return name; }

void cityName::setID(int inID) { ID = inID; }
void cityName::setName(char * buffer) {
    if (name != nullptr) { delete [] name; }

    int l = 0;
    while (buffer[l] != '\0') { l++; }

    name = new char[l+1];
    for (int i = 0; i < l; i++) { name[i] = buffer[i]; }
    name[l] = '\0';
}

cityName::cityName(int inID, char * inName) {
    ID = inID;
    if (inName != nullptr) {
        setName(inName);
    } else {
        name = nullptr;
    }
}
cityName::~cityName() {
    if (name != nullptr) {
        delete [] name;
    }
}