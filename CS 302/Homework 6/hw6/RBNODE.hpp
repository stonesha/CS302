/**
 * @file RBNODE.h
 * @author Stone Sha (stones@nevada.unr.edu)
 * @date April, 2019
 * @brief Class file for Red-Black Node, self-contained header
 */

#pragma once
#include <string>

template <class ItemType>
class RBNODE
{

private:
    ItemType item;
    RBNODE<ItemType> *leftChildPtr;
    RBNODE<ItemType> *rightChildPtr;

    bool red; //if true, node is red, if false node is black


public:

    RBNODE<ItemType> ();
    RBNODE<ItemType> (const ItemType &anItem);

    ItemType getItem(void) const;
    void setItem(const ItemType &anItem);

    RBNODE<ItemType>* getLeftChildPtr(void);
    RBNODE<ItemType>* getRightChildPtr(void);
    RBNODE<ItemType>* getParentPtr(void);

    void setLeftChildPtr(RBNODE<ItemType> *leftPtr);
    void setRightChildPtr(RBNODE<ItemType> *rightPtr);

    bool getColor(void);
    std::string getTrueColor(void);
    void setColor(bool color);
    void flipColor(void);


};

template <class ItemType>
RBNODE<ItemType>::RBNODE () :
    leftChildPtr(nullptr),
    rightChildPtr(nullptr),
    red(false)

{
}

template <class ItemType>
RBNODE<ItemType>::RBNODE (const ItemType &anItem) :
    item(anItem),
    leftChildPtr(nullptr),
    rightChildPtr(nullptr),
    red(true)

{
}

template <class ItemType>
ItemType RBNODE<ItemType>::getItem() const
{
    return item;
}

template <class ItemType>
void RBNODE<ItemType>::setItem(const ItemType &anItem)
{
    item = anItem;
}

template <class ItemType>
RBNODE<ItemType>* RBNODE<ItemType>::getLeftChildPtr()
{
    return leftChildPtr;
}

template <class ItemType>
RBNODE<ItemType>* RBNODE<ItemType>::getRightChildPtr()
{
    return rightChildPtr;
}

template <class ItemType>
void RBNODE<ItemType>::setLeftChildPtr(RBNODE<ItemType> *leftPtr)
{
    leftChildPtr = leftPtr;
}

template <class ItemType>
void RBNODE<ItemType>::setRightChildPtr(RBNODE<ItemType> *rightPtr)
{
    rightChildPtr = rightPtr;
}

template <class ItemType>
bool RBNODE<ItemType>::getColor()
{
    return red;
}

template <class ItemType>
void RBNODE<ItemType>::setColor(bool color)
{
    red = color;
}

template <class ItemType>
void RBNODE<ItemType>::flipColor()
{
    red = (red == true ? false : true);
}

template <class ItemType>
std::string RBNODE<ItemType>::getTrueColor(void)
{
    std::string Black = "black", Red = "red";

    return red == true ? Red : Black;
}
