#include "BubbleSort.h"

BubbleSort::BubbleSort(int sizeVal)
{
    //dynamically allocate memory then insert random values

    //initialization for random ints
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1000000);

    //resizes vector and sets size
    arr = new (std::nothrow) int [sizeVal];
    size = sizeVal;

    //fills vector with random values
    for(int i = 0; i < size; i++)
    {
        arr[i] = dis(gen);
    }

}

BubbleSort::~BubbleSort()
{
    //dtor
    delete[] arr;
    arr = nullptr;
}

void BubbleSort::deallocate()
{
    delete[] arr;
    arr = nullptr;
}

void BubbleSort::serialize()
{
    for(int i = 0; i < size; i++)
    {
        if(i % 10 == 0)
            std::cout << std::endl;
        std::cout << arr[i] << ", ";
    }
}

void BubbleSort::sort()
{
    bool swapped = false;

    for(int i = 0; i < size - 1; i++)
    {
        swapped = false;
        for(int j = 0; j < size - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                std::swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }

        if(!swapped)
            break;
    }
}
