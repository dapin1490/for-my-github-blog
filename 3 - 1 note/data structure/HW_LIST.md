과제 1 - [ds_W2HW1.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/data%20structure/ds_W2HW1.cpp)   
세 가지 방법으로 1부터 n까지의 합 구하기   
   
   
과제 2, 3 - [ds_W3HW2_3.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/data%20structure/ds_W3HW2_3.cpp)   
주어진 2차원 행렬에 대해 최대값의 위치와 최대값을 출력하는 프로그램을 작성하시오. + 최대값과 최대값의 위치뿐만 아니라, 최소값과 최소값의 위치도 출력, 단 이중 반복문은 1번만 사용.   
   
int arr[3]\[4] = { {3, 4, 10, 1}, {5, 12, 11, 8}, {11, 16, 4, 9} };   
   
<출력 예시>   
최대값 위치 = 3행 2열   
최대값 = 16   
최솟값 위치 =   
최솟값 =   
   
   
과제 4 : 강의 자료 코드 빈 프로젝트에 넣고 실행하기   
   
   
과제 5 - [ds_W4HW5.h](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/data%20structure/ds_W4HW5.h)   
void add(Polynomial a, Polynomial b)를 this 포인터 없이 구현   
   
   
과제 6   
스택 교안의 12~14 페이지의 코드 실습. 에러메세지가 나올 수 있는 상황 추가.   
   
   
과제 7, 8 - [ds_W6 폴더](https://github.com/dapin1490/study-note/tree/main/3%20-%201%20note/data%20structure/ds_W6)   
7 : 괄호 체크 소스 코드 실습. 괄호에 문제가 없는 경우와 문제가 있는 경우(왼쪽 괄호가 많은 경우, 오른쪽 괄호가 많은 경우 등)를 확인.   
8 : 괄호 문제가 발생했을 때, 문제에 따라 "왼쪽괄호가 많아요", "오른쪽 괄호가 많아요", "왼쪽,오른쪽 괄호가 매칭되지 않아요"가 출력이 될 수 있도록 코드를 수정하라.   
   
   
과제 9 - [ds_W9HW9.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/data%20structure/ds_W9HW9.cpp)   
가로, 세로를 인자로 넘겨받아 삼각형의 넓이와 직사각형의 넓이를 구하는 함수 `get_area(int width, int height, int* p_area3, int* p_area4)` 구현하여, `main` 함수에서 해당 함수를 호출하고, 결과도 `main`함수에서 출력하는 프로그램을 작성   
   
   
과제 10 - [ds_W10HW10.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/data%20structure/ds_W10HW10.cpp)   
누적합을 재귀호출 방식으로 구현하되, 중간과정이 출력되도록 프로그램을 작성.   
   
   
과제 11 - [ds_W10HW11.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/data%20structure/ds_W10HW11.cpp)   
아래 정의 된 피보나치 수열을 recursion으로 구현하고, F8을 화면에 출력.   
```cpp
F0 = 1
F1 = 1
Fn = 2 * Fn-1 + Fn-2
```   
   
   
과제 12 - [ds_W10HW12.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/data%20structure/ds_W10HW12.cpp)   
과제11을 iteration(반복) 형태로 구현하시오.   
   
   
과제 13 - [ds_W10HW13.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/data%20structure/ds_W10HW13.cpp)   
5장 30~33페이지 코드를 참고하세요.   
Student 클래스를 상속받지 말고, Node의 Member variable에 char data가 추가하여, 스택 코드를 만들고, 다음의 괄호 { \[ ( 를 순서대로 스택에 넣는다.   
   
   
과제 14-1 - [ds_W11HW14-1.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/data%20structure/ds_W11HW14-1.cpp)   
사각형의 너비와 높이를 입력받고, `void getRectInfo(int width, int height, int* p_area, int* p_perimeter)` 함수 구현하여 넓이와 둘레 구하기   
   
   
과제 14-2 - [ds_W11HW14-2.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/data%20structure/ds_W11HW14-2.cpp)   
`int front`, `int rear`, `int data[8]`을 전역변수로 두어 원형큐를 구현하고, 중간고사 6번의 순서로 enqueue(), dequeue()를 하고 매 이벤트시 queue에 있는 내용을 화면에 출력.   
  
  
과제 14-3 - [ds_W11HW14-3.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/data%20structure/ds_W11HW14-3.cpp)   
Node 와 LinkedStack 클래스와 기존에 제공한 괄호체크 코드를 합쳐서 하나로 구현하고, 중간고사 3번 문제에 적용.   
   
   
과제 14-4 - [ds_W11HW14-4.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/data%20structure/ds_W11HW14-4.cpp)   
`F0 = 1`, `F1 = 1`, `F2 = 1`, `Fn = 3 * Fn-1 + 2 * Fn-2 + Fn-3` 을 reucursion 방식으로 `fibo_recursion()`을 구현하고 iteration 방식으로 `fibo_iteration()`을 구현해서, 각 방식에 대해서 F100를 화면에 출력   
   
   
과제 15-1 - [ds_W12HW15-1.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/data%20structure/ds_W12HW15-1.cpp)   
`int aa[5] = {100,89,90,99,102}`를 `main()`함수에서 선언하고, 최대값과 최소값을 구해주는 void 타입의 함수 `void getMaxMin (int* p_aa, int* p_max, int* p_min)`로 구현하여, 결과는 `main()`함수에서 출력.   
   
   
과제 15-2 - [ds_W12HW15-2.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/data%20structure/ds_W12HW15-2.cpp)   
`const int front=-1`, `int rear`, `int data[8]`을 전역변수로 두어 선형큐를 구현하고, 중간고사 6번의 순서로 `enqueue()`, `dequeue()`를 하고 매 이벤트시 queue에 있는 내용을 화면에 출력.   
   
   
과제 15-3 - [ds_W12HW15-3.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/data%20structure/ds_W12HW15-3.cpp)   
나이, 몸무게를 member variable로 갖는 class Person을 선언하고, 이를 담는 원형큐를 구현. 1초에 한명씩 랜덤하게 발생한 나이(0\~100), 몸무게(0\~200)을 가진 사람이 enqueue 되고, 최초 사람이 enqueue된 이후 1초 후부터 랜덤하게 사람이 dequeue 되도록 프로그램을 구현한다. ([1초 지연을 위해 Sleep() 함수를 활용하기 바랍니다.](https://hijuworld.tistory.com/52))   
   
   
과제 15-4 - [ds_W12HW15-4.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/data%20structure/ds_W12HW15-4.cpp)   
리스트 강의 슬라이드 21~25페이지의 코드를 main4.cpp 파일 하나로 구현해서 실행   
   
   
과제 15-5 - [ds_W12HW15-5.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/data%20structure/ds_W12HW15-5.cpp)   
recursion 방식의 합병 정렬 코드를 활용하여, iteration 방식으로 구현.   
   
   
과제 16-1 - [ds_W13HW16-1.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/data%20structure/ds_W13HW16-1.cpp)   
`int aa[5] = {100, 89, 90, 99, 102}`를 `main()`함수에서 선언하고, 숫자를 서로 바꿔주는(a->c, c->b, b->a) void 타입의 함수 `void getMix(int* p_a, int* p_b, int* p_c)`로 구현하여, 결과는 main()함수에서 출력   
   
   
과제 16-2 - [ds_W13HW16-2.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/data%20structure/ds_W13HW16-2.cpp)   
`int front`, `int rear`, `int cnt`, `int data[8]`을 전역변수로 두어 원형큐를 구현. 새로 추가되는 cnt는 Queue에 저장되어 있는 중간고사 6번의 순서로 enqueue(), dequeue()를 하고 매 이벤트시 queue에 있는 내용을 화면에 출력.   
   
   
과제 16-3 - [ds_W13HW16-3.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/data%20structure/ds_W13HW16-3.cpp)   
(2)에서 전역변수로 구현한 것을 class 로 바꾸어 구현.   
   
   
과제 16-4 - [ds_W13HW16-4.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/data%20structure/ds_W13HW16-4.cpp)   
과제15의 (4)를 다시 해보고, `int getNumlessThan(int th)` th보다 작은 원소의 개수를 리턴하는 멤버함수를 추가해서, `main()`에서 활용   
   
   
과제 16-5 - [ds_W13HW16-5.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/data%20structure/ds_W13HW16-5.cpp)   
과제15의 (5)를 iteration 방식 구현을 for문을 사용하여 완료.   
   
---
   
퀴즈 1 : 주어진 알고리즘의 시간복잡도 구하기. `O(logn)`
```cpp
int algorithm(int n) {
	int k = 0;
	while (n > 1) {
		n = n / 2;
		k++;
	}
	return k;
}
```   
   
   
퀴즈 2 : 멤버함수 trim()과 display()의 코드를 분석하여 실행 결과의 특징을 서술.   
trim() : 다항식의 최고차항부터 계수가 0인지 검사하여 계수가 0이 아닐 때까지 차수를 감소시킴. (추가 : == 계수가 0이 되어 불필요한 최고차항을 지움.)   
display() : 전달받은 문자열로 시작하고, 이 함수를 호출한 객체의 식을 출력. 계수가 0이 아닌 항만 출력. 또한 계수가 1인 항은 계수를 출력하지 않음.   
답안 참고 : 강의 교재(ppt 말고 책) 84쪽에 1번의 (3), (4)번 문제로 출제되어 있음.   
   
   
퀴즈 3 : 오류가 났을 때 그 상태를 보고 프로그램을 종료시키기 위해서. (추가 : 파이썬의 raise와 비슷함.)   
   
   
퀴즈 4 : 괄호 체크 코드에 대해 (3+5} 를 넣어주면 정상으로 처리가 된다. 무엇이 문제인지 서술   
스택에서 pop을 할 때 괄호의 종류가 다르면 오류를 발생시키고 프로그램을 중단해야 하는데 그러지 않았음.   
   
   
퀴즈 5 : 트리의 탐색 순서 - DFS(깊이 우선)와 BFS(너비 우선)   
   
   
퀴즈 6 : 강의 코드 수정 후 예상 결과 서술
