#include <iostream>
#include "eval-postfix.h"
using namespace std;

int main()
{
	string infix, postfix;

	cout << "Enter an postfix expression: ";
	getline(cin, postfix);
	evaluatePostfix(postfix);

	return (0);
}
