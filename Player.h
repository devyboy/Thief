#pragma once

class Player {
	public:
		char ico;
		int x;
		int y;
		int hp;
		int dmg;
		bool dead;

		Player(char ico, int x, int y, int hp, int dmg);
};