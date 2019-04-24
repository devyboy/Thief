#include <ncurses.h>

int main()
{
	int ch, maxx, maxy;
	char player= 'x';
	initscr();
	curs_set(0);
	scrollok(stdscr, false);
	getmaxyx(stdscr, maxx, maxy);
	int x = maxx/2;
	int y = maxy/2;
	noecho();
	keypad(stdscr, TRUE)
	mvaddch(x, y, player);
	while (true) {
		ch = getch();
		switch (ch) {
			case KEY_UP:
				if (x - 1 != 0) {
					x = x - 1;
					erase();
					mvaddch(x, y, player);
				}
				break;
			case KEY_DOWN:
				if (x + 1 < maxx) {
					x = x + 1;
					erase();				
					mvaddch(x, y, player);
				}
 				break;
			case KEY_LEFT:
				if (y - 1 != 0) {
					y = y - 1;
					erase();
					mvaddch(x, y, player);
				}
				break;
			case KEY_RIGHT:
				if (y + 1 < maxy) {
					y = y + 1;
					erase();
					mvaddch(x, y, player);
				}
				break;
			case 113:
				erase();
				refresh();
				return 0;
			default:
				break;
		}
		refresh();
	}
	return 0;
}