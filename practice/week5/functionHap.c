#include <stdio.h>

int hapf(int value);	// >> ��ȣ���� : �Լ� ���� �����ϱ�

int main()		// >> ȣ����
{
	printf("1����   10������ ���� %d\n", hapf(10));		// 1���� 10������ �� �Լ�&value �Է�
	printf("1����  100������ ���� %d\n", hapf(100));	// 1���� 100������ �� �Լ�&value �Է�
	printf("1���� 1000������ ���� %d\n", hapf(1000));	// 1���� 1000������ �� �Լ�&value �Է�
	return 0;
}

int hapf(int value)		// hapf �Լ� ���� ��
{
	int i = 1;			// int ���� i �� 1 �ο�
	int hap = 0;		// int ���� hap �� 0 �ο�

	while ( i <= value )// while �Լ� ����Ͽ� �Լ� ��� ����
	{
		hap = hap + i;	// hap ������ i ���ϰ� �ٽ� hap�� �� ���� [�ݺ�]
		i++;
	}
	return hap;			// hap �� ��ȯ
}