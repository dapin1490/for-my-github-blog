#include <iostream>
using namespace std;

typedef struct Student {
	string name;
	int score;
};

int main()
{
	/*
	과제 10의 데이터를 그대로 사용하여, 내림 차순으로 이름과 성적을 보여주세요.
	*/

	int idx, n;
	Student s[5];

	n = 5;
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

	// 선택 정렬
	for (int i = 0; i < n - 1; i++) {
		int idx = i;

		for (int j = i + 1; j < n; j++) {
			if (s[j].score > s[idx].score) {
				idx = j;
			}
		}

		Student temp = s[i];
		s[i] = s[idx];
		s[idx] = temp;
	}

	cout << "내림차순 정렬\n";
	for (int i = 0; i < n; i++) {
		cout << s[i].name << " " << s[i].score << "\n";
	}

	return 0;
}