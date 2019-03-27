/**
 * @brief  CS-202 SmartPtr class Declaration
 * @author Christos Papachristos (cpapachristos@unr.edu)
 * @date   November, 2018
 *
 * This file contains the declaration of a smart pointer SmartPtr class for the purposes of CS-202.
 */

#ifndef SMARTPTR_H_
#define SMARTPTR_H_

#include "DataType.h"

using namespace std;

class SmartPtr {

  public:

    SmartPtr( ); //constructor
    SmartPtr( DataType * data ); //parameterized constructor
    SmartPtr( const SmartPtr & other ); // copy constructor

    ~SmartPtr( ); // destructor

    SmartPtr & operator=( const SmartPtr & rhs ); // assigment operator

    DataType & operator*( ); //reference / dereference operator
    DataType * operator->( ); //??? operator

  private:

    size_t * m_refcount; //for how many smart pointers are referenced
    DataType * m_ptr; //pointer of DataType type

};

#endif //SMARTPTR_H_
