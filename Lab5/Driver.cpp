	/******************************************************************
// Template Program
// Programmer: Alan Ngo
// Completed : March 29 2017
// Status    : Complete
//
// This program will be used to test the implementation of the linked and arraylist
******************************************************************/
#include "ArrayList.h"// ADT list operations
#include "LinkedList.h" 
#include <iostream>				// for cin, cout, endl
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include "ListInterface.h"

using namespace std;

template<class dataType>
void debug(dataType x)
{
	cout<<"******Debug Start******"<<endl;
	cout<<"Value is "<<x<<endl;
	cout<<"******End Debug******"<<endl;
}

/**/
//side functions
void showMenu()//menu
{
	cout<<"________________________MENU________________________"<<endl;
	cout<<"(a)ppend items "<<endl;
	cout<<"i(n)sert item at specific index "<<endl;
	cout<<"Remove item by (i)ndex "<<endl;
	cout<<"Remove item by (e)ntry "<<endl;
	cout<<"(r)eplace an item "<<endl;
	cout<<"search by (I)ndex "<<endl;
	cout<<"Search by (E)ntry "<<endl;
	cout<<"(c)lear list "<<endl;
	cout<<"(d)isplay list "<<endl;
	cout<<"e(x)it"<<endl;
	cout<<"_____________________________________________________"<<endl;
}

bool validChoice(char ch)// if the user chooses an invalid choice
{
	char valid[10]={'a','n','i','e','r','I','E','c','d','x'};
	for(int i=0; i<10; i++)
	{
		if (ch==valid[i])
		{
			return true;
		}
	}
	return false;
}

template<class ItemType>
bool outOfBounds(int index, ListInterface<ItemType>* listPtr)//if index is out of bounds
{
	if (index<1||index>listPtr->getLength())
	{
		return true;
	}
	return false;
}


//key functions
template<class ItemType>
void append(ListInterface<ItemType>* listPtr)//adds elements to the list continuously
{
	char again='y';
	ItemType item;
	for (int i=listPtr->getLength()+1; (again=='y'); i++)
	{
		cout<<"Enter the item ";
   		cin>>item;
        listPtr->insert(i, item);
        cout<<i<<"). "<<item<<endl;
        cout<<"Add another one? (y)es (n)o ";
        cin>>again;
	}

}//end of append

template<class ItemType>
bool insertItem(ListInterface<ItemType>* listPtr)//insert at a specific index
{
	if(listPtr->isEmpty())//empty list exception
	{
		char ans=' ';
		cout<<"Your list is empty! Add items to it? (y)es"<<endl;
		cin>>ans;
		if (ans=='y')
		{
			append(listPtr);
			return true;
		}
		else
		{
			return false;
		}
	}
	ItemType item;
	int index=1;
	cout<<"Enter the index you want to insert at: ";
	cin>>index;
	while (outOfBounds(index, listPtr))
	{
		cout<<index<<" is NOT a valid index! Enter an index no greater than "<<listPtr->getLength();
		cin>>index;
	}
	
	cout<<"Enter the item you want to insert ";
	cin>>item;
	listPtr->insert(index, item);
	return true;
}//end of insertItem

template<class ItemType>
bool removeByIndex(ListInterface<ItemType>* listPtr)//removes by having the user enter the index THIS REMOVES ONLY ONE OCCURENCE OF THE ITEM
{
	if(listPtr->isEmpty())//empty list exception
	{
		cout<<"Empty list error!"<<endl;
		return false;
	}
	
	//actual function
	int index=0;
	cout<<"Enter the index you want to remove ";
	cin>>index;
	while (outOfBounds(index, listPtr))
	{
		cout<<index<<" is NOT a valid index! Enter an index no greater than "<<listPtr->getLength();
		cin>>index;
	}
	
	cout<<listPtr->getEntry(index)<<" has been removed from index "<<index<<endl;
	listPtr->remove(index);
	return true;
}//end of removeByIndex

template<class ItemType>
bool removeByEntry(ListInterface<ItemType>* listPtr)//removes by having the user enter the entry THIS REMOVES ALL OCCURENCES OF THE ITEM
{
	if(listPtr->isEmpty())//empty list exception
	{
		cout<<"Empty list error!"<<endl;
		return false;
	}
	ItemType entry;
	cout<<"Enter the entry you want to remove ";
	cin>>entry;
	if (!listPtr->contains(entry))
	{
		cout<<"Could not find '"<<entry<<"'! "<<endl;
		return false;
	}
	listPtr->remove(entry);	
	cout<<"'"<<entry<<"' have been removed from the list "<<endl;
	return true;
}

