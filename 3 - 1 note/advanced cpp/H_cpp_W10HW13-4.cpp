#include <iostream>
#include <string>
using namespace std;

/*
이름, 생년, 타율을 member variable로 Hitter 클래스를 만들고,
생성자를 이용하여 아래 내용을 저장한 후,
타율 기준으로 내림차순으로 정렬하세요.
단, 타율이 같을 때는, 어린 사람이 먼저 출력되도록 하세요.
Kim,1988,0.350 / Chris,1990,0.250 / Hose,1991,0.261 / Tim,1992,0.261/ Lee,1990,0.350
*/

class Hitter {
	string name;
	int year;
	double hitrate;
public:
	Hitter(string n = "", int y = 0, double h = 0) {
		name = n;
		year = y;
		hitrate = h;
	}

	string getName() { return name; }
	int getYear() { return year; }
	double getHitrate() { return hitrate; }
};

int main()
{
	Hitter men[5];
	men[0] = Hitter("Kim", 1988, 0.350);
	men[1] = Hitter("Chris", 1990, 0.250);
	men[2] = Hitter("Hose", 1991, 0.261);
	men[3] = Hitter("Tim", 1992, 0.261);
	men[4] = Hitter("Lee", 1990, 0.350);

	for (int i = 0; i < 5 - 1; i++) {
		int idx = i;

		for (int j = i + 1; j < 5; j++) {
			if ((men[j].getHitrate() > men[idx].getHitrate()) || (men[j].getHitrate() == men[idx].getHitrate() && men[j].getYear() > men[idx].getYear()))
				idx = j;
		}

		Hitter temp = men[i];
		men[i] = men[idx];
		men[idx] = temp;
	}

	for (int i = 0; i < 5; i++)
		printf("name : %s\tbirth year : %d\thitrate : %f\n", men[i].getName().c_str(), men[i].getYear(), men[i].getHitrate());

	return 0;
}
