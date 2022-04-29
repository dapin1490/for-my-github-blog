/*
아래 알고리즘(이미지 생략)을 맨 아래 함수 코드로 완성하고,
the worst case에 대한 Time Complexity를 Big O notation으로 표기하시오
(풀이 과정 없이 답만 적으면 0점 처리합니다).
(List는 숫자가 오름 차순으로 정렬된 배열로 가정하고 푸세요.)
*/

#include <iostream> // 이 두 줄은 답안에 작성 안 함
using namespace std;

/*
int algorithm(int key, int[] List) // 왜 오류나는지 모르겠음
{
    int LI = 0;
    int HI = size(List) - 1; // 배열 크기를 이렇게 간단히 구할 수 없긴 한데 그것까지 생각할 시간이 없었음
        // 교수의 답안
        // sizeof(List) / sizeof(int) - 1;
		// 리스트가 함수로 전달된 것이기 때문에 이 방법도 물론 오류가 난다. 교수가 문제를 잘못 냈다. 답안은 어떻게 쓰든 정답처리한다고 함.
    int Mid = (LI + HI) / 2; // 이 줄이 while 안에 들어가야 맞음!!! 근데 시험볼때는 헷갈려서 밖에 썼음
    while (LI <= HI) {
        if (List[Mid] == key)
            return Mid;
        else if (key < List[Mid])
            HI = Mid - 1;
        else
            LI = Mid + 1;
    }
    return -1;
}
*/

/*
시간복잡도 : List의 크기를 n이라고 했을 때 the worst case는 while 내에서 값을 반환하지 못하고 실패했을 경우이다. 이때 반복문은 List 크기의 절반인 n/2만큼 실행되며, 가장 처음 검사한 List[Mid] 값이 key보다 작았다면 반복문 내에서는 한 반복당 선택문이 2번이므로 n/2 * 2 = n이고, 첫 번째 List[Mid]가 key보다 크거나 같았다면 한 반복당 선택문이 3번 실행되므로 n/2 * 3 = 3/2 * n, 어느쪽이든 시간복잡도는 O(n)이다.
*/
