/*
 ============================================================================
 Name        : Stone Sha
 Lab         : 1104
 Date        : 9/20/2018
 ============================================================================
 */
#include "func.h"
#include "Sensor.h"
#include "Agency.h"
#include "Car.h"


using namespace std;

int main()
{


    int option, total_sensors, k;
    float maximum = 0;
    char input[MAX_CHAR], input2;

    //Fstream
    ifstream inFile;
    ofstream outFile;

    //Objects
    Agency agencyObj;
    Car *carPtr = agencyObj.returnPtr(); //m_inventory
    Sensor *sensorPtr = carPtr->returnPtr();//m_sensors

    //while
    while(option != 5)
    {
        printOptions();
        cin >> option;

        //Beginning of switch
        switch(option)
        {

        case 1:
            cout << "Please enter the filename: ";
            cin >> input;

            inFile.open(input);

            inFile >> agencyObj;
            break;

        case 2:
            agencyObj.printAll();
            break;

        case 3:
            total_sensors = sensorPtr->getGPS() + sensorPtr->getCamera() + sensorPtr->getLidar() + sensorPtr->getRadar();
            cout << "The total amount of sensors is: " << total_sensors << endl << "GPS Sensors: " << sensorPtr->getGPS() << endl << "Camera Sensors: "
                 << sensorPtr->getCamera() << endl << "Lidar Sensors: "
                 << sensorPtr->getLidar() << endl << "Radar Sensors: "
                 << sensorPtr->getRadar() << endl;
            break;

        case 4:
            for(int i = 0; i < MAX_CAR; i++)
            {
                if(carPtr[i].getBasePrice() > maximum)
                {
                    maximum = carPtr[i].getBasePrice();
                    k = i;
                }
            }

            cout << "The most expensive car is: " << agencyObj[k].getYear() << " " << agencyObj[k].getMake()
                 << " " << agencyObj[k].getModel() << " for $" << agencyObj[k].getBasePrice() << endl;

            cout << "Would you like to rent the car(y/n)?: ";
            cin >> input2;
            if(input2 = 'y')
            {
                agencyObj[k].setOwner("User");
                agencyObj[k].setAvailable(0);

                cout << "You have rented the " << agencyObj[k].getYear() << " " << agencyObj[k].getMake()
                 << " " << agencyObj[k].getModel() << " for $" << agencyObj[k].getBasePrice() << ", Availability: " << boolalpha
                 << agencyObj[k].getAvailable() << " " << agencyObj[k].getOwner() << endl;
            }

        case 5:
            break;

        default:
            cout << "Invalid Option." << endl;
            break;

        }
        //End of switch
    }
    //End of while



    inFile.close();
    outFile.close();

    return 0;
}


