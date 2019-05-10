#pragma once

class Player {
	public:
		char ico;
		int x;
		int y;
		int hp;
		int dmg;
		int level;
		int exp;
		int expCap;
		int gold;
		bool dead;

		Player(char ico, int x, int y, int hp, int dmg);
};