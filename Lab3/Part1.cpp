/******************************************************************
// Template Program
// Programmer: Alan Ngo
// Completed : Febuary 21 2017
// Status    : Complete
//
// This program will be used to raise a base to a power using recursion
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
using namespace std;
double power(double a, int n);
int main()						
{ 

	double base=0;
	int exponent=0;
	
	for (int n=0; n<3; n++)
	{
		cout<<"Enter base ";
		cin>>base;
		
		cout<<"Enter exponent ";
		cin>>exponent;
		
		cout<<base<<" raised to  "<<exponent<<" = "<<power(base, exponent)<<endl;
	}

	
	
 return 0;
}   // end of main function

double power(double a/*base*/, int n/*exponent*/)
{
	
	if (n>1)
	{
		return a*power(a,(n-1));
	}	
	if (n<1)
	{
		return (1/a)*power(a, n+1);
	}
	if (n==0)
	{
		return 1;
	}

	return a;

}//end of power
