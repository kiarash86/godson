#pragma once

#include <iostream>
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

    while (true)
    {
    clear();
    refresh();
        std::cout << "==================================================\n";
        std::cout << "   " << title << "\n";
        std::cout << "==================================================\n\n";

        for (int i = 0; i < numCards; ++i)
        {
            if (i == selectedIndex)
            {
                std::cout << " 👉 ";
            }
            else
            {
                std::cout << "    ";
            }

            std::cout << cards[i];

            if (isCardSelected[i])
            {
                std::cout << "  <--- [ Selected 🏹 ]";
            }
            std::cout << "\n";
        }

        std::cout << "\n--------------------------------------------------\n";

        if (selectedIndex == numCards)
        {
            std::cout << " 👉 [ 📑 CONFIRM SELECTION (" << currentSelectedCount << "/3) ]\n";
        }
        else
        {
            std::cout << "    [ 📑 CONFIRM SELECTION (" << currentSelectedCount << "/3) ]\n";
        }

        int ch = getch();

        if (ch == 0 || ch == 224)
        {
            ch = getch();
            if (ch == KEY_UP)
            {
                selectedIndex = (selectedIndex - 1 + totalRows) % totalRows;
            }
            else if (ch == KEY_DOWN)
            {
                selectedIndex = (selectedIndex + 1) % totalRows;
            }
        }
        else if (ch == KEY_ENTER)
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
                        warningMessage = "You can only select EXACTLY 3 cards! delete one first.";
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
//with ai for now