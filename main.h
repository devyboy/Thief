#include "Enemy.cpp"
#include "Player.cpp"
#include <vector>

void drawBorders(int, int);
void showEnemies(std::vector<Enemy> &elist);
void playerMove(int, Player *ply, std::vector<Enemy> &elist, int, int);
