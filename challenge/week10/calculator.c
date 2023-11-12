#include <stdio.h>

// �Լ�����
double summation(double a, double b, double*result);	// ���ϱ� �Լ�
double subtraction(double a, double b, double*result);		// ���� �Լ�
double multification(double a, double b, double*result);	// ���ϱ� �Լ�
double division(double a, double b, double*result);		// ������ �Լ�



int main()
{
	// ���� ���� �� �ʱ�ȭ
	double a = 2, b = 3;
	double result;

	// ���ϱ�
	summation(a, b, &result);
	printf("%.0lf + %.0lf = %.2lf \n", a, b, result);

	// ����
	subtraction(a, b, &result);
	printf("%.0lf - %.0lf = %.2lf \n", a, b, result);

	// ���ϱ�
	multification(a, b, &result);
	printf("%.0lf * %.0lf = %.2lf \n", a, b, result);

	// ������
	division(a, b, &result);
	printf("%.0lf / %.0lf = %.2lf \n", a, b, result);

	return 0;
}

// ���ϱ� �Լ� ����
double summation(double a, double b, double*result) {
	*result = a + b;
}

// ���� �Լ� ����
double subtraction(double a, double b, double*result) {
	*result= a - b;
}

// ���ϱ� �Լ� ����
double multification(double a, double b, double*result) {
	*result= a * b;
}

// ������ �Լ� ����
double division(double a, double b,double*result) {
	// 0���� ������ ������ ������ ���� ����
	if  (b == 0) {
		printf("0���� ���� �� �����ϴ�. ������ �ʽ��ϴ�.");
		return 0;
	}
	else {
		*result= a / b;
	}

}