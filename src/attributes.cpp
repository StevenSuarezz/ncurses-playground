#include <ncurses.h>

int main()
{
	initscr();

	/*
	 * A_NORMAL
	 * A_STANDOUT
	 * A_REVERSE
	 * A_BLINK
	 * A_DIM
	 * A_BOLD
	 * A_PROTECT
	 * A_INVIS
	 * A_ALTCHARSET
	 * A_CHARTEXT
	 */

	// Apply an attribute to printed text
	attron(A_STANDOUT);
	printw("This is some text");
	attroff(A_STANDOUT);

	/*
	 * COLOR_PAIR(n)
	 * COLOR_BLACK		0
	 * COLOR_RED		1
	 * COLOR_GREEN		2
	 * COLOR_YELLOW		3
	 * COLOR_BLUE		4
	 * COLOR_MAGENTA	5
	 * COLOR_CYAN		6
	 * COLOR_WHITE		7
	 */

	// Safety check for terminal color changing capability
	if (!has_colors())
	{
		printw("Terminal does not support colors");
		getch();
		return -1;
	}

	// Creating a foreground/background
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_WHITE); 
	init_pair(2, COLOR_MAGENTA, COLOR_YELLOW);

	// Can change the color value for a color (R,G,B) from 0 - 999
	//init_color(COLOR_CYAN, 999, 999, 999);

	// Check for color changing functionality in terminal
	if (can_change_color())
	{
		printw("Can change color");
		init_color(COLOR_CYAN, 999, 999, 999);
	}
		

	// Use attributes and apply to printing
	attron(COLOR_PAIR(1));
	printw("This is some colored text");
	attroff(COLOR_PAIR(1));

	attron(COLOR_PAIR(2));
	printw("This is some even more colorful text");
	attroff(COLOR_PAIR(2));

	getch();
	endwin();

	return 0;
}
