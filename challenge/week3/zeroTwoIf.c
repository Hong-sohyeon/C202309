#include <stdio.h>

int main() {
	int num = 0;
	// ����ڿ��� ���� ���� �Է�
	printf("���ڸ� �Է��Ͻÿ�: ");
	scanf_s("%d", &num);	// ����� �Է��Լ�
	
	if (num == 0) {	// ���� 0�� �Է��� ��� zero ���
		printf("zero");
	}
	else if (num == 1) {	// ���� 1�� �Է��� ��� one ���
		printf("one");
	}
	else if (num == 2) {	// ���� 2�� �Է��� ��� two ���
		printf("two");
	}
	else {	// 0~2 ���� �� �Է� �� �Ʒ� ���� ���
		printf("not 0~2");
	}
	return 0;
}