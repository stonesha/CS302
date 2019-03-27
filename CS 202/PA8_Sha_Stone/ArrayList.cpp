/**
 * @brief  CS-202 Project 8 Array List source
 * @Author Stone Sha (stones@nevada.unr.edu)
 * @date   November, 2018
 *
 * This file is the source file for ArrayList
 */
#include "ArrayList.h"

ArrayList::ArrayList(): m_array(NULL),
    m_size(0),
    m_maxsize(0)//(1)
{
    std::cout << "ArrayList Default c-tor" << std::endl;
}

//param
ArrayList::ArrayList(size_t count, const DataType & value):
    m_size(count),
    m_maxsize(count)//(2)
{
    m_array = new DataType[count];

    //setting values
    for(size_t i = 0; i < m_maxsize; i++)
    {
        m_array[i] = value;
    }

    std::cout << "ArrayList Parameterized c-tor" << std::endl;
}

//copy
ArrayList::ArrayList(const ArrayList & other)			    	//(3)
{
    m_size = other.m_size;
    m_maxsize = other.m_maxsize;

    m_array = new DataType[m_maxsize];

    //copying values over
    for(size_t i = 0; i < m_maxsize; i++)
    {
        m_array[i] = other.m_array[i];
    }

    std::cout << "ArrayList Copy c-tor" << std::endl;
}

//dtor
ArrayList::~ArrayList()						    			//(4)
{
    //checking
    if(m_array != NULL)
    {
        delete[] m_array;
        m_array = NULL;
    }

    std::cout << "ArrayList Destructor" << std::endl;
}

//assignment
ArrayList & ArrayList::operator= (const ArrayList & rhs)			//(5)
{
    if (this == &rhs) return *this; // handle self assignment

    //assignment
    m_size = rhs.m_size;
    m_maxsize = rhs.m_maxsize;
    m_array = new DataType[m_maxsize];

    for(size_t i = 0; i < m_maxsize; i++)
    {
        m_array[i] = rhs.m_array[i];
    }

    return *this;
}

//output
std::ostream & operator<<(std::ostream & os, const ArrayList & arrayList)//(i)
{
    os << "{";
    for(size_t i = 0; i < arrayList.m_size; i++)
    {
        os << arrayList.m_array[i++] << ", ";
    }

    os << "}" << std::endl;

    return os;
}

//front
DataType * ArrayList::front()							     		//(6)
{
    DataType *ptr = m_array;

    if(ptr != NULL)
    {
        return ptr;
    }
    return NULL;
}

//back
DataType * ArrayList::back()						                //(7)
{
    DataType *ptr = m_array;

    if(ptr != NULL && m_size > 0)
    {
        for(size_t i = 0; i < m_size - 1; i++, ptr++){}
        return ptr;
    }
    return NULL;
}

//find
DataType * ArrayList::find(const DataType & target, DataType * & previous, const DataType * start /*= NULL*/)//(8)
{
    DataType *ptr = m_array;

    if(ptr == NULL)
    {
        previous = NULL;
        return NULL;

    }else if(ptr != NULL)
    {
        for(size_t i = 0;i < m_size;i++)
        {
            if(*ptr == target)
            {
                ptr--;
                if(ptr != NULL)
                {
                    previous = ptr;
                }else
                {
                    previous = NULL;
                }
                ptr++;
                return ptr;
            }
            ptr++;
        }
    }
    return NULL;
}

//inserts element after target
DataType * ArrayList::insertAfter(const DataType & target, const DataType & value)    	//(9)
{
    if(m_size == m_maxsize) resize(m_maxsize++);

    int index = 0;
    DataType *temp;

    for(size_t i = 0;i < m_maxsize;i++)
    {
        if(m_array[i] == target)
        {
            index = i + 1;
            temp = &m_array[index];
        }
    }

    DataType *m_temp = new DataType[m_maxsize];
    for(int i = 0; i < index;i++)
    {
        m_temp[i] = m_array[i];
    }

    m_array[index] = value;

    for(size_t i = index; i < m_maxsize - 1;i++)
    {
        m_array[i] = m_temp[i];
    }

    delete []m_temp;
    m_temp = NULL;

    if(m_array[index] == target)
    {
        return temp;
    }
    return NULL;
}

//inserts element before target
DataType * ArrayList::insertBefore(const DataType & target, const DataType & value)  		//(10)
{
    if(m_size == m_maxsize) resize(m_maxsize++);

    int index = 0;
    DataType *temp;

    for(size_t i = 0;i < m_maxsize;i++)
    {
        if(m_array[i] == target)
        {
            index = i;
            temp = &m_array[index];
        }
    }

    DataType *m_temp = new DataType[m_maxsize];
    for(int i = 0; i < index;i++)
    {
        m_temp[i] = m_array[i];
    }

    m_array[index] = value;

    for(size_t i = index; i < m_maxsize - 1;i++)
    {
        m_array[i+1] = m_temp[i];
    }

    if(m_array[index] == target)
    {
        return temp;
    }
    return NULL;
}

//erases target and returns pointer to after target
DataType * ArrayList::erase(const DataType & target)		 		//(11)
{
    DataType *ptr = m_array;

    while(ptr != NULL)
    {
        if(*ptr == target)
        {
            ptr = NULL;
            ptr++;
            return ptr;
        }
        ptr++;
    }

    return NULL;
}

//index
DataType & ArrayList::operator[] (size_t position)				//(12)
{
    return m_array[position];
}

size_t ArrayList::size() const									//(13)
{
    return m_size;
}

//checks if m_array is empty
bool ArrayList::empty() const									//(14)
{
    if(m_array != NULL && m_size != 0)
    {
        return false;
    }
    return true;
}

//clears m_array
void ArrayList::clear()									//(15)
{
    if(m_array != NULL)
    {
        delete [] m_array;
        m_array = NULL;
    }
    m_size = 0;
    m_maxsize = 0;
}

//for the purpose of reallocating and expanding
void ArrayList::resize(size_t count)
{
    DataType *temp = new DataType[m_size];
    //storing values temporarily
    for(size_t i = 0;i < m_size;i++)
    {
        temp[i] = m_array[i];
    }
    //freeing up and reallocating memory
    delete [] m_array;
    m_maxsize += count;
    m_array = new DataType[m_maxsize];
    //recopying values back into m_array
    for(size_t i = 0;i < m_size;i++)
    {
        m_array[i] = temp[i];
    }
}
