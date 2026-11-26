#include <iostream>
#include <ncurses.h>

int main(void) {
    // start ncurse
    initscr();
    // removes line buffering
    raw();
    // enables arrowkeys,etc
    keypad(stdscr, true);
    // print with row, col coord
    mvprintw(2, 10, "Sokoban");
    // render
    refresh();
    // wait for a key
    int ch = getch();
    if (ch == KEY_DOWN) {
        printw("Down!");
    }
    else{
        printw("No");
    }
    refresh();
    getch();
    // shut down
    endwin();

    return EXIT_SUCCESS;
}