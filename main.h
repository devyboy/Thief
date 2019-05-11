#include "Entity.h"
#include "Player.h"
#include <vector>

void showIntro(int, int);
void drawBorders(int, int, Player *ply);
void showEnemies(std::vector<Entity> &elist);
void playerMove(int, std::vector<int> keyList, Player *ply, std::vector<Entity> &elist, int, int);
