#include <iostream>
#include <algorithm> // std::shuffle, std::
#include <vector>
#include <numeric>      // std::accumulate
#include <random>

void randGen(std::vector<int> &vec);
void printVec(std::vector<int> vec);

int main()
{

    std::vector<int> v;

    randGen(v);

    std::cout << std::endl << "=====Randomly Generated Vector=====" << std::endl;

    printVec(v);

    make_heap(v.begin(), v.end());

    auto mean = std::accumulate(v.begin(), v.end(), 0) / v.size();

    v.push_back(mean);

    std::cout << std::endl  << "=====Mean pushed onto Heap=====" << std::endl;

    printVec(v);

    pop_heap(v.begin(), v.end());
    v.pop_back();

    std::cout << std::endl  << "=====Maximum Deleted Element=====" << std::endl;

    printVec(v);

    push_heap(v.begin(), v.end());

    std::cout << std::endl  << "=====Sorted Heap=====" << std::endl;

    printVec(v);

    return 0;
}


/**
* Fills binary search tree with
* random values between 0 and 200
* @param        BinarySearchTree object
**/
void randGen(std::vector<int> &vec)
{
    //initialization for random ints
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 999);

    //fills vector with random values
    for(int i = 0; i < 100; i++)
        vec.push_back(dis(gen));
}

void printVec(std::vector<int> vec)
{
    std::cout << std::endl;

    for(unsigned int i = 0; i < vec.size(); i++)
    {
        if(i % 10 == 0)
            std::cout << std::endl;

        std::cout  << vec[i] << ", ";
    }
}
