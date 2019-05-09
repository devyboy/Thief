#include "Entity.h"
#include <ncurses.h>
#include <stdlib.h>

Entity::Entity(char ico, int x, int y, int hp, int dmg) {
	this->ico = ico;
	this->x = x;
	this->y = y;
	this->hp = hp;
	this->dmg = dmg;
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
	erase(); // clear the screen
	mvprintw(10, 45, "Game Over"); // print the stuff
	mvprintw(12, 40, "Press Enter to quit");
	while (true) {
		if (getch() == 10) { // wait for the user to press Enter (key code 10)
			erase(); // clear screen again for neatness
			exit(0); // exit the game with code 0
		} 
	}
}
