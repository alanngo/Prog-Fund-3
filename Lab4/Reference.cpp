//******************************************************************
// Template Program
// Programmer: Alan Ngo
// Completed : November 12 2016
// Status    : Complete
//
// This program will be used to... 
//******************************************************************
/* PROMPT*/
#include <iostream>				// for cin, cout, endl
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include "ArrayStack.h"
using namespace std;

template<typename dataType>
void debug(dataType x)
{
	cout<<"******Debug Start******"<<endl;
	cout<<"Value is "<<x<<endl;
	cout<<"******End Debug******"<<endl;
}

// Checks for valid operator
bool isOperator(char);

// Check for valid numeric digit
bool isDigit(char);

// Calculate Expression
int performCalculation(int, int, char);


int main()
{
  ArrayStack<int> stack;
  string postfix;
  char valid;
  int num, op1, op2, result;
  bool error = false;
  bool again = true;


  while (again)
  {
  	cout << "Enter Postfix Expression: " << endl;
  	cin.sync();
    getline(cin, postfix);
  	
	for (int i = 0; i < postfix.length(); i++)
  	{
    	if (postfix[i] == ' ')
      		continue;
	
    	else if (isDigit(postfix[i]))
		{
    		num = (postfix[i] - 48);
       		stack.push(num);
        }
	
		else if (!(isOperator(postfix[i])))
		{
			cout << postfix[i] << " is an invalid character" << endl << endl;
			error = true;
			break;
		}
	
    	else if (isOperator(postfix[i]))
   	 	{      	
			try	{
				op1 = stack.peek();
      			stack.pop();
      			op2 = stack.peek();
      			stack.pop();
      			stack.push(performCalculation(op1, op2, postfix[i]));
		    }
		
			catch(runtime_error& e )
			{
				error = true;
				cout << e.what() << endl <<endl;
				break;
			}
		}
	
  	 }
  	if (error)
  	{
  		cout << "Another Calculation? (Y or N): ";
		cin >> valid;
	
		if (valid == 'Y' || valid == 'y')
		{
			again = true;
		}

		else if (valid == 'N' || valid == 'n')
		{
			again = false;
			cout << "Exiting....";
		}
		else
		{
			cout << "Invalid key pressed..Exiting..." << endl;
			again = false;
		}
  	}
  	else
  	{
  		result = stack.peek();
  		stack.pop();
  		
  		if (stack.isEmpty())
  		{
  			cout << "Value: " << result << endl << endl;
  		}
  		else
  		{
  			cout << "Malformed Expression " << endl << endl;
  			while (!stack.isEmpty())
  			{
  				stack.pop();
  				stack.isEmpty();
  			}
  		}
  		
  		cout << "Another Calculation? (Y or N): ";
		cin >> valid;
	
		if (valid == 'Y' || valid == 'y')
		{
			again = true;
		}

		else if (valid == 'N' || valid == 'n')
		{
			again = false;
			cout << "Exiting....";
		}
	
		else
		{
			cout << "Invalid key pressed..Exiting..." << endl;
			again = false;
		}
  	}
	error = false;
	cout << endl; 
}
  return 0;
}


bool isOperator(char ch)
{
  if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    return true;

  else
    return false;
}


bool isDigit(char ch)
{
  if (ch >= '0' && ch <= '9')
    return true;
  
  else
    return false;
}

int performCalculation(int num1, int num2, char op)
{
  int answer;

  switch(op)
  {
    case '+':
      answer = num2 + num1;
      break;
    case '-':
      answer = num2 - num1;
      break;
    case '*':
      answer = num2 * num1;
      break;
    case '/':
      answer = num2 / num1;
      break;
  }
  
  return answer;
}
