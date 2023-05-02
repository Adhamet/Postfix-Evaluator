#include <iostream>
#include "eval-postfix.h"
using namespace std;

// Function to push element into the stack
void push(int val)
{
	struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));

	newnode->data = val;
	newnode->next = top;
	top = newnode;
}

//Function to pop an element from the stack
int pop()
{
	int result;

	if (top == NULL) {
		return -1;
	}

	result = top->data;
	temp = top;
	top = top->next;
	free(temp);

	return (result);
}

//Function that displays elements of stack
void display()
{
	struct Node* ptr;

	if (top == NULL)
	{
		cout << "Stack is empty" << endl;
	}
	else
	{
		ptr = top;
		cout << "Stack elements are: " << endl;

		while (ptr != NULL)
		{
			cout << ptr->data << " ";
			ptr = ptr->next;
		}
	}

	cout << endl;
}

//Function that checks if stack is empty.
bool isEmpty()
{
	return (top == NULL);
}
