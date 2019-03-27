#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <cstring>

using namespace std;


class Vehicle
{
    public:
        Vehicle();
        Vehicle(const float *ptr);
        virtual ~Vehicle();
        Vehicle(const Vehicle& other);
        Vehicle& operator=(const Vehicle& other);



        void SetLLA(const float *ptr);
        float getLla(const int i);

        virtual void Move(float *ptr) = 0;
        friend ostream& operator<<(ostream& outFile, const Vehicle& vehicleObj);

    protected:
        float m_lla[3]; //latitude longitude altitude

    private:
        virtual void serialize(ostream& outFile)const;

};

#endif // VEHICLE_H
