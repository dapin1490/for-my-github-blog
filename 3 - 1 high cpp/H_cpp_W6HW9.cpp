#include <iostream>
using namespace std;

int main()
{
	/*
	과제6과 같은 데이터를 사용하여, 버블 정렬 교안처럼 출력되도록 코드를 수정해보세요.
	*/

	int* ar;
	int n;

	cout << "학생수 = ";
	cin >> n;

	ar = new int[n];
	for (int i = 0; i < n; i++)
		cin >> *(ar + i);

	for (int i = 0; i < n - 1; i++) {
        cout << "turn # " << i + 1 << "\n";
		for (int i = 0; i < n; i++)
			cout << *(ar + i) << " ";
		cout << "\n\n";

		for (int j = 0; j < n - 1 - i; j++) {
			if (*(ar + j) < *(ar + j + 1)) {
				int temp = *(ar + j);
				*(ar + j) = *(ar + j + 1);
				*(ar + j + 1) = temp;

                for (int i = 0; i < n; i++)
			        cout << *(ar + i) << " ";
		        cout << "\n\n";
			}
		}
	}

	cout << "내림차순 정렬\n";
	for (int i = 0; i < n; i++)
		cout << *(ar + i) << " ";

	delete[] ar;

	return 0;
}