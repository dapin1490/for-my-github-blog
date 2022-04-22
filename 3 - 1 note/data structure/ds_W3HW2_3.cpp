#include <iostream>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	/*
	주어진 2차원 행렬에 대해 최대값의 위치와 최대값을 출력하는 프로그램을 작성하시오.
	int arr[3][4] = {  { 3, 4,10, 1}, 
                          { 5,12,11, 8},
                          {11,16, 4, 9},
                       };
	<출력 예시>
	최대값 위치 = 3행 2열
	최대값 = 16
	*/

	int arr[3][4] = { {3, 4, 10, 1}, {5, 12, 11, 8}, {11, 16, 4, 9} };

	int maxi = arr[0][0];
	int mini = arr[0][0];
	int maxrow = 0, maxcol = 0;
	int minrow = 0, mincol = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr[i][j] > maxi) {
				maxi = arr[i][j];
				maxrow = i;
				maxcol = j;
			}
			if (arr[i][j] < mini) {
				mini = arr[i][j];
				minrow = i;
				mincol = j;
			}
		}
	}

	cout << "최댓값 위치 = " << maxrow + 1 << "행 " << maxcol + 1 << "열\n최댓값 = " << maxi << "\n";
	cout << "최솟값 위치 = " << minrow + 1 << "행 " << mincol + 1 << "열\n최솟값 = " << mini;

	return 0;
}