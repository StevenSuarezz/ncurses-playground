#include <ncurses.h>

int main()
{
	// Initializes screen, sets up memory and clears screen
	initscr();

	int x {10};
	int y {10};

	// Move the cursor to the specified location (y, x)
	move(y, x);

	printw("Hello World!");

	// Refreshes screen to match memory
	refresh();
	
	// Store character code in int var
	int charCode = getch();

	// Clear the screen
	clear();

	// move and print in one command
	//mvprintw(0,0, "%d", charCode);

	// More verbose to move and print in separate lines
	move(0, 0);
	printw("%d", charCode);

	// Waits for user input, returns int value of key
	getch();

	// Deallocates memory and ends ncurses
	endwin();

	return 0;
}
