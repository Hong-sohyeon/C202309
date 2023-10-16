#include <stdio.h>

// 상수 선언
#define NUMCITY 3
#define NUMPEOPLE 2

// 2차원 배열 및 1차원 배열 선언
char names[NUMPEOPLE][10];		//여행자이름 저장 2차원 배열
char cities[NUMCITY][10];		//도시이름 저장 2차원 배열
double averageDays[NUMCITY];	//각 도시 평균 머문 일 저장 배열

// 함수 원형 선언
void calculateTravelDays();
int getSum(int numArray[], int length);
double getAverage(int numArray[], int length);
void getFamousCity(double dayArray[], int length);

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
	// 여행 일수 계산 함수 호출
	calculateTravelDays();

	return 0;
}

// 각 도시에서 평균 머문 일 수를 계산하고 출력하는 함수
void calculateTravelDays() {
	// 각 도시에서 각 여행자가 보낸 일 수를 저장하는 2차원 배열 선언
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
		int totalDay = getSum(travelDays[i], NUMPEOPLE);
		double averageDay = getAverage(travelDays[i], NUMPEOPLE);
		printf("도시 %s에서 보낸 총 일수 : %d, 평균 일 수 : %.2f \n", cities[i], totalDay, averageDay);
		averageDays[i] = averageDay;
	}
	getFamousCity(averageDays, NUMCITY);
}


int getSum(int numArray[], int length) {
	int totalDays = 0;
	for (int i = 0; i < length; i++) {	// 총 일 수 계산하기
		totalDays += numArray[i];
	}
	return totalDays;
}

double getAverage(int numArray[], int length) {
	int totalDays = 0;
	for (int i = 0; i < length; i++) {	// 평균 일 수 계산하기
		totalDays += numArray[i];
	}
	double averageDays = (double)totalDays / length;
	return averageDays;
}
// 가장 인기 있는 도시를 찾아 출력하는 함수
void getFamousCity(double dayArray[], int length) {
	double maxDay = 0;
	int maxDayIndex = 0;
	// 가장 큰 값을 찾는 배열
	for (int i = 1; i < length; i++) {
		if (dayArray[i] > maxDay) {
			maxDay = dayArray[i];
			maxDayIndex = i;
		}
	}
	printf("평균일 기준으로 가장 인기있었던 도시는 %s 입니다. (평균머문일: %.2f)\n", cities[maxDayIndex], maxDay);
}