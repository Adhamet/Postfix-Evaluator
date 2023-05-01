#include <iostream>
#include "eval-postfix.h"
using namespace std;

//Helper function to check if a character is an operator.
bool isOperator(char c);

int evaluatePostfix(string postfix)
{
	int op1, op2, number, result = 0;
	string number_string = "";
	for (int i = 0; i < postfix.length(); i++)
	{
		if (isdigit(postfix[i])) // 23 51 *
		{
			number_string += postfix[i];
		}
		else if (postfix[i] == ' ' && isdigit(postfix[i-1]))
		{
			number = stoi(number_string);
			push(number);
			number_string = "";
		}
		else if (isOperator(postfix[i]))
		{
			op2 = pop();
			op1 = pop();

			switch (postfix[i]) {
				case '+':
						result =  op1 + op2;
						push(result);
						break;
				case '-':
						result = op1 - op2;
						push(result);
						break;
				case '*':
						result = op1 * op2;
						push(result);
						break;
				case '/':
						result = op1 / op2;
						push(result);
						break;		
			}
		}
	}

	return cout << "The answer is: " << top->data, top->data;
}

bool isOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}
