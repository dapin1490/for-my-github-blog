#include <iostream>
using namespace std;

/*
int front, int rear, int cnt, int data[8]을 전역변수로 두어 원형큐를 구현한다.
새로 추가되는 cnt는 Queue에 저장되어 있는
중간고사 6번의 순서로 enqueue(), dequeue()를 하고 매 이벤트시 queue에 있는 내용을 화면에 출력한다.
*/

int front = 0;
int rear = 0;
int cnt = 0;
int data[8] = { 0 };
int size = 8;

bool isEmpty() { return cnt == 0; }
bool isFull() { return cnt == ::size; }

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
		cout << "error : full\n";
		return;
	}

	cnt++;
	rear = (rear + 1) % ::size;
	::data[rear] = n;
	return;
}

int dequeue()
{
	if (isEmpty()) {
		cout << "error : empty\n";
		return NULL;
	}

	cnt--;
	front = (front + 1) % ::size;
	return ::data[front];
}

void display()
{
	printf("display the queue : ");
	
	if (isEmpty()) {
		printf("there is no entity for display\n\n");
		return;
	}

	int end = (front < rear) ? rear : rear + ::size;
	for (int i = front + 1; i < end; i++)
		printf("%d, ", ::data[i % ::size]);
	printf("%d", ::data[end % ::size]);

	printf("\n\n");

	return;
}
