#include <iostream>
#include <random>
#include "LeftLeaningRedBlack.h"

void Performance(void);

int main()
{
    Performance();

    return 0;
}

void Performance(void)
{
    std::random_device gen;
    std::mt19937 rng(gen());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1,100); // distribution in range [1, 6]

    int limit = 10;

    int *pKeys = new int[limit];

    for (int i = 0; i < limit; ++i)
    {
        pKeys[i] = dist(rng);
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
