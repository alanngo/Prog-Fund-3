/******************************************************************
// Template Program
// Programmer: Alan Ngo
// Completed : November 12 2016
// Status    : Complete
//
// This program will be used...
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
#include <cassert>
#include "ArrayStack.h"
#include <stack>
#include <cstring>
#include "StackInterface.h"
using namespace std;

template<typename dataType>
void debug(dataType x)
{
	cout<<"******Debug Start******"<<endl;
	cout<<"Value is "<<x<<endl;
	cout<<"******End Debug******"<<endl;
}

//postfix to infix related functions
bool isOperator(char ch)
{
    if (ch=='+' || ch=='-' || ch=='*' || ch=='/')
    {
    	return true;
	}   
    return false;
}
bool isDigit(char ch)
{
	if (ch>='0'&&ch<='9')
	{
		return true;
	}
	
return false;
}
int performOperation(int op1, int op2, char op)
{
    int ans;
    switch(op)
	{
    case '+':
        ans = op2 + op1;
        break;
    case '-':
        ans = op2 - op1;
        break;
    case '*':
        ans = op2 * op1;
        break;
    case '/':
        ans = op2 / op1;
        break;
    }
    return ans;
}
// convert postfix expression to infix using a stack
void postfix2Infix()
{
	char exp[1000]; //expression
	char buffer[15];
    int op1=0;//first operand 
	int op2=0;//second operand
	int len, x;
    ArrayStack<int> s;//stack expression
    int j = 0;
    bool hasError=false; // decides whether to do calculations
    
    cout<<"Enter a Postfix Expression: ( e.g. 2 3 + 4 * )\n";
    cin >> exp;
    len = strlen(exp);

    for(int i=0; i<len;i++)//goes through expression
	{

        if(isDigit(exp[i]))
		{
            buffer[j++] = exp[i];
        }

        else if(exp[i]==' ')//pushes the expression into the stack
		{
            if(j>0)
			{
                buffer[j] = '\0';
                x = atoi(buffer);
                s.push(x);
                j = 0;
            }
        }

        else if(!isOperator(exp[i]))//if any illegal characters are entered
        {
		
        	cout<<"ERROR - Invalid character/operand/operator detected!"<<endl;
        	hasError=true;
        	break;
		}

        else if(isOperator(exp[i]))// does the calculations
		{
			if (s.isEmpty())
			{
				cout<<"Malformed Expression - Invald Postfix!"<<endl;
				hasError=true;
				break;
			}
            op1 = s.peek();
            s.pop();
            if (s.isEmpty())
			{
				cout<<"Malformed Expression - Invald Postfix"<<endl;
				hasError=true;
				break;
			}
            op2 = s.peek();
            s.pop();
            s.push(performOperation(op1, op2, exp[i]));
        }
    }//end of for loop
	
	
	if (!hasError)
	{
		if (s.isEmpty())// if the stack is empty error
		{
			cout<<"Empty Expression! "<<endl;
		}
		else
		{
			printf("Answer is %d\n", s.peek());	
		}

	}
}

//infix to postfix related functions
int getWeight(char ch) 
{
   switch (ch) 
   {
      case '/': 
      case '*': return 2;
      case '+': 
      case '-': return 1;
      default : return 0;
   }
}
bool isOpenParen(char ch)
{
	if (ch=='(')
	{
		return true;
	}

return false;
}
bool isCloseParen(char ch)
{
	if (ch==')')
	{
		return true;
	}

return false;
}
// convert infix expression to postfix using a stack
void infix2Postfix() 
{
   ArrayStack<char> s;
   int k = 0;
   char ch;	
   char infix[20] = "";
   
   cout <<"Enter the Infix Expression \n";
   cin.getline (infix, 20);
 
   int size = strlen(infix);
   char postfix[size];
   // iterate over the infix expression  
    
   for (int i =0; i < size; i++) 
   {
      ch = infix[i];
      if (isOpenParen(ch)) //opening parenthesis detected
	  {
         // push opening parenthesis
         s.push(ch);
         continue;
      }
      if (isCloseParen(ch)) //closing parenthesis detected
	  {
         while (!s.isEmpty() && !isOpenParen(s.peek()))//not empty expression and no open parenthises
		 {
            postfix[k++] = s.peek();
            s.pop(); 
		 }
         // pop off the opening parenthesis also
         if (!s.isEmpty())
		 {
            s.pop();
		 }
         continue;
      }
      if (getWeight(ch) == 0) 
	  {
         postfix[k++] = ch;// append it to postfix expression
      }
      else 
	  {
         if (s.isEmpty()) 
		 {
            s.push(ch);
         }
         else 
		 { //pops all operators until they are arranged in a postfix manner
            while (!s.isEmpty() && !isOpenParen(s.peek()) && getWeight(ch) <= getWeight(s.peek())) 
			{
				postfix[k++] = s.peek();
	            s.pop();
            }
            // push the current operator onto stack
            s.push(ch);
         }
      }
   }
 
   // pops remaining operators and appends it to expression 
   while (!s.isEmpty()) 
   {
      postfix[k++] = s.peek();
      s.pop();
   }
	postfix[k] = 0; // null terminate the postfix expression

	cout<<"Infix Expression :: "<<infix;
	cout<<"\nPostfix Expression :: "<<postfix; 
	cout<<endl;

}//end of i2P	

int main() 
{
	string again="y";
	string again2="y";
	
	while (again=="y")
	{
		postfix2Infix();
		cin.clear();
		cout<<"Go again? (y)es ";
		cin>>again;
		cin.ignore();
	}
	while (again2=="y")
	{
		infix2Postfix();
		cin.clear();
		cout<<"Go again? (y)es ";
		cin>>again2;
		cin.ignore();
	}
   return 0;
}// end main
