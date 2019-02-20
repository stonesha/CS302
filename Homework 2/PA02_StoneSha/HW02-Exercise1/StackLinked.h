/**
 * @brief  CS-302 Homework 1
 * @Author Stone Sha (stones@nevada.unr.edu)
 * @date   February 2019
 *
 * This file is the header file for stack linked list
 */
//--------------------------------------------------------------------
//
//  StackLinked.h
//
//  Class declaration for the linked implementation of the Stack ADT
//
//--------------------------------------------------------------------

#ifndef STACKLINKED_H
#define STACKLINKED_H

#include "Stack.h"

template <typename DataType>
class StackLinked : public Stack<DataType>
{

public:

    //constructor doesn't need a separate definition, only sets top to NULL because empty
    StackLinked(int maxNumber = Stack<DataType>::MAX_STACK_SIZE): top(NULL){}
    StackLinked(const StackLinked& other);
    StackLinked& operator=(const StackLinked& other);
    ~StackLinked();

    void push(const DataType& newDataItem) throw (logic_error);
    DataType pop() throw (logic_error);

    void clear();

    bool isEmpty() const;
    bool isFull() const {return false;}

    void showStructure() const;

private:

    class StackNode
    {
    public:
        StackNode (StackNode *nextPtr) : next(nextPtr) {}
        StackNode(const DataType& nodeData, StackNode* nextPtr): dataItem(nodeData), next(nextPtr){}

        DataType dataItem;
        StackNode* next;
    };

    StackNode* top;
};

//copy constructor
template <typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other)
{
    //pointers to each top element of the stacks used
    StackNode *curr = top;
    StackNode *otherCurr = other.top;

    //while loop until ending of other stack
    while(otherCurr != NULL)
    {
        //allocates elements for current stack
        curr = new StackNode(otherCurr->dataItem, otherCurr->next);

        //iterates over stack
        curr = curr->next;
        otherCurr = otherCurr->next;
    }
}

//= operator overload, basically same as the copy constructor with some checks
template <typename DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked& other)
{
    if(this == &other) return *this;//checks for self assignment

    //clears stack to be ready to be written over
    clear();

    StackNode *curr = top;
    StackNode *otherCurr = other.top;

    while(otherCurr != NULL)
    {
        curr = new StackNode(otherCurr->dataItem, otherCurr->next);

        curr = curr->next;
        otherCurr = otherCurr->next;
    }

    return *this;
}

//destructor only clears
template <typename DataType>
StackLinked<DataType>::~StackLinked()
{
    clear();
}

//pushes element, doesn't need to throw because stack will never be full
template <typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error)
{
    top = new StackNode(newDataItem, top);
}

//pops element, throws error if empty
template <typename DataType>
DataType StackLinked<DataType>::pop() throw (logic_error)
{
    if(isEmpty()) {throw logic_error("Empty, can't pop");}

    DataType topdata = top->dataItem;

    top = top->next;

    return topdata;
}

//iterates over stacks and deletes
template <typename DataType>
void StackLinked<DataType>::clear()
{
    StackNode *curr = top;
    StackNode *temp;

    while(curr != NULL)
    {
        temp = curr->next;
        delete[] curr;
        curr = temp;
    }

    top = NULL;
}

//checks if empty
template <typename DataType>
bool StackLinked<DataType>::isEmpty() const
{
    if(top == NULL) return true;

    return false;
}

//shows the stack
template <typename DataType>
void StackLinked<DataType>::showStructure() const
{
    if( isEmpty() )
    {
	cout << "Empty stack" << endl;
    }
    else
    {
        cout << "Top\t";
	for (StackNode* temp = top; temp != 0; temp = temp->next) {
	    if( temp == top ) {
		cout << "[" << temp->dataItem << "]\t";
	    }
	    else {
		cout << temp->dataItem << "\t";
	    }
	}
        cout << "Bottom" << endl;
    }
}
#endif		//#ifndef STACKLINKED_H

