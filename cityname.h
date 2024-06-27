#ifndef CITYNAME_H
#define CITYNAME_H
#include <iostream>

class cityName {
    int ID;
    char * name;
public:
    int getID();
    char * getName();

    void setID(int inID);
    void setName(char * buffer);
    
    cityName(int inID = 0, char * inName = nullptr);
    ~cityName();
    
};
#endif