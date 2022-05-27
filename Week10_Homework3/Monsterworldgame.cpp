#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include <time.h>

int main()
{
	srand((unsigned int)time(NULL));
	int w = 16, h = 8;
	MonsterWorld game(w, h);

	game.add(new Zombie("�ڹ�������", "��", rand() % w, rand() % h));
	game.add(new Vampire("���������", "��", rand() % w, rand() % h));
	game.add(new KGhost("������ͽ�", "��", rand() % w, rand() % h));
	game.add(new Jiangshi("����ȣ����", "��", rand() % w, rand() % h, true));
	game.add(new Jiangshi("��â����", "��", rand() % w, rand() % h, false));
	game.add(new Tuman("���б��ͽ�", "��", rand() % w, rand() % h));
	game.add(new Tuman("���񼮱ͽ�", "��", rand() % w, rand() % h));
	game.play(500, 10);
	printf("------���� ����-------------------\n");
	getchar();
	getchar();
}