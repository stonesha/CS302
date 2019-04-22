#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "LeftLeaningRedBlack.h"

void Performance(void);

int main()
{
    Performance();

    return 0;
}

void Performance(void)
{
    int limit = 10;
    int *pKeys = new int[limit];

    //randomly generate unique values
    std::vector<int> values;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    for(int i = 0; i < 100; i++)
        values.push_back(i);

    std::shuffle(values.begin(), values.end(), std::default_random_engine(seed));


    for (int i = 0; i < limit; ++i)
    {
        pKeys[i] = values[i];
    }

    LeftLeaningRedBlack sort4;

    int dummy;
	VoidRef_t ref;
	ref.pContext = &dummy;

	sort4.FreeAll();

	std::cout << std::endl << "Inserts" << "\t"
        "| Parent at Insertion" << std::endl
        << "-----------------------------" << std::endl;

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
        << std::endl << "-----------------------------" << std::endl;

    sort4.Traverse();

    std::cout << std::endl << "Removal of 4th Element Inserted"
    << std::endl << "-----------------------------" << std::endl;

    sort4.Delete(pKeys[3]); //deletes fourth element

    sort4.Traverse();

    for (int i = 0; i < limit; ++i)
    {
        sort4.Delete(pKeys[i]);
    }

    sort4.FreeAll();

}
