#include "Player.h"

Player::Player(char ico, int x, int y, int hp, int dmg) {
    this->ico = ico;
    this->x = x;
    this->y = y;
    this->hp = hp;
    this->dmg = dmg;
    this->level = 1;
    this->exp = 0;
    this->expCap = 20;
    this->gold = 0;
    this->dead = false;
}
