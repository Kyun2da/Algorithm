#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = -1;

void push(int item) // ���Ҹ� �߰��ϴ� �Լ�
{
	if (top >= STACK_SIZE - 1) {
		printf("\n\n Stack is Full ! \n");
		return;
	}
	else stack[++top] = item;
}

int pop() //�� �����Ҹ� ������ ��ȯ�ϴ� �Լ�
{
	if (top == -1)
	{
		printf("\n\n Stack is Empty!!\n");
		return 0;
	}
	else return stack[top--];
}

void del() //�� ���� ���Ҹ� �����ϴ� ����
{
	if (top == -1)
	{
		printf("\n\n Stack is Empty !\n");
		exit(1);
	}
	else top--;
}

int peek() //���� ���Ҹ� �������� �Լ�
{
	if (top == -1) {
		printf("\n\n Stack is Empty !\n");
		exit(1);
	}
	else return stack[top];
}

void printStack() // ���� ���Ҹ� ��� print �ϴ� �Լ�
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