#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = -1;

void push(int item) // 원소를 추가하는 함수
{
	if (top >= STACK_SIZE - 1) {
		printf("\n\n Stack is Full ! \n");
		return;
	}
	else stack[++top] = item;
}

int pop() //맨 위원소를 삭제후 반환하는 함수
{
	if (top == -1)
	{
		printf("\n\n Stack is Empty!!\n");
		return 0;
	}
	else return stack[top--];
}

void del() //맨 위의 원소를 삭제하는 원소
{
	if (top == -1)
	{
		printf("\n\n Stack is Empty !\n");
		exit(1);
	}
	else top--;
}

int peek() //현재 원소를 가져오는 함수
{
	if (top == -1) {
		printf("\n\n Stack is Empty !\n");
		exit(1);
	}
	else return stack[top];
}

void printStack() // 현재 원소를 모두 print 하는 함수
{
	int i;
	printf("\n STACK [ ");
	for (i = 0; i <= top; i++)
		printf("%d ", stack[i]);
	printf("] ");
}

int main()
{
	int item;
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

	getchar();

	return 0;
}