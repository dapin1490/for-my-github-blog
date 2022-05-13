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

/*
// 교수 답안
#include "stdlib.h"
#include <iostream>
using namespace std;

class Node {	
	Node* link; 		// 다음 노드를 가리키는 포인터 변수
	char data;
public:
	Node(char in){ // 클래스 이름이 Node인데, 함수 이름이 Node => 생성자(인스턴스 생성할 때, 호출되는 함수)
		link = NULL;
        data = in;
	}
	~Node(void) { } // ~Node() => 소멸자(Destructor) (인스턴스 삭제시 호출되는 함수) 
	Node* getLink() { return link; }
	void setLink(Node* p) { link = p; }
    char getData() { return data; }
    void setData(char in) { data = in; }
};

class LinkedStack {
    Node* top;
public:
    LinkedStack() { top = NULL; }
    ~LinkedStack() { while (!isEmpty()) delete pop(); }
    bool isEmpty() { return top == NULL; }

    void push(Node* p) {
        if (isEmpty()){
            top = p;
        }
        else {
            p->setLink(top);		// p->link = top;
            top = p;
        }
    }

    Node* pop()
    {
        Node* p = NULL;
        if (isEmpty()) {
            cout << "stack이 비어 있어서 리턴할 데이터가 없다" << endl;
        }
        else
        {
            p = top;
            top = p->getLink();//p->link; private하니까 get 함수로 접근
        }
        return p;
    }

    // display
    void display()
    {
	    Node *p;

        for (Node* p = top; p != NULL; p = p->getLink())
        {
            cout << p->getData() << " ";
        }
        cout << endl;


    }
};

void main()
{
    LinkedStack s1;
    Node* return_data;
    s1.push(new Node('{'));
    s1.push(new Node('['));
    s1.push(new Node('('));
    s1.display();
    return_data = s1.pop();
    cout << return_data->getData() << endl;
    s1.display();
}
*/
