#ifndef AGENCY_H
#define AGENCY_H

#include "func.h"
#include "Car.h"

class Agency
{
    public:
        Agency();

        //GET AND SET FUNCTIONS ==============================
        char *getName();
        int getZipcode();
        void setName(char temp[MAX_CHAR]);
        void setZipcode(int temp);
        //==============================================
        Car operator[](const int index);
        friend std::istream& operator>>(std::istream& inFile, Agency &agencyPtr);
        void printAll();
        void printAvailable();
        Car *returnPtr();

    private:
        char m_name[MAX_CHAR];
        int m_zipcode;
        Car m_inventory[MAX_CAR];
};

#endif // AGENCY_H
