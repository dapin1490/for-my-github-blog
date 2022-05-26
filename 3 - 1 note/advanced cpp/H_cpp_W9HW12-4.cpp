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
	
	/*
	(4) 사용자가 아이디, 패스워드를 넣어서 기존에 있는 것과 일치되면,
	“dnfn님 환영합니다.” 처럼 환영의 메시지를 화면에 뿌려준다.
	사용자가 넣은 아이디가 없으면 “입력하신 아이디가 없습니다” 화면에 뿌려주고,
	아이디가 있는데 패스워드가 틀리면 “입력하신 비밀번호가 틀립니다.”를 화면에 뿌려주고,
	3회 비밀번호가 틀린 경우
	“3회 비밀번호가 틀렸습니다. 매장으로 방문해주세요”를 화면에 뿌려주기 바랍니다.
	이상의 조건을 만족하는 프로그램을 작성하세요.
	( https://choryeonworkshop.tistory.com/119 : C/C++ 문자열 비교)
	*/
	printf("\n(4) 로그인\n");

	int user_idx;
	bool id_correct = false;
	bool pw_correct = false;
	char input_id[MAX_ID];
	string input_pw;
	int pw_wrong_count;

	while (true) {
		printf("아이디 입력 : ");
		scanf("%s", input_id);

		for (int i = 0; i < n; i++) {
			if (ps[i].checkId(input_id)) {
				user_idx = i;
				id_correct = true;
				break;
			}
		}

		if (id_correct)
			break;
		else {
			printf("입력하신 아이디가 없습니다\n");
			// return 0; // 아이디가 틀리면 비밀번호 입력받지 않고 종료
		}
	}

	pw_wrong_count = 0;
	while (true) {
		cout << "비밀번호 입력 : ";
		cin >> input_pw;

		if (ps[user_idx].checkPw(input_pw)) {
			printf("%s님 환영합니다.\n", ps[user_idx].getId());
			break;
		}
		else {
			printf("입력하신 비밀번호가 틀립니다.\n");
			pw_wrong_count++;
		}

		if (pw_wrong_count >= 3) {
			printf("3회 비밀번호가 틀렸습니다. 매장으로 방문해주세요.\n");
			break;
		}
	}

	return 0;
}
