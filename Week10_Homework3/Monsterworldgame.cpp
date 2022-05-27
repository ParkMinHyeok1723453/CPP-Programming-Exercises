#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include <time.h>

int main()
{
	srand((unsigned int)time(NULL));
	int w = 16, h = 8;
	MonsterWorld game(w, h);

	game.add(new Zombie("¹Ú¹ÎÇõÁ»ºñ", "¡İ", rand() % w, rand() % h));
	game.add(new Vampire("ÀÌÈñ¿õ¹ÚÁã", "¡Ú", rand() % w, rand() % h));
	game.add(new KGhost("ÀÌÁØÈñ±Í½Å", "¢¾", rand() % w, rand() % h));
	game.add(new Jiangshi("Á¶¹ÎÈ£°­½Ã", "¡ê", rand() % w, rand() % h, true));
	game.add(new Jiangshi("Á¤Ã¢¿í°­½Ã", "¢Õ", rand() % w, rand() % h, false));
	game.add(new Tuman("ÀÌÇĞ±º±Í½Å", "ÁÂ", rand() % w, rand() % h));
	game.add(new Tuman("ÀÌÈñ¼®±Í½Å", "¿ì", rand() % w, rand() % h));
	game.play(500, 10);
	printf("------°ÔÀÓ Á¾·á-------------------\n");
	getchar();
	getchar();
}