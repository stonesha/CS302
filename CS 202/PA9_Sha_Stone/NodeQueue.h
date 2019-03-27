#ifndef NODEQUEUE_H
#define NODEQUEUE_H

#include <iostream>
#include "DataType.h"

class Node{

  friend class NodeQueue;  //allows direct accessing of link and data from class NodeQueue
	

  public:
    Node() :
	  m_next( NULL )
	{
	}
	Node(const DataType & data, Node * next = NULL) :
	  m_next( next ),
	  m_data( data )
	{
	}
	Node(const Node & other) :
	  m_next( other.m_next ),
	  m_data( other.m_data )
	{
	}

    DataType & data(){  //gets non-const reference, can be used to modify value of underlying data
      //return const_cast<DataType &>(static_cast<const Node &>(*this).getData());  //an alternative implementation, just for studying reference
	  return m_data;
    }
    const DataType & data() const{  //gets const reference, can be used to access value of underlying data
      return m_data;
    }

  private:
    Node * m_next;
    DataType m_data;
};


class NodeQueue
{
    friend std::ostream &operator<<(std::ostream & os,          //(i)
                                    const NodeQueue & nodeQueue);
    public:
        NodeQueue(); //(1)
        NodeQueue(size_t size, const DataType & value);              //(2)
        NodeQueue(const NodeQueue & other);                      //(3)
        ~NodeQueue();                                                            //(4)

        NodeQueue& operator= (const NodeQueue & rhs);      //(5)
	DataType & operator[] (size_t position);
	DataType & operator[] (size_t position) const;

        DataType &front();                                       //(6a)
        const DataType &front() const;                            //(6b)
        DataType &back();                                        //(7a)
        const DataType &back() const;                             //(7b)

        void push(const DataType & value); //(8)
        void pop();                                                //(9)
        size_t size() const;           //(10)
        bool empty() const;             //(11)
        bool full() const;             //(12)
        void clear();                                                //(13)

        void serialize(std::ostream & os) const;                               //(14)
    private:
        Node * m_front;
        Node * m_back;
};

#endif // NODEQUEUE_H
