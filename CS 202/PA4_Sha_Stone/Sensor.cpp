#include "Sensor.h"

int Sensor::gps_cnt = 0;
int Sensor::camera_cnt = 0;
int Sensor::lidar_cnt = 0;
int Sensor::radar_cnt = 0;

Sensor::Sensor()
{
    my_StringCopy(m_type, "sensor");
    m_extracost = 0;
}

Sensor::Sensor(char temp[MAX_CHAR], int cost)
{
    my_StringCopy(m_type, temp);
    m_extracost = cost;
}

Sensor::Sensor(const Sensor& other)
{
    my_StringCopy(m_type, other.m_type);
    m_extracost = other.m_extracost;
}


//GET AND SET FUNCTIONS ==============================
char *Sensor::getType(){return m_type;}

float Sensor::getExtraCost(){return m_extracost;}

int Sensor::getGPS(){return gps_cnt;}

int Sensor::getCamera(){return camera_cnt;}

int Sensor::getLidar(){return lidar_cnt;}

int Sensor::getRadar(){return radar_cnt;}

void Sensor::setType(char temp[MAX_CHAR]){my_StringCopy(m_type, temp);}

void Sensor::setExtraCost(float temp){m_extracost = temp;}

void Sensor::resetGPS(){gps_cnt = 0;}

void Sensor::resetCamera(){camera_cnt = 0;}

void Sensor::resetLidar(){lidar_cnt = 0;}

void Sensor::resetRadar(){radar_cnt = 0;}
//=======================================================

void Sensor::incGPS(){gps_cnt++;}

void Sensor::incCamera(){camera_cnt++;}

void Sensor::incLidar(){lidar_cnt++;}

void Sensor::incRadar(){radar_cnt++;}

void Sensor::printValues()
{
    std::cout << getType() << " ";
    printf("%.2f ", getExtraCost());
    std::cout << getGPS() << " " << getLidar() << " " << getRadar() << " " << getCamera();
}

//Sensor operator overload ==
bool operator==(Sensor s1, Sensor s2)
{
    return my_StringCompare(s1.getType(), s2.getType()) == 0 ? true : false;
}



