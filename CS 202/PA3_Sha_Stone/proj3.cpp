/*
 ============================================================================
 Name        : Stone Sha
 Lab         : 1104
 Date        : 9/19/2018
 ============================================================================
 */
#include "proj3.h"

//Main
int main()
{

    int option;

    //Fstream
    ifstream inFile;
    ofstream outFile;

    RentalAgency agencies[AGENCY_NUM];
    RentalAgency *temp = agencies;
    RentalCar *temp_inventory = agencies->inventory;


    //while
    while(option != 6)
    {
        printOptions();
        cin >> option;

        //Beginning of switch
        switch(option)
        {

        case 1:
            readinData(temp, inFile, temp_inventory);
            temp = agencies;
            temp_inventory = agencies->inventory;
            break;

        case 2:
            printStruct(temp);
            temp = agencies;
            temp_inventory = agencies->inventory;
            break;

        case 4:
            //findExpensiveCar(temp);
            break;

        case 6:
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
