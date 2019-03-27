#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string.h>

using namespace std;


class Vehicle
{
    public:
        Vehicle();
        virtual ~Vehicle();
        Vehicle(const Vehicle &vl);
        Vehicle(int x, float *lla);
        friend ostream& operator<<(ostream& outFile, Vehicle& vehicleObj);
        friend istream& operator>>(istream& inFile, Vehicle& vehicleObj);
        static int getIdgen();
        Vehicle& operator=(Vehicle& vl);
        void move(float *lla);

        float getLla(int i) const;
        void setLla(float *lla);

        int getVin() const;
        void setVin(int x);

    protected:
        float m_lla[3]; //location of vehicle on earth, lla = latitude,longitude,altitude
        const int m_vin; //Vehicle identification number

    private:
        static int s_idgen;
};



#endif // VEHICLE_H
