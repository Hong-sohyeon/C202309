#include <stdio.h>

int main()
{
	int a = 10;	// int타입의 a의 이름을 가진 변수에 10 대입
	int b = 15;	// int타입의 b의 이름을 가진 변수에 15 대입
	printf("%d \n", a + b);

	char text1[10] = "Hello";
	char text2[50] = "World";

	printf("%s! \n", text1);
	printf("%s! \n", text2);

	return 0;
}