#include <iostream>
using namespace std;

/*
int front, int rear, int data[8]을 전역변수로 두어 원형큐를 구현하고,
중간고사 6번의 순서로 enqueue(), dequeue()를 하고
매 이벤트시 queue에 있는 내용을 화면에 출력한다.
*/

int front = 0;
int rear = 0;
int data[8];
const int SIZE = 8;

bool isFull() { return (rear + 1) % SIZE == front; }
bool isEmpty() { return front == rear; }

void enqueue(int n);
int dequeue();

void display();

int main()
{
	int dq_data;

	enqueue(1);
	printf("enqueue(1);\n");
	display();

	enqueue(2);
	printf("enqueue(2);\n");
	display();

	enqueue(3);
	printf("enqueue(3);\n");
	display();

	dq_data = dequeue();
	printf("dequeue();\ndequeued data = %d\n", dq_data);
	display();

	enqueue(4);
	printf("enqueue(4);\n");
	display();

	enqueue(5);
	printf("enqueue(5);\n");
	display();

	enqueue(6);
	printf("enqueue(6);\n");
	display();

	enqueue(7);
	printf("enqueue(7);\n");
	display();

	dq_data = dequeue();
	printf("dequeue();\ndequeued data = %d\n", dq_data);
	display();

	return 0;
}

void enqueue(int n)
{
	if (isFull()) {
		printf("error : full\n");
		return;
	}

	rear = (rear + 1) % SIZE;
	::data[rear] = n; // ::는 전역변수라는 뜻
	
	return;
}

int dequeue()
{
	if (isEmpty()) {
		printf("error : empty\n");
		return NULL;
	}

	front = (front + 1) % SIZE;
	return ::data[front];
}

void display()
{
	printf("in the queue : ");
	
	int end = (front < rear) ? rear : rear + SIZE;
	for (int i = front + 1; i < end; i++)
		printf("%d, ", ::data[i % SIZE]);
	printf("%d", ::data[end % SIZE]);

	printf("\n\n");

	return;
}
