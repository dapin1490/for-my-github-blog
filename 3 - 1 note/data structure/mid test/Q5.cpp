/*
Queue 강의슬라이드 13~15페이지 코드를 참조하여 다음의 코드를 완성하시오.
두개의 데이터를 넣고 빼는 void enqueue_two (int first, int second)와
void dequeue_two(int* p_first, int* p_second)를 구현하고,
main()에서 두 함수를 호출하는 예시(dequeue의 경우 나온 데이터 출력)까지 구현하시오.
(first가 먼저 들어가는(나오는) 데이터를 second를 두번째로 들어가는(나오는) 데이터를 의미한다.)
*/

/*
class CircularQueue {
    // 강의자료에 이미 있는 코드 생략
    void enqueue_two (int first, int second) {
        if (isFull()) error("큐가 포화 상태");
        else {
            rear = (rear + 1) % MAX_QUEUE_SIZE;
            data[rear] = first;
        }
        if (isFull()) error("큐가 포화 상태");
        else {
            rear = (rear + 1) % MAX_QUEUE_SIZE;
            data[rear] = second;
        }
    }
}
*/
