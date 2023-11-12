#include <stdio.h>

// 함수선언
double summation(double a, double b, double*result);	// 더하기 함수
double subtraction(double a, double b, double*result);		// 빼기 함수
double multification(double a, double b, double*result);	// 곱하기 함수
double division(double a, double b, double*result);		// 나누기 함수



int main()
{
	// 변수 선언 및 초기화
	double a = 2, b = 3;
	double result;

	// 더하기
	summation(a, b, &result);
	printf("%.0lf + %.0lf = %.2lf \n", a, b, result);

	// 빼기
	subtraction(a, b, &result);
	printf("%.0lf - %.0lf = %.2lf \n", a, b, result);

	// 곱하기
	multification(a, b, &result);
	printf("%.0lf * %.0lf = %.2lf \n", a, b, result);

	// 나누기
	division(a, b, &result);
	printf("%.0lf / %.0lf = %.2lf \n", a, b, result);

	return 0;
}

// 더하기 함수 정의
double summation(double a, double b, double*result) {
	*result = a + b;
}

// 빼기 함수 정의
double subtraction(double a, double b, double*result) {
	*result= a - b;
}

// 곱하기 함수 정의
double multification(double a, double b, double*result) {
	*result= a * b;
}

// 나누기 함수 정의
double division(double a, double b,double*result) {
	// 0으로 나누면 오류가 나도록 조건 설정
	if  (b == 0) {
		printf("0으로 나눌 수 없습니다. 계산되지 않습니다.");
		return 0;
	}
	else {
		*result= a / b;
	}

}