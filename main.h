#include "Entity.h"
#include "Player.h"
#include <vector>

void drawBorders(int, int);
void showEnemies(std::vector<Entity> &elist);
void playerMove(int, std::vector<int> keyList, Player *ply, std::vector<Entity> &elist, int, int);
