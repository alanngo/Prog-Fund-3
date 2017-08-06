/******************************************************************
// Template Program
// Programmer: Alan Ngo
// Completed : November 12 2016
// Status    : Complete
//
// This program will be used test the program
******************************************************************/

#include <iostream>				// for cin, cout, endl
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include "ArrayList.h"
#include "LinkedList.h"
#include "ListInterface.h"

using namespace std;

template<typename dataType>
void debug(dataType x)
{
	cout<<"******Debug Start******"<<endl;
	cout<<"Value is "<<x<<endl;
	cout<<"******End Debug******"<<endl;
}//end of debug 
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
int main()						
{ 

	ListInterface<string>* arrayList = new ArrayList<string>();//array list version
	ListInterface<string>* linkList =new LinkedList<string>();//linked list version
	arrayList->insert(1, "Bullshit");
	displayList(arrayList);
	cout<<arrayList->contains("Bullshit");
	
	
	
 return 0;
}   // end of main function
