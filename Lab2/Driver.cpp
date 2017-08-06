/******************************************************************
// Template Program
// Programmer: Alan Ngo
// Completed : January 30 2017
// Status    : Complete
//
// This program will be used to test the ArrayBag header file
//******************************************************************/

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
void display(ArrayBag<ItemType>& bag)
{
	 cout << "The bag contains " << bag.getCurrentSize()<< " items:" <<  endl;
    vector<ItemType> bagItems = bag.toVector();
   
   int numberOfEntries = (int) bagItems.size();
   for (int i = 0; i < numberOfEntries; i++)
   {
       cout << bagItems[i] << " ";
   }  // end for
	 cout <<  endl <<  endl;
}  // end displayBag

void bagTester(ArrayBag< string>& bag)
{
    cout << "isEmpty: returns " << bag.isEmpty() 
        << "; should be 1 (true)" <<  endl;
   //displayBag(bag);

	 string items[] = {"one", "two", "three", "four", "five", "one"};
    cout << "Add 6 items to the bag: " <<  endl;
	for (int i = 0; i < 6; i++)
    {
		bag.add(items[i]);
	}  // end for
   
   //displayBag(bag);
   
    cout << "isEmpty: returns " << bag.isEmpty() 
        << "; should be 0 (false)" <<  endl;
	
    cout << "getCurrentSize: returns " << bag.getCurrentSize() 
        << "; should be 6" <<  endl;
   
    cout << "Try to add another entry: add(\"extra\") returns " 
        << bag.add("extra") <<  endl;      
   
    cout << "contains(\"three\"): returns " << bag.contains("three")
        << "; should be 1 (true)" <<  endl;
    cout << "contains(\"ten\"): returns " << bag.contains("ten")
        << "; should be 0 (false)" <<  endl;
    cout << "getFrequencyOf(\"one\"): returns "
        << bag.getFrequencyOf("one") << " should be 2" <<  endl;
    cout << "remove(\"one\"): returns " << bag.remove("one")
        << "; should be 1 (true)" <<  endl;
    cout << "getFrequencyOf(\"one\"): returns "
        << bag.getFrequencyOf("one") << " should be 1" <<  endl;
    cout << "remove(\"one\"): returns " << bag.remove("one")
        << "; should be 1 (true)" <<  endl;
    cout << "remove(\"one\"): returns " << bag.remove("one")
        << "; should be 0 (false)" <<  endl;
    cout <<  endl;
   
   //displayBag(bag);
   
    cout << "After clearing the bag, ";
   bag.clear();
   
    cout << "isEmpty: returns " << bag.isEmpty()<< "; should be 1 (true)" <<  endl;
}  // end bagTester


int main()
{	
	ArrayBag<string> electronics;
	ArrayBag<string> groceries;
	ArrayBag<string> combined;
	ArrayBag<string> augmentUnion;
	ArrayBag<string> intersection;
	ArrayBag<string> difference;
	
	string items[3];
	string items1[3];
	
	for (int i=0; i<3; i++)
	{
		cout<<"Enter item for electronics ";
		cin>>items[i];
		electronics.add(items[i]);
	}
	
	for (int i=0; i<3; i++)
	{
		cout<<"Enter item for groceries ";
		cin>>items1[i];
		groceries.add(items1[i]);
	}
	
	combined=electronics.bagUnion(groceries);
	augmentUnion=electronics.augmentedBagUnion(groceries);
	intersection=electronics.bagIntersection(groceries);
	difference=electronics.bagDifference(groceries);
	
	display(combined);
	display(augmentUnion);
	display(intersection);
	display(difference);
	/**/
	/*ArrayBag<char>bag1;//first bag
	ArrayBag<char>bag2;//second bag
	ArrayBag<char>bag3;//union bag
	ArrayBag<char>bag4;//augmented union bag
	ArrayBag<char>bag5;//intersection bag
	ArrayBag<char>bag6;//difference bag
	char items1[]={'a','a','b','c'};
	char items2[]={'a','g'};

	//union
	for (int i=0; i<4; i++)
	{
		bag1.add(items1[i]);
	}
	
	for (int i=0; i<2; i++)
	{
		bag2.add(items2[i]);
	}

	cout<<"***********************Testing Union***********************"<<endl;
	cout<<endl;
	
	cout<<"Bag 1 contents"<<endl;
	display(bag1);
	cout<<"Bag 2 contents"<<endl;
	display(bag2);
	
	cout<<"Bag Union (this DOES NOT removes duplicates)"<<endl;
	bag3=bag1.bagUnion(bag2);
	display(bag3);
	
	cout<<"Augmented Bag Union (this removes duplicates)"<<endl;
	bag4=bag1.augmentedBagUnion(bag2);
	display(bag4);
	
	//intersection
	ArrayBag<char>bagA;
	ArrayBag<char>bagB;
	char items3[]={'a','a','b','c','d'};
	char items4[]={'a','b','b','c','g'};
	
	for (int i=0; i<5; i++)
	{
		bagA.add(items3[i]);
	}
	
	for (int i=0; i<5; i++)
	{
		bagB.add(items4[i]);
	}
	cout<<"***********************Testing Intersection***********************"<<endl;
	cout<<endl;
	cout<<"Bag 1 contents"<<endl;
	display(bagA);
	cout<<"Bag 2 contents"<<endl;
	display(bagB);
	
	cout<<"Bag Intersection"<<endl;
	bag5=bagA.bagIntersection(bagB);
	display(bag5);

	//difference
	ArrayBag<char>bagC;
	ArrayBag<char>bagD;
	char items5[]={'a','b','c','d'};
	char items6[]={'b','c'};
	
	for (int i=0; i<4; i++)
	{
		bagC.add(items5[i]);
	}
	
	for (int i=0; i<2; i++)
	{
		bagD.add(items6[i]);
	}
	cout<<"***********************Testing Difference***********************"<<endl;
	cout<<endl;
	cout<<"Bag 1 contents"<<endl;
	display(bagC);
	cout<<"Bag 2 contents"<<endl;
	display(bagD);
	
	cout<<"Bag Difference"<<endl;
	bag6=bagC.bagDifference(bagD);
	display(bag6);
	/**/
	cout<<"All Done!";
   return 0;
}  // end main


/*
 Testing the Array-Based Bag:
 The initial bag is empty.
 isEmpty: returns 1; should be 1 (true)
 The bag contains 0 items:
 
 
 Add 6 items to the bag:
 The bag contains 6 items:
 one two three four five one
 
 isEmpty: returns 0; should be 0 (false)
 getCurrentSize: returns 6; should be 6
 Try to add another entry: add("extra") returns 0
 contains("three"): returns 1; should be 1 (true)
 contains("ten"): returns 0; should be 0 (false)
 getFrequencyOf("one"): returns 2 should be 2
 remove("one"): returns 1; should be 1 (true)
 getFrequencyOf("one"): returns 1 should be 1
 remove("one"): returns 1; should be 1 (true)
 remove("one"): returns 0; should be 0 (false)
 
 The bag contains 4 items:
 five two three four
 
 After clearing the bag, isEmpty: returns 1; should be 1 (true)
 All done!
 */ 
