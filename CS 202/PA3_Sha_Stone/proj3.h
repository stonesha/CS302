/*
 ============================================================================
 Name        : Stone Sha
 Lab         : 1104
 Date        : 9/19/2018
 ============================================================================
 */
#ifndef RENTALCAR_H_INCLUDED
#define RENTALCAR_H_INCLUDED

#include <iostream>
#include <fstream>

using namespace std;

int const MAX = 256;
int const CAR_NUM = 5;
int const AGENCY_NUM = 3;

size_t my_StringLength (const char *str);
int my_StringCompare (const char *str1, const char *str2);
char *my_StringCat (char *dest, const char *src);
char *my_StringCopy (char *dest, const char *src);

//Class
class RentalCar
{
public:
    RentalCar()
    {
        m_year = 1999;
        my_StringCopy(m_make, "make");
        my_StringCopy(m_model, "model");
        m_price = 0.00;
        m_available = false;
    }

    RentalCar(int year, char make[MAX], char model[MAX], float price, bool available)
    {
        m_year = year;
        my_StringCopy(m_make, make);
        my_StringCopy(m_model, model);
        m_price = price;
        m_available = available;

    }

    //Year set and get
    int getYear()
    {
        return m_year;
    }

    void setYear(int year)
    {
        m_year = year;
    }

    //Make set and get
    char *getMake()
    {
        return m_make;
    }

    char setMake(char make[MAX])
    {
        my_StringCopy(m_make, make);
    }

    //Model set and get
    char *getModel()
    {
        return m_model;
    }

    char setModel(char model[MAX])
    {
        my_StringCopy(m_model, model);
    }

    //Price set and get
    float getPrice()
    {
        return m_price;
    }

    void setPrice(float price)
    {
        m_price = price;
    }

    //Available set and get
    bool getAvailable()
    {
        return m_available;
    }

    void setAvailable(bool available)
    {
        m_available = available;
    }

    //Printing out cars data
    void print()
    {
        cout << m_year << " " << m_make << " " << m_model << ", $";
        printf("%.2f", m_price);
        cout << " per day, Available:  " << boolalpha << m_available << endl;
    }

    //Estimating cost of cars rent per day
    float estimateCost(int days)
    {
        return days * m_price;
    }

private:
    int m_year; //year of production
    char m_make[MAX];
    char m_model[MAX];
    float m_price; //price per day
    bool m_available;

};

struct RentalAgency
{

    char name[MAX];
    int zipcode[CAR_NUM];
    RentalCar inventory[CAR_NUM];

};

//Function to print the options otherwise it would be repetitive
void printOptions()
{
    cout << "Options:" << endl << "   1: Read Data from File" << endl
         << "   2: Print out Data for all Cars & Agencies" << endl
         << "   3: Estimate Car Rental Cost" << endl
         << "   4: Fine Most Expensive Car" << endl
         << "   5: Print out Available Cars to Output File" << endl
         << "   6: Exit Program" << endl
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

void readinData(struct RentalAgency *agencies, ifstream &inFile, RentalCar *temp_inventory)
{
    char input[MAX];

    cout << "Enter the filename: ";
    cin >> input;
    inFile.open(input);

    struct RentalAgency *temp = agencies;

    char *temp_name = temp->name;
    int *temp_zipcode = temp->zipcode;

    int year;
    char make[MAX];
    char model[MAX];
    float price;
    bool available;

    if(!inFile)
    {
        cout << "Could not open file." << endl;
    }
    else
    {

        for(int i = 0; i < AGENCY_NUM; i++, agencies++)
        {

            inFile >> agencies->name;

            inFile >> *agencies->zipcode;

            for(int j = 0; j < CAR_NUM; j++, temp_inventory++)
            {
                inFile >> year;
                temp_inventory->setYear(year);
                inFile >> make;
                temp_inventory->setMake(make);
                inFile >> model;
                temp_inventory->setModel(model);
                inFile >> price;
                temp_inventory->setPrice(price);
                inFile >> available;
                temp_inventory->setAvailable(available);
            }
        }



    }



}

void printStruct(struct RentalAgency *agencies)
{
    struct RentalAgency *temp = agencies;

    for(int i = 0; i < AGENCY_NUM; i++, temp++)
    {
        cout << temp->name << " " << *temp->zipcode << endl;
    }
}

void findExpensiveCar(struct RentalAgency *agencies)
{
    int highNum = 0;

    RentalCar *temp_inventory = agencies->inventory;

    for(int i = 0; i < AGENCY_NUM; i++, agencies++)
    {

        for(int i = 0; i < CAR_NUM; i++, temp_inventory++)
        {

            if(temp_inventory->getPrice() > highNum)
            {
                highNum = temp_inventory ->getPrice();
            }

        }
    }

    cout << highNum;
}

#endif // RENTALCAR_H_INCLUDED
