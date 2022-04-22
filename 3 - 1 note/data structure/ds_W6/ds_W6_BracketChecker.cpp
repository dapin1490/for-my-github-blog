#include "ds_W6_ArrayStack.h"

int CheckMatching(const char* filename ) {
	// 플래그 추가 : false일 때는 문제가 없음, true일 때는 문제가 있음
	bool flag = false;
	
	int nLine = 1, nChar = 0;
	char	ch;
	ArrayStack	stack;

	FILE* fp; 
	fopen_s(&fp, filename, "r"); // 파일 열기
	if (fp == NULL) {
		error("Error: 파일 존재하지 않습니다.\n");
		return 0; // 파일이 존재하지 않을 때 오류 문구 출력 후 함수 실행을 바로 종료함
		// main() 함수에 쓰인 return 0;와는 다름 : 뒤에 남은 코드를 실행하지 않고
		// 함수가 호출된 곳으로 돌아가기 위해 사용, 이 함수의 반환형이 int이기 때문에
		// 정수 값을 반드시 반환해야 하므로 0 반환. 반환하는 정수는 무엇이든 상관 없음.
	}

	while ((ch = getc(fp)) != EOF) {

		printf("%c", ch);

		nChar++;
		if( ch == '\n' ) nLine++;
		
		if( ch == '[' || ch == '(' || ch == '{' )
			stack.push(ch);
		else if( ch == ']' || ch == ')' || ch == '}' ) {
			int prev = stack.pop();
			if (prev == -1) { // pop() 함수 수정됨 헤더 파일 확인
				printf("오른쪽 괄호가 더 많습니다\n");
				flag = true; // 오류가 있으므로 플래그 변경
				break; // 반복문에서 탈출
			}
			else if ((ch == ']' && prev != '[')
				|| (ch == ')' && prev != '(')
				|| (ch == '}' && prev != '{')) {
				printf("왼쪽, 오른쪽 괄호가 매칭되지 않아요\n");
				flag = true; // 오류가 있으므로 플래그 변경
				break; // 반복문에서 탈출
			}
		}
	}
	fclose(fp); // 사용한 파일 닫기

	printf("[%s] 파일 검사결과:\n", filename );
	if (stack.isEmpty() == false) { // 스택이 비어있지 않을 경우 : 왼쪽 괄호가 남았다
		printf("왼쪽 괄호가 더 많습니다\n");
		printf("  오류발견 (라인수=%d, 문자수=%d)\n\n", nLine, nChar);
	}
	else if (flag) { // 스택은 비어있지만 오류가 발생한 상태일 경우
					// : 이전에 오류 문구가 이미 출력되었을 것이므로 오류 카운트만 출력
		printf("  오류발견 (라인수=%d, 문자수=%d)\n\n", nLine, nChar); // 이게 오류 카운트
	}
	else { // 위의 모든 선택문을 다 지나왔다면 정상 실행
		printf("  괄호정상 (라인수=%d, 문자수=%d)\n\n", nLine, nChar);
	}
	return stack.isEmpty();
}
void main()
{
	// 파일 경로는 절대경로와 상대경로가 있음
	// 절대경로 : 하드디스크 드라이브부터 시작해 파일이 실제 있는 곳까지 그 경로를 모두 표시함
	// 상대경로 : 현재 이 소스 코드의 파일이 있는 폴더를 기준으로 상대적 위치를 표현함
	// ex) "../bracket.txt"라고 쓰면 이 소스 코드의 폴더로부터 한 단계 상위의 폴더로 나간 다음 지정한 텍스트 파일을 찾음
	CheckMatching("ds_W6_bracket_test.txt");
}
