#include <stdio.h>

int main() {
    int floor;
    // 피라미드 층수 검수
    while (1) {
        printf("몇 층을 쌓으시겠습니까? (5~100): ");
        scanf_s("%d", &floor);

        if (floor >= 5 && floor <= 100) {
            break; // 올바른 층 수 입력 시 루프 종료
        }
        else {
            printf("5에서 100 사이의 층 수를 입력해주세요.\n");  // 올바르지 않은 범위의 숫자 입력 시 출력할 문구
        }
    }
    // 피라미드 쌓는 반복문 출력
    for (int i = floor; i > 0; i--) {
        for (int j = 0; j < floor - i; j++) {
            printf("S");  // S로 피라미드 왼쪽 공백 채우는 식
        }
        for (int k = 0; k < i * 2 - 1; k++) {
            printf("*");  // *로 피라미드 그리기
        }
        printf("\n");  // 줄바꾸기
    }
    return 0;
}