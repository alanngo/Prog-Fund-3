/******************************************************************
// Template Program
// Programmer: Alan Ngo
// Completed : November 12 2016
// Status    : Complete
//
// This program will be used to test searching algoritms
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
#include <ctime>
#include <cstdlib>
#include "BinarySearch.cpp"
#include "LinearSearch.cpp"
#include "QuickSort.cpp"
using namespace std;
template<class ItemType>
void display(ItemType a[], int n);

template<class dataType>
void debug(dataType x)
{
	cout<<"******Debug Start******"<<endl;
	cout<<"Value is "<<x<<endl;
	cout<<"******End Debug******"<<endl;
}
void showMenu()
{
	cout<<"__________________________Search Menu__________________________"<<endl;
	cout<<"(l)inear"<<endl;
	cout<<"(b)inary"<<endl;
	cout<<"_______________________________________________________________"<<endl;
}
bool isValidChoice(char ch)
{
	switch(ch)
	{
		case'l':
			return true;
		case'b':
			return true;
	}
	return false;
}//end of isValidChoice

bool isOnMenu(char ch)
{
	switch (ch)
	{
		case'n':
			return true;
		case 'N':
			return true;
		case 'x':
			return true;
	}
	return false;
}
template<class ItemType>
bool search(ItemType list[], int size, ItemType key)
{
	char choice=' ';
	int trialRuns=0;
	int i=0;
	cout<<"Enter the trial runs ";
	cin>>trialRuns;
	cout<<"Enter your choice ";
	cin>>choice;
	bool exists=(linearSearch(list, 0, size, key)>=0&&linearSearch(list, 0, size, key)>=0);
	if (exists)
	{
		while(!isValidChoice(choice))
		{
			cout<<"Enter valid choice ";
			cin>>choice;	
		}
		clock_t start;
		switch (choice)
		{
			{
				case 'l':
					cout<<"processing linear search "<<endl;
					//quickSort(list, 0, size-1);
					start=clock();
					//display(list, size);
					for ( i=1; i<=trialRuns; i++)
					{
						cout<<key<<" is located at index "<<linearSearch(list, 0, size, key)<<endl;
					}
					cout<<"Process Complete within "<<i*(clock()-double(start))/CLOCKS_PER_SEC<<"sec "<<endl;
					debug (size);
					return exists;
				case'b':
					cout<<"processing binary search "<<endl;
					quickSort(list, 0, size-1);
					start=clock();
					display(list, size);
					for ( i=1; i<=trialRuns; i++)
					{
						cout<<key<<" is located at index "<<binarySearch(list, 0, size, key)<<endl;
					}
					cout<<"Process Complete within "<<i*(clock()-double(start))/CLOCKS_PER_SEC<<"sec "<<endl;
					debug(size);
					return exists;
			}
		}
	}
	else
	{
		cout<<"ENTRY DOES NOT EXIST ON THE LIST "<<endl;
		return exists;
	}
	return exists;
	
}//end of search

int getNumEntries()//determine the number of lines
{
	ifstream infile;
	string line="";
	int count=0;
	infile.open("LastName.txt");
	if(infile.is_open())
	{
		while (getline(infile, line))
		count++;
	}
	else
	{
		cout<<"No file found"<<endl;
	}
	infile.close();
	return count;
}//end of getNumEntries

template<class ItemType>
void scan(ItemType a[], int n)//read from file
{
	ifstream infile;
	ItemType temp;
	int count=0;
	infile.open("LastName.txt");
	infile>>temp;
	while(infile && count<n)
	{
		a[count]=temp;;
		count++;
		infile>>temp;
	}
	infile.close();
}//end of scan

void generate(int a[], int n)//random number generator
{
	for (long int i=0; i<n; i++)
	{
		a[i] = (rand());
	}
}//end of generate

template<class ItemType>
void display(ItemType a[], int n)//random number generator
{
	ofstream outfile;
	outfile.open("result.txt");
	for (long int i=0; i<n; i++)
	{
		//cout<<i<<". "<<a[i]<<endl;
		outfile<<i<<". "<<a[i]<<endl;
	}
	cout<<"Results written to file"<<endl;
	outfile.close();
}//end of display

void searchInts()
{
	int key=0;
	int size=0;
	cout<<"How many numbers do you want to generate ";
	cin>>size;
	int *list =new int[size];
	generate(list, size);
	showMenu();
	cout<<"Enter a key to search for ";
	cin>>key;
	search(list, size, key);
	display(list, size);
	delete [] list;
	list=NULL;
}//end of searchInts()

void searchStrings()
{
	string key="";
	long long int size=getNumEntries();
	string list[size];
	//debug(size);
	scan(list, size);
	cout<<"Enter the key you want to search for ";
	cin>>key;
	showMenu();
	search(list, size, key);
	//display(list, size);
}//end of searchStrings

int main()						
{ 

	char again='y';
	char choice=' ';
	while (again=='y')
	{
		cout<<"Search (n)umbers or (N)ames? ";
		cin>>choice;
		while(!isOnMenu(choice))
		{
			cout<<"Enter a valid choice";
			cin>>choice;
		}
		switch(choice)
		{
			case 'n':
				searchInts();
				cout<<"Done!"<<endl;
				break;
			case 'N':
				searchStrings();
				cout<<"Done!"<<endl;
				break;	
			case'x':
				exit(0);
		}
		cout<<"go again? ";
		cin>>again;
	}
			
 return 0;
}   // end of main function
