//--------------------------------------------------------------------
//
//  StackLinked.h
//
//  Class declaration for the linked implementation of the Stack ADT
//
//--------------------------------------------------------------------

#ifndef STACKARRAY_H
#define STACKARRAY_H

#include "Stack.h"

template <typename DataType>
class StackLinked : public Stack<DataType>
{

public:

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

template <typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other)
{
    StackNode *curr = top;
    StackNode *otherCurr = other.top;

    while(otherCurr != NULL)
    {
        curr = new StackNode(otherCurr->dataItem, otherCurr->next);

        curr = curr->next;
        otherCurr = otherCurr->next;
    }
}

template <typename DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked& other)
{
    if(this == &other) return *this;

    clear();
    top = other.top;

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

template <typename DataType>
StackLinked<DataType>::~StackLinked()
{
    clear();
}

template <typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error)
{
    top = new StackNode(newDataItem, top);
}

template <typename DataType>
DataType StackLinked<DataType>::pop() throw (logic_error)
{
    if(isEmpty()) {throw logic_error("Empty, can't pop");}

    StackNode *curr = top->next;

    top = curr;

    return top->dataItem;
}

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

template <typename DataType>
bool StackLinked<DataType>::isEmpty() const
{
    if(top == NULL) return true;

    return false;
}

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
#endif		//#ifndef STACKARRAY_H

