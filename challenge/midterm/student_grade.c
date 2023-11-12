#include <stdio.h>

#define STUDENTS 5
#define SUBJECTS 3
#define CHARNUM 20

char subjectNames[SUBJECTS][CHARNUM] = { "����", "�߰����", "�⸻���" }; // ���� �̸� ���� �迭
char studentNames[STUDENTS][CHARNUM] = { "" }; // �л� �̸��� ����� �迭
double studentScores[STUDENTS][SUBJECTS] = { 0.0 }; // �л��� ���� �� ������ ������ ����� �迭

// �Լ� ����
void printStudentResults();
void printSubjectResults();


int main() {


	// �л� �̸� �Է� �ڵ� ���
	printf("�л� %d���� �̸��� �Է��� �����մϴ�. \n", STUDENTS);
	for (int i = 1; i <= STUDENTS; i++) {
		printf("	%d��° �л��� �̸��� �Է��ϼ���: ", i);
		scanf_s("%s", studentNames[i - 1], (char)sizeof(studentNames[i - 1]));
	}


	// �Էµ� �л� �̸��� �� ����Ǿ����� Ȯ���ϴ� �ڵ� ���
	printf("�л� �̸��� ��� �ԷµǾ����ϴ�. \n");
	printf("�Էµ� �л� �̸��� ������ �����ϴ�. \n");
	for (int i = 0; i < STUDENTS; i++) {
		printf("%s", studentNames[i]);
		if (i != STUDENTS - 1) {
			printf(", ");
		}
	}
	printf("\n");
	printf("--------------------\n");
	printf("�� �л��� %s, %s, %s ������ ���ʴ�� �Է����ּ���. (���� ����)\n ", subjectNames[0], subjectNames[1], subjectNames[2]);


	// �� �л��� ���� �� ������ �Է¹޴� ���
	// for���� 2���� �迭�� ����Ͽ� �Է¹޾� �����ϱ�

	for (int i = 0; i < STUDENTS; i++) {
		printf("	%s�� ����: ", studentNames[i]);
		scanf_s(" %lf %lf %lf", &studentScores[i][0], &studentScores[i][1], &studentScores[i][2]);
	}



	printf("�л����� ���� ������ ��� �Է� �Ǿ����ϴ�.\n");
	printf("--------------------\n");
	printf("�л� �� ������ ������ �����ϴ� \n");

	// �л� ��� ���� ��� �Լ� ȣ��
	printStudentResults();



	printf("--------------------\n");
	printf("���� �� ��� ������ �Ʒ��� �����ϴ�. \n");

	// ���� �� ��� ���� ��� �Լ� ȣ��
	printSubjectResults();


	printf("���α׷��� �����մϴ�. ");
	return 0;
}

// �л� ��� ���� ��� �Լ� ����
void printStudentResults() {

	for (int i = 0; i < STUDENTS; i++) {
		double sum = 0;	// ��������_�л��� ��� ��� ����
		for (int j = 0; j < SUBJECTS; j++) {
			sum += studentScores[i][j];
		}
		double Average = sum / SUBJECTS;
		printf("	%s�� �������: %.2lf\n", studentNames[i], Average);
	}
}

void printSubjectResults() {

	for (int i = 0; i < SUBJECTS; i++) {
		double sum = 0;	// ��������_���� ��� ��� ����
		for (int j = 0; j < STUDENTS; j++) {
			sum += studentScores[j][i];
		}
		double Average = sum / STUDENTS;
		printf("	%s�� ���������  %.2lf�Դϴ�. \n", subjectNames[i], Average);
	}
}