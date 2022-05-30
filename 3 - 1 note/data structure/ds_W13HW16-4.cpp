#include <cstdio>

/*
과제15의 (4)를 다시 해보고, int getNumlessThan(int th) th보다 작은 원소의 개수를 리턴하는
멤버함수를 추가해서, main()에서 활용 바랍니다.
*/

class Node {
	Node* link; // 다음 노드를 가리키는 포인터 변수
	int data; // 노드의 데이터 필드

public:
	Node(int val = 0) : data(val), link(NULL) {}
	Node* getLink() { return link; }

	void setLink(Node* next) { link = next; }
	void display() { printf("<%2d> ", data); }
	bool hasData(int val) { return data == val; }
	int getData() { return data; }

	// 자신의 다음에 새로운 노드 n을 삽입하는 함수
	void insertNext(Node* n) {
		if (n != NULL) {
			n->link = link;
			link = n;
		}
	}

	// 자신의 다음 노드를 리스트에서 삭제하는 함수
	Node* removeNext() {
		Node* removed = link;
		if (removed != NULL) // 다음 노드가 마지막 노드라면 굳이 지금 노드에 연결할 필요가 없음
			link = removed->link;
		return removed;
	}
};

class LinkedList {
	Node org; // 헤드 노드(헤드 포인터가 아님)

public:
	LinkedList() : org(0) {} // 생성자
	~LinkedList() { clear(); } // 소멸자

	void clear() { while (!isEmpty()) delete remove(0); }
	Node* getHead() { return org.getLink(); }
	bool isEmpty() { return getHead() == NULL; }

	// pos번째 항목을 반환함
	Node* getEntry(int pos) {
		Node* n = &org;
		for (int i = -1; i < pos; i++, n = n->getLink())
			if (n == NULL) break;
		return n;
	}

	// 리스트의 어떤 위치에 항목 삽입
	void insert(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL)
			prev->insertNext(n);
	}

	// 리스트의 어떤 위치의 항목 삭제
	Node* remove(int pos) {
		Node* prev = getEntry(pos - 1);
		return prev->removeNext();
	}

	// 탐색 함수
	Node* find(int val) {
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			if (p->hasData(val)) return p;
		return NULL;
	}

	// 리스트의 pos번째 노드를 다른 노드로 교체
	void replace(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL) {
			delete prev->removeNext();
			prev->insertNext(n);
		}
	}

	// 리스트 항목 개수를 반환
	int size() {
		int count = 0;
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			count++;
		return count;
	}

	// 화면에 보기 좋게 출력
	void display() {
		printf("[전체 항목 수 = %2d] : ", size());
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			p->display();
		printf("\n");
	}

	// th보다 작은 원소의 개수를 리턴
	int getNumlessThan(int th)
	{
		int cnt = 0;
		
		for (Node* p = getHead(); p != NULL; p = p->getLink()) {
			if (p->getData() < th)
				cnt++;
		}
		
		return cnt;
	}
};

void main()
{
	LinkedList list;

	list.insert(0, new Node(10));
	list.insert(0, new Node(20));
	list.insert(1, new Node(30));
	list.insert(list.size(), new Node(40));
	list.insert(2, new Node(50));

	list.display();

	printf("list.getNumlessThan(35) -> %d\n", list.getNumlessThan(35));

	list.remove(2);
	list.remove(list.size() - 1);
	list.remove(0);

	list.replace(1, new Node(90));

	list.display();

	list.clear();

	list.display();
}
