#include "MineSweeper.h"
void main()
{
	int total;
	int nx, ny = 0;
	printf(" <Mine Sweeper>\n");
	printf(" �ż��� �� ������ ���� �Է� : ");
	scanf("%d", &total);

	printf("���� ����: \n");
	scanf("%d, &DIM");

	printf("���� ����: \n");
	scanf("%d, &DIN");

	playMineSweeper(total);
}