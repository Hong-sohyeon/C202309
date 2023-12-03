#include <stdio.h>
#include <stdlib.h>

/* student ����ü */
typedef struct {
    char* name;
    int score;
} STUDENT;

/* �Լ� ȣ�� */
void classifyStudents(STUDENT students[], int numStudents, char targetGrade);
int sumScores(STUDENT students[], int numStudents);
double averageScores(STUDENT students[], int numStudents);
void printRanks(STUDENT students[], int numStudents);

// ���� �Լ� ���
int main() {
    int numStudents;

    printf(" �л� ���� �Է����ּ���: ");
    scanf_s("%d", &numStudents);

    /* ���� �޸� �Ҵ�  */
    STUDENT* students = (STUDENT*)malloc(numStudents * sizeof(STUDENT));

    // �޸� �Ҵ� ����
    if (students == NULL) {
        return 1;
    }

    /* �л� �̸�&���� �Է� �ޱ� */
    for (int i = 0; i < numStudents; i++) {
        students[i].name = (char*)malloc(50 * sizeof(char));

        if (students[i].name == NULL) {
            return 1;
        }

        printf("�л� %d�� �̸��� �Է��ϼ���: ", i + 1);
        scanf_s("%s", students[i].name, 10);

        printf("�л� %d�� ������ �Է��ϼ���: ", i + 1);
        scanf_s("%d", &students[i].score);
    }

    char targetGrade;
    printf("Ư�� ���� (A, B, C, D, F)�� �Է��Ͻÿ�:");
    scanf_s(" %c", &targetGrade, 1);

    classifyStudents(students, numStudents, targetGrade);    // classifyStudents �Լ� ����Ͽ� �л� ���� �з�&Ư�� ������ ���� �л� ���

    /* �л� ���� �� ��, ��� �ű�� */
    int sum = sumScores(students, numStudents);
    double average = averageScores(students, numStudents);
    printf("�л��� ������ ������ %d �̰�, ��� ���� %lf �Դϴ�.\n", sum, average);

    printRanks(students, numStudents);

    /* ���� �޸� ���� */
    for (int i = 0; i < numStudents; i++) {
        free(students[i].name);
    }
    free(students);

    return 0;
}

// classifyStudents �Լ� ����
// scores�� �л� ������ ��� �迭, targetGrade�� ����Ϸ��� �ϴ� Ư�� ���� �Է� 
void classifyStudents(STUDENT students[], int numStudents, char targetGrade) {
    printf("�л� ���� �з�: \n");

    char grade = ' ';                       // �л� ���� ���� ����

    for (int i = 0; i < numStudents; i++) { // �л����� ������ ���� ���� �ο�
        if (students[i].score >= 90) {
            grade = 'A';
        }
        else if (students[i].score >= 80) {
            grade = 'B';
        }
        else if (students[i].score >= 70) {
            grade = 'C';
        }
        else if (students[i].score >= 60) {
            grade = 'D';
        }
        else {
            grade = 'F';
        }
        if (targetGrade == grade) {            // ����Ϸ��� �ϴ� ������ grade �� ��ġ�ϴ� �� Ȯ��
            printf("%s �л��� %c ������ �޾ҽ��ϴ�.\n", students[i].name, targetGrade);
        }
    }
}

int sumScores(STUDENT students[], int numStudents) {
    int sum = 0;
    for (int i = 0; i < numStudents; i++) {
        sum += students[i].score;
    }
    return sum;
}

double averageScores(STUDENT students[], int numStudents) {
    int sum = sumScores(students, numStudents);
    double average = (double)sum / (double)numStudents;
    return average;
}

void printRanks(STUDENT students[], int numStudents) {
    int* ranks = (int*)malloc(numStudents * sizeof(int));

    if (ranks == NULL) {
        return;
    }

    for (int i = 0; i < numStudents; i++) {
        ranks[i] = 1;   // �ʱ� ������ 1�� ����

        for (int j = 0; j < numStudents; j++) {
            if (students[j].score > students[i].score) {
                ranks[i]++; // ���� ��Һ��� ū �ٸ� ��Ұ� ������ ������ �����ϴ� ���
            }
        }
        printf("%s �л��� ������ %d �Դϴ�.\n", students[i].name, ranks[i]);
    }
    free(ranks);
}