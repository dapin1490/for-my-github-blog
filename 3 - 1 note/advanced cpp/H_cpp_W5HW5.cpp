#include <iostream>
using namespace std;

int main()
{
    // 선택 정렬 교안에 있는 숫자 데이터를 1차원 배열에 초기화하여,
    // 예시처럼 중간 과정이 출력되는 프로그램을 작성하시오.

    int ar[] = { 7, 4, 11, 9, 2 };
	int cnt = 0;

	cout << "The array before sort\n{ ";
	for (int i = 0; i < 5 - 1; i++) {
		cout << ar[i] << ", ";
	}
	cout << ar[5 - 1] << " }\n";

	for (int i = 0; i < 5 - 1; i++) {
		int idx = i;

		for (int j = i + 1; j < 5; j++) {
			cnt++;
            cout << "comparison " << ar[j] << " and " << ar[idx] << "\n";
			if (ar[j] < ar[idx]) {
				idx = j;
                cout << "key changed\n";
			}
		}

		int temp = ar[i];
		ar[i] = ar[idx];
		ar[idx] = temp;

        cout << "pass # " << i + 1 << "\n{ ";
	    for (int k = 0; k < 5 - 1; k++) {
		    cout << ar[k] << ", ";
	    }
	    cout << ar[5 - 1] << " }\n";
	}

	cout << "\nThe array after sort\n{ ";
	for (int i = 0; i < 5 - 1; i++) {
		cout << ar[i] << ", ";
	}
	cout << ar[5 - 1] << " }";

	cout << "\n\ntotal comparison count : " << cnt;
}
