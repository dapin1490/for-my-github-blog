#include <cstdio>
#include <cstdlib>
#include <cstring>

class Node { // Student를 상속하지 않고 구현
	Node* link; // 다음 노드를 가리키는 포인터 변수
	char data; // 스택에는 노드가 들어가고 노드에는 괄호가 들어감

public:
	Node(char br) { // 생성자
		data = br;
		link = NULL;
	}

	~Node(void) {} // 소멸자

	Node* getLink() { return link; }

	void setLink(Node* p) { link = p; }

	void display() { printf("%c\n", data); }
};

class LinkedStack {
	Node* top;

public:
	LinkedStack() { top = NULL; }

	~LinkedStack() { while (!isEmpty()) delete pop(); }

	bool isEmpty() { return top == NULL; }

	void push(Node* p) {
		if (isEmpty()) top = p;
		else {
			p->setLink(top); // p->link = top;
			top = p;
		}
	}

	Node* pop() {
		if (isEmpty()) return NULL;

		Node* p = top;
		top = top->getLink();
		return p;
	}

	Node* peek() { return top; }

	void display() {
		printf("[LinkedStack]\n");
		for (Node* p = top; p != NULL; p = p->getLink())
			p->display();
		printf("\n");
	}
};

void main()
{
	LinkedStack stack;

	stack.push(new Node('{'));
	stack.push(new Node('['));
	stack.push(new Node('('));

	stack.display();
}
