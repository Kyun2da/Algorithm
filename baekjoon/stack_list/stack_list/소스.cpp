#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stackNode {
	int data;
	stackNode* link;
}stackNode;

stackNode* top;

void push(int item)
{
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;
	top = temp;
}

int pop()
{
	int item;
	stackNode* temp = top;

	if (top == NULL)
	{
		printf("\n\n Stack is empty! \n");
		return 0;
	}
	else
	{
		item = temp->data;
		top = temp->link;
		free(temp);
		return item;
	}
}

int peek()
{
	int item;
	if (top == NULL)
	{
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else
	{
		item = top->data;
		return item;
	}
}

void del()
{
	stackNode* temp;
	if (top == NULL)
	{
		printf("\n\n Stack is empty !\n");
	}
	else
	{
		temp = top;
		top = top->link;
		free(temp);
	}
}

void printStack()
{
	stackNode* p = top;
	printf("\n STACK [ ");
	while (p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("] ");
}

int main()
{
	int item;
	top = NULL;
	printStack();
	push(1);
	printStack();
	push(2);
	printStack();
	push(3);
	printStack();

	item = peek();
	printStack();
	printf("peek top => %d", item);

	del();
	printStack();

	item = pop();
	printStack();
	printf("\t pop top => %d", item);

	item = pop();
	printStack();
	printf("\t pop top => %d", item);

	pop();

	return 0;
}