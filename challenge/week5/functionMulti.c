#include <stdio.h>

int multiF(long value);		// >> 피호출자 : 함수 원형 선언하기

void main()		// >> 호출자
{
	printf("1부터  2까지의 곱은 %d\n", multiF(2));		// 1부터 2까지의 곱 함수&value 입력
	printf("1부터  3까지의 곱은 %d\n", multiF(3));		// 1부터 3까지의 곱 함수&value 입력
	printf("1부터  5까지의 곱은 %d\n", multiF(5));		// 1부터 5까지의 곱 함수&value 입력
}

int multiF(long value)	// multiF 함수 정의 ↓
{
	int i = 1;			// int 변수 i 에 1 부여
	int multi = i;		// int 변수 multi 에 1 부여

	while (i <= value)	// while 함수 사용하여 함수 기능 구현
	{
		multi = multi * i;	// multi 변수에 i 곱하고 다시 multi에 값 저장 [반복]
		i++;
	}
	return multi;		// multi 값 반환
}