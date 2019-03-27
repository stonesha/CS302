#include "ArrayQueue.h"

ArrayQueue::ArrayQueue() // (1)
{
    //ctor
	m_front = 0;
    m_size = 0;
}

//param ctor
ArrayQueue::ArrayQueue(size_t count, const DataType & value)        //(2)
{
    for(size_t i = 0; i < count; i++)
    {
        m_array[i] = value;
    }
    m_front = 0;
    m_back = count;
    m_size = count;
}

//copy ctor
ArrayQueue::ArrayQueue(const ArrayQueue & other):
		m_front(other.m_front), 
		m_back(other.m_back), 
		m_size(other.m_size)
{
	for(size_t i = 0;i < other.m_size;i++)
	{	
		m_array[i] = other.m_array[i];
	}
}

//assignment operator
ArrayQueue& ArrayQueue::operator=(const ArrayQueue& rhs)
{
    if (this == &rhs)
        return *this; // handle self assignment
    //assignment operator
    for(size_t i = 0; i < m_size; i++)
    {
        m_array[i] = rhs.m_array[i];
    }
	m_front = rhs.m_front;
    m_back = rhs.m_back;
    m_size = rhs.m_size;

    return *this;
}

//returns index to first array value
DataType &ArrayQueue::front()                                       //(6a)
{
    return m_array[m_front];
}

//returns index to first array value
const DataType &ArrayQueue::front() const                            //(6b)
{
    return m_array[m_front];
}

//returns index to last array value
DataType &ArrayQueue::back()                                        //(7a)
{
    return m_array[m_back];
}

//returns index to last array value
const DataType &ArrayQueue::back() const                             //(7b)
{
    return m_array[m_back];
}

// inserts at the back
void ArrayQueue::push(const DataType & value) //(8)
{
    //checks if array is full
    if(full())
    {
        std::cout << "Array Full, can't push." << std::endl;
        return;
    }
    //pushes
	m_back = (m_back + 1) % ARRAY_MAX;
	m_size++;

    m_array[m_back] = value;
    

}

//removes at front
void ArrayQueue::pop()                                            //(9)
{

	if(empty()) return;
	
	m_front = (m_front + 1) % ARRAY_MAX;
	--m_size;
    
}

//returns size of array
size_t ArrayQueue::size() const          //(10)
{
    return m_size;
}

//checks if array is empty
bool ArrayQueue::empty() const                                                                 //(11)
{
    if(m_size == 0) return true;

    return false;
}

//checks if array is full
bool ArrayQueue::full() const                                                             //(12)
{
    if(m_size == ARRAY_MAX) return true;

    return false;
}

//"clears" queue
void ArrayQueue::clear()                                            //(13)
{
    DataType temp(0, 0.0);

    for(size_t i = 0;i < m_back;i++)
    {
        m_array[i] = temp;
    }

}

void ArrayQueue::serialize(std::ostream & os) const                               //(14)
{
	os << "{ ";
    for(size_t i = 0;i < m_size;i++)
    {
        os << m_array[i] << " ";
    }
	os << "} ";
}
