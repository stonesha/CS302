/**
 * @brief  CS-202 Project 8 Test driver
 * @Author Stone Sha (stones@nevada.unr.edu)
 * @date   November, 2018
 *poopoo caca
 * This file is the test driver for Project 9
 */

#include <iostream>
#include "NodeQueue.h"
#include "ArrayQueue.h"

using namespace std;

int main()
{

    	//Default (1)
	cout << "----- Testing Default Constructors -----" << endl;
    	ArrayQueue aq_default;
    	NodeQueue nq_default;

    	//Parameterized (2)
	cout << "----- Testing Parameterized Constructors -----" << endl;
    	DataType dt_param(360, 420.69);
    	ArrayQueue aq_param(5, dt_param);
	NodeQueue nq_param(5, dt_param);
	
	cout << "dt_param is equal to " << dt_param << endl;

	cout << "aq_param is equal to";
	aq_param.serialize(cout);
	cout << endl;

	cout << "nq_param is equal to" << nq_param << endl;

	//Copy (3)
	cout << "----- Testing Copy Constructors -----" << endl;
	DataType dt_copy(dt_param);
	ArrayQueue aq_copy(aq_param);
	NodeQueue nq_copy(nq_param);

	cout << "dt_copy is equal to " << dt_copy << endl;

	cout << "aq_copy is equal to";
	aq_copy.serialize(cout);
	cout << endl;

	cout << "nq_copy is equal to" << nq_copy << endl;

	//Assignment (5)
	cout << "----- Testing Assignment Operators -----" << endl;
	DataType dt_new(2, 8.09);
	ArrayQueue aq_new(4, dt_new);
	NodeQueue nq_new(4, dt_new);

	cout << "dt_new is equal to " << dt_new << endl;

	cout << "aq_new is equal to";
	aq_new.serialize(cout);
	cout << endl;

	cout << "nq_new is equal to" << nq_new << endl;

	//-------------------------------------
	dt_copy = dt_new;
	aq_copy = aq_new;
	nq_copy = nq_new;

	cout << "----- ASSIGNING -----" << endl;
	
	cout << "dt_copy is now equal to " << dt_copy << endl;

	cout << "aq_copy is now equal to";
	aq_copy.serialize(cout);
	cout << endl;
	//THIS HERE NO WORKe
	cout << "nq_copy is now equal to" << nq_copy << endl;

	//Front and Back (6) and (7)
	cout << "----- Testing front() and back() -----" << endl;
	cout << "The front of aq_new is equal to " << aq_new.front() << endl;
	cout << "The front of nq_new is equal to " << nq_new.front() << endl;

	//Push and Pop (8) and (9)
	cout << "----- Testing push() and pop() -----" << endl;
	DataType dt_push(10, 2.5);
	//Push
	aq_new.push(dt_push);
	nq_new.push(dt_push);

	cout << "After pushing aq_new, it is now";
	aq_new.serialize(cout);
	cout << endl;

	cout << "After pushing nq_new, it is now" << nq_new << endl;

	//Pop
	aq_new.pop();
	nq_new.pop();
	
	cout << "After pushing aq_new, it is now";
	aq_new.serialize(cout);
	cout << endl;

	cout << "After pushing nq_new, it is now" << nq_new << endl;

	//Size(10), empty(11), and full(12)
	cout << "----- Testing size(), empty(), and full() -----" << endl;
	cout << "Size of aq_new is " << aq_new.size() << endl;
	cout << "Size of nq_new is " << nq_new.size() << endl;
	
	cout << "aq_new.empty() returns " << boolalpha << aq_new.empty() << endl;
	cout << "nq_default.empty() returns " << boolalpha << nq_default.empty() << endl;

	//destructors/clear
	cout << "----- Testing Destructors/clear() -----" << endl; 
	aq_default.clear();
	aq_param.clear();
	aq_copy.clear();
	aq_new.clear();
	
    return 0;
}
