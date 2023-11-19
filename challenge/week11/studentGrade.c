#include <stdio.h>
#define STUDENTS 5		// ��� ����


// classifyStudents �Լ� �����ϱ�
// scores�� �л� ������ ��� �迭, targetGrade�� ����Ϸ��� �ϴ� Ư�� ���� �Է� 
void classifyStudents(int* scores[], char targetGrade) {
	printf("�л� ���� �з�: \n");
	char grade = ' ';						// �л� ���� ���� ����
	for (int i = 0; i < STUDENTS; i++) {	// �л����� ������ ���� ���� �ο�
		if (*(scores+i) >= 90) {
			grade = 'A';
		}
		else if (*(scores+i) >= 80) {
			grade = 'B';
		}
		else if (*(scores+i) >= 70) {
			grade = 'C';
		}
		else if (*(scores+i) >= 60) {
			grade = 'D';
		}
		else {
			grade = 'F';
		}
		if (targetGrade == grade) {			// ����Ϸ��� �ϴ� ������ grade �� ��ġ�ϴ� �� Ȯ��
			printf("%d �л��� %c ������ �޾ҽ��ϴ�.", i + 1, targetGrade);
		}
	}
}

int sumScores(int*scores) {
	int sum = 0;
	for (int i = 0; i < STUDENTS; i++) {
		sum += *(scores+i);
	}
	return sum;
}

double averageScores(int*scores) {
	int sum = sumScores(scores);
	double average = (double)sum / (double)STUDENTS;
	return average;
}

void printRanks(int*scores) {
	int ranks[STUDENTS];
	for (int i = 0; i < STUDENTS; i++) {
		ranks[i] = 1;	// �ʱ� ������ 1�� ����
		for (int j = 0; j < STUDENTS; j++) {
			if (*(scores+j) > *(scores+i)) {
				ranks[i]++;	// ���� ��Һ��� ū �ٸ� ��Ұ� ������ ������ �����ϴ� ���
			}
		}
		printf("%d �л��� ������ %d �Դϴ�.\n", i, ranks[i]);
	}
}


// ���� �Լ� ���
int main() {
	int scores[STUDENTS];	// STUDENTS ��� ��ŭ�� ũ�⸦ ���� scores �迭 ����

	for (int i = 0; i < STUDENTS; i++) {		// �ݺ��� ����Ͽ� �л��� ���� �Է� �ޱ�
		printf("�л� %d�� ������ �Է��ϼ���: ", i + 1);
		scanf_s("%d", &scores[i]);
	}

	char ch = getchar(); //���� �ӽ� ���� ����, ���� ����� ����

	char target;
	printf("Ư�� ���� (A, B, C, D, F)�� �Է��Ͻÿ�:");
	scanf_s("%c", &target, 1);

	classifyStudents(scores, target);	// classifyStudents �Լ� ����Ͽ� �л� ���� �з�&Ư�� ������ ���� �л� ���

	int sum = sumScores(scores);
	double average = averageScores(scores);
	printf("�л��� ������ ������ %d �̰�, ��� ���� %lf �Դϴ�.\n", sum, average);

	printRanks(scores);

	return 0;
}