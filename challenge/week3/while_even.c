#include <stdio.h>

int main()
{
	int i = 0; // i �� 0 ����
	while (i < 10) {	// ���� ����
		i++;
		if (i % 2 == 0) {	// i�� ¦���̸� �ݺ��� ó������
			continue;
		}
		printf(" %d Hello World! \n", i);	// ����� ����

	}
	return 0;
}