#include <iostream>
#include "LLRBT.hpp"

int main()
{

    LLRBT<int> tree;
    tree.add(1);

    tree.add(2);
    tree.add(3);
    tree.add(4);
    tree.add(5);


    tree.inorder();

    return 0;
}

