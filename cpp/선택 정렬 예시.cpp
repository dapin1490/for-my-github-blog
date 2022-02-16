#include <iostream>
#include <array>
using namespace std;

int main()
{
	array <int, 15> ar = { 3, 4, 2, 6, 8, 2, 9, 0, 4, 8, 7, 5, 2, 4, 0 };
	int cnt = 0;

	cout << "The array before sort\n{ ";
	for (int i = 0; i < ar.size() - 1; i++) {
		cout << ar.at(i) << ", ";
	}
	cout << ar.at(ar.size() - 1) << " }\n";

	for (int i = 0; i < ar.size() - 1; i++) {
		int idx = i;

		for (int j = i + 1; j < ar.size(); j++) {
			cnt++;
			if (ar.at(j) < ar.at(idx)) {
				idx = j;
			}
		}

		int temp = ar.at(i);
		ar.at(i) = ar.at(idx);
		ar.at(idx) = temp;
	}
	
	cout << "\nThe array after sort\n{ ";
	for (int i = 0; i < ar.size() - 1; i++) {
		cout << ar.at(i) << ", ";
	}
	cout << ar.at(ar.size() - 1) << " }";

	cout << "\n\ntotal comparison count : " << cnt;
	
	return 0;
}
