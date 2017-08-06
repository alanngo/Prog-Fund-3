#ifndef EncryptedString_H
#define EncryptedString_H
#include <iostream>				// for cin, cout, endl
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include <iomanip>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
class EncryptedString
{
	private:
		string field;
		
	public:
		//constructor
		EncryptedString();
		EncryptedString(string s);
		
		//get
		string get() const;
		string getEncrypted() const;
		
		//set
		void set(string inString);	
};//end of class
#include "EncryptedString.cpp"
#endif 

