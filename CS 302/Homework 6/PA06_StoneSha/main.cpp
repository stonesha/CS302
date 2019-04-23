#include <iostream>
#include <vector> //std::vector
#include <stdlib.h> //srand()
#include "LeftLeaningRedBlack.h"

void Performance(void);

int main()
{
    Performance();

    return 0;
}

//Function to test left leaning red black tree
void Performance(void)
{
    int limit = 10;
    int *pKeys = new int[limit];
    srand(123456);

    //fills pKeys with random values
    for (int i = 0; i < limit; ++i)
    {
        pKeys[i] = rand() % 100;
    }

    //LLRB tree
    LeftLeaningRedBlack sort4;

    int dummy;
	VoidRef_t ref;
	ref.pContext = &dummy;

	//safety check to make sure tree is empty
	sort4.FreeAll();

	//prints nodes at time of insertion, also prints parent
	//at time of insertion
	std::cout << std::endl << "Inserts" << "\t"
        "| Parent at Insertion" << std::endl
        << "-----------------------------" << std::endl;

    for (int i = 0; i < limit; ++i)
    {
        ref.Key = pKeys[i];
        sort4.Insert(ref);
        sort4.printNode(pKeys[i]);

        std::cout << "\t";

        sort4.printParent(ref.Key);
        std::cout << std::endl;

    }

    //prints entire tree
    std::cout << std::endl << "Traversal After Insertion"
        << std::endl << "-----------------------------" << std::endl;

    sort4.Traverse();

    //removes 4th element and reprints tree
    std::cout << std::endl << "Removal of 4th Element Inserted"
    << std::endl << "-----------------------------" << std::endl;

    sort4.Delete(pKeys[3]); //deletes fourth element

    sort4.Traverse();

    //deletes all keys inside tree
    for (int i = 0; i < limit; ++i)
    {
        sort4.Delete(pKeys[i]);
    }

    //safety to make sure that nothing is left
    sort4.FreeAll();
    delete[] pKeys;

}
