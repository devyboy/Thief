#include <ncurses.h>
#include <vector>
#include <iostream>
#include <string>
#include "main.h"

int main() {

// Variable declarations
	int ch, maxx, maxy;
	std::vector<Entity> elist;
	Entity *bat = new Entity('X', 10, 20, 10, 3);
	Entity *goblin = new Entity('X', 30, 60, 20, 5);
	Entity *orc = new Entity('X', 15, 80, 30, 6);
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
	mvaddch(player->x, player->y, player->ico); // place the player in the middle
	drawBorders(maxx, maxy);

// Main game loop
	while (true) {
		int curx, cury; 
		getmaxyx(stdscr, cury, curx); // get the current dimensions of the terminal
		showEnemies(elist);
		if (curx < 100 || cury < 25) { // if the terminal is smaller than 100 x 25, stop until fixed
			erase();
			mvprintw((cury/2) - 1, (curx/2) - 21, "Please make your terminal atleast 100 x 25");
			mvprintw((cury/2), (curx/2) - 12, "Press any key when fixed");
		}
		else {
			getmaxyx(stdscr, maxx, maxy); 
			ch = getch();
			playerMove(ch, player, elist, maxx, maxy);
			drawBorders(maxx, maxy);
		}
	}
	return 0;
}

void showEnemies(std::vector<Entity> &elist) {
	for (std::vector<Entity>::iterator it = elist.begin(); it != elist.end(); ++it) {
		mvaddch(it->x, it->y, it->ico);
	}
}

void playerMove(int ch, Player *ply, std::vector<Entity> &elist, int maxx, int maxy) {
	for (std::vector<Entity>::iterator it = elist.begin(); it != elist.end(); ++it) {
		it->moveCloser(ply);

	}
	switch (ch) {
		case KEY_UP:
			if (ply->x - 1 != 0) {
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
			if (ply->y - 1 > 0) {
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
			if (ply->y + 1 < maxy - 1) {
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

void drawBorders(int maxx, int maxy) {
	for (int i = 0; i < maxx; i++) {
		for (int j = 0; j < maxy; j++) {
			if (i == 0 || i == maxx - 1) {
				mvaddch(i, j, '-');
			}
			else if (j == 0 || j == maxy - 1) {
				mvaddch(i, j, '|');
			}
		}
	}
}
