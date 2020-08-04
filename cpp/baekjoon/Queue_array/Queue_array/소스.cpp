#include <stdio.h>
#include <stdlib.h>

#define Q_SIZE 100

typedef struct
{
	char queue[Q_SIZE];
	int front, rear;
}QueueType;

QueueType* createQueue() //공백 큐를 생성하는 연산
{
	QueueType* Q;
	Q = (QueueType*)malloc(sizeof(QueueType));
	Q->front = -1;
	Q->rear = -1;
	return Q;
}

int isEmpty(QueueType* Q) // 큐가 공백인지 확인하는 연산
{
	if (Q->front == Q->rear) {
		printf("\n Queue is empty! \n");
		return 1;
	}
	else return 0;
}

int isFull(QueueType* Q) //큐가 포화상태인지 확인하는 연산
{
	if (Q->rear == Q_SIZE - 1) {
		printf("\n Queue is full! \n");
		return 1;
	}
	else return 0;
}

void enQueue(QueueType* Q, char item) //큐의 rear에 원소를 삽입하는 연산
{
	if (isFull(Q)) exit(1);
	else {
		Q->rear++;
		Q->queue[Q->rear] = item;
	}
}

char deQueue(QueueType* Q) //큐의 front에서 원소를 삭제하고 반환하는 연산
{
	if (isEmpty(Q)) exit(1);
	else
	{
		Q->front++;
		return Q->queue[Q->front];
	}
}

void del(QueueType* Q) //큐의 front에서 원소를 삭제하는연산
{
	if (isEmpty(Q)) exit(1);
	else Q->front++;
}

char peek(QueueType* Q) // 큐의 가장 앞에 있는 원소를 검색하여 반환하는 연산
{
	if (isEmpty(Q)) exit(1);
	else return Q->queue[Q->front + 1];
}

void printQ(QueueType* Q) //큐의 내용을 출력하는 연산
{
	int i;
	printf(" Queue : [");
	for (i = Q->front + 1; i <= Q->rear; i++)
		printf("%2c", Q->queue[i]);
	printf(" ] \n");
}

int main()
{
	QueueType* Q1 = createQueue();
	char data;
	printf("삽입 A>>"); enQueue(Q1, 'A'); printQ(Q1);
	printf("삽입 B>>"); enQueue(Q1, 'B'); printQ(Q1);
	printf("삭제  >>"); deQueue(Q1); printQ(Q1);
	printf("삽입 C>>"); enQueue(Q1, 'C'); printQ(Q1);
	data = peek(Q1); printf(" peek item : %c \n", data);
	printf("삭제 >>"); deQueue(Q1); printQ(Q1);
	printf("삭제 >>"); deQueue(Q1); printQ(Q1);

	getchar();
	return 0;
}