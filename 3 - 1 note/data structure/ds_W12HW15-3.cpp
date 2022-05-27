#include <iostream>
#include <windows.h> // Sleep()
#include <cstdlib> // rand(), srand()
#include <ctime> // time()
using namespace std;

/*
나이, 몸무게를 member variable로 갖는 class Person을 선언하고,
이를 담는 원형큐를 구현한다.
1초에 한명씩 랜덤하게 발생한 나이(0~100), 몸무게(0~200)을 가진 사람이 enqueue 되고,
최초 사람이 enqueue된 이후 1초 후부터 랜덤하게 사람이 dequeue 되도록 프로그램을 구현한다.
(1초 지연을 위해 Sleep() 함수를 활용하기 바랍니다. https://hijuworld.tistory.com/52)
*/

class Person {
	int age;
	int weight;
public:
	Person() {
		age = 0;
		weight = 0;
	}
	Person(int a, int w) {
		age = a;
		weight = w;
	}

	void display() { printf("age %d, weight %d\n", age, weight); }
};

class PCQ {
	Person* que;
	int size;
	int front;
	int rear;

public:
	PCQ(int s) {
		size = s;
		que = new Person[size];
		front = 0;
		rear = 0;
	}
	~PCQ() { delete[] que; }

	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % size == front; }

	void enqueue(Person p) {
		if (isFull()) {
			printf("QueueFullError: there is no space for enqueue\n");
			return;
		}

		rear = (rear + 1) % size;
		*(que + rear) = p;
	}

	Person dequeue() {
		if (isEmpty()) {
			printf("QueueEmptyError: there is no entity for dequeue\n");
			return Person(0, 0);
		}

		front = (front + 1) % size;
		return *(que + front);
	}

	int q_size() { return size; } // 큐의 전체 길이
	int count() { // 현재 큐에 있는 원소 개수
		if (isEmpty())
			return 0;
		else
			return (((front < rear) ? rear : rear + size) - front);
	}

	void display() {
		printf("display the queue:\n");

		if (isEmpty()) {
			printf("The queue is empty.\n\n\n");
			return;
		}

		int end = (front <= rear) ? rear : rear + size;
		for (int i = front + 1; i <= end; i++)
			(que + (i % size))->display();
		printf("\n\n");

		return;
	}
};

int main()
{
	int s = 10; // 실제 사이즈는 지정한 크기보다 1 작음 : 배열로 구현한 원형큐라서 한 칸은 비워둬야 하기 때문
	int roop = 5; // 1 roop == 2 second
	int dq_rate = 2; // dequeue 확률은 1/dq_rate

	/*
	printf("input queue size : ");
	cin >> s;
	printf("input roop count : ");
	cin >> roop;
	printf("input dequeue rate by integer(1/dequeue rate) : ");
	cin >> dq_rate;
	*/

	PCQ q(s); // 원형큐 선언, 소멸자는 프로그램 종료 시 자동 호출

	srand((unsigned int)time(NULL)); // 랜덤 시드를 랜덤하게 설정
	// 참고 : https://blockdmask.tistory.com/308

	for (int i = 0; i < roop; i++) {
		printf("roop : %d\n", i + 1);

		Sleep(1000); // 1초 정지

		int a = rand() % 101;
		int w = rand() % 201;
		q.enqueue(Person(a, w));
		printf("enqueued + age %d, weight %d\n", a, w);

		Sleep(1000); // 1초 정지

		if (rand() % dq_rate == 0) { // 기본값 2 -> 0.5 확률
			Person dq = q.dequeue();
			printf("dequeued - ");
			dq.display();
		}

		q.display();

		if (q.count() >= 5)
			break;
	}

	return 0;
}
