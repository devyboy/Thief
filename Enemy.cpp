
class Enemy {
	public:
		char ico;
		int x;
		int y;
		int hp;
		int dmg;
		bool dead;


		Enemy(char ico, int x, int y, int hp, int dmg) {
			this->ico = ico;
			this->x = x;
			this->y = y;
			this->hp = hp;
			this->dmg = dmg;
			this->dead = false;
		}

		void moveCloser(int x, int y) {
			if (this->x < x) {
				this->x++;
			}
			else if (this->x > x) {
				this->x--;
			}
			else if (this->y < y) {
				this->y++;
			}
			else if (this->y > y) {
				this->y--;
			}
			else {
				erase();
				refresh();
				mvprintw(12, 45, "Game Over.");
				getch();
				exit(0);
			}
		}
};