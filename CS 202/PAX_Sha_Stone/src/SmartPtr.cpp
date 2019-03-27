#include "SmartPtr.h"

SmartPtr::SmartPtr()
{
    //ctor
}

SmartPtr::~SmartPtr()
{
    //dtor
}

SmartPtr::SmartPtr(const SmartPtr& other)
{
    //copy ctor
}

SmartPtr& SmartPtr::operator=(const SmartPtr& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
