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
		if (this->x + 1 == ply->x && this->y == ply->y) {
			gameOver();
		}
		else {
			this->x++;
			mvaddch(this->y, this->x - 1, ' ');
		}
	}
	else if (this->x > ply->x) {
		if (this->x - 1 == ply->x && this->y == ply->y) {
			gameOver();
		}
		else {
			this->x--;
			mvaddch(this->y, this->x + 1, ' ');
		}
	}
	else if (this->y < ply->y) {
		if (this->y + 1 == ply->y && this->x == ply->x) {
			gameOver();
		}
		else {
			mvaddch(this->y - 1, this->x, ' ');
			this->y++;
		}
	}
	else if (this->y > ply->y) {
		if (this->y - 1 == ply->y && this->x == ply->x) {
			gameOver();
		}
		else {
			mvaddch(this->y + 1, this->x, ' ');
			this->y--;
		}
	}
	else {
		gameOver();
	}
}

void Entity::gameOver() {
	erase();
	refresh();
	mvprintw(10, 45, "Game Over");
	mvprintw(12, 40, "Press Enter to quit");
	while (true) {
		if (getch() == 10) {
			erase();
			refresh();
			exit(0);
		} 
	}
}
