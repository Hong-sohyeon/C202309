#include <stdio.h>

int main() {
    int floor;
    // �Ƕ�̵� ���� �˼�
    while (1) {
        printf("�� ���� �����ðڽ��ϱ�? (5~100): ");
        scanf_s("%d", &floor);

        if (floor >= 5 && floor <= 100) {
            break; // �ùٸ� �� �� �Է� �� ���� ����
        }
        else {
            printf("5���� 100 ������ �� ���� �Է����ּ���.\n");  // �ùٸ��� ���� ������ ���� �Է� �� ����� ����
        }
    }
    // �Ƕ�̵� �״� �ݺ���
    for (int i = 0; i < floor; i++) {
        for (int j = 0; j < floor - 1 - i; j++) {
            printf("S");  // S�� �Ƕ�̵� ���� ���� ä��� ��
        }
        for (int k = 0; k < i * 2 + 1; k++) {
            printf("*");  // *�� �Ƕ�̵� �ױ�
        }
        printf("\n");  // �ٹٲ�
    }
    return 0;
}