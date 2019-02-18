//--------------------------------------------------------------------
//
//  StackLinked.h
//
//  Class declaration for the linked implementation of the Stack ADT
//
//--------------------------------------------------------------------

#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <stdexcept>
#include <iostream>

using namespace std;

#include "Stack.h"

template <typename DataType>
class StackLinked : public Stack<DataType>
{

public:

    StackLinked(int maxNumber = Stack<DataType>::MAX_STACK_SIZE);
    StackLinked(const StackLinked& other);
    StackLinked& operator=(const StackLinked& other);
    ~StackLinked();

    void push(const DataType& newDataItem) throw (logic_error);
    DataType pop() throw (logic_error);

    void clear();

    bool isEmpty() const;
    bool isFull() const;

    void showStructure() const;

private:

    class StackNode
    {
    public:
        StackNode(const DataType& nodeData, StackNode* nextPtr);

        DataType dataItem;
        StackNode* next;
    };

    StackNode* top;
};

template <typename DataType>
StackLinked<DataType>::StackLinked(int maxNumber)
{

}

template <typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other)
{

}

template <typename DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked& other)
{

}

template <typename DataType>
StackLinked<DataType>::~StackLinked()
{

}

template <typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error)
{

}

template <typename DataType>
DataType StackLinked<DataType>::pop() throw (logic_error)
{

}

template <typename DataType>
void StackLinked<DataType>::clear()
{

}

template <typename DataType>
bool StackLinked<DataType>::isEmpty() const
{

}

template <typename DataType>
bool StackLinked<DataType>::isFull() const
{

}

template <typename DataType>
void StackLinked<DataType>::showStructure() const
{

}
#endif		//#ifndef STACKARRAY_H

