#include <stdio.h>

int main() {
	int choice;
	// 사용자에게 보일 선택지 입력
	printf("1. 파일 저장 \n");
	printf("2. 저장 없이 닫기 \n");
	printf("3. 종료 \n");
	scanf_s("%d", &choice);	// 사용자 입력함수

	if (choice == 1) {	// 선택지 1을 선택한 경우와 출력문
		printf("파일을 저장합니다.");
	}
	else if (choice == 2) {	// 선택지 2를 선택한 경우와 출력문
		printf("저장 없이 닫습니다.");
	}
	else if (choice == 3) {	// 선택지 3을 선택한 경우와 출력문
		printf("종료합니다.");
	}
	else {	// 1~3값을 입력하지 않은 경우
		printf("잘못 입력하셨습니다.");
	}
	return 0;
}