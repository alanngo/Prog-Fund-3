/******************************************************************
// Template Program
// Programmer: Alan Ngo
// Completed : April 26 2017
// Status    : Complete
//
// This program will be used to do timely studies w/ different sorting algorithms
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
#include "InsertionSort.cpp"
#include "MergeSort.cpp"
#include "SelectionSort.cpp"
#include "QuickSort.cpp"
#include "BubbleSort.cpp"
#include "ShellSort.cpp"
#include "RadixSort.cpp"
#include "HeapSort.cpp"
using namespace std;

template<class ItemType>
void debug(ItemType x)
{
	cout<<"******Debug Start******"<<endl;
	cout<<"Value is "<<x<<endl;
	cout<<"******End Debug******"<<endl;
}//end of debug

bool isDigit(char ch)
{
	if (ch>=0&&ch<=9)
	{
		return true;
	}
	return false;
}
/*-----------------------------------------------------------------*/
template <class ItemType>
void populate(ItemType a[], int n)//read from keyboard
{
		for (long int i=0; i<n; i++)
	{
		cout<<"Enter the elements ";
		cin>>a[i];
	}
}//end of populate

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
}
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

template<class ItemType>
void generate(ItemType a[], int n)//random number generator
{
	for (long int i=0; i<n; i++)
	{
		a[i] = (rand());
	}
}

template<class ItemType>//displays the list
void display(ItemType a[], int n)
{
	for (int i=0; i<n; i++)
	{
		cout<<i+1<<". "<<a[i]<<endl;
	}
}//end of display

template <class ItemType>
void writeToFile(ItemType a[],  int n, string method)//overloaded display function that writes to file
{
	ofstream outfile;
	outfile.open("result2.txt");
	outfile<<"______________________________________"<<endl;
	outfile<<"Method used: "<<method<<" Sort"<<endl;
	outfile<<"______________________________________"<<endl;
	for (int i=0; i<n; i++)
	{
		outfile<<i+1<<". "<<a[i]<<endl;
	}
	outfile.close();
}//end of overloaded display
void displayMenu()
{
	cout<<"______________________________________"<<endl;
	cout<<"(i)nsertion"<<endl;
	cout<<"(m)erge"<<endl;
	cout<<"(s)election"<<endl;
	cout<<"(q)uick"<<endl;
	cout<<"(b)ubble"<<endl;
	cout<<"(S)hell"<<endl;
	cout<<"(r)adix"<<endl;
	cout<<"(h)eap"<<endl;
	cout<<"________________________________________________"<<endl;
}//end of displayMenu

bool isValidChoice(char ch)
{
	switch (ch)
	{
		case 'i':
			return true;
		case 'm':
			return true;
		case 's':
			return true;
		case 'q':
			return true;
		case 'b':
			return true;
		case 'S':
			return true;
		case 'r':
			return true;
		case 'h':
			return true;
	}
	return false;
}//end of isValidChoice

