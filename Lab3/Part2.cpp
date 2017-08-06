/******************************************************************
// Template Program
// Programmer: Alan Ngo
// Completed : Febuary 13 2017
// Status    : Complete
//
// This program will be used to test the factorial function using both
iterative and recursive functions
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
using namespace std;

//prototypes
int recursiveFactorial(int);
int iterativeFactorial(int);
void input(int&, long long int&);
void output(int&, long long int&, double, double);
void determineEfficiency(double, double);

int main()						
{ 
	cout << fixed << showpoint << setprecision (2);
	long int test = 0;
	
	long long int trialRuns=0;
	int x=0;
	
	clock_t start;
	double recursiveTime=0;
	double iterativeTime=0;
	
	char again='y';
	while(again=='y')
	{
	
		input(x, trialRuns);
		
		start=clock();
		for (int n = 0; n <trialRuns; n++) 
		{
			test=recursiveFactorial(x);
			//cout<<test<<endl;
		}
		recursiveTime=(clock()-double(start))/CLOCKS_PER_SEC;
		/*______________________________________________________*/
		start=clock();
		for (int n=0; n<trialRuns; n++)
		{
			test=iterativeFactorial(x);
			//cout<<test<<endl;
		}
		iterativeTime=(clock()-double(start))/CLOCKS_PER_SEC;
		
		output(x, trialRuns, recursiveTime, iterativeTime);
		determineEfficiency(recursiveTime, iterativeTime);
		/*______________________________________________________*/
		cout<<"Do you want to run it again? ";
		cin>>again;
	}


 return 0;
}   // end of main function

int recursiveFactorial(int x)
{
	if (x==0)//base case x=0
	{
		return 1;
	}
	else//recursive case OTHERWISE
	{
		return x* recursiveFactorial(x-1);
	}
}//end of recursive factorial

int iterativeFactorial(int x)
{
	int product=1;
	for (int i=1; i<=x; i++)
	{
		product*=i;
	}
	return product;
}//end of iterativeFactorial

void determineEfficiency(double recur, double iter)
{
	double diff=0;
	diff=abs(recur-iter);
	if (recur<iter)
	{
		cout<<"Recursion is more effective by "<<diff<<" sec"<<endl;
	}
	else if (recur>iter)
	{
		cout<<"Iteration is more effective by "<<diff<<" sec"<<endl;
	}
	else
	{
		cout<<"Neither one is more effective than the other"<<endl;
	}
}//end of determineEfficiency

void input(int &x, long long int &trialRuns)
{
	cout<<"Enter the number of trial runs ";
	cin>>trialRuns;
	cout<<"Enter the number to take factorial ";
	cin>>x;
	cout<<"Processing..."<<endl;
}//end of input

void output(int&x, long long int& trialRuns, double recur, double iter)
{
   cout<<"*********************************************"<<endl;
   cout<<"Trial Runs: "<<trialRuns<<endl;
   cout<<"Number used: "<<x<<endl;
   cout<<"Recursive version: "<<recur<<endl;
   cout<<"Iterative version: "<<iter<<endl;
   cout<<"*********************************************"<<endl;
}//end of output

