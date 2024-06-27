//These are the only header files allowed
//-----------------------------------------
#include <iostream>	//for cin and cout
#include <fstream>	//for file handling
#include <iomanip>	//for output formatting
#include <cmath>	//for sqrt
//-----------------------------------------
using namespace std;  //Define the namespace.
#include "city.h"
/***********************************************************************/
//Write here your code to define the enumerators, structures, and any 
// function needed.

int countRecords(const char fn[]) {
    ifstream infile;
    infile.open(fn);
    if (!infile.is_open()) {
        return -1;
    }

    int count = 0;
    char buffer[1000];
    while (!infile.eof()) {
        infile.getline(buffer,sizeof(buffer));
        count++;
    }
    return count;
}

int readLocation(const char fn[], location * lData, city * data, int size) {
    ifstream infile;
    infile.open(fn);
    if (!infile.is_open()) {
        return -2;
    }

    int count = 0;
    int helper;
    while (!infile.eof()) {
        infile >> helper;
        lData[count].setID(helper);
        data[count].location::setID(helper);

        infile >> helper;
		lData[count].setLat(helper);
        data[count].setLat(helper);

        infile >> helper;
		lData[count].setLon(helper);
        data[count].setLon(helper);

        count++;
    }
    return count;
}

int readCityName(const char fn[], location * lData, city * data, int size) {
    ifstream infile;
    infile.open(fn);
    if (!infile.is_open()) {
        return -2;
    }

    int count = 0;
    char buffer[100];
    int helper;
    while (!infile.eof()) {

        infile >> helper;
		infile.getline(buffer, sizeof(buffer));
        for (int i = 0; i < size; i++) {
			if (helper == lData[i].getID()) {
				data[count].cityName::setID(helper); // set id to cityName class
				data[count].setName(buffer); // sets name to cityName class
			}
		}
        count++;
    }
    return count;
}

bool stringInAString(const char * stringA, const char * stringB) {
    int i = 0;
    while (stringA[i] != '\0') {
        if (stringA[i] == stringB[0]) {
            int j = 0;
            while (stringB[j] != '\0') {
                if (stringA[i + j] != stringB[j]) {
                    break;
                }
                j++;
            }
            if (stringB[j] == '\0') {
                return true;
            }
        }
        i++;
    }

    return false;
}

int main() {
	int option;

	do {
		cout << "\n1. Display city data\n";
		cout << "2. Print list\n";
		cout << "3. Sort by city id\n";
		cout << "4. Find the linear distance between two cities(enter city ids)\n";
		cout << "5. Find the linear distance between two cities(enter city names)\n";
		cout << "6. Closest city\n";
		cout << "7. Exit\n";
		cin >> option;
		cin.ignore();

		switch (option) {
		case 1:
		{
			    char filename1[] = "location.txt";
                char filename2[] = "cityNames.txt";
                int numberOfRecords = countRecords(filename1);
                    if (numberOfRecords <= 0) {
                        return numberOfRecords;
                	}
				cout << "records are good." << endl;
				
                city * data = new city[numberOfRecords];
				cout << "declaration of city is good." << endl;
				location * lData = new location[numberOfRecords];
				cout << "declaration of location is good." << endl;


                int value1 = readLocation(filename1,lData,data,numberOfRecords);
					if (value1 <= 0) {
                        return -1;
                	}
				cout << "Reading location was good." << endl;
				int value2 = readCityName(filename2,lData,data,numberOfRecords);
					if (value2 <= 0) {
                        return -2;
                	}
				cout << "Reading city name was good." << endl;
				
				int number;
				cin >> number;
					if (number >= 0) {
						data[number].display(numberOfRecords);
					}
				
				delete [] data;
				delete [] lData;
			break;
		}
		case 2: {
			//2) Print as a table
			break;
		}
		case 3: {
			//3) Sort by city id
			break;
		}
		case 4: {
			//4) Find the linear distance between two cities(enter city ids)
			int cId1, cId2;
			cout << "Enter the first city id: ";
			cin >> cId1;
			cout << "Enter the second city id: ";
			cin >> cId2;

			if (cId1 == cId2) {
				cout << "id for the first and second city cannot be the same.\n";
				continue;
			}


			break;
		}
		case 5: {
			//5) Find the linear distance between two cities(enter city names)
			char cn1[100] = "Nome, Alaska";
			char cn2[100] = "Sitka, Alaska";
			cout << "Enter the first city name: ";
			cin.getline(cn1, sizeof(cn1));
			cout << "Enter the second city name: ";
			cin.getline(cn2, sizeof(cn2));



			break;
		}
		case 6: {
			int cId;
			cout << "Enter the  city id: ";
			cin >> cId;

			break;
		}

		case 7: {
			cout << "Ending the program....\n";
			break;
		}
		default: {
			cout << "Invalid option...\n";
			break;
		}
		}
	} while (option != 7);
	return 0;
}//End of main
