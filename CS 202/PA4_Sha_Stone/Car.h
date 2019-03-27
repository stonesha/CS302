#ifndef CAR_H
#define CAR_H

#include "func.h"
#include "Sensor.h"

class Car
{
    public:
        Car();
        Car(const Car& other);
        Car(char temp_make[MAX_CHAR], char temp_model[MAX_CHAR], int temp_year, float temp_baseprice, Sensor(temp_sensor));

        //GET AND SET FUNCTIONS ==============================
        char *getMake();
        char *getModel();
        int getYear();
        float getBasePrice();
        float getFinalPrice();
        bool getAvailable();
        char *getOwner();
        void setMake(char temp[MAX_CHAR]);
        void setModel(char temp[MAX_CHAR]);
        void setYear(int temp);
        void setBasePrice(float temp);
        void setAvailable(bool temp);
        void setOwner(char temp[MAX_CHAR]);
        //============================================================
        void updatePrice();
        void print();
        float estimateCost(int days);
        Sensor *returnPtr();
        //=======================================================
        Car& operator+(Sensor& s1);
        Car& operator+(const char *temp);
        Sensor operator[](const int index);

    private:
        char m_make[MAX_CHAR]; //car make
        char m_model[MAX_CHAR];//car model
        int m_year;//year of production
        Sensor m_sensors[MAX_SENSOR];//max allowable number of sensors per car
        float m_baseprice;//price per day for the sensor-less vehicle
        float m_finalprice;//(price per day with the increased cost of the car sensors)
        bool m_available;//1 = true; 0 = false
        char m_owner[MAX_CHAR];//(the current lessee; if no lessee, i.e.the Car object is available), set to a ‘\0’-starting (0-length) C-string

};

#endif // CAR_H
