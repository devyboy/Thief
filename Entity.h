#include "Player.h"

class Entity {
	public:
		char ico;
		int x;
		int y;
		int hp;
		int dmg;
		bool dead;

		Entity(char ico, int x, int y, int hp, int dmg);

		void moveCloser(Player *ply);
		void gameOver();
};
