#include "Player.h"

class Entity {
	public:
		char ico;
		int x;
		int y;
		int hp;
		int dmg;
		int expGive;
		bool dead;

		Entity(char ico, int x, int y, int hp, int dmg, int expGive);

		void moveCloser(Player *ply);
		void gameOver();
};
