// Header file that includes prototypes of all functions you need
// for converting from infix to postfix.
#ifndef POSTFIX_EVALUATOR
#define POSTFIX_EVALUATOR

#include <string>

struct Node{
	char data;
	Node* next;
};

Node *top = NULL;
Node *temp;

// Stack Functions
void push(char val);
int pop();
void display();
bool isEmpty();

// Logic
string evaluatePostfix(string postfix);

#endif
