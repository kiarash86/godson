#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13

int viewInteractiveMenu(const std::string &title, const std::vector<std::string> &options)
{
    int selectedIndex = 0;
    int numOptions = options.size();

    while (true)
    {
        system("cls");

        std::cout << "=================================\n";
        std::cout  <<""<< title << "\n";
        std::cout << "=================================\n\n";

        for (int i = 0; i < numOptions; ++i)
        {
            if (i == selectedIndex)
            {
                std::cout << " 👉 [ " << options[i] << " ] \n";
            }
            else
            {
                std::cout << "    " << options[i] << "\n";
            }
        }
        std::cout << "\n---------------------------------\n";
        int ch = _getch();

        if (ch == 0 || ch == 224)
        {
            ch = _getch(); 
            if (ch == KEY_UP)
            {
                selectedIndex = (selectedIndex - 1 + numOptions) % numOptions;
            }
            else if (ch == KEY_DOWN)
            {
                selectedIndex = (selectedIndex + 1) % numOptions;
            }
        }
        else if (ch == KEY_ENTER)
        {
            return selectedIndex;
        }
    }
}