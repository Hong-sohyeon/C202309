#include <stdio.h>

int main() {
	int choice;
	// ����ڿ��� ���� ������ �Է�
	printf("1. ���� ���� \n");
	printf("2. ���� ���� �ݱ� \n");
	printf("3. ���� \n");
	scanf_s("%d", &choice);	// ����� �Է��Լ�

	if (choice == 1) {	// ������ 1�� ������ ���� ��¹�
		printf("������ �����մϴ�.");
	}
	else if (choice == 2) {	// ������ 2�� ������ ���� ��¹�
		printf("���� ���� �ݽ��ϴ�.");
	}
	else if (choice == 3) {	// ������ 3�� ������ ���� ��¹�
		printf("�����մϴ�.");
	}
	else {	// 1~3���� �Է����� ���� ���
		printf("�߸� �Է��ϼ̽��ϴ�.");
	}
	return 0;
}