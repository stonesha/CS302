//--------------------------------------------------------------------
//
//  StackArray.h
//
//  Class declaration for the array implementation of the Stack ADT
//
//--------------------------------------------------------------------

#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <stdexcept>
#include <iostream>

using namespace std;

#include "Stack.h"

template <typename DataType>
class StackArray : public Stack<DataType>
{
public:
    StackArray(int maxNumber = Stack<DataType>::MAX_STACK_SIZE);
    StackArray(const StackArray& other);
    StackArray& operator=(const StackArray& other);
    ~StackArray();

    void push(const DataType& newDataItem) throw (logic_error);
    DataType pop() throw (logic_error);

    void clear();

    bool isEmpty() const;
    bool isFull() const;

    void showStructure() const;

private:
    int maxSize;
    int top = 0;
    DataType* dataItems;
};

template <typename DataType>
StackArray<DataType>::StackArray(int maxNumber)
{
    maxSize = maxNumber;
    dataItems = new (nothrow) DataType[maxSize];

    if(dataItems == NULL) cout << "Error: Couldn't allocate memory." << endl;

}

template <typename DataType>
StackArray<DataType>::StackArray(const StackArray& other)
{
    maxSize = other.maxSize;
    top = other.top;
    for(int i = 0;i < maxSize; i++)
    {
        dataItems[i] = other.dataItems[i];
    }
}

template <typename DataType>
StackArray<DataType>& StackArray<DataType>::operator=(const StackArray& other)
{

}

template <typename DataType>
StackArray<DataType>::~StackArray()
{
    delete[] dataItems;
    dataItems = NULL;
}

template <typename DataType>
void StackArray<DataType>::push(const DataType& newDataItem) throw (logic_error)
{

}

template <typename DataType>
DataType StackArray<DataType>::pop() throw (logic_error)
{

}

template <typename DataType>
void StackArray<DataType>::clear()
{

}

template <typename DataType>
bool StackArray<DataType>::isEmpty() const
{

}

template <typename DataType>
bool StackArray<DataType>::isFull() const
{

}

template <typename DataType>
void StackArray<DataType>::showStructure() const
{

}


#endif		//#ifndef STACKARRAY_H
