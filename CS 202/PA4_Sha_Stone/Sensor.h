#ifndef SENSOR_H
#define SENSOR_H

#include "func.h"

class Sensor
{
    public:
        Sensor();
        Sensor(const Sensor& other);
        Sensor(char temp[MAX_CHAR], int cost);

        //GET AND SET FUNCTIONS ==============================
        char *getType();
        float getExtraCost();
        int getGPS();
        int getCamera();
        int getLidar();
        int getRadar();
        void setType(char temp[MAX_CHAR]);
        void setExtraCost(float temp);
        void resetGPS();
        void resetCamera();
        void resetLidar();
        void resetRadar();
        //======================================================
        void incGPS();
        void incCamera();
        void incLidar();
        void incRadar();

        void printValues();
        friend bool operator==(Sensor s1, Sensor s2);


    private:
        char m_type[MAX_CHAR];
        float m_extracost;
        static int gps_cnt;
        static int camera_cnt;
        static int lidar_cnt;
        static int radar_cnt;
};


#endif // SENSOR_H
