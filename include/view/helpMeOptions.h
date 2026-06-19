#pragma once
#include <vector>
#include <string>
#include <ncurses.h>

inline void displayOption(const std::string &title, const std::string &bio)
{
    clear();
    printw("==================================================\n");
    printw(" SUBJECT: %s\n", title.c_str());
    printw("==================================================\n\n");
    printw("%s\n\n", bio.c_str());
    printw("--------------------------------------------------\n");
    printw("Press any key to return to the Help Menu...");
    refresh();
    getch();
}

inline void handleOptionsMenu(int index)
{
    switch (index)
    {
    case 0:
        displayOption("HOW TO PLAY", "IF U WANT TO PLAY THIS GAME U SHOULD CONSIDER...");
        break;
    case 1:
        displayOption("ABOUT GAME", "NOTHING TO SAY");
        break;
    }
}