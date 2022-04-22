/*
코로나19로 인해 마스크를 사는 요일이 정해져 있었습니다..
출생년도를 입력하면, 마스크를 사야하는 요일을 출력하는 소스코드를 작성하시오.
단 아래의 조건들이 지켜져야 함.

(1)	출생년도는 birth_year 라는 변수명을 사용해야 함
(2)	1910년생 ~ 2022년생 외의 출생년도를 입력하면 다시 입력받도록 함(무한루프+break) 
(3) 입력이 3회 틀리면 더 이상 입력을 받지 않고, 이후 처리를 하지 않음

<< 출생년도 끝자리와 마스크 구매 가능 요일 규칙>> 
1·6 → 월요일만 구매 가능
2·7 → 화요일만 구매 가능
3·8 → 수요일만 구매 가능
4·9 → 목요일만 구매 가능
5·0 → 금요일만 구매 가능
*/

#include <iostream>
using namespace std;

int main()
{
    int birth_year, input_count;
    input_count = 0;
    while (true) {
        cin >> birth_year;
        input_count++;
        if (birth_year >= 1910 && birth_year <= 2022)
            break;
        if (input_count >= 3)
            return 0;
    }

    switch (birth_year % 10)
    {
        case 1: case 6: cout << "월요일\n"; break;
        case 2: case 7: cout << "화요일\n"; break;
        case 3: case 8: cout << "수요일\n"; break;
        case 4: case 9: cout << "목요일\n"; break;
        case 5: case 0: cout << "금요일\n"; break;
    }

    return 0;
}
