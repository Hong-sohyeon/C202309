#include <stdio.h>

int main()
{
	int i = 0; // i 에 0 선언
	while (i < 10) {	// 조건 설정
		i++;
		if (i % 2 == 0) {	// i가 짝수이면 반복문 처음으로
			continue;
		}
		printf(" %d Hello World! \n", i);	// 출력할 문장

	}
	return 0;
}