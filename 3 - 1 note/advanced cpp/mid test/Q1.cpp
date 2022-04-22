/*
N을 입력받아 아래와 같이 화면에 출력되도록 프로그램을 작성하시오. 

입력예시>
N=5
출력예시>
     *
    **
   ***
  ****
 *****
*/

#include <iostream>
using namespace std;

int main()
{
    int n, space;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        space = n - i;
        for (int j = 0; j < space; j++)
            cout << " "; // 공백 한 칸
        for (int j = 0; j < i; j++)
            cout << "*";
        cout << "\n";
    }

    return 0;
}
