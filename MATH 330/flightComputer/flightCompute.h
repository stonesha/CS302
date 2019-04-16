#pragma once

#define AIR_DENSITY_SEA_LEVEL 1.22 //kg/m^3

/**
* Computes magnetic heading (degrees)
* @param        theta = true heading in degrees
* @param        v = indicated air speed (IAS) in knots
* @param        h = altitude above sea level in feet
* @param        w = wind speed in knots
* @param        phi = wind direction in degrees
* @param        t = temperature of air in Celsius
**/
void computeFlight(double theta, double v, double h,
                   double w, double phi, double t)
{


}

/**
* Computes true ground speed (knots)
* @param        theta = true heading in degrees
* @param        v = indicated air speed (IAS) in knots
* @param        h = height in feet
* @param        w = wind speed in knots
* @param        phi = wind direction in degrees
* @param        t = temperature of air in Celsius
**/
void computeGroundSpeed(double theta, double v, double h,
                   double w, double phi, double t)
{


}

/**
* Computes True Airspeed (TAS)
* @param        v = indicated air speed (IAS) in knots
* @param        h = altitude above sea level in feet
**/
double calculateTAS(double v, double h)
{

}

double feetToMeters(double& h)
{
    h = h * 0.3048;

    return h;
}
