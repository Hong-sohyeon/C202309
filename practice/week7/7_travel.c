#include <stdio.h>
// ��� ����
#define NUMCITY 3
#define NUMPEOPLE 2

// 2���� �迭 ����
char names[NUMPEOPLE][10];  // ������ �̸� ���� 2���� �迭
char cities[NUMCITY][10];	// ���� �̸� ���� 2���� �迭

// �Լ� ���� ����
void calculateTravelDays();

int main() {
	// ���ø� �Է� �ޱ�
	printf("%d���� ���ø��� ���ʴ�� �Է����ּ���. \n", NUMCITY);
	for (int i = 0; i < NUMCITY; i++) {
		scanf_s("%s", cities[i], (int)sizeof(cities[i]));
	}
	// ������ �̸� �Է� �ޱ�
	printf("%d���� ������ �̸��� ���ʴ�� �Է����ּ���. \n", NUMPEOPLE);
	for (int i = 0; i < NUMPEOPLE; i++) {
		scanf_s("%s", names[i], (int)sizeof(names[i]));
	}
	// �Լ� �ҷ��ͼ� ����
	calculateTravelDays(names);

	return 0;
}

// �� ���ÿ��� ��� �ӹ� �� ���� ����ϰ� ����ϴ� �Լ�
void calculateTravelDays() {
	// travelDays��� �ϴ� 2���� �迭 ����
	int travelDays[NUMCITY][NUMPEOPLE];

	// �� ���ÿ��� �� ����� ���� �� �� �Է¹ޱ�
	for (int i = 0; i < NUMCITY; i++) {
		for (int j = 0; j < NUMPEOPLE; j++) {
			printf("���� %s���� ��� %s�� ���� �� ���� �Է��ϼ���: ", cities[i], names[j]);
			scanf_s("%d", &travelDays[i][j]);
		}
	}

	// �� ���ÿ��� �� �� �� �� ��� �� �� ��� �� ���
	for (int i = 0; i < NUMCITY; i++) {
		int totalDays = 0;
		for (int j = 0; j < NUMPEOPLE; j++) {	// �� �� �� ����
			totalDays += travelDays[i][j];
		}
		float averageDays = (float)totalDays / NUMPEOPLE;	// ��� �� �� ����
		printf("���� %s���� ���� �� �ϼ� : %d, ��� �� �� : %.2f \n", cities[i], totalDays, averageDays);
	}
}
