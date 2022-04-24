/*
5번문제에서 처음 코드가 주어진 부분(즉 5번 문제에서 (1),(2)를 제외한 부분)을
Student를 class로 정의해서 같은 기능을 하도록 코드를 수정하시오.
*/

#include <iostream>
using namespace std;

#define N 5
class Student
{
    string name;
    int math;
    int eng;
    double total;

public: Student() {}
    Student(string n, int m, int e) {
        name = n;
        math = m;
        eng = e;
        total = double(m) * 0.6 + double(e) * 0.4;
    }
}; // 답안에 세미콜론 안 찍음

void main()
{
    Student S[N];
    S[0] = Student("John", 95, 95);
    S[1] = Student("Kim", 95, 95);
    S[2] = Student("Lee", 95, 95);
    S[3] = Student("Chris", 95, 95);
    S[4] = Student("Young", 95, 95);

    // 이후 답안 작성 안 함, 생략
}
