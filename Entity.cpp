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
	const char* line1 = "	       _______";
	const char* line2 = "     .-*       *-.";
	const char* line3 = "    /             \\";
    const char* line4 = "   |               |";
    const char* line5 = "   |,  .-.   .-.  ,|";
    const char* line6 = "   | )(__/   \\__)( |";
    const char* line7 = "   |/     / \\     \\|";     
	const char* line8 = "   (_     ^^^     _)";
	const char* line9 = "    \\__|IIIIIII|__/";
    const char* line10 = "     | \\IIIIIII/ |";
    const char* line11 = "     \\           /";
    const char* line12 = "      `---------`";


	getmaxyx(stdscr, maxx, maxy);
	erase(); // clear the screen

	mvprintw(maxx/9, (maxy/2) - 4, "YOU DIED"); // print the stuff
	mvprintw(maxx/1.25, (maxy/2) - 9, "PRESS [ENTER] TO QUIT");
	
	mvprintw((maxx/2) - 7, (maxy/2) - 11, line1);
	mvprintw((maxx/2) - 6, (maxy/2) - 11, line2);
	mvprintw((maxx/2) - 5, (maxy/2) - 11, line3);
	mvprintw((maxx/2) - 4, (maxy/2) - 11, line4);
	mvprintw((maxx/2) - 3, (maxy/2) - 11, line5);
	mvprintw((maxx/2) - 2, (maxy/2) - 11, line6);
	mvprintw((maxx/2) - 1, (maxy/2) - 11, line7);
	mvprintw((maxx/2), (maxy/2) - 11, line8);
	mvprintw((maxx/2) + 1, (maxy/2) - 11, line9);
	mvprintw((maxx/2) + 2, (maxy/2) - 11, line10);
	mvprintw((maxx/2) + 3, (maxy/2) - 11, line11);
	mvprintw((maxx/2) + 4, (maxy/2) - 11, line12);
	
	while (true) {
		if (getch() == 10) { // wait for the user to press Enter (key code 10)
			erase(); // clear screen again for neatness
			refresh();
			exit(0); // exit the game with code 0
		} 
	}
}
