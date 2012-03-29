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
void printPostfix(string);
bool isNumeric(char);
bool isOperator(char);


int main (int argc, const char * argv[])
{
    cout << "0.0.1\n";
    
    string expressionString;
    stack<char> operators;
    stack<double> numbers;
    
    getExpression(expressionString);
    
    if(evaluateParenthesis(expressionString))
        cout << "Parenthesis matched.\n";
    else
        cout << "Parenthesis mismatched.\n";
    
    return 0;
}

void getExpression(string & expression)
{
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

void printPostfix(string expression)
{
    stack <char> operators;
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


