#include <stdio.h>
#include <string.h>
#define MAX_SIZE 10000

int stack[MAX_SIZE];
int sizeNum = -1;  //실제 사이즈는 sizeNum+1이다.

int IsEmpty() {
	if (sizeNum < 0)
		return 1;
	else
		return 0;
}
int IsFull() {
	if (sizeNum > MAX_SIZE)
		return 1;
	else
		return 0;
}
void push()
{
	if (IsFull())
		return;
	int a;
	scanf(" %d", &a);
	stack[++sizeNum] = a;
}

void pop()
{
	if (IsEmpty()==1)
	{
		printf("-1\n");
		return;
	}
	else
	{
		printf("%d\n", stack[sizeNum]);
		stack[sizeNum--];
	}
}

void size()
{
	printf("%d\n", sizeNum + 1);
}

void empty()
{
	if (IsEmpty()==1)
		printf("1\n");
	else
		printf("0\n");
}

void top()
{
	if (IsEmpty() == 1)
		printf("-1\n");
	else
	printf("%d\n", stack[sizeNum]);
}

int main()
{
	int num;
	char s[6];
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%s", s);
		if (strcmp(s, "push") == 0)
			push();
		else if (strcmp(s, "pop") == 0)
			pop();
		else if (strcmp(s, "size") == 0)
			size();
		else if (strcmp(s, "empty") == 0)
			empty();
		else if (strcmp(s, "top") == 0)
			top();
	}

	return 0;
}