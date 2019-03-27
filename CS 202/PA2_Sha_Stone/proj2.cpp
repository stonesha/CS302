/*
 ============================================================================
 Name        : Stone Sha
 Lab         : 1104
 Date        : 9/9/2018
 ============================================================================
 */
#include <iostream>
#include <fstream>

#define MAX 10//maximum size
#define NUM 5//number of cars

using namespace std;

//Struct
    struct RentalCar
    {
        int year;
        char make[MAX];
        char model[MAX];
        float price;
        bool available;

    };

size_t my_StringLength (const char *str);
int my_StringCompare (const char *str1, const char *str2);
char *my_StringCat (char *dest, const char *src);
char *my_StringCopy (char *dest, const char *src);

//to print options
void printOptions();

//Struct Switch functions
void printStruct(struct RentalCar *cars);
void readinStruct(struct RentalCar *cars, ifstream &inFile);
void outputStruct (struct RentalCar *cars, ofstream &outFile);
void sortPrices (struct RentalCar *cars);
void rentStruct(struct RentalCar *cars);
void carchoiceStruct(struct RentalCar *cars);

int main()
{


    RentalCar cars[NUM];

    int option;

    ifstream inFile;
    ofstream outFile;

    while(option != 7)
    {
        printOptions();
        cin >> option;

        switch(option)
        {
        //-----------------------------------
        case 1:
            readinStruct(cars, inFile);
            break;

        //----------------------------------
        case 2:
            printStruct(cars);
            break;

        //----------------------------------
        case 3:
            outputStruct(cars, outFile);
            break;

        //----------------------------------
        case 4:
            sortPrices(cars);
            break;

        //----------------------------------
        case 5:
            rentStruct(cars);
            break;

        //----------------------------------
        case 6:
            carchoiceStruct(cars);
            break;

            //End of switch
        }
    }

    inFile.close();

    return 0;
}

//displays if car was rented successfully and calculates rent
void carchoiceStruct(struct RentalCar *cars)
{
    int carChoice, days;

    cout << "Which car do you want to rent?: ";
            cin >> carChoice;

            if(cars[carChoice].available == false)
            {
                cout << "That car is unavailable." << endl;

            }
            else if(cars[carChoice].available == true)
            {
                cout << "How many days would you like to rent this car?: ";
                cin >> days;
                cars[carChoice].available = false;
                cout << "Car rented successfully. The total cost will amount to: $"
                     << days * cars[carChoice].price << endl;
            }
}

//calculates cost for rentstruct
void rentStruct(struct RentalCar *cars)
{
    int days;

    cout << "How many days would you like to rent a car?: ";
            cin >> days;

            for(int i = 0; i < NUM; i++)
            {
                if(cars[i].available == true)
                {
                    cout << cars[i].year << " " << cars[i].make << " " << cars[i].model
                         << ", Total Cost: $" << cars[i].price * days << endl;
                }
            }
}

//sorts prices in array struct
void sortPrices (struct RentalCar *cars)
{
    for(int i = 0; i < NUM - 1; i++)
            {
                for(int j = 0; j < NUM - 1; j++)
                {
                    if(cars[j].price > cars[j + 1].price)
                    {
                        swap(cars[j + 1].price, cars[j].price);
                        swap(cars[j + 1].year, cars[j].year);
                        swap(cars[j + 1].make, cars[j].make);
                        swap(cars[j + 1].model, cars[j].model);
                        swap(cars[j + 1].available, cars[j].available);
                    }
                }
            }
}

//to output the struct to a file
void outputStruct (struct RentalCar *cars, ofstream &outFile)
{
    char fileOut[MAX + 3];// I add three to account for the file extension. e.g. ".txt" or ".dat"

    cout << "Enter your filename: ";
            cin >> fileOut;
            outFile.open(fileOut);
            for (int i = 0; i < NUM; i++)
            {
                outFile << cars[i].year << " " << cars[i].make << " " << cars[i].model
                        << ", $" << cars[i].price << " per day , Available: " << boolalpha
                        << cars[i].available << endl << endl;
            }
}

//to read in the struct from a file
void readinStruct(struct RentalCar *cars, ifstream &inFile)
{
    char fileIn [MAX + 3];// I add three to account for the file extension. e.g. ".txt" or ".dat"

    cout << "Enter your filename: ";
            cin >> fileIn;
            inFile.open(fileIn);
            for (int i = 0; i < NUM; i++)
            {
                inFile >> cars[i].year;
                inFile >> cars[i].make;
                inFile >> cars[i].model;
                inFile >> cars[i].price;
                inFile >> cars[i].available;
            }

    if(!inFile)
    {
        cerr << "Could not open File." << endl;
    }
}

//to print the struct array
void printStruct(struct RentalCar *cars)
{

    for(int i = 0; i < NUM; i++)
    {
        cout << cars[i].year << " " << cars[i].make << " " << cars[i].model << ", $" << cars[i].price
                 << " per day , Available: " << boolalpha << cars[i].available << endl;
    }

}

//Function to print the options otherwise it would be repetitive
void printOptions()
{
    cout << "Options:" << endl << "   1: Read Data from File" << endl
         << "   2: Print out Data for all Cars" << endl
         << "   3: Print Data to separate Output File" << endl
         << "   4: Sort Cars by Ascending Price" << endl
         << "   5: Renting Price Information" << endl
         << "   6: Choice of Car Rental and Length" << endl
         << "   7: Exit Program" << endl
         << "Enter your option: ";
}

//String Length Function ================================================
size_t my_StringLength (const char *str)
{

    int i = 0, length = 0;

    for(i = 0; str[i] != '\0'; i++)
    {
        length++;
    }

    return length;

}

//String Compare Function ================================================
int my_StringCompare (const char *str1, const char *str2)
{

    char *c1 = (char *) str1;
    char *c2 = (char *) str2;

    while (*c1 != '\0')
    {
        if (*c2 == '\0') return 1;

        if (*c2 > *c1) return -1;

        if (*c2 < *c1) return 1;

        c1++;
        c2++;
    }

    if (*c2 != '\0') return -1;

    return 0;

}

//String Concatenate Function ================================================
char *my_StringCat (char *dest, const char *src)
{
    char *final = dest;

    while(*dest != '\0')
    {
        dest++;
    }

    while(*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';

    return final;
}

//String Copy Function ================================================
char *my_StringCopy (char *dest, const char *src)
{
    char *final = dest;

    while(*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';

    return final;

}
