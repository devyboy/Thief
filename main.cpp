#include <ncurses.h>
#include <vector>
#include <iostream>
#include <string>
#include "main.h"

int main() {
// Variable declarations
	int ch, maxx, maxy;
	std::vector<Entity> elist; // list of enemies in the current room
	std::vector<int> keyList = {KEY_UP, KEY_RIGHT, KEY_DOWN, KEY_LEFT, 113}; // list of available controls to use 
	Entity *bat = new Entity('B', 10, 20, 10, 3, 5);
	Entity *goblin = new Entity('G', 30, 60, 20, 5, 10);
	Entity *orc = new Entity('O', 15, 80, 30, 6, 15);
	elist.push_back(*bat);
	elist.push_back(*goblin);
	elist.push_back(*orc);

// Window Settings
	initscr(); // start the screen
	curs_set(0); // make the cursor invisible
	scrollok(stdscr, false); // disable scrolling
	getmaxyx(stdscr, maxx, maxy); // get the terminal dimensions
	noecho(); // dont print the keys that are pressed
	keypad(stdscr, TRUE); // allow non letter keys like arrows
	Player *player = new Player('@', maxx/2, maxy/2, 10, 2);
	showIntro(maxx, maxy);

// Main game loop
	while (true) {
		int curx, cury; 
		getmaxyx(stdscr, cury, curx); // get the current dimensions of the terminal
		// if (curx < 100 || cury < 25) { // if the terminal is smaller than 100 x 25, stop until fixed
		// 	erase();
		// 	refresh();
		// 	mvprintw((cury/2) - 1, (curx/2) - 21, "Please make your terminal atleast 100 x 25");
		// 	mvprintw((cury/2), (curx/2) - 12, "Press any key when fixed");
		// }
		// else {
			showEnemies(elist); // render the enemies on the screen
			mvaddch(player->x, player->y, player->ico); // place the player in the middle
			drawBorders(maxx, maxy, player);
			getmaxyx(stdscr, maxx, maxy); // get screen dimensions (again)
			playerMove(getch(), keyList, player, elist, maxx, maxy); // send the users key input to the move function
			drawBorders(maxx, maxy, player); // draws the borders again after they get erased
		//}
	}
	return 0;
}

void showEnemies(std::vector<Entity> &elist) { // Render the enemies on the screen
	for (std::vector<Entity>::iterator it = elist.begin(); it != elist.end(); ++it) {
		mvaddch(it->x, it->y, it->ico);
	}
}

void playerMove(int ch, std::vector<int> keyList, Player *ply, std::vector<Entity> &elist, int maxx, int maxy) {
	std::vector<int>::iterator result = std::find(keyList.begin(), keyList.end(), ch); // Search the controls list for the key that was pressed and put in a variable
	if (result != keyList.end()) {	// if the result is the end of the list, that means it wasn't in there
		for (std::vector<Entity>::iterator it = elist.begin(); it != elist.end(); ++it) {
			it->moveCloser(ply); // iterate over the list of enemies and use their move functions to move every turn
		}
		switch (ch) {
			case KEY_UP:
				if (ply->x - 1 >= 0) {
					ply->x--;
					erase();
					mvaddch(ply->x, ply->y, ply->ico);
				}
				else {
					erase();
					mvaddch(ply->x, ply->y, ply->ico);
				}
				break;
			case KEY_DOWN:
				if (ply->x + 1 < maxx - 1) {
					ply->x++;
					erase();
					mvaddch(ply->x, ply->y, ply->ico);
				}
				else {
					erase();
					mvaddch(ply->x, ply->y, ply->ico);
				}
				break;
			case KEY_LEFT:
				if (ply->y - 1 >= 0) {
					ply->y--;
					erase();
					mvaddch(ply->x, ply->y, ply->ico);
				}
				else {
					erase();
					mvaddch(ply->x, ply->y, ply->ico);
				}
				break;
			case KEY_RIGHT:
				if (ply->y + 1 < maxy) {
					ply->y++;
					erase();
					mvaddch(ply->x, ply->y, ply->ico);
				}
				else {
					erase();
					mvaddch(ply->x, ply->y, ply->ico);
				}
				break;
			case 113: // if Q is pressed, quit the game
				erase();
				refresh();
				exit(0);
			default:
				break;
		}
	}
}

void drawBorders(int maxx, int maxy, Player *ply) { // iterate over every coordinate
	for (int i = 0; i < maxx; i++) {
		for (int j = 0; j < maxy; j++) {
			if (i == maxx - 1 && j == 0) {
				// For the sake of brevity...
				std::string hp = "HP: " + std::to_string(ply->hp);
				std::string gold = "   Gold: " + std::to_string(ply->gold);
				std::string level = "   Level: " + std::to_string(ply->level);
				std::string exp = "   Exp: " + std::to_string(ply->exp) + "/" + std::to_string(ply->expCap);
				std::string HUD = hp + gold + level + exp;

				mvaddstr(i, j, HUD.c_str());
			}
		}
	}
}

void showIntro(int maxx, int maxy) {
	// preformatted strings didn't work for some reason
	const char* line1 = "ooooooooooooo  ooooo   ooooo  ooooo  oooooooooooo  oooooooooooo";
	const char* line2 = "     888       `888'   `888'  `888'  `888'         `888'     `";
	const char* line3 = "     888        888     888    888    888           888";
	const char* line4 = "     888        888ooooo888    888    888oooo8      888oooo8";
	const char* line5 = "     888        888     888    888    888           888";
	const char* line6 = "     888        888     888    888    888           888";
	const char* line7 = "    o888o      o888o   o888o  o888o  o888ooooood8  o888o";
	const char* line8 = "                    PRESS [ENTER] TO START";

	mvprintw((maxx/2) - 6, (maxy/2) - 31, line1);
	mvprintw((maxx/2) - 5, (maxy/2) - 31, line2);
	mvprintw((maxx/2) - 4, (maxy/2) - 31, line3);
	mvprintw((maxx/2) - 3, (maxy/2) - 31, line4);
	mvprintw((maxx/2) - 2, (maxy/2) - 31, line5);
	mvprintw((maxx/2) - 1, (maxy/2) - 31, line6);
	mvprintw((maxx/2), (maxy/2) - 31, line7);

	mvprintw((maxx/2) + 5, (maxy/2) - 31, line8);

	while (true) {
		if (getch() == 10) {
			erase();
			return;
		}
 	}
}
