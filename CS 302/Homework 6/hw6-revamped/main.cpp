#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "LeftLeaningRedBlack.h"

void Performance(void);

int main()
{
    Performance();

    return 0;
}

void Performance(void)
{
    srand(time(NULL));

    int limit = 10;

    int *pKeys = new int[limit];

    for (int i = 0; i < limit; ++i)
    {
        pKeys[i] = rand() % 100;
    }

    LeftLeaningRedBlack sort4;

    int dummy;
	VoidRef_t ref;
	ref.pContext = &dummy;

	sort4.FreeAll();

	std::cout << std::endl << "Inserts" << "\t"
        "| Parents" << std::endl
        << "------------------------" << std::endl;

    for (int i = 0; i < limit; ++i)
    {
        ref.Key = pKeys[i];
        std::cout << ref.Key << "\t";
        sort4.Insert(ref);

        sort4.printParent(ref.Key);
        std::cout << std::endl;

    }

    for (int i = 0; i < limit; ++i)
    {
        sort4.LookUp(pKeys[i]);
    }

    std::cout << std::endl << "Traversal After Insertion"
        << std::endl << "------------------------" << std::endl;

    sort4.Traverse();

    std::cout << std::endl << "Removal of 4th Element Inserted"
    << std::endl << "------------------------" << std::endl;

    sort4.Delete(pKeys[3]); //deletes fourth element

    sort4.Traverse();

    for (int i = 0; i < limit; ++i)
    {
        sort4.Delete(pKeys[i]);
    }

    sort4.FreeAll();

}