template<class ItemType>
bool sort(ItemType arr[], int quantity)//different sorting methods
{
	char choice=' ';
	int first=0;
	int last=quantity-1;
	int i=0;
	int trialRuns=0;
	
	
	cout<<"Enter the trial runs";
	cin>>trialRuns;
	while(!isDigit(trialRuns))
	{
		cout<<"Enter a number";
		cin>>trialRuns;
	}
	cout<<"choose a sort method ";
	cin>>choice;
	while (!isValidChoice(choice))
	{
		cout<<"choose a valid sort method ";
		cin>>choice;
	}
	clock_t start;
		switch (choice)
	{
		case 'i':
			start=clock();
			for ( i=1; i<=trialRuns; i++)
			{
				//start=clock();
				cout<<"Insertion Sort"<<endl;
				cout<<"processing..."<<endl;
				insertionSort(arr, quantity);
				writeToFile(arr,  quantity, "Insertion");
				cout<<"Process Complete within "<<(clock()-double(start))/CLOCKS_PER_SEC<<"sec "<<endl;
				cout<<"Results written to result2.txt" <<endl;
			}
			//cout<<"Process Complete within "<<i*(clock()-double(start))/CLOCKS_PER_SEC<<"sec "<<endl;
			/**/return true;
		case 'm':
			start=clock();
			for (i=1; i<=trialRuns; i++)
			{
				//start=clock();
				cout<<"Merge Sort"<<endl;
				cout<<"processing..."<<endl;
				mergeSort(arr, first, last);
				writeToFile(arr,  quantity, "Merge");
				//cout<<"Process Complete within "<<(clock()-double(start))/CLOCKS_PER_SEC<<"sec "<<endl;
				cout<<"Results written to result2.txt" <<endl;
			}
			cout<<"Process Complete within "<<i*(clock()-double(start))/CLOCKS_PER_SEC<<"sec "<<endl;
			/**/return true;
		case 's':
			start=clock();
			for (i=1; i<=trialRuns; i++)
			{
				//start=clock();
				cout<<"Selection Sort"<<endl;
				cout<<"processing..."<<endl;
				selectionSort(arr, quantity);
				writeToFile(arr,  quantity, "Selection");
				//cout<<"Process Complete within "<<(clock()-double(start))/CLOCKS_PER_SEC<<"sec "<<endl;
				cout<<"Results written to result2.txt" <<endl;
			}
			cout<<"Process Complete within "<<i*(clock()-double(start))/CLOCKS_PER_SEC<<"sec "<<endl;
			/**/return true;
		case 'q':
			start=clock();
			for (i=1; i<=trialRuns; i++)
			{			
				//start=clock();
				cout<<"Quick Sort"<<endl;
				cout<<"processing..."<<endl;
				quickSort(arr, first, last);
				writeToFile(arr,  quantity, "Quick");
				//cout<<"Process Complete within " <<(clock()-double(start))/CLOCKS_PER_SEC<<"sec "<<endl;
				cout<<"Results written to result2.txt" <<endl;
			}
			cout<<"Process Complete within "<<i*(clock()-double(start))/CLOCKS_PER_SEC<<"sec "<<endl;

			/**/return true;
		case 'b':
			start=clock();
			for (i=1; i<=trialRuns; i++)
			{			
				//start=clock();
				cout<<"Bubble Sort"<<endl;
				cout<<"processing..."<<endl;
				bubbleSort(arr, quantity);
				writeToFile(arr,  quantity, "Bubble");
				//cout<<"Process Complete within "<<(clock()-double(start))/CLOCKS_PER_SEC<<"sec "<<endl;
				cout<<"Results written to result2.txt" <<endl;
			}
			cout<<"Process Complete within "<<i*(clock()-double(start))/CLOCKS_PER_SEC<<"sec "<<endl;
			/**/return true;
		case 'S':
			start=clock();
			for (i=1; i<=trialRuns; i++)
			{
				//start=clock();
				cout<<"Shell Sort"<<endl;
				cout<<"processing..."<<endl;
				shellSort(arr, quantity);
				writeToFile(arr,  quantity, "Shell");
				//cout<<"Process Complete within "<<(clock()-double(start))/CLOCKS_PER_SEC<<"sec "<<endl;
				cout<<"Results written to result2.txt" <<endl;
			}
			cout<<"Process Complete within "<<(clock()-double(start))/CLOCKS_PER_SEC<<"sec "<<endl;
			/**/return true;
		case 'r':
			for (i=1; i<=trialRuns; i++)
			{
				start=clock();
				cout<<"Radix Sort"<<endl;
				cout<<"processing..."<<endl;
				radixSort(arr, quantity);
				writeToFile(arr,  quantity, "Radix");
				cout<<"Process Complete within"<<(clock()-double(start))/CLOCKS_PER_SEC<<"sec "<<endl;
				cout<<"Results written to result2.txt" <<endl;
			}
			cout<<"Process Complete within "<<i*(clock()-double(start))/CLOCKS_PER_SEC<<"sec "<<endl;
			return true;
		case 'h':
			start=clock();
			for (i=1; i<=trialRuns; i++)
			{
				//start=clock();
				cout<<"Heap Sort"<<endl;
				cout<<"processing..."<<endl;
				heapSort(arr, quantity);
				writeToFile(arr,  quantity, "Heap");
				//cout<<"Process Complete within "<<(clock()-double(start))/CLOCKS_PER_SEC<<"sec! "<<endl;
				cout<<"Results written to result2.txt" <<endl;
			}
			cout<<"Process Complete within "<<i*(clock()-double(start))/CLOCKS_PER_SEC<<"sec "<<endl;
			/**/return true;
	}
	/**/return false;
}
void sortNumbers()//sort num
{
	long long int n=0;
	cout<<"How many numbers do you want to generate? "<<endl;
	cin>> n;
	int* list = new int[n];
	generate(list, n);
	displayMenu();
	sort(list, n);
	delete [] list;
	list=NULL;
}



void sortNames()//sort string
{
	long long int n=getNumEntries();
	string list[n];
	scan(list, n);
	displayMenu();
	sort(list, n);
}
int main()						
{
	char choice=' ';
	char again='y';
	cout<<"Sort (n)umbers or (N)ames? ";
	cin>>choice;
	while (again=='y')
	{
		switch (choice)
		{
			case 'n':
				cout<<"Sorting numbers"<<endl;
				sortNumbers();
				break;
			case 'N':
				cout<<"Sorting names"<<endl;
				sortNames();
				break;
			case'x':
				exit(0);
		}
		cout<<"go again? (y)es";
		cin>>again;
	}

 return 0;
}   // end of main function
