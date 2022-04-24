/*
아래 코드는 편입생 지원자 중 합격자 2명의 이름을 출력하려는 프로그램의 일부이다.
수학 점수와 영어 점수를 6:4 로 반영하여, 총점이 높은 사람이 합격하는 방식이다.
아래 (1), (2) 부분을 완성하시오..
*/

#include <iostream>
using namespace std;

#define N 5
typedef struct
{
char name[10];
int math;
int eng;
/// (1) ////
}Student;

void main()
{
   Student S[N];
   memcpy(S[0].name, "John", 10);
   S[0].math = 95;
   S[0].eng = 95;
   memcpy(S[1].name, "Kim", 10);
   S[1].math = 100;
   S[1].eng = 90;
   memcpy(S[2].name, "Lee", 10);
   S[2].math = 85;
   S[2].eng = 95;
   memcpy(S[3].name, "Chris", 10);
   S[3].math = 88;
   S[3].eng = 100;
   memcpy(S[4].name, "Young", 10);
   S[4].math = 92;
   S[4].eng = 80;

   /// (2) ///   

}
