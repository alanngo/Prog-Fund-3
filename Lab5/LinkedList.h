//Â  Created by Frank M. Carrano and Timothy M. Henry.
//Â  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT list: Link-based implementation.
    Listing 9-2.
    @file LinkedList.h */

#ifndef LINKED_LIST_
#define LINKED_LIST_

#include "ListInterface.h"
#include "Node.h"
#include <cassert>
#include <iostream>
template<class ItemType>
class LinkedList : public ListInterface<ItemType>
{
private:
   Node<ItemType>* headPtr; // Pointer to first node in the chain;
                            // (contains the first entry in the list)
   int itemCount;           // Current count of list items 
   
   // Locates a specified node in this linked list.
   // @pre  position is the number of the desired node;
   //       position >= 1 and position <= itemCount.
   // @post  The node is found and a pointer to it is returned.
   // @param position  The number of the node to locate.
   // @return  A pointer to the node at the given position.
   Node<ItemType>* getNodeAt(int position) const;

public:
   LinkedList();
   LinkedList(const LinkedList<ItemType>& aList);
   virtual ~LinkedList();

   bool isEmpty() const;
   int getLength() const;
   bool insert(int newPosition, const ItemType& newEntry);
   bool remove(int position);
   void clear();
   
   /** @abort if position < 1 or position > getLength(). */
   ItemType getEntry(int position) const;

   /** @abortp if position < 1 or position > getLength(). */
   void replace(int position, const ItemType& newEntry);
   
   //Additional Functions
   int getCapacity() const;
   
   int remove(const ItemType& anEntry); //overloaded remove function'

   int getPosition(const ItemType& anEntry) const;

   bool contains(const ItemType& anEntry) const; 
}; // end LinkedList

/** Implementation file for the class LinkedList.
 @file LinkedList.cpp */


  
template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(NULL), itemCount(0)
{
}  // end default constructor

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList) : itemCount(aList.itemCount)
{
   Node<ItemType>* origChainPtr = aList.headPtr;  // Points to nodes in original chain

   if (origChainPtr == NULL)
      headPtr = NULL;  // Original list is empty
   else
   {
      // Copy first node
      headPtr = new Node<ItemType>();
      headPtr->setItem(origChainPtr->getItem());
      
      // Copy remaining nodes
      Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
      origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
      while (origChainPtr != NULL)
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();
         
         // Create a new node containing the next item 
         Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);  
         
         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr); 
         
         // Advance pointer to new last node      
         newChainPtr = newChainPtr->getNext();
         
         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while
      
      newChainPtr->setNext(NULL);              // Flag end of chain
   }  // end if
}  // end copy constructor

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
   clear();
}  // end destructor

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
   return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
   return itemCount;
}  // end getLength

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
   bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
   if (ableToInsert)
   {
      // Create a new node containing the new entry 
      Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);  
      
      // Attach new node to chain
      if (newPosition == 1)
      {
         // Insert new node at beginning of chain
         newNodePtr->setNext(headPtr); 
         headPtr = newNodePtr;
      }
      else
      {
         // Find node that will be before new node
         Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);
         
         // Insert new node after node to which prevPtr points
         newNodePtr->setNext(prevPtr->getNext()); 
         prevPtr->setNext(newNodePtr);
      }  // end if

      itemCount++;  // Increase count of entries
   }  // end if
   
   return ableToInsert;
}  // end insert

template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
   bool ableToRemove = (position >= 1) && (position <= itemCount);
   if (ableToRemove)
   {
      Node<ItemType>* curPtr = NULL;
      if (position == 1)
      {
         // Remove the first node in the chain
         curPtr = headPtr; // Save pointer to node
         headPtr = headPtr->getNext();
      }
      else
      {
         // Find node that is before the one to delete
         Node<ItemType>* prevPtr = getNodeAt(position - 1);
         
         // Point to node to delete
         curPtr = prevPtr->getNext();
         
         // Disconnect indicated node from chain by connecting the
         // prior node with the one after
         prevPtr->setNext(curPtr->getNext());
      }  // end if
      
      // Return node to system
      curPtr->setNext(NULL);
      delete curPtr;
      curPtr = NULL;
      
      itemCount--;  // Decrease count of entries
   }  // end if
   
   return ableToRemove;
}  // end remove

template<class ItemType>
void LinkedList<ItemType>::clear()
{
   while (!isEmpty())
   {
       remove(1);  	
   }

}  // end clear

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const
{
   // Enforce precondition
   bool ableToGet = (position >= 1) && (position <= itemCount);
   assert(ableToGet);

   Node<ItemType>* nodePtr = getNodeAt(position);
   return nodePtr->getItem();
}  // end getEntry

template<class ItemType>
void LinkedList<ItemType>::replace(int position, const ItemType& newEntry)
{
   // Enforce precondition
   bool ableToSet = (position >= 1) && (position <= itemCount);
   
   assert(ableToSet);

   Node<ItemType>* nodePtr = getNodeAt(position);
   nodePtr->setItem(newEntry);
}  // end replace

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
   // Debugging check of precondition
   assert( (position >= 1) && (position <= itemCount) );
   
   // Count from the beginning of the chain
   Node<ItemType>* curPtr = headPtr;
   for (int skip = 1; skip < position; skip++)
   {
    	curPtr = curPtr->getNext(); 	
   }

   return curPtr;
}  // end getNodeAt

//Additional Functions
template<class ItemType>
int LinkedList<ItemType>::getCapacity() const
{
	return 1;
}
//overloaded remove function
template<class ItemType>
int LinkedList<ItemType>::remove(const ItemType& anEntry) //remove by item
{
	Node<ItemType>* curPtr = headPtr;//current pointer
	Node <ItemType>*prevPtr=NULL;//previous pointer
	int numRemoved=0;
	/**/
	while (contains(anEntry))
	{
		for (int i= 1; i<=itemCount&&curPtr!=NULL; i++)
		{	
			if (curPtr->getItem()==anEntry)//for consecutive repeats
			{
				prevPtr=curPtr->getNext();
				remove(i);
				curPtr=prevPtr;
				numRemoved++;
				i--;
			}
			else// non-consecutive repeats
			{
				curPtr=curPtr->getNext();//traverse through the list
			}
		}
	}/**/

	cout<<"Occurences removed: "<<numRemoved<<endl;
	return numRemoved;
}

template<class ItemType>
int LinkedList<ItemType>::getPosition(const ItemType& anEntry) const
{
	bool found=false;
	Node<ItemType>* curPtr = headPtr;
	int position=0;
	assert(!isEmpty());
	
	for(int index=1; index<=itemCount&&curPtr!=NULL&&!found; index++)
	{
		if (curPtr->getItem()==anEntry)
		{
			found=true;
			position= index;
		}
		curPtr=curPtr->getNext();//traverse code
	}
	return position;
}

template<class ItemType>
bool LinkedList<ItemType>::contains(const ItemType& anEntry) const
{
	Node<ItemType>* curPtr = headPtr;
	while(curPtr!=NULL)
	{
		if (curPtr->getItem()==anEntry)
		{
			return true;
		} 
		curPtr=curPtr->getNext();
	}
	return false;	
} 
//  End of implementation file.
#endif 
