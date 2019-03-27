#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"


class Car : public Vehicle
{
    public:
        Car();
        virtual ~Car();
        Car(float *ptr);
        Car(const Car& other);
        Car& operator=(const Car& other);

        void setThrottle(int x);
        int getThrottle();
        void drive(int x);

        virtual void Move(float *ptr);



    protected:

    private:
        int m_throttle; //throttle command to bring into motion
        virtual void serialize(ostream& outFile)const; // serialize
};

#endif // CAR_H
