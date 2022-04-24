/*
교안에 있는 버블정렬은 아래 그림(생략)처럼 옆의 숫자들끼리 비교해가며
매회 뒤에서부터 큰 수를 채워 넣는 방식으로 구현되어 있습니다.
이와 반대로 매회 앞에서부터 작은 수를 채워넣는 방식으로 오름차순 정렬이 되는 코드를 완성하시오.
이번에는 숫자는 int aa[5] = { 5, 39, 2, 44, 23 }으로 주어졌다고 가정한다.
(중간 과정이 출력 안 되도 상관없음)
*/

#include <iostream>
using namespace std;

int main()
{
    int aa[5] = { 5, 39, 2, 44, 23 };
    int n = 5;

    for (int i = n - 1; i > 0; i--) {
        for (int j = n - 1 - i; j >= 0; j--) {
            if (aa[j] > aa[j + 1]) {
                int temp = aa[j];
                aa[j] = aa[j + 1];
                aa[j + 1] = temp;
            }
        }
    }

    cout << "오름차순 정렬\n";
    for (int i = 0; i < n; i++)
        cout << aa[i] << " ";
    
    return 0;
}
