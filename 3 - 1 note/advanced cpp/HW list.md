1. [H_cpp_W3HW1.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/advanced%20cpp/H_cpp_W3HW1.cpp)   
1부터 입력받은 수(n)까지의 숫자중 2의 배수이면서 5의 배수인 수의 누적합과 갯수를 화면에 출력하는 프로그램을 작성하시오.   
   
   
2. [H_cpp_W4HW2.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/advanced%20cpp/H_cpp_W4HW2.cpp)   
정수 n을 입력받아 n개의 정수형 동적 배열을 생성하고 n개의 정수를 입력받아 최대값과 최소값을 출력하는 프로그램을 작성하시오.   
\- **포인터** 동적 배열 할당   
\- 최댓값과 최솟값 **선형 탐색**   
   
   
3. [H_cpp_W4HW3.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/advanced%20cpp/H_cpp_W4HW3.cpp)   
과제 2를 `void get_max_min(int* p_arr, int* p_max, int* p_min)` 함수를 구현하여 푸세요. max와 min은 `main` 함수에서 출력되어야 함.   
\- 비포인터 변수 **주소(&)를 함수로 전달**, 함수 내에서 포인터로 사용   
\- **선형 탐색**   
   
   
4. [H_cpp_W4HW4.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/advanced%20cpp/H_cpp_W4HW4.cpp)   
반지름을 입력받아 원주와 원의 넓이를 구하는 프로그램을 작성하시오. 이때, 원주율은 `3.14`를 사용하고, `void get_circle_info(double r, double* p_circumference, double* p_area)` 함수를 구현하여, 원주와 원의 넓이는 `main` 함수에서 출력하도록 하세요.   
\- 비포인터 변수 **주소(&)를 함수로 전달**, 함수 내에서 포인터로 사용   
   
   
5. [H_cpp_W5HW5.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/advanced%20cpp/H_cpp_W5HW5.cpp)   
선택 정렬 교안에 있는 숫자 데이터를 1차원 배열에 초기화하여, 예시처럼 중간 과정이 출력되는 프로그램을 작성하시오.   
\- **선택 정렬**(과정 출력)   
   
   
6. [H_cpp_W5HW6.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/advanced%20cpp/H_cpp_W5HW6.cpp)   
다음의 중간고사 성적을 `88, 90, 70, 95, 100, 66` 포인터 동적할당을 통해 입력하고, 선택정렬을 이용하여 내림차순으로 정렬하여 화면에 출력하시오.   
\- **포인터** 동적 할당 입력받기   
\- **선택 정렬**   
   
   
7. [H_cpp_W5HW7.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/advanced%20cpp/H_cpp_W5HW7.cpp)   
아래 성적(2차원 배열 형태)을 2차원 배열에 초기화 하고, 총점이 높은 순서대로 화면에 성적을 출력하는 프로그램을 작성하시오.   
\- 2차원 배열 **선택 정렬**   
   
   
8. [H_cpp_W6HW8.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/advanced%20cpp/H_cpp_W6HW8.cpp)   
과제 6과 동일한 예시를 다른 방식의 선택정렬로 정렬하시오(동적할당 안 해도 됨). 다른 방식이란, 교안의 선택 정렬은 배열의 앞부분부터 업데이트를 하고 있습니다. 뒷부분부터 업데이트 하여 동일한 결과를 얻도록 프로그램을 작성하시오.   
\- **역순 선택 정렬**   
   
   
9. [H_cpp_W6HW9.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/advanced%20cpp/H_cpp_W6HW9.cpp)   
과제6과 같은 데이터를 사용하여, 버블 정렬 교안처럼 출력되도록 코드를 수정해보세요.   
\- **버블 정렬**(과정 출력)   
   
   
10. [H_cpp_W6HW10.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/advanced%20cpp/H_cpp_W6HW10.cpp)   
이름과 수학점수를 멤버 변수로 하는 구조체 Student를 정의하고 Student 타입의 배열을 정의하여 점수가 제일 높은 사람의 이름과 점수를 출력하는 프로그램을 작성하시오.    
\- **구조체 정의**   
\- **구조체** 멤버 변수 **선형 탐색**   
   
   
11. [H_cpp_W6HW11.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/advanced%20cpp/H_cpp_W6HW11.cpp)   
과제 10의 데이터를 그대로 사용하여, 내림 차순으로 이름과 성적을 보여주세요.   
\- **구조체**   
\- **선택 정렬**   
   
   
12. [H_cpp_W9HW12.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/advanced%20cpp/W9/H_cpp_W9HW12.cpp)   
조건에 따라 `class Person`을 만들고 제시된 프로그램을 구현.   
(1) 수학 점수 상위 3명을 출력하는 프로그램   
(2) (1)의 프로그램을 함수 `void display_top3(Person *p, int n)`로 구현   
(3) 영어, 수학 점수를 3:7로 반영하여 상위 3명을 출력하는 프로그램   
(4) 조건에 맞게 로그인 프로그램 구현   
   
   
13. (13-1) [H_cpp_W10HW13-1.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/advanced%20cpp/H_cpp_W10HW13-1.cpp)   
main에서 배열 선언 후 함수 정의하여 정렬   
\- **선택 정렬**   
   
   
13. (13-2) [H_cpp_W10HW13-2.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/advanced%20cpp/H_cpp_W10HW13-2.cpp)   
swap 함수 정의 후 사용   
   
   
13. (13-3) [H_cpp_W10HW13-3.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/advanced%20cpp/H_cpp_W10HW13-3.cpp)   
13-1과 13-2 합치기   
   
   
13. (13-4) [H_cpp_W10HW13-4.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/advanced%20cpp/H_cpp_W10HW13-4.cpp)   
조건에 따라 `class Hitter`를 만들고 인스턴스 생성 후 조건에 따라 정렬   
\- **클래스** 생성 및 활용   
\- **선택 정렬**   
   
   
14. (14-1) [H_cpp_W11HW14-1.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/advanced%20cpp/H_cpp_W11HW14-1.cpp)   
main에서 배열 선언하고 두 가지 order에 따라 정렬   
\- **선택 정렬**   
   
   
14. (14-2) [H_cpp_W11HW14-2.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/advanced%20cpp/H_cpp_W11HW14-2.cpp)   
지정된 멤버 변수를 포함하는 `class Rect`를 만들고 주어진 인스턴스 생성 후 조건에 따라 정렬   
\- **클래스** 생성 및 활용   
\- **선택 정렬**   
   
   
14. (14-3) opencv 예제 코드 실행 후 결과 이미지 캡쳐하여 제출   
   
   
14. (14-4) [H_cpp_W11HW14-4.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/advanced%20cpp/H_cpp_W11HW14-4.cpp)   
14-2에서 생성한 클래스를 opencv 예제 코드에 적용   
\- **`opencv`** 활용   
   
   
15. (15-1) [H_cpp_W12HW15-1.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/advanced%20cpp/H_cpp_W12HW15-1.cpp)   
주어진 조건에 따라 `class Rect` 만들고 인스턴스 생성 후 정렬 함수 만들어 정렬   
\- **클래스** 생성 및 활용   
\- **선택 정렬**   
\- 함수에 함수를 인자로 전달   
   
   
15. (15-2) [H_cpp_W12HW15-2.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/advanced%20cpp/H_cpp_W12HW15-2.cpp)   
`class Rect` 만들고 `swap` 함수 구현   
   
   
15. (15-3) [H_cpp_W12HW15-3.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/advanced%20cpp/H_cpp_W12HW15-3.cpp)   
15-1과 15-2 합치기   
   
   
15. (15-4) [H_cpp_W12HW15-4.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/advanced%20cpp/H_cpp_W12HW15-4.cpp)   
opencv 예제 코드에 `class Rect` 끼워넣어 지정된 크기의 이미지 안에서 튕기며 돌아다니는 사각형 출력   
\- **클래스** 생성 및 활용   
\- `opencv` 활용   
   
   
16. (16-1) [H_cpp_W13HW16-1.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/advanced%20cpp/H_cpp_W13HW16-1.cpp)   
`class MyRect` 만들고 주어진 인스턴스 생성해 넓이가 넓은 순으로 정렬하는 프로그램 작성. `void Sort_Rect(MyRect* p_arr, int n)` 함수를 만들어 정렬하고, `opencv` 코드를 이용하여, 왼쪽에서 오른쪽 순서로 x, y를 변경하여 해당하는 사각형을 겹치지 않게 출력.   
   
   
16. (16-2) [H_cpp_W13HW16-2.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/advanced%20cpp/H_cpp_W13HW16-2.cpp)   
과제 15-4번의 충돌 관련 코드를 `MyRect`의 멤버 함수로 구현해서 동일한 기능을 수행하도록 하라   
   
   
16. (16-3) [H_cpp_W13HW16-3.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/advanced%20cpp/H_cpp_W13HW16-3.cpp)   
16-2번을 기반으로 `class MyGameTable` 선언, 게임판의 위치와 크기 `((x,y,w,h) = (0,0,640,480))`와 `MyRect`의 객체를 멤버 변수로 구현하여 동일한 기능을 수행하도록 하라   
   
   
16. (16-4) [H_cpp_W13HW16-4.cpp](https://github.com/dapin1490/study-note/blob/main/3%20-%201%20note/advanced%20cpp/H_cpp_W13HW16-4.cpp)   
16-3번을 기반으로 `MyRect`의 객체 5개를 멤버 변수로 하고, 위치와 크기는 랜덤하게 초기화한 후, 동일한 기능을 수행하도록 하라   
   
   
