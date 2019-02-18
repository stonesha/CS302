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
        int top;
        DataType* dataItems;
};

template <typename DataType>
StackArray<DataType>::StackArray(int maxNumber): top(-1)
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
    if (this == &other) return *this; //self assignment check

    maxSize = other.maxSize;
    top = other.top;
    for(int i = 0;i < maxSize; i++)
    {
        dataItems[i] = other.dataItems[i];
    }

    return *this;
}

template <typename DataType>
StackArray<DataType>::~StackArray()
{
    clear();
}

template <typename DataType>
void StackArray<DataType>::push(const DataType& newDataItem) throw (logic_error)
{
    if(isFull())
    {
        cout << "Error: StackArray is full." << endl;
    } else
    {
        dataItems[++top] = newDataItem;
        cout << "Success: Data item successfully pushed." << endl;
    }
}

template <typename DataType>
DataType StackArray<DataType>::pop() throw (logic_error)
{
    if(isEmpty())
    {
        cout << "Error: StackArray is empty." << endl;
    }

    DataType popData = dataItems[top--];
    return popData;

}

template <typename DataType>
void StackArray<DataType>::clear()
{
    delete[] dataItems;
    dataItems = NULL;
}

template <typename DataType>
bool StackArray<DataType>::isEmpty() const
{
    if(top == -1) return true;

    return false;
}

template <typename DataType>
bool StackArray<DataType>::isFull() const
{
    if(top == maxSize - 1) return true;

    return false;
}

template <typename DataType>
void StackArray<DataType>::showStructure() const
{
    if( isEmpty() ) {
	cout << "Empty stack." << endl;
    }
    else {
	int j;
	cout << "Top = " << top << endl;
	for ( j = 0 ; j < maxSize ; j++ )
	    cout << j << "\t";
	cout << endl;
	for ( j = 0 ; j <= top  ; j++ )
	{
	    if( j == top )
	    {
	        cout << '[' << dataItems[j] << ']'<< "\t"; // Identify top
	    }
	    else
	    {
		cout << dataItems[j] << "\t";
	    }
	}
	cout << endl;
    }
    cout << endl;
}


#endif		//#ifndef STACKARRAY_H
