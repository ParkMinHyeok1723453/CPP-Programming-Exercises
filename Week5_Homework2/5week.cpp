#include "MineSweeper.h"
void main()
{
	int total;
	int nx, ny = 0;
	printf(" <Mine Sweeper>\n");
	printf(" 매설할 총 지뢰의 개수 입력 : ");
	scanf("%d", &total);

	printf("가로 길이: \n");
	scanf("%d, &DIM");

	printf("세로 길이: \n");
	scanf("%d, &DIN");

	playMineSweeper(total);
}