/**
 * @brief  CS-202 Project 10 NodeStack header
 * @Author Stone Sha (stones@nevada.unr.edu)
 * @date   November - December, 2018
 *
 * This file is the header file for the class NodeStack
 */
#ifndef NODESTACK_H
#define NODESTACK_H

#include "DataType.h"

template <class DataType> class Node;
template <class DataType> class NodeStack;
template <class DataType> std::ostream & operator<<(std::ostream & os,
                                     const NodeStack<DataType> & nodeStack);

template <class DataType>
class Node
{
    friend class NodeStack<DataType>;

    public:
        Node() : m_next(NULL)

        {
        }
        Node(const DataType & data, Node<DataType> * next = NULL) :
            m_next( next ),
            m_data( data )
        {
        }
        Node(const Node<DataType> & other) :
            m_next(other.m_next),
            m_data(other.m_data)
        {
        }

        DataType & data()   //gets non-const reference, can be used to modify value of underlying data
        {
            //return const_cast<DataType &>(static_cast<const Node &>(*this).getData());  //an alternative implementation, just for studying reference
            return m_data;
        }
        const DataType & data() const   //gets const reference, can be used to access value of underlying data
        {
            return m_data;
        }

    private:
        Node<DataType> *m_next;
        DataType m_data;

};

template <class DataType>
class NodeStack
{
    friend std::ostream & operator<< <DataType>(std::ostream & os, //(i)
                                        const NodeStack<DataType> & nodeStack);


    public:
        NodeStack(); //(1)
        NodeStack(size_t count, const DataType & value); //(2)
        NodeStack(const NodeStack<DataType> & other); //(3)
        ~NodeStack(); //(4)
        NodeStack & operator= (const NodeStack<DataType> & rhs); //(5)
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
        Node<DataType> * m_top;
};

template <class DataType>
std::ostream & operator<<(std::ostream & os, //(i)
                          const NodeStack<DataType> & nodeStack)
{
    nodeStack.serialize(os);

    return os;
}

template <class DataType>
NodeStack<DataType>::NodeStack():m_top(NULL) //(1)
{
    std::cout << "Default Constructor" << std::endl;
}

template <class DataType>
NodeStack<DataType>::NodeStack(size_t count, const DataType & value) //(2)
{
    m_top = new Node<DataType>(value, NULL);

    Node<DataType> *temp = m_top;

    for(size_t i = 0; i < count - 1; i++, temp = temp->m_next)
    {
        temp->m_next = new Node<DataType> (value, NULL);
    }

    temp->m_next = NULL;
}

template <class DataType>
NodeStack<DataType>::NodeStack(const NodeStack<DataType> & other): m_top(other.m_top) //(3)
{
    m_top = new Node<DataType> (other.m_top->data(), NULL);

    Node<DataType> *temp1 = m_top;
    Node<DataType> *temp2 = other.m_top;

    while(temp2->m_next != NULL)
    {
        temp1->m_next = new Node<DataType> (temp2->data(), NULL);
        temp1 = temp1->m_next;
        temp2 = temp2->m_next;
    }

    temp1->m_next = NULL;
}

template <class DataType>
NodeStack<DataType>::~NodeStack() //(4)
{
    clear();
}

template <class DataType>
NodeStack<DataType> & NodeStack<DataType>::operator= (const NodeStack & rhs) //(5)
{
    if(this == &rhs) return *this; //handles self assignment;

    //assignment code
    Node<DataType> *temp1 = m_top;
    Node<DataType> *temp2 = rhs.m_top;

    if(this->size() < rhs.size())
    {
        clear();
        DataType dt_temp(0, 0.0);
        NodeStack<DataType> tempNode(rhs.size(), dt_temp);
        temp1 = tempNode.m_top;
    }

    m_top = new Node<DataType> (rhs.m_top->data(), NULL);

    while(temp2->m_next != NULL)
    {
        temp1->m_next = new Node<DataType> (temp2->data(), NULL);
        temp1 = temp1->m_next;
        temp2 = temp2->m_next;
    }

    temp1->m_next = NULL;
    return *this;
}

template <class DataType>
DataType & NodeStack<DataType>::top() //(6a)
{
    if(empty())
        std::cout << "nodeStack is empty" << std::endl;

    return m_top->m_data;
}

template <class DataType>
const DataType & NodeStack<DataType>::top() const //(6b)
{
    if(empty())
        std::cout << "nodeStack is empty" << std::endl;

    return m_top->m_data;
}

template <class DataType>
void NodeStack<DataType>::push(const DataType & value) //(7)
{
    Node<DataType> *temp = new Node<DataType> (value, NULL);

    if(empty())m_top = temp;

    temp->m_next = m_top;
    m_top = temp;

}

template <class DataType>
void NodeStack<DataType>::pop() //(8)
{
    //Node *temp = m_top;

    if(empty())
    {
        std::cout << "NodeQueue is empty." << std::endl;
        return;
    }

    m_top = m_top->m_next;

}

template <class DataType>
size_t NodeStack<DataType>::size() const //(9)
{
    size_t count = 0;
    Node<DataType> *temp = m_top;

    while(temp)
    {
        temp = temp->m_next;

        count++;
    }

    return count;
}

template <class DataType>
bool NodeStack<DataType>::empty() const //(10)
{
    return m_top == NULL ? true : false;
}

template <class DataType>
bool NodeStack<DataType>::full() const //(11)
{
    return false;
}

template <class DataType>
void NodeStack<DataType>::clear() //(12)
{
    Node<DataType> *temp1 = m_top;
    Node<DataType> *temp2 = m_top;

    while(temp1 != NULL)
    {
        temp1 = temp1->m_next;
        delete temp2;
        temp2 = temp1;
    }

    m_top = NULL;
}

template <class DataType>
void NodeStack<DataType>::serialize(std::ostream & os) const //(13)
{


    os << "[ ";

    for(Node<DataType> *temp = m_top; temp != NULL; temp = temp->m_next)
    {
        os << temp->m_data << " ";
    }

    os << "]" << std::endl;
}


#endif // NODESTACK_H
