#include <stdio.h>

int multiF(long value);		// >> ��ȣ���� : �Լ� ���� �����ϱ�

void main()		// >> ȣ����
{
	printf("1����  2������ ���� %d\n", multiF(2));		// 1���� 2������ �� �Լ�&value �Է�
	printf("1����  3������ ���� %d\n", multiF(3));		// 1���� 3������ �� �Լ�&value �Է�
	printf("1����  5������ ���� %d\n", multiF(5));		// 1���� 5������ �� �Լ�&value �Է�
}

int multiF(long value)	// multiF �Լ� ���� ��
{
	int i = 1;			// int ���� i �� 1 �ο�
	int multi = i;		// int ���� multi �� 1 �ο�

	while (i <= value)	// while �Լ� ����Ͽ� �Լ� ��� ����
	{
		multi = multi * i;	// multi ������ i ���ϰ� �ٽ� multi�� �� ���� [�ݺ�]
		i++;
	}
	return multi;		// multi �� ��ȯ
}