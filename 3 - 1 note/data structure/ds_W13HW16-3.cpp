#include <iostream>
using namespace std;

/*
(2)에서 전역변수로 구현한 것을 class 로 바꾸어 구현한다.
*/

class Q {
	int front = 0;
	int rear = 0;
	int cnt = 0;
	int data[8] = { 0 };
	int size = 8;

public:
	Q() {}

	bool isEmpty() { return cnt == 0; }
	bool isFull() { return cnt == size; }

	void enqueue(int n)
	{
		if (isFull()) {
			cout << "error : full\n";
			return;
		}

		cnt++;
		rear = (rear + 1) % size;
		data[rear] = n;
		return;
	}

	int dequeue()
	{
		if (isEmpty()) {
			cout << "error : empty\n";
			return NULL;
		}

		cnt--;
		front = (front + 1) % size;
		return data[front];
	}

	void display()
	{
		printf("display the queue : ");
	
		if (isEmpty()) {
			printf("there is no entity for display\n\n");
			return;
		}

		int end = (front < rear) ? rear : rear + size;
		for (int i = front + 1; i < end; i++)
			printf("%d, ", data[i % size]);
		printf("%d", data[end % size]);

		printf("\n\n");

		return;
	}
};

int main()
{
	Q q;

	int dq_data;

	q.enqueue(1);
	printf("enqueue(1);\n");
	q.display();

	q.enqueue(2);
	printf("enqueue(2);\n");
	q.display();

	q.enqueue(3);
	printf("enqueue(3);\n");
	q.display();

	dq_data = q.dequeue();
	printf("dequeue();\ndequeued data = %d\n", dq_data);
	q.display();

	q.enqueue(4);
	printf("enqueue(4);\n");
	q.display();

	q.enqueue(5);
	printf("enqueue(5);\n");
	q.display();

	q.enqueue(6);
	printf("enqueue(6);\n");
	q.display();

	q.enqueue(7);
	printf("enqueue(7);\n");
	q.display();

	dq_data = q.dequeue();
	printf("dequeue();\ndequeued data = %d\n", dq_data);
	q.display();

	return 0;
}
