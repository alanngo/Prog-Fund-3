#include <iostream>				// for cin, cout, endl
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include "EncryptedString.h"
using namespace std;

EncryptedString::EncryptedString()
{
	field="";
}//end of default constructor

EncryptedString::EncryptedString(string s)
{
	set(s);
}//end of constructor

string EncryptedString::get() const//returns original statement
{
	return field;
}//end of get

string EncryptedString::getEncrypted() const//encrypts and returns encrypted string
{
	string encryptedString = "";
	
	for(int i=0; i<field.length(); i++)
	{
		char ch = field[i];
		if (ch == 'Z')
		{
			ch = 'A';
			encryptedString += ch;
		}
		else if (ch == 'z')
		{
			ch = 'a';
			encryptedString += ch;
		}
		else if (isalpha(ch))
		{
			ch++;
			encryptedString += ch;
		}
		else if (ch == ' ')
		{
			encryptedString += ch;
		}
	}
	return encryptedString;
}//end of getEncrypted

void EncryptedString::set(string inString)//inputs the string
{
	field=inString;
}//end of set
