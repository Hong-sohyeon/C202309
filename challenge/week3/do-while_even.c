#include <stdio.h>

int main()
{
	int i = 0;	// i�� 0 ����
	do {
		i++;

		if (i % 2 == 0) {	// i�� ¦���̸� �ݺ��� ó������
			continue;
		}
		printf("%d Hello World! \n", i);	// ��¹� �ۼ�
	} while (i < 10);	// ���� ����
	return 0;
}