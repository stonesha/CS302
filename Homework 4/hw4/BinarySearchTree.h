/**
 * @file BinarySearchTree.h
 * @author Stone Sha (stones@nevada.unr.edu)
 * @date March, 2019
 * @brief Class file for BinarySearchTree, self-contained header
 */
#ifndef BINARY_SEARCH_TREE_
#define BINARY_SEARCH_TREE_

#include <memory> // std::shared_ptr
#include <stdexcept> // std::throw, std::logic_error
#include <random> //random_device, mt199937, uniform_int_distribution
#include <algorithm> //std::max
#include "BinaryNode.h"

template<class ItemType>
class BinarySearchTree
{
private:
    std::shared_ptr<BinaryNode<ItemType>> rootPtr;

protected:
//------------------------------------------------------------
// Protected Utility Methods Section:
// Recursive helper methods for the public methods.
//------------------------------------------------------------

// Removes the given target value from the tree while maintaining a
// binary search tree.
    auto removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                     const ItemType target,
                     bool& isSuccessful);

// Removes a given node from a tree while maintaining a binary search tree.
    auto removeNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr);

// Removes the leftmost node in the left subtree of the node
// pointed to by nodePtr.
// Sets inorderSuccessor to the value in this node.
// Returns a pointer to the revised subtree.
    auto removeLeftmostNode(std::shared_ptr<BinaryNode<ItemType>>subTreePtr,
                            ItemType& inorderSuccessor);

    auto copyTree(const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const;

    int getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;

    std::shared_ptr<BinaryNode<ItemType>>
                                       sortedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                                               std::shared_ptr<BinaryNode<ItemType>> newNodePtr);

    auto destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr);


    void preorderHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;

    void inorderHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;

    void postorderHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;

public:
//------------------------------------------------------------
// Constructor and Destructor Section.
//------------------------------------------------------------
    BinarySearchTree();
    BinarySearchTree(const ItemType& rootItem);
    BinarySearchTree(const BinarySearchTree<ItemType>& tree);
    virtual ~BinarySearchTree();

//------------------------------------------------------------
// Public Methods Section.
//------------------------------------------------------------
    bool isEmpty() const;
    int getHeight() const;
    int getNumberOfNodes(const std::shared_ptr<BinaryNode<ItemType>> root) const;

    ItemType getRootData() const throw(std::logic_error);
    void setRootData(const ItemType& newData);

    bool add(const ItemType& newEntry);

    bool remove(const ItemType& target);
    void clear();

    void randGen();

//------------------------------------------------------------
// Public Traversals Section.
//------------------------------------------------------------

    void preorderTraverse() const;
    void inorderTraverse() const;
    void postorderTraverse() const;

//------------------------------------------------------------
// Overloaded Operator Section.
//------------------------------------------------------------
    BinarySearchTree<ItemType>&
    operator=(const BinarySearchTree<ItemType>& rhs);

}; // end BinarySearchTree


//------------------------------------------------------------
// Protected Methods Implementation
//------------------------------------------------------------

/**
*
* @param
**/
template<class ItemType>
auto BinarySearchTree<ItemType>::removeNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr)
{
    nodePtr = nullptr;

    return nodePtr == nullptr;
}

/**
*
* @param
**/
template<class ItemType>
auto BinarySearchTree<ItemType>::removeLeftmostNode(std::shared_ptr<BinaryNode<ItemType>>subTreePtr,
        ItemType& inorderSuccessor)
{

}

/**
*
* @param
**/
template<class ItemType>
auto BinarySearchTree<ItemType>::
copyTree(const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const
{
    std::shared_ptr<BinaryNode<ItemType>> newTreePtr;

    if (oldTreeRootPtr != nullptr)
    {
        newTreePtr = std::make_shared<BinaryNode<ItemType>>(oldTreeRootPtr->getItem(), nullptr, nullptr);
        setLeftChildPtr(copyTree(oldTreeRootPtr->getLeftChildPtr()));
        setRightChildPtr(copyTree(oldTreeRootPtr->getRightChildPtr()));
    }

    return newTreePtr;
}


/**
*
* @param
**/
template<class ItemType>
int BinarySearchTree<ItemType>::
getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
    if(rootPtr == nullptr)
        return 0;

    return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()),
                        getHeightHelper(subTreePtr->getRightChildPtr()));
}

/**
*
* @param
**/
template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>>
                                   BinarySearchTree<ItemType>::
                                   sortedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                                           std::shared_ptr<BinaryNode<ItemType>> newNodePtr)
{
    std::shared_ptr<BinaryNode<ItemType>> tempPtr;

    if(subTreePtr == nullptr)
    {
        return newNodePtr;
    }
    else if(subTreePtr->getItem() > newNodePtr->getItem())
    {
        tempPtr = sortedAdd(subTreePtr->getLeftChildPtr(), newNodePtr);
        subTreePtr->setLeftChildPtr(tempPtr);
    }
    else
    {
        tempPtr = sortedAdd(subTreePtr->getRightChildPtr(), newNodePtr);
        subTreePtr->setRightChildPtr(tempPtr);
    }

    return subTreePtr;
}

