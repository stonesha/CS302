/**
 * @brief  CS-202 Project 10 ArrayStack header
 * @Author Stone Sha (stones@nevada.unr.edu)
 * @date   November - December, 2018
 *
 * This file is the header file for the class ArrayStack
 */
#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "DataType.h"

//global value
const int MAX_STACKSIZE = 1000;

//forward declaration of template
template <class Datatype> class ArrayStack;
template <class Datatype> std::ostream & operator<< (std::ostream & os, const ArrayStack<DataType> & arrayStack);

//class method declarations
template <class DataType>
class ArrayStack
{

    friend std::ostream & operator<< <DataType>(std::ostream & os, const ArrayStack<DataType> & arrayStack);//(i)


    public:
        ArrayStack(); //(1)
        ArrayStack(size_t count, const DataType & value); //(2)
        ArrayStack(const ArrayStack<DataType> & other); //(3)

        ArrayStack & operator= (const ArrayStack<DataType> & rhs); //(5)

        DataType & top(); //(6a)
        const DataType & top() const; //(6b)

        void push(const DataType & value); //(7)
        void pop(); //(8)

        size_t size() const; //(9)
        bool empty() const; //(10)
        bool full() const; //(11)
        void clear(); //(12)

        void serialize(std::ostream & os) const; //(13)

    private:
        DataType m_container[MAX_STACKSIZE];
        size_t m_top;
};

//outputting values of arraystack
template <class DataType>
std::ostream & operator<< (std::ostream & os, //(i)
                          const ArrayStack<DataType> & arrayStack)
{
    arrayStack.serialize(os);
    return os;
}

template <class DataType>
ArrayStack<DataType>::ArrayStack():m_top(0) //(1) instantiates new object with no valid data
{
    std::cout << "Default Constructor" << std::endl;
}

template <class DataType>
ArrayStack<DataType>::ArrayStack(size_t count, const DataType & value):m_top(count) //(2) holds size_t number of values, all values set equal
{
    for(size_t i = 0; i < m_top; i++)
    {
        m_container[i] = value;
    }
    std::cout << "Param Constructor: m_top = " << m_top << ", values set to " << value << std::endl;
}

template <class DataType>
ArrayStack<DataType> & ArrayStack<DataType>::operator= (const ArrayStack<DataType> & rhs) //(5) copies values of one ArrayStack to another
{
    if(this == &rhs)
        return *this; //handles self assignment

    for(size_t i = 0; i < rhs.m_top; i++)
    {
        m_container[i] = rhs.m_container[i];
    }

    m_top = rhs.m_top;

    return *this;
}

template <class DataType>
DataType & ArrayStack<DataType>::top() //(6a) returns top of container
{
    if(m_top == 0)
        std::cout << "m_container is empty, exiting..." << std::endl;

    return m_container[m_top - 1];

}

template <class DataType>
const DataType & ArrayStack<DataType>::top() const //(6b)
{
    if(m_top == 0)
        std::cout << "m_container is empty, exiting..." << std::endl;

    return m_container[m_top - 1];

}

template <class DataType>
void ArrayStack<DataType>::push(const DataType & value) //(7) pushes value to top
{
    if(m_top == MAX_STACKSIZE)
    {
        std::cout << "m_container is full, exiting..." << std::endl;
    }

    m_container[m_top] = value;
    ++m_top;
}

template <class DataType>
void ArrayStack<DataType>::pop() //(8) pops top value
{
    if(m_top == 0)
    {
        std::cout << "m_container is empty, exiting..." << std::endl;
        return;
    }

    DataType dt_null;

    m_container[m_top - 1] == dt_null;
    --m_top;
}

template <class DataType>
size_t ArrayStack<DataType>::size() const //(9) returns size of container
{
    return m_top;
}

template <class DataType>
bool ArrayStack<DataType>::empty() const //(10)
{
    return m_top == 0 ? true : false;
}

template <class DataType>
bool ArrayStack<DataType>::full() const //(11) returns bool for if full or not
{
    return m_top == MAX_STACKSIZE ? true : false;
}

template <class DataType>
void ArrayStack<DataType>::clear() //(12) "clears" m_container
{
    DataType dt_null;

    for(size_t i = 0; i < m_top; i++)
    {
        m_container[i] = dt_null;
    }

    m_top = 0;
}

template <class DataType>
void ArrayStack<DataType>::serialize(std::ostream & os) const //(13) to print out values
{
    os << "[";
    for(size_t i = 0; i < m_top; i++)
    {
        os << m_container[i] << " ";
    }
    os << "]";
}

#endif // ARRAYSTACK_H
