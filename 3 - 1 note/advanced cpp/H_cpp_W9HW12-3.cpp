#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string> // C++ 문자열 string
#include <cstring> // C 문자열 char[], strcmp()
using namespace std;

/*
아이디(문자 기준 20개 이하), 비밀번호(정수 4자리), 생년(정수 4자리), 키(실수), 수학 점수(정수),
영어 점수(정수)를 member variable로 하는 class Person을 만들고, 5개 객체 배열을 정의하여,
다섯 사람의 정보를 입력한다. 여기까지는 과제의 공통사항임.
*/

const int MAX_ID = 21; // '\0' 포함

class Person {
private:
	char id[MAX_ID];
	string pw; // int로 저장하면 앞자리가 0으로 시작할 경우 "4자리" 유지가 안 됨
	int birth;// 생년은 제대로 입력한다면 0으로 시작할 일이 없다
	double height;
	int math, eng;

public:
	Person(const char* i = "", string p = "0000", int b = 0000, double h = 0.0, int m = 0, int e = 0) {
		memcpy(id, i, MAX_ID);
		pw = p;
		birth = b;
		height = h;
		math = m, eng = e;
	}

	char* getId() { return id; }
	string getPw() { return pw; }
	
	int getBirth() { return birth; }
	double getHeight() { return height; }
	
	int getMath() { return math; }
	int getEng() { return eng; }

	void setId(const char* i = "") {
		memcpy(id, i, MAX_ID);
		printf("id setted\n");
	}

	void setPw(string p = "0000") {
		pw = p;
		printf("password setted\n");
	}

	bool checkId(char* i) { return ((strcmp(id, i) == 0) ? true : false); }
	bool checkPw(string p) { return pw == p; }
};

void display_top3(Person* p, int n);

int main()
{
	Person ps[5];
	int n = 5;

	ps[0] = Person("dnfn", "1234", 2000, 155.7, 91, 90);
	ps[1] = Person("asdf", "0001", 2002, 159.3, 95, 91);
	ps[2] = Person("bluesky", "1004", 2001, 165.0, 96, 92);
	ps[3] = Person("seoul", "4321", 2000, 162.3, 93, 98);
	ps[4] = Person("sswu21", "8990", 2002, 167.3, 97, 88);

	// (3) 영어, 수학 점수를 이용하여 3:7로 반영하여 AI융합학부 합격자 3명을 정하려고 한다.
	// 3명의 아이디를 출력하는 프로그램을 작성하세요.
	printf("\n(3) 영어, 수학 점수를 이용하여 3:7로 반영하여 AI융합학부 합격자 3명을 정하려고 한다.\n3명의 아이디를 출력하는 프로그램을 작성하세요.\n");
	
	for (int i = 0; i < n - 1; i++) {
		int idx = i;
		for (int j = i + 1; j < n; j++) {
			double idx_score = double(ps[idx].getEng()) * 0.3 + double(ps[idx].getMath()) * 0.7;
			double j_score = double(ps[j].getEng()) * 0.3 + double(ps[j].getMath()) * 0.7;
			idx = (j_score > idx_score) ? j : idx;
		}

		Person temp = ps[i];
		ps[i] = ps[idx];
		ps[idx] = temp;
	}

	for (int i = 0; i < 3; i++)
		printf("%d. %s\n", i + 1, ps[i].getId());

	return 0;
}
