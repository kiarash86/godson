#pragma once
#include <vector>
#include <string>
#include <ncurses.h>

inline int viewInteractiveMenu(const std::string &title, const std::vector<std::string> &options)
{
    int selectedIndex = 0;
    int numOptions = options.size();

    keypad(stdscr, TRUE); 
    curs_set(0);   

    while (true)
    {
        clear();

        printw("=================================\n");
        printw(" %s\n", title.c_str());
        printw("=================================\n\n");

        for (int i = 0; i < numOptions; ++i)
        {
            if (i == selectedIndex)
            {
                printw(" -> [ %s ] \n", options[i].c_str());
            }
            else
            {
                printw("    %s\n", options[i].c_str());
            }
        }
        printw("\n---------------------------------\n");
        
        refresh(); 

        int ch = getch();

        if (ch == KEY_UP)
        {
            selectedIndex = (selectedIndex - 1 + numOptions) % numOptions;
        }
        else if (ch == KEY_DOWN)
        {
            selectedIndex = (selectedIndex + 1) % numOptions;
        }
        else if (ch == '\n' || ch == KEY_ENTER || ch == 10) 
        {
            return selectedIndex;
        }
    }
}