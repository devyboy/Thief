#include "Entity.h"
#include <ncurses.h>
#include <stdlib.h>

Entity::Entity(char ico, int x, int y, int hp, int dmg, int expGive) {
	this->ico = ico;
	this->x = x;
	this->y = y;
	this->hp = hp;
	this->dmg = dmg;
	this->expGive = expGive;
	this->dead = false;
}

void Entity::moveCloser(Player *ply) {
	if (this->x < ply->x) {
		if (this->x + 1 == ply->x && this->y == ply->y) { // if the next move is going to be on top of the player, you lose
			gameOver();
		}
		else {
			this->x++;
		}
	}
	else if (this->x > ply->x) {
		if (this->x - 1 == ply->x && this->y == ply->y) {
			gameOver();
		}
		else {
			this->x--;
		}
	}
	else if (this->y < ply->y) {
		if (this->y + 1 == ply->y && this->x == ply->x) {
			gameOver();
		}
		else {
			this->y++;
		}
	}
	else if (this->y > ply->y) {
		if (this->y - 1 == ply->y && this->x == ply->x) {
			gameOver();
		}
		else {
			this->y--;
		}
	}
	else {
		gameOver(); // should never really get here but just in case?
	}
}

void Entity::gameOver() {
	int maxx, maxy;

	// i love ASCII art okay.
	const char* line1 = "     e@@@@@@@@@@@@@@@@@@@@";
	const char* line2 = "  _@@@@@@@@@@@@@@@@@@@@@@@@@@";
	const char* line3 = "_e@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
    const char* line4 = "@@@@@*@@~~~~~~~~@@@.@@~~~~~~.@@e";
    const char* line5 = "@ @@@@.@     . ..@@@@ .    . ..@";
    const char* line6 = "@ @@@@.*   ... ..@@@@e.   . ...@";
    const char* line7 = "@.*@@@@@eeeeeeee@@~ ~@@eeeeee@@@";     
	const char* line8 = " @e.@@@@@@@@@@@@@@ | @@@@@@@@@'";
	const char* line9 = "   @eeeeeee@@@@@@@[ : ]@@@@@'";
    const char* line10 = "     ***@@@@@@@@::@::@@@@@";
    const char* line11 = "         @@@@@@@@@@@@@@@@@";
    const char* line12 = "         v@@@@@@@@@v@@@v@@";
	const char* line13 = "          V  VV  V  V    V";

	getmaxyx(stdscr, maxx, maxy);
	erase(); // clear the screen
	mvprintw(20, 45, "You Died"); // print the stuff
	mvprintw(22, 40, "Press Enter to quit");
	
	mvprintw((maxx/2) - 9, (maxy/2) - 18, line1);
	mvprintw((maxx/2) - 8, (maxy/2) - 18, line2);
	mvprintw((maxx/2) - 7, (maxy/2) - 18, line3);
	mvprintw((maxx/2) - 6, (maxy/2) - 18, line4);
	mvprintw((maxx/2) - 5, (maxy/2) - 18, line5);
	mvprintw((maxx/2) - 4, (maxy/2) - 18, line6);
	mvprintw((maxx/2) - 3, (maxy/2) - 18, line7);
	mvprintw((maxx/2) - 2, (maxy/2) - 18, line8);
	mvprintw((maxx/2) - 1, (maxy/2) - 18, line9);
	mvprintw((maxx/2), (maxy/2) - 18, line10);
	mvprintw((maxx/2) + 1, (maxy/2) - 18, line11);
	mvprintw((maxx/2) + 2, (maxy/2) - 18, line12);
	mvprintw((maxx/2) + 3, (maxy/2) - 18, line13);
	
	while (true) {
		if (getch() == 10) { // wait for the user to press Enter (key code 10)
			erase(); // clear screen again for neatness
			refresh();
			exit(0); // exit the game with code 0
		} 
	}
}
