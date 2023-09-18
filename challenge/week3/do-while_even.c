#include <stdio.h>

int main()
{
	int i = 0;	// i에 0 선언
	do {
		i++;

		if (i % 2 == 0) {	// i가 짝수이면 반복문 처음으로
			continue;
		}
		printf("%d Hello World! \n", i);	// 출력문 작성
	} while (i < 10);	// 조건 설정
	return 0;
}