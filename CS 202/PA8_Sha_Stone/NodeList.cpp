/**
 * @brief  CS-202 Project 8 NodeList source
 * @Author Stone Sha (stones@nevada.unr.edu)
 * @date   November, 2018
 *
 * This file is the source file for the class NodeList
 */
#include "NodeList.h"

//default
NodeList::NodeList():m_head(NULL)
{
    std::cout << "NodeList Default c-tor" << std::endl;
}							    		  //(1)

//param
NodeList::NodeList(size_t count, const DataType & value)		  //(2)
{
    m_head = new Node(value, NULL);
    Node *temp = m_head;

    //one less loop to save last for NULL
    for(size_t i = 0;i < count - 1;i++)
    {
        temp->m_next = new Node(value, NULL);
        temp=temp->m_next;
    }
    temp->m_next = NULL;

    std::cout << "NodeList Parameterized c-tor" << std::endl;
}

//copy
NodeList::NodeList(const NodeList & other)					  //(3)
{
    if(other.m_head != NULL)
    {
        m_head = new Node(other.m_head->data(), NULL);

        Node *temp1 = m_head;
        Node *temp2 = other.m_head;

        while(temp2->m_next != NULL)
        {
            temp2 = temp2->m_next;
            temp1->m_next = new Node (temp2->data(), NULL);
            temp1 = temp1->m_next;
        }
        temp1->m_next = NULL;
    }
    std::cout << "NodeList Copy c-tor" << std::endl;
}

//dtor
NodeList::~NodeList()							   			  //(4)
{
    clear();

    std::cout << "NodeList Destructor" << std::endl;
}

//assignment
NodeList & NodeList::operator= (const NodeList & rhs)		  //(5)
{
    if (this == &rhs) return *this; //handles self assignment

    Node *temp1 = m_head;
    Node *temp2 = rhs.m_head;

    if(this->size() < rhs.size())
    {
        clear();
        DataType tempDat(0, 0.0);
        NodeList tempNode(rhs.size(), tempDat);
        temp1 = tempNode.m_head;
    }

    while(temp2->m_next != NULL)
    {
        temp1->m_data = temp2->data();
        temp1 = temp1->m_next;
        temp2 = temp2->m_next;
    }

    return *this;
}

//front
Node * NodeList::front()						    		  //(6)
{
    if(m_head != NULL)
    {
        return m_head;
    }
    return NULL;
}

//back
Node * NodeList::back()										  //(7)
{
    Node *temp = m_head;

    while(temp->m_next != NULL)
    {
        temp = temp->m_next;
    }
    return temp;
}

//finds target
Node * NodeList::find(const DataType & target, Node * & previous, const Node * start/* = NULL*/)			  //(8)
{
    Node *temp = m_head;
    Node *temp_next = temp->m_next;
    while(temp->m_next != NULL && temp != NULL)
    {
        if(temp_next->data() == target)
        {
            if(temp != NULL)
            {
                previous = temp;
            }else
            {
                previous = NULL;
            }
            return temp_next;
        }
    }
    previous = NULL;
    return NULL;
}

//inserts value after target
Node * NodeList::insertAfter(const DataType & target, const DataType & value)    		  //(9)
{
    Node* temp = m_head;

    while(temp != NULL)
    {
        temp = temp->m_next;
        if(temp->m_data == target)
        {
            Node *insert = new Node(value);
            Node *tempPt = temp->m_next;
            temp->m_next = insert;
            insert->m_next = tempPt;
            return insert;
        }
    }
    return NULL;
}

//inserts value before target
Node * NodeList::insertBefore(const DataType & target, const DataType & value)   	  //(10)
{
    Node *insert;
    Node *current = m_head;

    while(current != NULL)
    {
        if(current->m_data == target)
        {
            Node *temp = insert;
            insert = new Node(value, current);
            temp->m_next = insert;

        }
        current = current->m_next;
        insert = current;
    }

    return current->m_next;
}

//erases target
Node * NodeList::erase(const DataType & target) 			      //(11)
{
    Node* temp;

    for(temp = m_head;temp != NULL; temp = temp->m_next)
    {
        if(temp->m_data == target)
        {
            delete temp;
            return temp->m_next;
        }
    }
    return NULL;
}

//index
DataType & NodeList::operator[] (size_t position)			  //(12a)
{
    Node *temp = m_head;
    for(size_t i = 0;i < position; i++)
    {
        temp++;
    }
    return temp->data();
}
const DataType & NodeList::operator[] (size_t position) const  //(12b)
{
    Node *temp = m_head;
    for(size_t i = 0;i < position; i++)
    {
        temp++;
    }
    return temp->data();
}

//returns size
size_t NodeList::size() const								  //(13)
{
    size_t count = 0;
    Node *temp = m_head;

    while(temp != NULL)
    {
        count++;
        temp = temp->m_next;
    }
    return count;
}

//checks if empty
bool NodeList::empty() const									  //(14)
{
    if(m_head == NULL)
    {
        return true;
    }else{ return false;}
}

//clears nodelist
void NodeList::clear()										  //(15)
{
    Node *temp1 = m_head;
    Node *temp2 = m_head;

    while(temp1 != NULL)
    {
        temp1 = temp1->m_next;
        delete temp2;
        temp2 = temp1;
    }
    m_head = NULL;
}

//output
std::ostream & operator<<(std::ostream & os, const NodeList & nodeList)	  //(i)
{
    os << "{";
    for(size_t i = 0;i < nodeList.size(); i++)
    {
        os << nodeList[i] << ", ";
    }
    os << "}" << std::endl;
    return os;
}
