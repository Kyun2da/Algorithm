#include <stdio.h>
#include <stdlib.h>
#define cQ_SIZE 4

typedef char element;

typedef struct {
	element queue[cQ_SIZE];
	int front, rear;
}cQueueType;

cQueueType* createQueue()
{
	cQueueType* cQ;
	cQ = (cQueueType*)malloc(sizeof(cQueueType));
	cQ->front = 0; // ���� ť�� front �ʱⰪ ����
	cQ->rear = 0; // ���� ť�� rear �ʱⰪ ����
	return cQ;
}

int isEmpty(cQueueType* cQ) //����ť�� ����ִ��� Ȯ��
{
	if (cQ->front == cQ->rear)
	{
		printf(" Circular Queue is Empty! \n");
		return 1;
	}
	else return 0;
}

int isFull(cQueueType* cQ) //���� ť�� �������ִ��� Ȯ��
{
	if (((cQ->rear + 1) % cQ_SIZE) == cQ->front) { //����ִ��� Ȯ���ϴ� �Ͱ� �������ֱ����� ��ĭ�� ����д�
		printf(" Circular Queue is full!! \n");
		return 1;
	}
	else return 0;
}

void enQueue(cQueueType* cQ, element item) //����ť�� ���Ҹ� ���
{
	if (isFull(cQ)) exit(1);
	else {
		cQ->rear = (cQ->rear + 1) % cQ_SIZE;
		cQ->queue[cQ->rear] = item;
	}
}

element deQueue(cQueueType* cQ) //����ť��front���� �ִ� ���� �����ϰ� ��ȯ
{
	if (isEmpty(cQ)) exit(1);
	else {
		cQ->front = (cQ->front + 1) % cQ_SIZE;
		return cQ->queue[cQ->front];
	}
}

void del(cQueueType* cQ) { //����ť�� �ִ� ���� ����
	if (isEmpty(cQ)) exit(1);
	else cQ->front = (cQ->front + 1) % cQ_SIZE;
}

element peek(cQueueType* cQ) //����ť�� �ִ� ���� �տ��ִ� ���Ҹ� �˻��Ͽ� ��ȯ
{
	if (isEmpty(cQ)) exit(1);
	else return cQ->queue[(cQ->front + 1) % cQ_SIZE];
}

void printQ(cQueueType* cQ) //���� ť ����Ʈ
{
	int i, first, last;
	first = (cQ->front + 1) % cQ_SIZE;
	last = (cQ->rear + 1) % cQ_SIZE;
	printf(" Circular Queue : [");
	i = first;
	while (i != last) {
		printf("%2c", cQ->queue[i]);
		i = (i + 1) % cQ_SIZE;
	}
	printf(" ] \n");
}

int main()
{
	cQueueType* cQ1 = createQueue();
	element data;
	printf("���� A>>"); enQueue(cQ1, 'A'); printQ(cQ1);
	printf("���� B>>"); enQueue(cQ1, 'B'); printQ(cQ1);
	printf("����  >>"); deQueue(cQ1);      printQ(cQ1);
	printf("���� C>>"); enQueue(cQ1, 'C'); printQ(cQ1);
	printf("���� D>>"); enQueue(cQ1, 'D'); printQ(cQ1);
	printf("���� E>>"); enQueue(cQ1, 'E'); printQ(cQ1);

	getchar();
	return 0;
}