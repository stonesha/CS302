#include <iostream>
#include "NodeQueue.h"
#include "ArrayQueue.h"

using namespace std;

int main()
{
    //Default (1)
    ArrayQueue aq_default;
    NodeQueue nq_default;

    //Parameterized (2)
    DataType dt_param(360, 420.69);
    ArrayQueue aq_param(5, dt_param);

    return 0;
}
