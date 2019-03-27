#include "Car.h"

Car::Car()
{

    my_StringCopy(m_make, "Make");
    my_StringCopy(m_model, "Model");
    m_year = 2000;
    m_baseprice = 100.01;
    m_finalprice = 100.01;
    m_available = 0;
    my_StringCopy(m_owner, "Jerry");

}


Car::Car(const Car& other)
{
    my_StringCopy(m_make, other.m_make);
    my_StringCopy(m_model, other.m_model);
    m_year = other.m_year;
    m_baseprice = other.m_baseprice;
    m_finalprice = other.m_finalprice;
    m_available = other.m_available;
    my_StringCopy(m_owner, other.m_owner);
}

Car::Car(char temp_make[MAX_CHAR], char temp_model[MAX_CHAR], int temp_year, float temp_baseprice, Sensor(temp_sensor))
{
    my_StringCopy(m_make, temp_make);
    my_StringCopy(m_model, temp_model);
    m_year = temp_year;
    m_baseprice = temp_baseprice;
}
//GET AND SET FUNCTIONS ==============================
char *Car::getMake(){return m_make;}

char *Car::getModel(){return m_model;}

int Car::getYear(){return m_year;}

float Car::getBasePrice(){return m_baseprice;}

float Car::getFinalPrice(){return m_finalprice;}

bool Car::getAvailable(){return m_available;}

char *Car::getOwner(){return m_owner;}

void Car::setMake(char temp[MAX_CHAR]){my_StringCopy(m_make, temp);}

void Car::setModel(char temp[MAX_CHAR]){my_StringCopy(m_model, temp);}

void Car::setYear(int temp){m_year = temp;}

void Car::setBasePrice(float temp){m_baseprice = temp;}

void Car::setAvailable(bool temp){m_available = temp;}

void Car::setOwner(char temp[MAX_CHAR]){my_StringCopy(m_owner, temp);}
//=====================================================

void Car::updatePrice()
{
    m_finalprice = m_baseprice;
}

void Car::print()
{
    std::cout << m_year << " " << m_model << " " << m_make << " $" << m_baseprice << "per day, Available: " << std::boolalpha << m_available << std::endl;
}

float Car::estimateCost(int days)
{
    float total;
    total = m_finalprice * days;
    return total;
}

Sensor *Car::returnPtr()
{
    Sensor *sensorPtr = m_sensors;
    return sensorPtr;
}

//=====================================================
Car& Car::operator+(Sensor& s1)
{
    Sensor *sp = m_sensors;

    for(int i = 0; i < MAX_SENSOR; i++)
    {
        if(my_StringCompare(sp->getType(), "none"))
        {
            sp->setType(s1.getType());
        }
        sp++;
    }

    return *this;
}

Car & Car::operator+(const char *temp)
{
    if(m_available == 1)
    {
        my_StringCopy(m_owner, temp);
        m_available = 0;
    }

    return *this;
}
Sensor Car::operator[](const int index)
{
    return m_sensors[index];
}


