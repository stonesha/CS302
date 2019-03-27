#include "Agency.h"
#include "Sensor.h"

Agency::Agency()
{
    my_StringCopy(m_name, "name");
    m_zipcode = 12345;
}
//GET AND SET FUNCTIONS ==============================

char *Agency::getName()
{
    return m_name;
}

int Agency::getZipcode()
{
    return m_zipcode;
}

void Agency::setName(char temp[MAX_CHAR])
{
    my_StringCopy(m_name, temp);
}

void Agency::setZipcode(int temp)
{
    m_zipcode = temp;
}

//====================================================
Car *Agency::returnPtr()
{
    Car *carPtr = m_inventory;
    return carPtr;
}

void Agency::printAll()
{
    Car *carPtr = returnPtr(); //m_inventory
    Sensor *sensorPtr = carPtr->returnPtr();//m_sensors

    std::cout << getName() << " " << getZipcode() << std::endl;

    for(int i = 0; i < MAX_CAR; i++, carPtr++, sensorPtr++)
    {
        std::cout << carPtr->getYear() << " " << carPtr->getMake() << " " << carPtr->getModel() << " ";
        printf("$%.2f", carPtr->getBasePrice());
        std::cout << " " << sensorPtr->getType() << "}, Availability: " << std::boolalpha << carPtr->getAvailable();
        if(carPtr->getAvailable() == 0)
        {
            std::cout << ", Owner: " << carPtr->getOwner() << std::endl;
        }
        else
        {
            std::cout << std::endl;
        }
    }

}

void Agency::printAvailable()
{
    Car *carPtr = returnPtr(); //m_inventory
    Sensor *sensorPtr = carPtr->returnPtr();//m_sensors

    std::cout << getName() << " " << getZipcode() << std::endl;

    for(int i = 0; i < MAX_CAR; i++, carPtr++, sensorPtr++)
    {
        if(carPtr->getAvailable() == 1)
        {
            std::cout << carPtr->getYear() << " " << carPtr->getMake() << " " << carPtr->getModel() << " ";
            printf("$%.2f", carPtr->getBasePrice());
            std::cout << " " << sensorPtr->getType() << "}, Availability: " << std::boolalpha << carPtr->getAvailable() << std::endl;
        }
    }
}

//OPERATORS===================================================
Car Agency::operator[](const int index)
{
    return m_inventory[index];
}


std::istream& operator>>(std::istream& inFile, Agency &agencyObj)
{
    int temp_int;
    float temp_float;
    char temp_char[MAX_CHAR];
    bool temp_bool;
    Car *carPtr = agencyObj.returnPtr(); //m_inventory
    Sensor *sensorPtr = carPtr->returnPtr();//m_sensors

    if(inFile.good() && !inFile.eof())
    {
        std::cout << "File opened successfully." << std::endl;
    }
    else
    {
        std::cout << "File not opened successfully." << std::endl;
    }

    inFile >> temp_char >> temp_int;//zipcode and agency name
    agencyObj.setName(temp_char);
    agencyObj.setZipcode(temp_int);

    for(int i = 0; i < MAX_CAR; i++, carPtr++, sensorPtr++) //reads in car/m_inventory data
    {
        inFile >> temp_int;
        carPtr->setYear(temp_int);

        inFile >> temp_char;
        carPtr->setMake(temp_char);

        inFile >> temp_char;
        carPtr->setModel(temp_char);

        inFile >> temp_float;
        carPtr->setBasePrice(temp_float);

        inFile.getline(temp_char, 25, '}');
        sensorPtr->setType(temp_char);

        if(my_StringCompare(temp_char, "{gps") == 0)
        {
            sensorPtr->incGPS();
            if(my_StringCompare(temp_char, "{gps camera") == 0)
            {
                sensorPtr->incCamera();
                if(my_StringCompare(temp_char, "{gps camera lidar") == 0)
                {
                    sensorPtr->incLidar();
                }
                else if (my_StringCompare(temp_char, "{gps camera radar") == 0)
                {
                    sensorPtr->incRadar();
                }
            }
            else if(my_StringCompare(temp_char, "{gps lidar") == 0)
            {
                sensorPtr->incLidar();
            }
            else if(my_StringCompare(temp_char, "{gps radar") == 0)
            {
                sensorPtr->incRadar();
            }
        } else if(my_StringCompare(temp_char, "{camera") == 0)
        {
            sensorPtr->incCamera();
            if(my_StringCompare(temp_char, "{camera lidar") == 0)
            {
                sensorPtr->incLidar();
            }else if(my_StringCompare(temp_char, "{camera radar") == 0)
            {
                sensorPtr->incRadar();
            }
        } else if(my_StringCompare(temp_char, "{lidar") == 0)
        {
            sensorPtr->incLidar();
            if(my_StringCompare(temp_char, "{lidar radar") == 0)
            {
                sensorPtr->incRadar();
            }
        }else if(my_StringCompare(temp_char, "{radar") == 0)
        {
            sensorPtr->incRadar();
        }


        inFile >> temp_bool;
        carPtr->setAvailable(temp_bool);

        if(temp_bool == 0) //checks for owner
        {
            inFile >> temp_char;
            carPtr->setOwner(temp_char);
        }

    }

    std::cout << "File read successfully" << std::endl;

    return inFile;
}

