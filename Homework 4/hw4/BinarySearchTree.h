/**
 * @file BinarySearchTree.h
 * @author Stone Sha (stones@nevada.unr.edu)
 * @date March, 2019
 * @brief Class file for BinarySearchTree, self-contained header
 */
#ifndef BINARY_SEARCH_TREE_
#define BINARY_SEARCH_TREE_

#include <memory>
#include <stdexcept>
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
// Places a given new node at its proper position in this binary
// search tree.
    auto placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                   std::shared_ptr<BinaryNode<ItemType>> newNode);

// Removes the given target value from the tree while maintaining a
// binary search tree.
    auto removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                     const ItemType target,
                     bool& isSuccessful) override;

// Removes a given node from a tree while maintaining a binary search tree.
    auto removeNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr);

// Removes the leftmost node in the left subtree of the node
// pointed to by nodePtr.
// Sets inorderSuccessor to the value in this node.
// Returns a pointer to the revised subtree.
    auto removeLeftmostNode(std::shared_ptr<BinaryNode<ItemType>>subTreePtr,
                            ItemType& inorderSuccessor);

// Returns a pointer to the node containing the given value,
// or nullptr if not found.
    auto findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr,
                  const ItemType& target) const;

    auto copyTree(const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const;

    int getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;

    auto balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
            std::shared_ptr<BinaryNode<ItemType>> newNodePtr);

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

    ItemType getEntry(const ItemType& anEntry) const throw(std::logic_error);
    bool contains(const ItemType& anEntry) const;

//------------------------------------------------------------
// Public Traversals Section.
//------------------------------------------------------------
    void preorderTraverse(void visit(ItemType&)) const;
    void inorderTraverse(void visit(ItemType&)) const;
    void postorderTraverse(void visit(ItemType&)) const;

//------------------------------------------------------------
// Overloaded Operator Section.
//------------------------------------------------------------
    BinarySearchTree<ItemType>&
    operator=(const BinarySearchTree<ItemType>& rhs);

}; // end BinarySearchTree
#endif

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

template<class ItemType>
int BinarySearchTree<ItemType>::
getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
    if(rootPtr == nullptr)
        return 0;

    return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()),
                   getHeightHelper(subTreePtr->getRightChildPtr()));
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
    rootPtr = balancedAdd(rootPtr, newNodePtr);

    return true;
}

template<class ItemType>
auto BinarySearchTree<ItemType>::balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
        std::shared_ptr<BinaryNode<ItemType>> newNodePtr)
{
    if(isEmpty())
        rootPtr = newNodePtr;
    else
    {
        auto leftPtr = rootPtr->getLeftChildPtr();
        auto rightPtr = rootPtr->getRightChildPtr();

        if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr))
        {
            rightPtr = balancedAdd(rightPtr, newNodePtr);
            subTreePtr->setRightChildPtr(rightPtr);
        }
        else
        {
            leftPtr = balancedAdd(leftPtr, newNodePtr);
            subTreePtr->setLeftChild(leftPtr);
        }
        return subTreePtr;
    }

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

    }else if(rootPtr->getItem() == target)
    {

        rootPtr = removeNode(rootPtr);
        return true;

    }else if (rootPtr->getItem() > target)
    {

        auto tempPtr = rootPtr->getLeftChildPtr();
        tempPtr = remove(target);
        rootPtr->setLeftChildPtr(tempPtr);

    }else
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
template<class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry) const throw(std::logic_error)
{

}

/**
*
* @param
**/
template<class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& anEntry) const
{

}


//------------------------------------------------------------
// Public Traversals Section.
//------------------------------------------------------------

/**
*
* @param
**/
template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(void visit(ItemType&)) const
{

}

/**
*
* @param
**/
template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{

}

/**
*
* @param
**/
template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
{

}

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


