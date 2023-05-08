// Header file that includes prototypes of all functions you need
// for converting from infix to postfix.
#ifndef POSTFIX_EVALUATOR
#define POSTFIX_EVALUATOR

#include <string>

struct Node{
	int data;
	Node* next;
};

extern Node *top;
extern Node *temp;

// Stack Functions
void push(int val);
int pop();
void display();
bool isEmpty();

// Logic
int evaluatePostfix(std::string postfix);

#endif
