#pragma once
#include <vector>
#include <string>
#include <ncurses.h>

inline std::vector<int> selectThreeCards(const std::string &title, const std::vector<std::string> cards)
{
    int selectedIndex = 0;
    int numCards = cards.size();
    int totalRows = numCards + 1;

    std::vector<bool> isCardSelected(numCards, false);
    int currentSelectedCount = 0;
    std::string warningMessage = "";

    keypad(stdscr, TRUE);
    curs_set(0);

    while (true)
    {
        clear();
        
        printw("==================================================\n");
        printw("   %s\n", title.c_str());
        printw("==================================================\n\n");

        for (int i = 0; i < numCards; ++i)
        {
            if (i == selectedIndex)
            {
                printw("  ► ");
            }
            else
            {
                printw("    ");
            }

            if (isCardSelected[i])
            {
                printw("[X] %s  <--- [ SELECTED ]\n", cards[i].c_str());
            }
            else
            {
                printw("[ ] %s\n", cards[i].c_str());
            }
        }

        printw("\n--------------------------------------------------\n");

        if (selectedIndex == numCards)
        {
            printw("  ► [ CONFIRM SELECTION (%d/3) ]\n", currentSelectedCount);
        }
        else
        {
            printw("    [ CONFIRM SELECTION (%d/3) ]\n", currentSelectedCount);
        }

        if (!warningMessage.empty())
        {
            printw("\n[!] Warning: %s\n", warningMessage.c_str());
        }

        refresh();

        int ch = getch();

        if (ch == KEY_UP)
        {
            selectedIndex = (selectedIndex - 1 + totalRows) % totalRows;
        }
        else if (ch == KEY_DOWN)
        {
            selectedIndex = (selectedIndex + 1) % totalRows;
        }
        else if (ch == '\n' || ch == KEY_ENTER || ch == 10)
        {
            warningMessage = "";

            if (selectedIndex < numCards)
            {
                if (isCardSelected[selectedIndex])
                {
                    isCardSelected[selectedIndex] = false;
                    currentSelectedCount--;
                }
                else
                {
                    if (currentSelectedCount < 3)
                    {
                        isCardSelected[selectedIndex] = true;
                        currentSelectedCount++;
                    }
                    else
                    {
                        warningMessage = "You can only select EXACTLY 3 cards! Deselect one first.";
                    }
                }
            }
            else if (selectedIndex == numCards)
            {
                if (currentSelectedCount == 3)
                {
                    std::vector<int> chosenIndices;
                    for (int i = 0; i < numCards; ++i)
                    {
                        if (isCardSelected[i])
                        {
                            chosenIndices.push_back(i);
                        }
                    }
                    return chosenIndices;
                }
                else
                {
                    warningMessage = "Please select exactly 3 cards before confirming! (Current: " + std::to_string(currentSelectedCount) + ")";
                }
            }
        }
    }
}