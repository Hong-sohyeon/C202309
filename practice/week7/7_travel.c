#include <stdio.h>
// 상수 선언
#define NUMCITY 3
#define NUMPEOPLE 2

// 2차원 배열 선언
char names[NUMPEOPLE][10];  // 여행자 이름 저장 2차원 배열
char cities[NUMCITY][10];	// 도시 이름 저장 2차원 배열

// 함수 원형 선언
void calculateTravelDays();

int main() {
	// 도시명 입력 받기
	printf("%d개의 도시명을 차례대로 입력해주세요. \n", NUMCITY);
	for (int i = 0; i < NUMCITY; i++) {
		scanf_s("%s", cities[i], (int)sizeof(cities[i]));
	}
	// 여행자 이름 입력 받기
	printf("%d개의 여행자 이름을 차례대로 입력해주세요. \n", NUMPEOPLE);
	for (int i = 0; i < NUMPEOPLE; i++) {
		scanf_s("%s", names[i], (int)sizeof(names[i]));
	}
	// 함수 불러와서 실행
	calculateTravelDays(names);

	return 0;
}

// 각 도시에서 평균 머문 일 수를 계산하고 출력하는 함수
void calculateTravelDays() {
	// travelDays라고 하는 2차원 배열 선언
	int travelDays[NUMCITY][NUMPEOPLE];

	// 각 도시에서 각 사람이 보낸 일 수 입력받기
	for (int i = 0; i < NUMCITY; i++) {
		for (int j = 0; j < NUMPEOPLE; j++) {
			printf("도시 %s에서 사람 %s가 보낸 일 수를 입력하세요: ", cities[i], names[j]);
			scanf_s("%d", &travelDays[i][j]);
		}
	}

	// 각 도시에서 총 일 수 및 평균 일 수 계산 및 출력
	for (int i = 0; i < NUMCITY; i++) {
		int totalDays = 0;
		for (int j = 0; j < NUMPEOPLE; j++) {	// 총 일 수 계산식
			totalDays += travelDays[i][j];
		}
		float averageDays = (float)totalDays / NUMPEOPLE;	// 평균 일 수 계산식
		printf("도시 %s에서 보낸 총 일수 : %d, 평균 일 수 : %.2f \n", cities[i], totalDays, averageDays);
	}
}
