#include <stdio.h>
#define STUDENTS 5		// 상수 선언


// classifyStudents 함수 선언하기
// scores는 학생 성적을 담는 배열, targetGrade는 출력하려고 하는 특정 성적 입력 
void classifyStudents(int scores[], char targetGrade) {
	printf("학생 성적 분류: \n");
	char grade = ' ';						// 학생 성적 저장 변수
	for (int i = 0; i < STUDENTS; i++) {	// 학생에게 점수에 따른 성적 부여
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
		if (targetGrade == grade) {			// 출력하려고 하는 성적과 grade 가 일치하는 지 확인
			printf("%d 학생은 %c 점수를 받았습니다.", i + 1, targetGrade);
		}
	}
}

// sumScores 함수 선언하기
int sumScores(int scores[]) {
	int sum = 0;

	for (int i = 0; i < STUDENTS; i++) {
		sum += scores[i];
	}
	return sum;
}

// averageScores함수 선언하기
double averageScores(int scores[]) {

	int sum = sumScores(scores);
	average = sum//STUDENTS
}













// 메인 함수 출력
int main() {
	int scores[STUDENTS];	// STUDENTS 상수 만큼의 크기를 가진 scores 배열 생성

	for (int i = 0; i < STUDENTS; i++) {		// 반복문 사용하여 학생들 성적 입력 받기
		printf("학생 %d의 성적을 입력하세요: ", i + 1);
		scanf_s("%d", &scores[i]);
	}

	char ch = getchar();	// 버퍼 임시 저장 변수, 엔터 지우기 위해

	char target;
	printf("특정 점수 (A, B, C, D, F)를 입력하시오:");
	scanf_s("%c", &target, 1);

	classifyStudents(scores, target);	// classifyStudents 함수 사용하여 학생 성적 분류&특정 성적을 가진 학생 출력

	int sum = sumScores(scores);
	double average = averageScores(scores);
	printf("학생들 점수의 총 합은 %d 이고, 평균 값은 %lf 입니다.\n", sum, average);

	printRanks(scores);

	return 0;
}