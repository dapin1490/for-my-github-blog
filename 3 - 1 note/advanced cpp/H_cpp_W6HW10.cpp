#include <iostream>
using namespace std;

typedef struct Student {
	string name;
	int score;
};

int main()
{
	/*
	이름과 수학점수를 멤버 변수로 하는 구조체 Student를 정의하고 Student 타입의 배열을 정의하여
	점수가 제일 높은 사람의 이름과 점수를 출력하는 프로그램을 작성하시오. 
	
	John 95
	Kim 100
	Lee 85
	Chris 88
	Young 92
	*/

	int midx;
	Student s[5];

	s[0].name = "John";
	s[0].score = 95;
	s[1].name = "Kim";
	s[1].score = 100;
	s[2].name = "Lee";
	s[2].score = 85;
	s[3].name = "Chris";
	s[3].score = 88;
	s[4].name = "Young";
	s[4].score = 92;

	midx = 0;
	for (int i = 1; i < 5; i++) {
		if (s[i].score > s[midx].score)
			midx = i;
	}

	cout << s[midx].name << " " << s[midx].score;

	return 0;
}