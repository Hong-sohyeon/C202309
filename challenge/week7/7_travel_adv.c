#include <stdio.h>

// ��� ����
#define NUMCITY 3
#define NUMPEOPLE 2

// 2���� �迭 �� 1���� �迭 ����
char names[NUMPEOPLE][10];		//�������̸� ���� 2���� �迭
char cities[NUMCITY][10];		//�����̸� ���� 2���� �迭
double averageDays[NUMCITY];	//�� ���� ��� �ӹ� �� ���� �迭

// �Լ� ���� ����
void calculateTravelDays();
int getSum(int numArray[], int length);
double getAverage(int numArray[], int length);
void getFamousCity(double dayArray[], int length);

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
	// ���� �ϼ� ��� �Լ� ȣ��
	calculateTravelDays();

	return 0;
}

// �� ���ÿ��� ��� �ӹ� �� ���� ����ϰ� ����ϴ� �Լ�
void calculateTravelDays() {
	// �� ���ÿ��� �� �����ڰ� ���� �� ���� �����ϴ� 2���� �迭 ����
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
		int totalDay = getSum(travelDays[i], NUMPEOPLE);
		double averageDay = getAverage(travelDays[i], NUMPEOPLE);
		printf("���� %s���� ���� �� �ϼ� : %d, ��� �� �� : %.2f \n", cities[i], totalDay, averageDay);
		averageDays[i] = averageDay;
	}
	getFamousCity(averageDays, NUMCITY);
}


int getSum(int numArray[], int length) {
	int totalDays = 0;
	for (int i = 0; i < length; i++) {	// �� �� �� ����ϱ�
		totalDays += numArray[i];
	}
	return totalDays;
}

double getAverage(int numArray[], int length) {
	int totalDays = 0;
	for (int i = 0; i < length; i++) {	// ��� �� �� ����ϱ�
		totalDays += numArray[i];
	}
	double averageDays = (double)totalDays / length;
	return averageDays;
}
// ���� �α� �ִ� ���ø� ã�� ����ϴ� �Լ�
void getFamousCity(double dayArray[], int length) {
	double maxDay = 0;
	int maxDayIndex = 0;
	// ���� ū ���� ã�� �迭
	for (int i = 1; i < length; i++) {
		if (dayArray[i] > maxDay) {
			maxDay = dayArray[i];
			maxDayIndex = i;
		}
	}
	printf("����� �������� ���� �α��־��� ���ô� %s �Դϴ�. (��ոӹ���: %.2f)\n", cities[maxDayIndex], maxDay);
}