template<class ItemType>
bool replaceItem(ListInterface<ItemType>* listPtr)//replaces 1 item w/ another by having the user enter the index and the replacement item
{
	if(listPtr->isEmpty())//empty list exception
	{
		cout<<"Empty list error!"<<endl;
		return false;
	}
	int index=0;
	ItemType entry;
	cout<<"Enter the index you want to conduct the replacement ";
	cin>>index;
	while (outOfBounds(index, listPtr))
	{
		cout<<index<<" is NOT a valid index! Enter an index no greater than "<<listPtr->getLength();
		cin>>index;
	}
	cout<<"Enter the replacement item ";
	cin>>entry;
	cout<<"'"<<listPtr->getEntry(index)<<"' has been replaced with '"<<entry<<"'"<<endl;
	listPtr->replace(index, entry);
	return true;
}//end of replace item

template<class ItemType>//search by entry
void searchByEntry(ListInterface<ItemType>* listPtr)//searches by having the user enter a key
{
	ItemType key;
	cout<<"Enter the key to search for ";
	cin>>key;
	if (listPtr->contains(key))
	{
		cout<<"First occurence of "<<"'"<<key<<"' is located at "<<listPtr->getPosition(key)<<endl;	
	}
	else
	{
		cout<<"NO SUCH ENTRY EXISTS"<<endl;
	}
}//end of searchByEntry

template<class ItemType>//search by index
bool searchByIndex(ListInterface<ItemType>* listPtr)//searches by having the user enter an index
{
	int index=0;
	cout<<"Enter the index ";
	cin>>index;
	if(outOfBounds(index, listPtr))
	{
		cout<<"No such index exists "<<endl;
		return false;
	}
	cout<<listPtr->getEntry(index)<<" is at "<<index<<endl;
	return true;
}//end of searchByIndex
template<class ItemType>
bool clearList(ListInterface<ItemType>* listPtr)//clears list by calling the clear function
{
	if (listPtr->isEmpty())
	{
		cout<<"List is already empty! "<<endl;
		return false;
	}
	listPtr->clear();
	cout<<"List Cleared"<<endl;
	return true;
}

template<class ItemType>
void displayList(ListInterface<ItemType>* listPtr)//outputs the list
{
	//debug(listPtr->contains("alan"));
    cout << "The list contains " << listPtr->getLength()<<" items" <<endl;
    cout<<"*****************************************************"<<endl;
   for (int pos = 1; pos <= listPtr->getLength(); pos++)
   {
        cout <<pos<<"). "<< listPtr->getEntry(pos) << endl;
   } // end for
    cout <<  endl;
}  // end displayList

template<class ItemType>
bool implementList(ListInterface<ItemType>* listPtr)//implemetns list
{
	char choice=' ';
	char again='y';
	showMenu();
	cout<<"Enter choice ";
	cin>>choice;

	while (!validChoice(choice))
	{
		cout<<"Enter a valid choice ";
		cin>>choice;
	}
	while (again=='y')
	{
		switch(choice)
		{
			case 'a'://appends items to list
				append(listPtr);//insert item iteratively
				break;
			case 'n'://inserts items to a specific index
				insertItem(listPtr);//insert item once
				break;
			case 'i'://removes items by index
				removeByIndex(listPtr);//uses the default remove function
				break;
			case 'e'://removes items by entry
				removeByEntry(listPtr);//uses the overloaded remove and contains function
				break;
			case 'r'://replaces items
				replaceItem(listPtr);//uses the replace function
				break;
			case 'E'://search by entry
				searchByEntry(listPtr);//uses getEntry function
				break;
			case 'I'://search by index
				searchByIndex(listPtr);//uses getPosition function and contains function
				break;
			case 'c'://clear list
				clearList(listPtr);
				break;
			case 'd'://display list
				displayList(listPtr);
				break;
			case 'x'://exit
				return false;
		}
		choice=' ';
		showMenu();
		cin>>choice;	
	}/**/
}
int main()
{
	ListInterface<string>* arrayList = new ArrayList<string>();//array list version
	ListInterface<string>* linkList =new LinkedList<string>();//linked list version
	char choice=' ';
	cout<<"(a)rray list implementation "<<endl;
	cout<<"(l)inked list implementation "<<endl;
	cin>>choice;
	switch(choice)
	{
		case 'a':
			cout<<"TESTING ARRAY BASED IMPLEMENTATION"<<endl;
			implementList(arrayList);
		case 'l':
			cout<<"TESTING LINK BASED IMPLEMENTATION"<<endl;
			implementList(linkList);
		case'x':
			exit(0);
	}
   return 0;
}  // end main
/**/
/**/

