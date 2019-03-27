#include "NodeQueue.h"

NodeQueue::NodeQueue(): m_front(NULL), m_back(NULL)
{
    //ctor
}

//parameterized ctor
NodeQueue::NodeQueue(size_t size, const DataType & value)
{
	m_front = new Node(value, NULL);
	Node *temp = m_front;

	for(size_t i = 0;i < size - 1;i++, temp = temp->m_next)
	{
		temp->m_next = new Node(value, NULL);
	}
	m_back = new Node(value, NULL);
	m_back->m_next = NULL;
}

NodeQueue::NodeQueue(const NodeQueue& other)
{
    //copy ctor
	if(empty())
	{
		m_front = new Node (other.m_front->data(), NULL);
		Node *temp1 = m_front;
		Node *temp2 = other.m_front;

		while(temp2->m_next != NULL)
		{
			temp1->m_next = new Node(temp2->data(), NULL);
			temp1 = temp1->m_next;
			temp2 = temp2->m_next;
		}
	}
	m_back = new Node(other.m_back->data(), NULL);
	m_back->m_next = NULL;
}

NodeQueue::~NodeQueue()
{
    //dtor
	clear();
	
}

//assignment operator
NodeQueue& NodeQueue::operator=(const NodeQueue& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator

	Node *temp1 = m_front;
	Node *temp2 = rhs.m_front;

	
    if(this->size() < rhs.size())
    {
        clear();
        DataType tempDat(0, 0.0);
        NodeQueue tempNode(rhs.size(), tempDat);
        temp1 = tempNode.m_front;
    }

    m_front = new Node (rhs.m_front->data(), NULL);

	while(temp2->m_next != NULL)
	{
		temp1->m_next = new Node(temp2->data(), NULL);
		temp1 = temp1->m_next;
		temp2 = temp2->m_next;
	}

	m_back = new Node(rhs.m_back->data(), NULL);
	m_back->m_next = NULL;
    return *this;
}

//index operator
DataType & NodeQueue::operator[] (size_t position)
{
	Node *temp = m_front;
	
	for(size_t i = 0;i < position; i++)
	{
		temp = temp->m_next;
	}
	
	return temp->data();

}

DataType & NodeQueue::operator[] (size_t position) const
{
	Node *temp = m_front;
	
	for(size_t i = 0;i < position; i++)
	{
		temp = temp->m_next;
	}
	
	return temp->data();
}

//ostream operator
std::ostream &operator<<(std::ostream & os, const NodeQueue & nodeQueue) //(i)
{
	
	os << "{ ";	

	for(size_t i = 0;i < nodeQueue.size();i++)
	{
		os << nodeQueue[i] << " ";
	}

	os << "} ";

	return os;
}

//returns data of front of NodeQueue
DataType &NodeQueue::front()                                       //(6a)
{
	return m_front->data();
}

const DataType &NodeQueue::front() const                            //(6b)
{
	return m_front->data();
}

//returns data of back of NodeQueue
DataType &NodeQueue::back()                                        //(7a)
{
	return m_back->data();
}

const DataType &NodeQueue::back() const                             //(7b)
{
	return m_back->data();
}

//inserts at back of the Queue
void NodeQueue::push(const DataType & value) //(8)
{

	if(empty())
	{
		Node *temp = new Node;
		temp->m_next = NULL;
		temp->data() = value;

		m_front = m_back = temp;
		
	} else
	{
		Node *temp = new Node;
		temp->m_next = NULL;
		temp->m_data = value;

		m_back->m_next = temp;
		m_back = temp;

	}
}

//deletes first element of Queue
void NodeQueue::pop()                                                //(9)
{
	Node *temp = m_front;

	if(!empty())
	{
		delete temp;
		m_front = m_front->m_next;
	} else
	{
		std::cout << "NodeQueue is empty." << std::endl;
	}
}

//returns size of NodeQueue
size_t NodeQueue::size() const           //(10)
{
	size_t count = 0;
	Node *temp = m_front;

	while(temp != NULL)
	{
		count++;
		temp = temp->m_next;
	}
	
	return count;
}

//checks if NodeQueue is empty
bool NodeQueue::empty() const          //(11)
{
	if(m_front == NULL) return true;
	
	return false;
}

//checks if NodeQueue is full
bool NodeQueue::full() const             //(12)
{
	if(m_front != NULL && m_back != NULL) return true;
	
	return false;
}

//checks if NodeQueue is clear
void NodeQueue::clear()                                                //(13)
{
	Node *temp1 = m_front;
	Node *temp2 = m_front;

	while(temp1 != NULL)
	{
		temp1 = temp1->m_next;
		delete temp2;
		temp2 = temp1;
	}
	
	m_front = NULL;
	m_back = NULL;
}

//outputs NodeQueue in order
void NodeQueue::serialize(std::ostream & os) const                               //(14)
{
	Node *temp = m_front;

	os << "{ ";	

	for(size_t i = 0;i < size();i++, temp = temp->m_next)
	{
		os << temp->data() << " ";
	}

	os << "} ";

}
