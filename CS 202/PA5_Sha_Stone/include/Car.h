#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

using namespace std;

class Car : public Vehicle
{
    public:
        Car();
        virtual ~Car();
        Car(char plates[256], int x, float lla[3]);
        friend ostream& operator<<(ostream& outFile, Car &carObj);
        friend istream& operator>>(istream& infile, Car &carObj);
        void setLla(float *lla);
        Car& operator=(Car& vl);
        Car(const Car &obj);

        char* getPlates();
        int getThrottle();
        void setPlates(char *str);
        void setThrottle(int x);

        void drive(int x);
        void move(float *lla);

    protected:

    private:
        char m_plates[256]; //car license plates
        int m_throttle; //throttle command to bring into motion
};

#endif // CAR_H
