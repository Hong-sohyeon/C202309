#include <stdio.h>
#define MAX_TASKS 10
#define CHAR_NUM 100
#include <string.h>

// 전역변수 설정하기 //

int taskCount = 0;							 // 할 일 수 저장 변수
char tasks[MAX_TASKS][CHAR_NUM] = { "" };	 // 할 일 목록 저장 2차원 배열

int terminate = 0; // 종료를 위한 flag
int delIndex = -1;  // 할 일 삭제를 위한 index 저장 변수
int changeIndex = -1; // 할 일 수정을 위한 index 저장 변수
char ch; // 할 일 수정시 버퍼를 받기 위한 문자 변수

// 함수 선언하기 //

void addTask(char task[]);
void delTask(int delIndex, int taskCount);
void printTask(int taskCount);

int main() {

	printf("TODO 리스트 시작! \n");

	// while 함수를 사용하여 반복적인 기능을 하는 프로그램 작성
	while (1) {
		int choice = -1; // 사용자 입력 메뉴를 저장하기 위한 변수

		// 메뉴 출력 및 입력받기
		printf("------------------\n");
		printf("메뉴를 입력해주세요.\n");;
		printf("1. 할 일 추가\n2. 할 일 삭제\n3. 목록 보기\n4. 종료\n5.할 일 수정\n");
		printf("현재 할 일 수 = %d\n", taskCount);
		printf("------------------\n");
		scanf_s("%d", &choice);

		// 1~5번 기능에 대한 각 case 작성
		switch (choice) {
		// 1번. 할 일 추가 기능 작성
		case 1:
			addTask(tasks[taskCount]);
			taskCount++;
			// 할 일이 10개가 되면 프로그램 종료하도록 코드 작성
			if (taskCount == 10) {
				printf("할 일이 다 찼습니다.\n<현재 할 일 수: %d>\n", taskCount);
				terminate = 1;
			}
			break;
		// 2번. 할 일 삭제 기능 작성
		case 2:
			printf("삭제할 할 일의 번호를 입력해주세요. (1부터 시작):");
			scanf_s("%d", &delIndex);
			if (delIndex > taskCount || delIndex <= 0) {
				printf("삭제 범위가 벗어났습니다.\n");
			}
			else {
				delTask(delIndex, taskCount);
				taskCount -= 1;
			}
			break;
		// 3번. 할 일 목록 출력 기능 작성
		case 3:
			printf("할 일 목록\n");
			printTask(taskCount);	// printTask 함수 사용하여 할 일 목록 나열하기
			break;
		// 4번. 프로그램 종료 기능 작성
		case 4:
			terminate = 1;
			break;
		// 5번. 할 일 목록 수정 기능 작성
		case 5:
			printf("수정할 할 일의 번호를 입력해주세요(1~) : ");
			scanf_s("%d", &changeIndex);
			ch = getchar();
			printf("새로운 할 일을 입력해주세요 : ");
			scanf_s("%s", tasks[changeIndex - 1], (int)sizeof(tasks[changeIndex - 1]));
			printf("새로운 할 일이 추가되었습니다 : %d. %s \n", changeIndex, tasks[changeIndex - 1]);
			break;

		// 기본값 설정
		default:
			printf("잘못된 선택입니다. 다시 선택하세요.\n");
		}

		if (terminate == 1) {
			printf("프로그램을 종료합니다.\n");
			break;
		}
	}
	return 0;
}

void addTask(char task[]) {
	printf("할 일을 입력하세요 (공백 없이 입력하세요): ");
	scanf_s("%s", tasks[taskCount], (int)sizeof(tasks[taskCount]));		// 할 일 입력받기
	printf("할 일 ""%s""가 저장되었습니다\n\n", tasks[taskCount]);
}

void delTask(int delIndex, int taskCount) {
	printf("%d. %s : 할 일을 삭제합니다.\n", delIndex, tasks[delIndex - 1]);

	// 배열간 대입 (=배열에 문자 배열인 문자열의 대입) 이 불가능하기 때문에
	// 문자열 복사 함수로 삭제
	strcpy_s(tasks[delIndex - 1], sizeof(tasks[delIndex - 1]), "");

	// 특정 인덱스의 할 일 삭제 후 뒤에 있는 할 일 앞으로 옮기기
	for (int i = delIndex; i < taskCount + 1; i++) {
		strcpy_s(tasks[i - 1], sizeof(tasks[i]), tasks[i]);
	}
}

void printTask(int taskCount) {
	for (int i = 0; i < taskCount; i++) {
		printf("%d. %s \n", i + 1, tasks[i]);
	}
	printf("\n");
}