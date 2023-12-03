#include <stdio.h>
#include <stdlib.h>

/* student 구조체 */
typedef struct {
    char* name;
    int score;
} STUDENT;

/* 함수 호출 */
void classifyStudents(STUDENT students[], int numStudents, char targetGrade);
int sumScores(STUDENT students[], int numStudents);
double averageScores(STUDENT students[], int numStudents);
void printRanks(STUDENT students[], int numStudents);

// 메인 함수 출력
int main() {
    int numStudents;

    printf(" 학생 수를 입력해주세요: ");
    scanf_s("%d", &numStudents);

    /* 동적 메모리 할당  */
    STUDENT* students = (STUDENT*)malloc(numStudents * sizeof(STUDENT));

    // 메모리 할당 오류
    if (students == NULL) {
        return 1;
    }

    /* 학생 이름&성적 입력 받기 */
    for (int i = 0; i < numStudents; i++) {
        students[i].name = (char*)malloc(50 * sizeof(char));

        if (students[i].name == NULL) {
            return 1;
        }

        printf("학생 %d의 이름을 입력하세요: ", i + 1);
        scanf_s("%s", students[i].name, 10);

        printf("학생 %d의 성적을 입력하세요: ", i + 1);
        scanf_s("%d", &students[i].score);
    }

    char targetGrade;
    printf("특정 점수 (A, B, C, D, F)를 입력하시오:");
    scanf_s(" %c", &targetGrade, 1);

    classifyStudents(students, numStudents, targetGrade);    // classifyStudents 함수 사용하여 학생 성적 분류&특정 성적을 가진 학생 출력

    /* 학생 점수 총 합, 평균 매기기 */
    int sum = sumScores(students, numStudents);
    double average = averageScores(students, numStudents);
    printf("학생들 점수의 총합은 %d 이고, 평균 값은 %lf 입니다.\n", sum, average);

    printRanks(students, numStudents);

    /* 동적 메모리 해제 */
    for (int i = 0; i < numStudents; i++) {
        free(students[i].name);
    }
    free(students);

    return 0;
}

// classifyStudents 함수 선언
// scores는 학생 성적을 담는 배열, targetGrade는 출력하려고 하는 특정 성적 입력 
void classifyStudents(STUDENT students[], int numStudents, char targetGrade) {
    printf("학생 성적 분류: \n");

    char grade = ' ';                       // 학생 성적 저장 변수

    for (int i = 0; i < numStudents; i++) { // 학생에게 점수에 따른 성적 부여
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
        if (targetGrade == grade) {            // 출력하려고 하는 성적과 grade 가 일치하는 지 확인
            printf("%s 학생은 %c 점수를 받았습니다.\n", students[i].name, targetGrade);
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
        ranks[i] = 1;   // 초기 순위를 1로 설정

        for (int j = 0; j < numStudents; j++) {
            if (students[j].score > students[i].score) {
                ranks[i]++; // 현재 요소보다 큰 다른 요소가 있으면 순위가 증가하는 기능
            }
        }
        printf("%s 학생의 순위는 %d 입니다.\n", students[i].name, ranks[i]);
    }
    free(ranks);
}