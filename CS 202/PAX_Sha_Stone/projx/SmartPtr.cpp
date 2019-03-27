/**
 * @brief  CS-202 SmartPtr class Implementation
 * @author Stone Sha (stones@nevada.unr.edu)
 * @date   November, 2018
 *
 * This file contains the implementation of a smart pointer SmartPtr class.
 */

#include "SmartPtr.h"

SmartPtr::SmartPtr()
{
    //ctor
    m_ptr = new DataType;
    m_refcount = new size_t (1);

    cout << "SmartPtr Default Constructor for new allocation, RefCount=" << m_refcount << endl;

}

SmartPtr::~SmartPtr()
{
    //dtor
}

SmartPtr::SmartPtr(const SmartPtr& rhs)
{
    //copy ctor
}

SmartPtr& SmartPtr::operator=(const SmartPtr& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

