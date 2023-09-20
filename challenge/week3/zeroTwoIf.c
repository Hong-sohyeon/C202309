#include <stdio.h>

int main() {
	int num = 0;
	// 사용자에게 보일 문장 입력
	printf("숫자를 입력하시오: ");
	scanf_s("%d", &num);	// 사용자 입력함수
	
	if (num == 0) {	// 숫자 0을 입력한 경우 zero 출력
		printf("zero");
	}
	else if (num == 1) {	// 숫자 1을 입력한 경우 one 출력
		printf("one");
	}
	else if (num == 2) {	// 숫자 2를 입력한 경우 two 출력
		printf("two");
	}
	else {	// 0~2 외의 값 입력 시 아래 문장 출력
		printf("not 0~2");
	}
	return 0;
}