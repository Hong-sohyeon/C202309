#include <stdio.h>

#define STUDENTS 5
#define SUBJECTS 3
#define CHARNUM 20

char subjectNames[SUBJECTS][CHARNUM] = { "퀴즈", "중간고사", "기말고사" }; // 과목 이름 저장 배열
char studentNames[STUDENTS][CHARNUM] = { "" }; // 학생 이름이 저장될 배열
double studentScores[STUDENTS][SUBJECTS] = { 0.0 }; // 학생의 시험 별 성적이 점수가 저장될 배열

// 함수 선언
void printStudentResults();
void printSubjectResults();


int main() {


	// 학생 이름 입력 코드 블록
	printf("학생 %d명의 이름의 입력을 시작합니다. \n", STUDENTS);
	for (int i = 1; i <= STUDENTS; i++) {
		printf("	%d번째 학생의 이름을 입력하세요: ", i);
		scanf_s("%s", studentNames[i - 1], (char)sizeof(studentNames[i - 1]));
	}


	// 입력된 학생 이름이 잘 저장되었는지 확인하는 코드 블록
	printf("학생 이름이 모두 입력되었습니다. \n");
	printf("입력된 학생 이름은 다음과 같습니다. \n");
	for (int i = 0; i < STUDENTS; i++) {
		printf("%s", studentNames[i]);
		if (i != STUDENTS - 1) {
			printf(", ");
		}
	}
	printf("\n");
	printf("--------------------\n");
	printf("각 학생의 %s, %s, %s 점수를 차례대로 입력해주세요. (띄어쓰기 구분)\n ", subjectNames[0], subjectNames[1], subjectNames[2]);


	// 각 학생의 시험 별 점수를 입력받는 기능
	// for문과 2차원 배열을 사용하여 입력받아 저장하기

	for (int i = 0; i < STUDENTS; i++) {
		printf("	%s의 성적: ", studentNames[i]);
		scanf_s(" %lf %lf %lf", &studentScores[i][0], &studentScores[i][1], &studentScores[i][2]);
	}



	printf("학생들의 시험 점수가 모두 입력 되었습니다.\n");
	printf("--------------------\n");
	printf("학생 별 성적은 다음과 같습니다 \n");

	// 학생 평균 성적 출력 함수 호출
	printStudentResults();



	printf("--------------------\n");
	printf("과목 별 평균 점수는 아래와 같습니다. \n");

	// 과목 별 평균 점수 출력 함수 호출
	printSubjectResults();


	printf("프로그램을 종료합니다. ");
	return 0;
}

// 학생 평균 성적 출력 함수 정의
void printStudentResults() {

	for (int i = 0; i < STUDENTS; i++) {
		double sum = 0;	// 지역변수_학생별 평균 계산 목적
		for (int j = 0; j < SUBJECTS; j++) {
			sum += studentScores[i][j];
		}
		double Average = sum / SUBJECTS;
		printf("	%s의 평균점수: %.2lf\n", studentNames[i], Average);
	}
}

void printSubjectResults() {

	for (int i = 0; i < SUBJECTS; i++) {
		double sum = 0;	// 지역변수_과목별 평균 계산 목적
		for (int j = 0; j < STUDENTS; j++) {
			sum += studentScores[j][i];
		}
		double Average = sum / STUDENTS;
		printf("	%s의 평균점수는  %.2lf입니다. \n", subjectNames[i], Average);
	}
}