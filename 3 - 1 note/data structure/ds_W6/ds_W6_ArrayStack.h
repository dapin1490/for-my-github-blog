#pragma once
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE	100

inline void error(const char* str) {
	fprintf(stderr, "%s\n", str);
	exit(1); // 에러 함수의 이 부분이 프로그램을 강제로 종료시켜서
	// 이후의 오류 문구 출력이나 결과 출력 등의 코드를 실행하지 못하게 함
};

class ArrayStack
{
	int		data[MAX_STACK_SIZE];
	int		top;

public:
	ArrayStack() { top = -1; }
	~ArrayStack() {}
	bool isEmpty() { return top == -1; }
	bool isFull() { return top == MAX_STACK_SIZE - 1; }

	void push(int e) {
		if (isFull()) error("스택 포화 에러\n");
		data[++top] = e;
	}

	int pop() { // 함수 변경됨
		if (isEmpty()) // error("스택 공백 에러\n");
			return -1; // 공백 에러 오류 코드 -1로 정함 : 프로그래머가 직접 정한 것이니 바꿀 수 있음
						// 또한 return으로 이전 호출로 돌아가기 때문에 아래의 코드는 실행되지 않음
		return data[top--];
	}

	int peek() { // 함수 변경됨
		if (isEmpty()) // error("스택 공백 에러\n");
			return -1; // 공백 에러 오류 코드. 위와 같음.
		return data[top];
	}

	void display() {
		printf("[스택 항목의 수 = %2d] ==> ", top + 1);
		for (int i = 0; i <= top; i++)
			printf("<%2d>", data[i]);
		printf("\n");
	}
};
