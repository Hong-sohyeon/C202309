#include <stdio.h>

int hapf(int value);	// >> 피호출자 : 함수 원형 선언하기

int main()		// >> 호출자
{
	printf("1부터   10까지의 합은 %d\n", hapf(10));		// 1부터 10까지의 합 함수&value 입력
	printf("1부터  100까지의 합은 %d\n", hapf(100));	// 1부터 100까지의 합 함수&value 입력
	printf("1부터 1000까지의 합은 %d\n", hapf(1000));	// 1부터 1000까지의 합 함수&value 입력
	return 0;
}

int hapf(int value)		// hapf 함수 정의 ↓
{
	int i = 1;			// int 변수 i 에 1 부여
	int hap = 0;		// int 변수 hap 에 0 부여

	while ( i <= value )// while 함수 사용하여 함수 기능 구현
	{
		hap = hap + i;	// hap 변수에 i 더하고 다시 hap에 값 저장 [반복]
		i++;
	}
	return hap;			// hap 값 반환
}