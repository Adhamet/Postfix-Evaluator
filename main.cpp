#include <iostream>
#include <string>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node *top = NULL;
Node *temp;

// Stack Functions
void push(int val);
int pop();
void display();
bool isEmpty();

// Logic
int evaluatePostfix(std::string postfix);
bool isOperator(char c);

int main()
{
	string infix, postfix;

	cout << "Enter an postfix expression: ";
	getline(cin, postfix);
	evaluatePostfix(postfix);

	return (0);
}

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
