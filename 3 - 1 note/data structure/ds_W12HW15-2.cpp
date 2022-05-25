#include <iostream>
using namespace std;

/*
const int front=-1, int rear, int data[8]을 전역변수로 두어 선형큐를 구현하고,
중간고사 6번의 순서로 enqueue(), dequeue()를 하고
매 이벤트시 queue에 있는 내용을 화면에 출력한다.
*/

const int front = -1;
int rear = -1;
int data[8] = { 0 };

bool isEmpty();
bool isFull();

void enqueue(int n);
int dequeue();
void display();

int main()
{
	enqueue(1);
	printf("enqueue(1);\n");
	display();
	printf("\n");

	enqueue(2);
	printf("enqueue(2);\n");
	display();
	printf("\n");

	enqueue(3);
	printf("enqueue(3);\n");
	display();
	printf("\n");
	
	dequeue();
	printf("dequeue();\n");
	display();
	printf("\n");
	
	enqueue(4);
	printf("enqueue(4);\n");
	display();
	printf("\n");
	
	enqueue(5);
	printf("enqueue(5);\n");
	display();
	printf("\n");
	
	enqueue(6);
	printf("enqueue(6);\n");
	display();
	printf("\n");
	
	enqueue(7);
	printf("enqueue(7);\n");
	display();
	printf("\n");
	
	dequeue();
	printf("dequeue();\n");
	display();
	printf("\n");

	return 0;
}

bool isEmpty()
{
	if (rear == front)
		return true;
	else
		return false;
}

bool isFull()
{
	if (rear == 8)
		return true;
	else
		return false;
}

void enqueue(int n)
{
	if (isFull()) {
		printf("QueueFullError : there is no space for enqueue\n");
		return;
	}

	::data[++rear] = n;
	return;
}

int dequeue()
{
	if (isEmpty()) {
		printf("QueueEmptyError : there is no entity for dequeue\n");
		return NULL;
	}

	int dq = ::data[0];
	for (int i = 1; i <= rear; i++)
		::data[i - 1] = ::data[i];
	rear--;

	return dq;
}

void display()
{
	printf("display queue :");

	for (int i = 0; i <= rear; i++)
		printf("\t%d", ::data[i]);
	printf("\n");

	return;
}