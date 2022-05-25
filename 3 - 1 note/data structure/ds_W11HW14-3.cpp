#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

/*
Node 와 LinkedStack 클래스와 기존에 제공한 괄호체크 코드를 합쳐서 하나로 구현하고,
중간고사 3번 문제에 적용해 보도록 한다.
*/

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
	char getData() { return data; }

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

void CheckMatching(const char* filename);

int main()
{
	// 파일 없음
	CheckMatching("ds_W6_bracket_test.txt");
	// 괄호 정상
	CheckMatching("university/3rd - 1/자료구조 (금1)/memo.txt");
	// [{( <- 괄호 비정상 걸림
	// 괄호 비정상
	CheckMatching("cpp backpaper project/my backpaper/backpaper.cpp");

	return 0;
}

void CheckMatching(const char* filename)
{
	// 플래그 추가 : false일 때는 문제가 없음, true일 때는 문제가 있음
	bool flag = false;

	int nLine = 1, nChar = 0;
	char ch;
	LinkedStack stack;

	FILE* fp;

	printf("파일명 : %s\n", filename);

	fopen_s(&fp, filename, "r"); // 파일 열기
	if (fp == NULL) {
		printf("Error: 파일 존재하지 않음\n\n");
		return;
	}

	while ((ch = getc(fp)) != EOF) {

		// printf("%c", ch);

		nChar++;
		if (ch == '\n') nLine++;

		if (ch == '[' || ch == '(' || ch == '{')
			stack.push(new Node(ch));
		else if (ch == ']' || ch == ')' || ch == '}') {
			int prev = (*stack.pop()).getData();
			if (prev == NULL) {
				printf("problem : 닫는 괄호가 더 많음\n");
				flag = true; // 오류가 있으므로 플래그 변경
				break; // 반복문에서 탈출
			}
			else if ((ch == ']' && prev != '[')
				|| (ch == ')' && prev != '(')
				|| (ch == '}' && prev != '{')) {
				printf("problem : 좌우 괄호 비대칭\n");
				flag = true; // 오류가 있으므로 플래그 변경
				break; // 반복문에서 탈출
			}
		}
	}
	fclose(fp); // 사용한 파일 닫기

	printf("결과 : ");

	if (stack.isEmpty() == false && !flag) { // 스택이 비어있지 않을 경우 : 왼쪽 괄호가 남았다
		printf("여는 괄호가 더 많음\n");
		printf("발견된 오류 - 줄 수 : %d, 문자 수 : %d\n\n", nLine, nChar);
	}
	else if (flag) { // 스택은 비어있지만 오류가 발생한 상태일 경우
		// : 이전에 오류 문구가 이미 출력되었을 것이므로 오류 카운트만 출력
		printf("발견된 오류 - 줄 수 : %d, 문자 수 : %d\n\n", nLine, nChar); // 이게 오류 카운트
	}
	else { // 위의 모든 선택문을 다 지나왔다면 정상 실행
		printf("발견된 오류 없음 - 줄 수 : %d, 문자 수 : %d\n\n", nLine, nChar);
	}

	return;
}
