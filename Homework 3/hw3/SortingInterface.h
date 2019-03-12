#ifndef SORTINGINTERFACE_H
#define SORTINGINTERFACE_H

#include <iostream>
#include <random>
#include <algorithm>
#include <vector>

class SortingInterface
{
    public:

        virtual ~SortingInterface();

        virtual void serialize()
        {
            for(int i = 0;i < size; i++)
            {
                if(i % 10 == 0) std::cout << std::endl;
                std::cout << arr[i] << ", ";
            }
        }
        virtual void sort();

    protected:
        std::vector<int> arr;

        int size;

    private:

};

#endif // SORTINGINTERFACE_H

