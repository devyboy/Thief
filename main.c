#include <ncurses.h>

void drawBorders(int, int);

int main()
{
// Variable declarations
	int ch, maxx, maxy, playerX, playerY;
	char player= '@';

// Window Settings
	initscr(); // start the screen
	curs_set(0); // make the cursor invisible
	scrollok(stdscr, false); // disable scrolling
	getmaxyx(stdscr, maxx, maxy); // get the screen dimensions
	noecho(); // dont print the keys that are pressed
	keypad(stdscr, TRUE); // allow non letter keys like arrows
	playerX = maxx/2; 
	playerY = maxy/2;
	mvaddch(playerX, playerY, player); // place the player in the middle
	drawBorders(maxx, maxy);

// Main game loop
	while (true) {
		int curx, cury;
		getmaxyx(stdscr, cury, curx);
		if (curx < 86 || cury < 21) {
			erase();
			mvprintw(cury/2, (curx/2) - 15, "Please make your terminal bigger");
		}
		else {
			getmaxyx(stdscr, maxx, maxy); // get the screen dimensions
			drawBorders(maxx, maxy);
			ch = getch();
			switch (ch) {
				case KEY_UP:
					if (playerX - 1 != 0) {
						playerX--;
						erase();
						drawBorders(maxx, maxy);
						mvaddch(playerX, playerY, player);
					}
					break;
				case KEY_DOWN:
					if (playerX + 1 < maxx - 1) {
						playerX++;
						erase();
						drawBorders(maxx, maxy);				
						mvaddch(playerX, playerY, player);
					}
					break;
				case KEY_LEFT:
					if (playerY - 1 != 0) {
						playerY--;
						erase();
						drawBorders(maxx, maxy);
						mvaddch(playerX, playerY, player);
					}
					break;
				case KEY_RIGHT:
					if (playerY + 1 < maxy - 1) {
						playerY++;
						erase();
						drawBorders(maxx, maxy);
						mvaddch(playerX, playerY, player);
					}
					break;
				case 113: // if Q is pressed, quit the game
					erase();
					refresh();
					return 0;
				default:
					break;
			}
		}
		refresh();
	}
	return 0;
}

void drawBorders(int maxx, int maxy) {
	int per = (maxx * 2) + (maxy * 2);
	for (int i = 0; i < maxx; i++) {
		for (int j = 0; j < maxy; j++) {
			if (i == 0 || i == maxx - 1) {
				mvaddch(i, j, '#');
			}
			else if (j == 0 || j == maxy - 1) {
				mvaddch(i, j, '#');
			}
		}
	}
}