/*
Stack강의슬라이드 12~14페이지 코드를 참조하여 다음의 코드를 완성하시오.
두개의 데이터를 넣고 빼는 void push_two (int first, int second)와
void pop_two(int* p_first, int* p_second)를 구현하고,
main()에서 두 함수를 호출하는 예시(pop의 경우 나온 데이터 출력)까지 구현하시오.
(first가 먼저 들어가는(나오는) 데이터를 second를 두번째로 들어가는(나오는) 데이터를 의미한다.)
추가되는 코드만 작성하면 됩니다.
*/

/*
#include <stdio.h>
#include <stdlib.h>

class ArrayStack
{
    // 강의 슬라이드에 있는 코드는 생략
    void pop_two(int first, int second) {
        if (isFull()) error("스택 포화 에러");
        data[++top] = first;
        if (isFull()) error("스택 포화 에러");
        data[++top] = second;
    }
    void pop_two(int* p_first, int* p_second) {
        if (isEmpty()) error("스택 공백 에러");
        *p_first = data[top--]; // 들여쓰기 헷갈려서 탭 하나 더 들였음
        if (isEmpty()) error("스택 공백 에러");
        *p_second = data[top--]; // 들여쓰기 헷갈려서 탭 하나 더 들였음
        return;
    }
}; // 또 세미콜론 안 찍음

int main()
{
    ArrayStack st;
    st.push_two(1, 2);
    int p_f, p_s;
    st.pop_two(%p_f, %p_s);
    printf("first : %2d, second : %2d", p_f, p_s);
    return 0;
}
*/