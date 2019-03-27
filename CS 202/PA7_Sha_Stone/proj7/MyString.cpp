/**
 * @brief  CS-202 Project 7 MyString class source
 * @Author Stone Sha (stones@nevada.unr.edu)
 * @date   October, 2018
 *
 * This file is the source file for MyString.h
 */

#include "MyString.h"

//PUBLIC
//CONSTRUCTORS/DECONSTRUCTORS
//default ctor
MyString::MyString()
{
    m_size = MAX_STRING_SIZE;
    buffer_allocate(m_size);

    cout << "Default Constructor" << endl;
}			            //(1)
//parameterized ctor
MyString::MyString(const char * str)
{
    m_size = strlen(str) + 1;
    buffer_allocate(m_size);
    strcpy(m_buffer, str);
    cout << "Parameterized Constructor" << endl;
}					   //(2)
//copy ctor
MyString::MyString(const MyString & other_myStr)
{
    m_size = other_myStr.size();
    buffer_allocate(m_size);
    strcpy(m_buffer, other_myStr.m_buffer);
    cout << "Copy Constructor" << endl;
}			   //(3)
//dtor
MyString::~MyString()
{
    buffer_deallocate();
    cout << "Destructor" << endl;

}						   //(4)

//METHODS
//returns m_size
size_t MyString::size() const
{
    return m_size;
}				           //(5)

//returns length of m_buffer
size_t MyString::length() const
{
    return strlen(m_buffer);
}					   //(6)

//returns char pointer to m_buffer
const char * MyString::c_str() const
{
    char const *charPtr = m_buffer;

    return charPtr;
}					   //(7)

//OPERATOR OVERLOADS
//checks for equivelancy
bool MyString::operator== (const MyString & other_myStr) const
{
    int test = strcmp(this->m_buffer, other_myStr.m_buffer);

    if(test == 0)
    {
        return true;
    }
    return false;
}           //(8)

//assigns values of one object to another
MyString & MyString::operator= (const MyString & other_myStr)
{
    this->m_size = other_myStr.m_size;
    this->buffer_allocate(this->m_size);
    strcpy(this->m_buffer, other_myStr.m_buffer);

    return *this;
}	           //(9)

//concatenates two strings together
MyString MyString::operator+ (const MyString & other_myStr) const
{
    /*
    int len1 = strlen(m_buffer);
    int len2 = strlen(other_myStr.m_buffer);
    int finallen = len1 + len2;

    char temp[finallen];

    strcpy(temp, strcat(m_buffer, other_myStr.m_buffer));
*/
    MyString rhs(strcat(this->m_buffer, other_myStr.m_buffer));

    return rhs;
}           //(10)

//index operator
char & MyString::operator[] (size_t index)
{
    return m_buffer[index];
}				   //(11a)

//index operator
const char & MyString::operator[] (size_t index) const
{
    return m_buffer[index];
}			   //(11b)

//ostream operator, outputs string
std::ostream & operator<<(std::ostream & os, const MyString & myStr)
{
    cout << myStr.m_buffer ;

    return os;
}   //(12)

//PRIVATE -------------------------
//deallocates memory
void MyString::buffer_deallocate()
{
    m_buffer= NULL;
    delete [] m_buffer;

}					    //(13)

//allocates memory
void MyString::buffer_allocate(size_t size)
{
    m_buffer = NULL;

    m_buffer = new char[size];

    //checks for allocation failure and success
    if(m_buffer)
    {
        for(size_t i = 0;i < size;i++)
        {
            m_buffer[i] = NULL;
        }

        //cout << "Memory allocation successful." << endl;

    }else if(!m_buffer)
    {
        buffer_deallocate();
        //cout << "Memory allocation unsuccessful." << endl;
    }

}

