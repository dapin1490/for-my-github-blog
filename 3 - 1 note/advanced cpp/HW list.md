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
