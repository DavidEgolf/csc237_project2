//
//  main.cpp
//  csc237_project2
//
//  Created by David Egolf on 3/28/12.
//  Copyright (c) 2012 David Egolf. All rights reserved.
//
#define TRUE true
#define FALSE false

#include <iostream>
#include <stack>

using namespace std;

void getExpression(string & expression);
bool evaluateParenthesis(string);
string evalPostfix(string);
bool isNumeric(char);
bool isOperator(char);
bool isHigherOp(char, char);

int main (int argc, const char * argv[])
{
    cout << "0.0.1\n";
    
    string expressionString;
    
    getExpression(expressionString);
    while(expressionString != "0")
    {
	    if(evaluateParenthesis(expressionString))
		{
	    	cout << "Parenthesis matched.\n";
			cout << evalPostfix(expressionString);
		}
	    else
	        cout << "Parenthesis mismatched.\n";

    	getExpression(expressionString);
	}
    
    return 0;
}

void getExpression(string & expression)
{
    cout << "Enter expression (0 to exit): ";
    getline(cin, expression);
}

bool evaluateParenthesis(string inputString)
{
    stack<char> parenthesis;
    
    for(int i = 0; i < inputString.size(); i++)
    {
        if(inputString[i] == '(')
            parenthesis.push(inputString[i]);
    }
    
    for(int i = 0; i < inputString.size(); i++)
    {
        if (inputString[i] == ')') 
        {
            parenthesis.pop();
        }
    }
    
    if (parenthesis.size())
        return FALSE;
    else
        return TRUE;
}

string evalPostfix(string expression)
{
    stack<char> operators;
	string postFix = "";
		
	for(int i = 0; i < expression.length(); i++)
	{
		if(isOperator(expression[i]))
		{
			if(!operators.size())
			{	
				//cout << "pushing " << expression[i] << endl;	
				operators.push(expression[i]);
			}
			else
			{
				if(!isHigherOp(operators.top(), expression[i]))
				{
					//cout << "pushing " << expression[i] << endl;
					operators.push(expression[i]);
				}
				else
				{
					//cout << "popping " << operators.top() << endl;
					postFix = postFix + expression[i] + operators.top();
					operators.pop();
				}
			}
		}
	}
	while(operators.size())
	{
		//cout << operators.size();
		postFix = postFix + operators.top();
		operators.pop();
	}
	return postFix;
}

bool isNumeric(char charToCompair)
{
    for(int i = 48; i < 58; i++)
    {
        if((int)charToCompair == i) 
        {
            return TRUE;
        }
    }
    return FALSE;
}

bool isOperator(char charToCompair)
{
    switch (charToCompair) 
    {
        case '+':
        case '-':
        case '*':
        case '/':
            return TRUE;
        default:
            return FALSE;
    }
}

bool isHigherOp(char firstOp, char secondOp)
{
	int firstPrec = 1, secondPrec = 1;
	if(firstOp == '+' || firstOp == '-')
		firstPrec = 0;
	if(secondOp == '+' || secondOp == '-')
		secondPrec = 0;
	return secondPrec >= firstPrec;
}

