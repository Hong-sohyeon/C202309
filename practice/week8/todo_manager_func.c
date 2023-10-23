#include <stdio.h>
#define MAX_TASKS 10
#define CHAR_NUM 100
#include <string.h>

// �������� �����ϱ� //

int taskCount = 0;							 // �� �� �� ���� ����
char tasks[MAX_TASKS][CHAR_NUM] = { "" };	 // �� �� ��� ���� 2���� �迭

int terminate = 0; // ���Ḧ ���� flag
int delIndex = -1;  // �� �� ������ ���� index ���� ����
int changeIndex = -1; // �� �� ������ ���� index ���� ����
char ch; // �� �� ������ ���۸� �ޱ� ���� ���� ����

// �Լ� �����ϱ� //

void addTask(char task[]);
void delTask(int delIndex, int taskCount);
void printTask(int taskCount);

int main() {

	printf("TODO ����Ʈ ����! \n");

	// while �Լ��� ����Ͽ� �ݺ����� ����� �ϴ� ���α׷� �ۼ�
	while (1) {
		int choice = -1; // ����� �Է� �޴��� �����ϱ� ���� ����

		// �޴� ��� �� �Է¹ޱ�
		printf("------------------\n");
		printf("�޴��� �Է����ּ���.\n");;
		printf("1. �� �� �߰�\n2. �� �� ����\n3. ��� ����\n4. ����\n5.�� �� ����\n");
		printf("���� �� �� �� = %d\n", taskCount);
		printf("------------------\n");
		scanf_s("%d", &choice);

		// 1~5�� ��ɿ� ���� �� case �ۼ�
		switch (choice) {
		// 1��. �� �� �߰� ��� �ۼ�
		case 1:
			addTask(tasks[taskCount]);
			taskCount++;
			break;
		// 2��. �� �� ���� ��� �ۼ�
		case 2:
			printf("������ �� ���� ��ȣ�� �Է����ּ���. (1���� ����):");
			scanf_s("%d", &delIndex);
			if (delIndex > taskCount || delIndex <= 0) {
				printf("���� ������ ������ϴ�.\n");
			}
			else {
				delTask(delIndex, taskCount);
				taskCount -= 1;
			}
			break;
		// 3��. �� �� ��� ��� ��� �ۼ�
		case 3:
			printf("�� �� ���\n");
			printTask(taskCount);	// printTask �Լ� ����Ͽ� �� �� ��� �����ϱ�
			break;
		// 4��. ���α׷� ���� ��� �ۼ�
		case 4:
			terminate = 1;
			break;
		// �⺻�� ����
		default:
			printf("�߸��� �����Դϴ�. �ٽ� �����ϼ���.\n");
		}

		if (terminate == 1) {
			printf("���Ḧ �����ϼ̽��ϴ�. ���α׷��� �����մϴ�.\n");
			break;
		}

		// TODO: �� ���� �� á���� üũ�ϴ� �ڵ� �ۼ�

	}
}

void addTask(char task[]) {
	printf("�� ���� �Է��ϼ��� (���� ���� �Է��ϼ���): ");
	scanf_s("%s", tasks[taskCount], (int)sizeof(tasks[taskCount]));		// �� �� �Է¹ޱ�
	printf("�� �� ""%s""�� ����Ǿ����ϴ�\n\n", tasks[taskCount]);
}

void delTask(int delIndex, int taskCount) {
	printf("%d. %s : �� ���� �����մϴ�.\n", delIndex, tasks[delIndex - 1]);

	// �迭�� ���� (=�迭�� ���� �迭�� ���ڿ��� ����) �� �Ұ����ϱ� ������
	// ���ڿ� ���� �Լ��� ����
	strcpy_s(tasks[delIndex - 1], sizeof(tasks[delIndex - 1]), "");

	// Ư�� �ε����� �� �� ���� �� �ڿ� �ִ� �� �� ������ �ű��
	for (int i = delIndex; i < taskCount + 1; i++) {
		strcpy_s(tasks[i - 1], sizeof(tasks[i]), tasks[i]);
	}
}

void printTask(int taskCount) {
	for (int i = 0; i < taskCount; i++) {
		printf("%d. %s \n", i + 1, tasks[i]);
	}
	printf("\n");
}