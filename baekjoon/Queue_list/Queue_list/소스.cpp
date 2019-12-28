#include <stdio.h>
#include <malloc.h>

typedef char element;

typedef struct QNode {
	element data;
	struct QNode* link;
}QNode;

typedef struct { //연결 큐에서 사용하는 포인터 front와 rear를 구조체로 정의
	QNode* front, * rear;
}LQueueType;

LQueueType* createLinkedQueue() //공백 연결 큐 생성 연산
{
	LQueueType* LQ;
	LQ = (LQueueType*)malloc(sizeof(LQueueType));
	LQ->front = NULL;
	LQ->rear = NULL;
	return LQ;
}

int isEmpty(LQueueType* LQ) //연결 큐가 공백인지 확인하는 연산
{
	if (LQ->front == NULL)
	{
		printf("\n Linked Queue is empty! \n");
		return 1;
	}
	else return 0;
}

void enQueue(LQueueType* LQ, element item) //연결 큐의 rear에 원소를 삽입하는 연산
{
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;
	if (LQ->front == NULL) { //현재 연결큐가 공백인 경우
		LQ->front = newNode;
		LQ->rear = newNode;
	}
	else { //현재 연결큐가 공백이 아닌 경우
		LQ->rear->link = newNode;
		LQ->rear = newNode;
	}
}

element deQueue(LQueueType* LQ) //연결 큐에서 front원소를 삭제하고 반환하는 연산
{
	QNode* old = LQ->front;
	element item;
	if (isEmpty(LQ)) return 0;
	else {
		item = old->data;
		LQ->front = LQ->front->link;
		if (LQ->front == NULL)
			LQ->rear = NULL;
		free(old);
		return item;
	}
}

int del(LQueueType* LQ) //연결 큐에서 front 원소를 삭제하는 연산
{
	QNode* old = LQ->front;
	if (isEmpty(LQ)) return 0;
	else {
		LQ->front = LQ->front->link;
		if (LQ->front == NULL)
			LQ->rear = NULL;
		free(old);
		return 1;
	}
}

element peek(LQueueType* LQ) //연결 큐에서 front 원소를 검색하여 반환하는 연산
{
	element item;
	if (isEmpty(LQ)) return 0;
	else {
		item = LQ->front->data;
		return item;
	}
}

void printLQ(LQueueType* LQ)
{
	QNode* temp = LQ->front;
	printf(" Linked Queue : [");
	while (temp) {
		printf("%2c", temp->data);
		temp = temp->link;
	}
	printf(" ] \n");
}

int main()
{
	LQueueType* LQ1 = createLinkedQueue();
	element data;
	printf("삽입 A>>"); enQueue(LQ1, 'A'); printLQ(LQ1);
	printf("삽입 B>>"); enQueue(LQ1, 'B'); printLQ(LQ1);
	printf("삭제  >>"); deQueue(LQ1); printLQ(LQ1);
	printf("삽입 C>>"); enQueue(LQ1, 'C'); printLQ(LQ1);
	data = peek(LQ1); printf(" peek item : %c \n", data);
	printf("삽입 D>>"); enQueue(LQ1, 'D'); printLQ(LQ1);
	printf("삽입 E>>"); enQueue(LQ1, 'E'); printLQ(LQ1);

	return 0;
}