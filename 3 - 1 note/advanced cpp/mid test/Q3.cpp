/*
교안에 있는 버블정렬은 아래 그림(이미지 생략)처럼 옆의 숫자들끼리 비교해가며
매회 뒤에서부터 큰 수를 채워 넣는 방식으로 오름 차순을 구현하였습니다.
배열이 int aa[5] = { 19, 11, 32, 44, 9 }으로 주어졌을 때,
아래와 같이 중간 과정(1회전, 2회전 등도 포함)이 표시 되도록 코드를 작성하시오.
*/

#include <iostream>
using namespace std;

int main()
{
    int aa[5] = {19, 11, 32, 44, 9};
    int n = 5;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "회전\n";

        for (int j = 0; j < n - 1 - i; j++) {
            for (int k = 0; k < n; k++)
                cout << aa[k] << " ";
            cout << "\n";
            if (aa[j] < aa[j + 1]) {
                int temp = aa[j];
                aa[j] = aa[j + 1];
                aa[j + 1] = temp;
                for (int k = 0; k < n; k++)
                    cout << aa[k] << " ";
                cout << "\n";
            }
        }
        cout << "\n";
    }
    cout << "내림차순 정렬\n";
    for (int i = 0; i < n; i++)
        cout << aa[i] << " ";
    return 0;
}
