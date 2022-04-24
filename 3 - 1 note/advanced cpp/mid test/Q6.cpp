/*
영어점수 배열 int eng[6] = {100,95,90,70,80,66} 를 main()에 선언하고,
배열의 주소를 포인터로 받아서 정렬하는 void sort(int* p_eng,int n, int order)를 호출하여,
order가 1일 때는 오름 차순을, order가 0일 때는 내림 차순을 main()에서 출력하는 프로그램을 작성하시오.
(n은 데이터의 개수를 의미하며, main에서 order를 다르게 하여 sort 함수를 2번 호출하여야 함.)
*/

#include <iostream>
using namespace std;

void sort2(int* p_eng,int n, int order); // 다시 쓴 답안
void sort(int* p_eng,int n, int order) { // 시험에 제출한 답안
    switch (order)
    {
    case 1:
        for (int i = 0; i < n - 1; i++) {
            int idx = i;
            for (int j = i + 1; j < n - 1; j++) {
                if (*(p_eng + j) < *(p_eng + idx))
                    idx = j;
            }
            int temp = *(p_eng + i);
            *(p_eng + i) = *(p_eng + idx);
            *(p_eng + idx) = temp;
        }
        break;
    case 0:
        for (int i = 0; i < n - 1; i++) {
            int idx = i;
            for (int j = i + 1; j < n - 1; j++) {
                if (*(p_eng + j) > *(p_eng + idx))
                    idx = j;
            }
            int temp = *(p_eng + i);
            *(p_eng + i) = *(p_eng + idx);
            *(p_eng + idx) = temp;
        }
        break;
    }
}

int main()
{
    int eng[6] = {100, 95, 90, 70, 80, 66};

    // 오름차순
    sort(eng, 6, 1);
    for (int i = 0; i < 6; i++)
        cout << eng[i] << " ";
    cout << "\n";
    
    // 내림
    sort(eng, 6, 0);
    for (int i = 0; i < 6; i++)
        cout << eng[i] << " ";

    return 0;
}

void sort2(int* p_eng,int n, int order) { // 다시 쓴 답안
    for (int i = 0; i < n - 1; i++) {
        int idx = i;
        for (int j = i + 1; j < n - 1; j++) {
            switch (order)
            {
            case 1:
                if (*(p_eng + j) < *(p_eng + idx))
                    idx = j;
                break;
            case 0:
                if (*(p_eng + j) > *(p_eng + idx))
                    idx = j;
                break;
            }
        }
        int temp = *(p_eng + i);
        *(p_eng + i) = *(p_eng + idx);
        *(p_eng + idx) = temp;
    }
}
