/*
이름과 수학점수와 영어 점수를 멤버 변수로 하는 구조체 Student를 정의하고
Student 타입의 배열을 정의하여 총점이 제일 높은 사람의 이름과 점수를 출력하는 프로그램을 작성하시오.

John 95 100
Kim 100 98
Lee 85 90
Chris 88 90
Young 92 88
*/

#include <iostream>
using namespace std;

typedef struct Student {
	string name;
	int score[2];
	int total;
};

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int maxidx = 0;
	Student li[5];
	li[0] = { "John", {95, 100}, 95 + 100 };
	li[1] = { "Kim", {100, 98}, 100 + 98 };
	li[2] = { "Lee", {85, 90}, 85 + 90 };
	li[3] = { "Chris", {88, 90}, 88 + 90 };
	li[4] = { "Young", {92, 88}, 92 + 88 };

	for (int i = 1; i < 5; i++) {
		if (li[i].total > li[maxidx].total)
			maxidx = i;
	}

	cout << li[maxidx].name << " " << li[maxidx].score[0] << " " << li[maxidx].score[1];

	return 0;
}
