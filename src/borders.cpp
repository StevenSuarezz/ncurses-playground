#include <ncurses.h>

int main()
{
	// Initialize screen
	initscr();

	// Exit out with ^C
	cbreak();
	// Raw input, no special characters
	// raw();
	// Dont print input to the screen
	noecho();

	int height {10};
	int width {20};
	int start_y {2};
	int start_x {2};

	// Window pointer to create a window to work in
	WINDOW* win = newwin(height, width, start_y, start_x);
	refresh();

	// box(Window, Left/Right border char code, Top/Bottom border char code)
	// Can also use static_cast<int>(a char) for the params
	box(win, 0, 0);
	// Standard window printing
	// wprintw(win, "This is a box!");
	mvwprintw(win, 1, 1, "This is a box!");
	wrefresh(win);

	// Wait for user input, get int value of key pressed
	int charCode = getch();

	endwin();

	return 0;
}
