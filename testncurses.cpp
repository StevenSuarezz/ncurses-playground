#include <ncurses.h>

int main()
{
	// Initializes screen, sets up memory and clears screen
	initscr();

	printw("Hello World!");

	// Refreshes screen to match memory
	refresh();

	// Waits for user input, returns int value of key
	getch();

	// Deallocates memory and ends ncurses
	endwin();

	return 0;
}
