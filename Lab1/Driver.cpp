//******************************************************************
// Template Program
// Programmer: Alan Ngo
// Completed : January 24 2017
// Status    : Complete
//
// 
//******************************************************************
/* This program will be used to store a message in a string then
//print out the encrypted form and unencrypted form.*/
#include <iostream>				// for cin, cout, endl
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include "EncryptedString.h"

using namespace std;

int main()						
{ 
EncryptedString x;
x.set("");
cout<<"Empty string not encrypted: "<<x.get()<<endl;
cout<<"Empty string encrypted: "<<x.getEncrypted()<<endl;
cout<<endl;

x.set("abcd");
cout<<"'abcd' not encrypted: "<<x.get()<<endl;
cout<<"'abcd' encrypted: "<<x.getEncrypted()<<endl;
cout<<endl;

x.set("Hi Mom!");
cout<<"Hi Mom not encrypted: "<<x.get()<<endl;
cout<<"Hi Mom encrypted: "<<x.getEncrypted()<<endl;
cout<<"Note the '!' is illegal and removed"<<endl; 
 return 0;
}   // end of main function