/**
*
* @param
**/
template<class ItemType>
auto BinarySearchTree<ItemType>::destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr)
{
    if(subTreePtr == nullptr)
        return;

    subTreePtr = nullptr;

    destroyTree(subTreePtr->getLeftChildPtr());
    destroyTree(subTreePtr->getRightChildPtr());
}
//------------------------------------------------------------
// Constructor and Destructor Section.
//------------------------------------------------------------

/**
* Constructor for BinarySearchTree sets rootPtr to nullptr
* indicating an empty tree
**/
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() : rootPtr(nullptr)
{
}//end constructor

/**
* Parameterized Constructor for BinarySearchTree
* @param rootItem       Value/ADT to be copied to rootPtr
**/
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem) :
    rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem, nullptr, nullptr))
{
}//end constructor

/**
*
* @param
**/
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& tree)
{
    rootPtr = copyTree(tree.rootPtr); //deep copy
}

/**
*
* @param
**/
template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{
    clear();
}


//------------------------------------------------------------
// Public Methods Section.
//------------------------------------------------------------

/**
*
* @param
**/
template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const
{
    return rootPtr == nullptr;
}

/**
*
* @param
**/
template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const
{
    return getHeightHelper(rootPtr);
}

/**
*
* @param
**/
template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes(const std::shared_ptr<BinaryNode<ItemType>> root) const
{

    int nodeNum = 1;

    if(root->left != nullptr)
        nodeNum += getNumberofNodes(root->leftChildPtr);

    if(root->right != nullptr)
        nodeNum += getNumberOfNodes(root->rightChildPtr);

    return nodeNum;
}


/**
*
* @param
**/
template<class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const throw(std::logic_error)
{
    if(isEmpty())
        throw std::logic_error("Tree is empty.\n");

    return rootPtr->getItem();
}

/**
*
* @param
**/
template<class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType& newData)
{
    rootPtr->setItem(newData);
}


/**
*
* @param
**/
template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newEntry)
{

    auto newNodePtr = std::make_shared<BinaryNode<ItemType>>(newEntry);
    rootPtr = sortedAdd(rootPtr, newNodePtr);

    return true;
}

/**
*
* @param
**/
template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType& target)
{

    if (rootPtr == nullptr)
    {
        return false;

    }
    else if(rootPtr->getItem() == target)
    {

        rootPtr = removeNode(rootPtr);
        return true;

    }
    else if (rootPtr->getItem() > target)
    {

        auto tempPtr = rootPtr->getLeftChildPtr();
        tempPtr = remove(target);
        rootPtr->setLeftChildPtr(tempPtr);

    }
    else
    {

        auto tempPtr = rootPtr->getRightChildPtr();
        tempPtr = remove(target);
        rootPtr->setRightChildPtr(tempPtr);

    }
}

/**
*
* @param
**/
template<class ItemType>
void BinarySearchTree<ItemType>::clear()
{
    if (rootPtr != nullptr)
    {
        destroyTree(rootPtr->getLeftChildPtr());
        destroyTree(rootPtr->getRightChildPtr());
        rootPtr.reset(); //decrement reference count to node;
    }
}

/**
*
* @param
**/
template <class ItemType>
void BinarySearchTree<ItemType>::randGen()
{
    //initialization for random ints
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 200);

    for(int i = 0; i < 5; i++)
    {
        add(dis(gen));
    }
}



//------------------------------------------------------------
// Public Traversals Section.
//------------------------------------------------------------

/**
*
* @param
**/
template<class ItemType>
void BinarySearchTree<ItemType>::
preorderHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
    if(isEmpty())
    {
        std::cout << "Empty" << std::endl;
        return;
    }


    std::cout << subTreePtr->getItem() << " ";

    preorderHelper(subTreePtr->getLeftChildPtr());

    preorderHelper(subTreePtr->getRightChildPtr());

}

/**
*
* @param
**/
template<class ItemType>
void BinarySearchTree<ItemType>::
inorderHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{

    if(isEmpty())
    {
        std::cout << "Empty" << std::endl;
        return;
    }

    inorderHelper(subTreePtr->getLeftChildPtr());

    std::cout << subTreePtr->getItem() << " ";

    inorderHelper(subTreePtr->getRightChildPtr());

}

/**
*
* @param
**/
template<class ItemType>
void BinarySearchTree<ItemType>::
postorderHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
    if(isEmpty())
    {
        std::cout << "Empty" << std::endl;
        return;
    }

    postorderHelper(subTreePtr->getLeftChildPtr());

    postorderHelper(subTreePtr->getRightChildPtr());

    std::cout << subTreePtr->getItem() << " ";

}


/**
*
* @param
**/
template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse() const
{
    std::cout << "===== Preorder =====" << std::endl;

    preorderHelper(rootPtr);
}

/**
*
* @param
**/
template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse() const
{
    std::cout << "===== Inorder =====" << std::endl;

    inorderHelper(rootPtr);
}

/**
*
* @param
**/
template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse() const
{
    std::cout << "===== Postorder =====" << std::endl;

    postorderHelper(rootPtr);
}


//------------------------------------------------------------
// Overloaded Operator Section.
//------------------------------------------------------------

/**
*
* @param
**/
template<class ItemType>
BinarySearchTree<ItemType>&
BinarySearchTree<ItemType>::operator=(const BinarySearchTree<ItemType>& rhs)
{
    if(this == &rhs)
        return *this; //checks self assignment

    rootPtr = copyTree(rhs->rootPtr);

    return *this;
}


#endif
