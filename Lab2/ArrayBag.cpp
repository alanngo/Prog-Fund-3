//******************************************************************
// Template Program
// Programmer: Alan Ngo
// Completed : January 30 2017
// Status    : Complete
//
// This program will be used...
//******************************************************************
/* PROMPT*/
#include <iostream>				// for cin, cout, endl
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include"ArrayBag.h"
#include <vector>
using namespace std;
template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)//constructor
{
}  // end default constructor

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const//getCurrentSize
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const//isEmpty
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)//add
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}  // end if
    
	return hasRoomToAdd;
}  // end add


template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)//remove
{
    int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}  // end if
    
	return canRemoveItem;
}  // end remove

template<class ItemType>
void ArrayBag<ItemType>::clear()//clear
{
	itemCount = 0;
}  // end clear

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const//getFrequencyOf
{
   int frequency = 0;
   int curIndex = 0;       // Current array index
   while (curIndex < itemCount)
   {
      if (items[curIndex] == anEntry)
      {
         frequency++;
      }  // end if
      
      curIndex++;          // Increment to next entry
   }  // end while
   
   return frequency;
}  // end getFrequencyOf


template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const//contains
{
   bool found = false;
   int curIndex = 0;        // Current array index
   while (!found && (curIndex < itemCount))
   {
      if (anEntry == items[curIndex])
      {
         found = true;
      } // end if
      
      curIndex++;           // Increment to next entry
   }  // end while   
   
   return found;
}  // end contains


template<class ItemType>
vector<ItemType> ArrayBag<ItemType>::toVector() const//vector
{
    vector<ItemType> bagContents;
	for (int i = 0; i < itemCount; i++)
	{
		bagContents.push_back(items[i]);
	}
	
   return bagContents;
}  // end toVector

// private
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const//getIndexOf
{
	bool found = false;
   int result = -1;
   int searchIndex = 0;
   
   // If the bag is empty, itemCount is zero, so loop is skipped
   while (!found && (searchIndex < itemCount))
   {
      if (items[searchIndex] == target)
      {
         found = true;
         result = searchIndex;
      } 
      else
      {
         searchIndex++;
      }  // end if
   }  // end while
   
   return result;
}  // end getIndexOf

//other functions
template<class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::bagUnion(const ArrayBag<ItemType> &aBag)//bag union that DOES NOT remove any duplicates
{
	ArrayBag<ItemType> result;//union bag
	//vector<ItemType> aBagItems=aBag.toVector();//second bag

	//Combination Algorithm
	int numItems=0;
	numItems=getCurrentSize();
	for (int i=0; i<numItems; i++)//add the contents of bag that was called to result
	{
			result.add(items[i]);//adds items of the first bag
	}
	numItems=getCurrentSize();
	for (int i=0; i<numItems; i++)//add the contents of the second bag to the result
	{
			result.add(aBag.items[i]);//adds items of the second bag
	}
	return result;
}//end of bagUnions

template<class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::augmentedBagUnion(const ArrayBag<ItemType> &aBag)//bag union that removes any duplicates
{
	ArrayBag<ItemType> result;//union bag
	vector<ItemType> aBagItems=aBag.toVector();//second bag

	//Combination Algorithm
	int numItems=0;
	numItems=getCurrentSize();
	for (int i=0; i<numItems; i++)//add the contents of bag that was called to result
	{
			result.add(items[i]);//adds items of the first bag
	}
	numItems=getCurrentSize();
	for (int i=0; i<numItems; i++)//add the contents of the second bag to the result
	{
			result.add(aBagItems[i]);//adds items of the second bag
	}
	
	for (int i=0; i<numItems; i++)//checks for repeats and removes them from the result bag
	{
		while(result.getFrequencyOf(items[i])>1)
		{
			result.remove(items[i]);
		}
	}

	return result;
}//end of augmentedBagUnion

template<class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::bagIntersection(const ArrayBag<ItemType> &aBag)// bag intersection that displays the common contents between the two bags
{
 	ArrayBag<ItemType> result;
 	vector<ItemType>temp=aBag.toVector();
	int numEntries=getCurrentSize();
	int numEntries2=aBag.getCurrentSize();
 	for (int i=0; i<numEntries; i++)//runs through the first bag
 	{
		for (int j=0; j<numEntries2; j++)//runs through the second bag
		{
			if (items[i]==temp[j])//checks for any common content
			{
				result.add(items[i]);//adds the content to the result bag
				//j=numEntries2+1;
			}
		}
		
		while(result.getFrequencyOf(items[i])>1)//remove duplicates algorithm
		{
			result.remove(items[i]);
		}
	}
	return result;
}//end of bagIntersection

template<class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::bagDifference(const ArrayBag<ItemType> &aBag)//bag difference that display the different contents between the two bags
{
	ArrayBag<ItemType>result;
	vector<ItemType>temp=aBag.toVector();
	int numItems=getCurrentSize();
	int numItems2=aBag.getCurrentSize();
	
	for (int i=0; i<numItems; i++)//add the contents of bag that was called to result
	{
			result.add(items[i]);//adds items of the first bag
	}

	for (int i=0; i<numItems2; i++)//add the contents of the second bag to the result
	{
			result.add(aBag.items[i]);//adds items of the second bag
	}
	
	for (int i=0; i<numItems; i++)//runs through the first bag
	{
		for (int j=0; j<numItems2; j++)//runs through the second bag
		{
			if (items[i]==temp[j])
			{
				result.remove(items[i]);
				result.remove(temp[j]);
			}
		}
		while(result.getFrequencyOf(items[i])>1)//remove duplicates algorithm
		{
			result.remove(items[i]);
		}
	}
	return result;
}//end of bagDifference
