#include <stdio.h>
#define STUDENTS 5		// ��� ����


// classifyStudents �Լ� �����ϱ�
// scores�� �л� ������ ��� �迭, targetGrade�� ����Ϸ��� �ϴ� Ư�� ���� �Է� 
void classifyStudents(int scores[], char targetGrade) {
	printf("�л� ���� �з�: \n");
	char grade = ' ';						// �л� ���� ���� ����
	for (int i = 0; i < STUDENTS; i++) {	// �л����� ������ ���� ���� �ο�
		if (scores[i] >= 90) {
			grade = 'A';
		}
		else if (scores[i] >= 80) {
			grade = 'B';
		}
		else if (scores[i] >= 70) {
			grade = 'C';
		}
		else if (scores[i] >= 60) {
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

// sumScores �Լ� �����ϱ�
int sumScores(int scores[]) {
	int sum = 0;

	for (int i = 0; i < STUDENTS; i++) {
		sum += scores[i];
	}
	return sum;
}

// averageScores�Լ� �����ϱ�
double averageScores(int scores[]) {

	int sum = sumScores(scores);
	average = sum//STUDENTS
}













// ���� �Լ� ���
int main() {
	int scores[STUDENTS];	// STUDENTS ��� ��ŭ�� ũ�⸦ ���� scores �迭 ����

	for (int i = 0; i < STUDENTS; i++) {		// �ݺ��� ����Ͽ� �л��� ���� �Է� �ޱ�
		printf("�л� %d�� ������ �Է��ϼ���: ", i + 1);
		scanf_s("%d", &scores[i]);
	}

	char ch = getchar();	// ���� �ӽ� ���� ����, ���� ����� ����

	char target;
	printf("Ư�� ���� (A, B, C, D, F)�� �Է��Ͻÿ�:");
	scanf_s("%c", &target, 1);

	classifyStudents(scores, target);	// classifyStudents �Լ� ����Ͽ� �л� ���� �з�&Ư�� ������ ���� �л� ���

	int sum = sumScores(scores);
	double average = averageScores(scores);
	printf("�л��� ������ �� ���� %d �̰�, ��� ���� %lf �Դϴ�.\n", sum, average);

	printRanks(scores);

	return 0;
}