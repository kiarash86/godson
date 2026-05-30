#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

void displayOption(const std::string &title, const std::string &bio)
{
    system("cls");
    std::cout << "==================================================\n";
    std::cout << " SUBJECT: " << title << "\n";
    std::cout << "==================================================\n\n";
    std::cout << bio << "\n\n";
    std::cout << "--------------------------------------------------\n";
    std::cout << "Press any key to return to the Stories Menu...";
    _getch();
}

void handleOptionsMenu(int index)
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