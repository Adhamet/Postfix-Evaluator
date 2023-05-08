#include <iostream>
#include "eval-postfix.h"
using namespace std;

Node *top = NULL;
Node *temp;

int main()
{
	string postfix;

	cout << "Enter n postfix expression: ";
	getline(cin, postfix);
	evaluatePostfix(postfix);

	return (0);
}
