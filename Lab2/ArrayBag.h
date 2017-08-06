/******************************************************************
// Template Program
// Programmer: Alan Ngo
// Completed : January 30 2017
// Status    : Complete
//
// This class will be used to create an ArrayBag object by defining 
	data fields and member functions
//******************************************************************/
#ifndef ARRAY_BAG_
#define ARRAY_BAG_
#include <iostream>				// for cin, cout, endl
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include "BagInterface.h"
#include <vector>
using namespace std;
template<class ItemType>
class ArrayBag
{
private:
	static const int DEFAULT_CAPACITY = 6; // Small size to test for a full bag
	ItemType items[DEFAULT_CAPACITY];      // Array of bag items
	int itemCount;                         // Current count of bag items 
	int maxItems;                          // Max capacity of the bag
	   
   // Returns either the index of the element in the array items that
   // contains the given target or -1, if the array does not contain 
   // the target.
   int getIndexOf(const ItemType& target) const;   

public:
	//core functions
	ArrayBag();//constructor
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	bool contains(const ItemType& anEntry) const;
	int getFrequencyOf(const ItemType& anEntry) const;
	vector<ItemType> toVector() const;
   
   //additional functions
   ArrayBag<ItemType>bagUnion(const ArrayBag<ItemType> &aBag);
   ArrayBag<ItemType> augmentedBagUnion(const ArrayBag<ItemType> &aBag);
   ArrayBag<ItemType> bagIntersection(const ArrayBag<ItemType> &aBag);
   ArrayBag<ItemType> bagDifference(const ArrayBag<ItemType> &aBag);
		
};//end of class
#include "ArrayBag.cpp"
#endif 

