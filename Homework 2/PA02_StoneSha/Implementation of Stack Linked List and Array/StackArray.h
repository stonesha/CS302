/**
 * @brief  CS-302 Homework 1
 * @Author Stone Sha (stones@nevada.unr.edu)
 * @date   February 2019
 *
 * This file is the header file for stack array
 */
//--------------------------------------------------------------------
//
//  StackArray.h
//
//  Class declaration for the array implementation of the Stack ADT
//
//--------------------------------------------------------------------

#ifndef STACKARRAY_H
#define STACKARRAY_H

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

//sets top to -1 to indicate emptiness since arrays use 0 as the 1st element
template <typename DataType>
StackArray<DataType>::StackArray(int maxNumber): top(-1)
{
    maxSize = maxNumber;
    //doesn't throw an error and instead sets to NULL if unable to allocate
    dataItems = new (nothrow) DataType[maxSize];

    //basically checks the above^
    if(dataItems == NULL) cout << "Error: Couldn't allocate memory." << endl;

}

//copy constructor
template <typename DataType>
StackArray<DataType>::StackArray(const StackArray& other)
{
    //sets elements to stack being copied
    maxSize = other.maxSize;
    top = other.top;
    for(int i = 0;i < maxSize; i++)
    {
        //iterates and copies every element
        dataItems[i] = other.dataItems[i];
    }
}

//same as copy constructor just with check for self assignment
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

//destructor calls clear() method
template <typename DataType>
StackArray<DataType>::~StackArray()
{
    clear();
}

//pushes element, checks if full and if does throws a logical error
template <typename DataType>
void StackArray<DataType>::push(const DataType& newDataItem) throw (logic_error)
{
    if(isFull()){throw logic_error("Full. Can't push");}

    //increments the top element index and sets it equal to the dataitem
    dataItems[++top] = newDataItem;
    cout << "Success: Data item successfully pushed." << endl;

}

//pops, checks if empty otherwise throws logical error
template <typename DataType>
DataType StackArray<DataType>::pop() throw (logic_error)
{
    if(isEmpty()){throw logic_error ("Empty, can't pop");}

    //opposite of push since it decrements top index
    DataType popData = dataItems[top--];

    //returns the popdata
    return popData;

}

//since its 1d it only needs the delete[] and no iteration
template <typename DataType>
void StackArray<DataType>::clear()
{
    delete[] dataItems;
    dataItems = NULL;
}

//nothing to explain here
template <typename DataType>
bool StackArray<DataType>::isEmpty() const
{
    if(top == -1) return true;

    return false;
}

//here either
template <typename DataType>
bool StackArray<DataType>::isFull() const
{
    if(top == maxSize - 1) return true;

    return false;
}

//shows/prints the stack
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
