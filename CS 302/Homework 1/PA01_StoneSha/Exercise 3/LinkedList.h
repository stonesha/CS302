/**
 * @brief  CS-302 Homework 1
 * @Author Stone Sha (stones@nevada.unr.edu)
 * @date   February 2019
 *
 * This file is the header file for linkedlist
 */
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

//cstddeff for NULL, iostream for outputting and inputting values
#include <cstddef>
#include <iostream>

//template definitions
template <class T> class Node;
template <class T> class LinkedList;
template <class T> std::ostream & operator<<(std::ostream & os,
                                     const LinkedList<T> & list);

//Node class. templated
template <class T>
class Node
{
    //allows for linkedlist to use nodes
    friend class LinkedList<T>;

    public:
        //constructor
        Node() : m_next(NULL)

        {
        }

        //parameterized constructor
        Node(const T & data, Node<T> * next = NULL) :
            m_next( next ),
            m_data( data )
        {
        }

        //copy constructor
        Node(const Node<T> & other) :
            m_next(other.m_next),
            m_data(other.m_data)
        {
        }

        //returns non const to allow for modification
        T & data()
        {
            return m_data;
        }
        //returns const for non modification
        const T & data() const
        {
            return m_data;
        }

    private:
        //next Node pointer
        Node<T> *m_next;
        //value held in Node
        T m_data;

};

//Linked List class
template <class T>
class LinkedList
{
    //friend function for outputting values
    friend std::ostream & operator<< <T>(std::ostream & os,
                                     const LinkedList<T> & list);
    public:
        //default constructor
        LinkedList();
        //destructor
        virtual ~LinkedList();

        //adds an item
        void push(const T & value);

        //deletes an item
        void pop();

        //shows the number of items
        int size() const;

        //show all items
        void serialize(std::ostream & os) const;

        //helper methods
        //checks if empty
        bool empty() const;

    private:
        //head and tail pointer, head pointing to first
        //element and tail pointing to last
        Node<T> *pfirst, *plast;
};

//method implementations - - - - - - - - -

//sets pfirst and plast to null indicating empty
template <class T>
LinkedList<T>::LinkedList() : pfirst(NULL), plast(NULL)
{
    //ctor
}

//clears and deletes all data/nodes in queue
template <class T>
LinkedList<T>::~LinkedList()
{
    //dtor

    //temp1 to traverse queue and temp2 is
    //used as a placeholder to delete the nodes
    Node<T> *temp1 = pfirst;
	Node<T> *temp2 = pfirst;

	while(temp1 != NULL)
	{
		temp1 = temp1->m_next;
		delete temp2;
		temp2 = temp1;
	}

	pfirst = NULL;
	plast = NULL;

}


template <class T>
//adds an item
void LinkedList<T>::push(const T & value)
{

    //for traversing queue
    Node<T> *curptr;
    //safety
    curptr = NULL;

    //if else statement determining emptiness
    if(empty())
	{
	    //parameterizing a new node with value needed for input
	    curptr = new Node<T>(value, NULL);

	    //since queue is empty, first and last pointer
	    //are the exact same
		pfirst = curptr;
		plast = curptr;

	} else
	{
	    //parameterizing a new node with value needed for input
	    curptr = new Node<T>(value, NULL);

	    //setting the cursor to replicate plast and holds the value
		curptr->m_next = NULL;
		//redundant, but safety purposes
		curptr->m_data = value;

		//tail pointer is set to cursor pointer
		plast->m_next = curptr;
		plast = curptr;

	}
}

template <class T>
//deletes an item
void LinkedList<T>::pop()
{
    //if else for emptiness
    if(empty())
    {
        //if empty just output the statement
        std::cout << "Linked List is empty." << std::endl;

    } else
    {
        //not exactly "deleting" and more ignoring the first node
        Node<T> *curptr = pfirst->m_next;

        pfirst = curptr;


    }
}

template <class T>
//shows the number of items
int LinkedList<T>::size() const
{
    //for the number size
    int sizenum = 0;
    //cursor pointer
    Node<T> *curptr = pfirst;

    //if empty just returns 0
    if(empty()) return sizenum;

    //while the cursor pointer hasn't reached the end
    while(curptr != NULL)
    {
        //increment the number indicating size
        sizenum++;
        //curptr is set to next node
        curptr = curptr->m_next;
    }

    return sizenum;
}

template <class T>
//helper method to show all items
void LinkedList<T>::serialize(std::ostream & os) const
{
    //cursor pointer at beginning
    Node<T> *curptr = pfirst;

    //formatting purposes
	os << "{ ";

	//traverse through node using curptr and output the data
	while(curptr != NULL){
		os << curptr->data() << " ";
        curptr = curptr->m_next;
	}

	 //formatting purposes
	os << "} ";
}

template <class T>
//checks if empty, not much to explain here, if you actually read these
//send an email to stones@nevada.unr.edu or give me a high five when you see me
bool LinkedList<T>::empty() const
{
    if(pfirst == NULL) return true;

    return false;
}

template <class T>
//ostream operator to output values within link list
std::ostream & operator<<(std::ostream & os, const LinkedList<T> & list)
{
    list.serialize(os);

    return os;
}


#endif // LINKEDLIST_H
