#ifndef ARRAY_STACK
#define ARRAY_STACK
#include <iostream>				// for cin, cout, endl
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include "StackInterface.h"

using namespace std;
const int MAX_STACK = 5;

template<class ItemType>
class ArrayStack : public StackInterface<ItemType>
{
	private:	
		ItemType items[MAX_STACK]; // Array of stack items
		int top;              // Index to top of stack
		
	public:
		 ArrayStack();             // Default constructor
		 bool isEmpty() const;
		 bool push(const ItemType& newEntry);
		 bool pop();
		 ItemType peek() const;	
}; // end ArrayStack
#include "ArrayStack.cpp"
#endif 

