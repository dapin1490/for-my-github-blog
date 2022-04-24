/*
포인터와연결리스트의 LinkedStack 코드(31~33페이지)를 참조하여,
학번이 id (함수 입력 파라미터임)인 학생의 이름과 학과를 화면에 출력하는 void printStudent(int id)를 추가하고,
main()에서 해당 함수를 호출하는 것까지 작성하시오. (해당하는 학생이 없을 경우 없다고 출력해야함.)
*/

/*
void printStudent(int id) {
    for (Node* p = top; p != NULL; p = p->link) { // p->link 는 (*p).link 와 같다
        int value = p->getId(); // Student 클래스에서 클래스 내부 변수의 값을 받는 getter 함수가 없어서 있다고 가정함
        if (value == id) {
            p->display();
            return;
        }
    }
    // 반복문이 끝나면 값이 없는 것
    printf("해당하는 학생 없음");
    return;
}

int main()
{
    LinkedStack ls;
    ls.push(new node(20220424, "dlrbwnd", "국어국문학과"));
    ls.printStudent(20220424); // "dlrbwnd"의 정보 출력
    ls.printStudent(12345678); // 해당 학생 없음

    return 0;
}
*/
