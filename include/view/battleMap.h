#pragma once
#include <string>
#include <vector>

struct Hero
{
    std::string name;
    int hp;
    int maxHp;
    bool isAlive;
};

struct PlayerStatus
{
    std::string name;
    std::vector<Hero> team; 
    // این وکتور دقیقاً شامل ۳ هیروی انتخاب شده است
};

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // برای تنظیم دقیق فاصله‌ها در ترمینال

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define WHITE "\033[1;37m"

inline void renderBattleScreen(int round, const PlayerStatus &p1, const PlayerStatus &p2,
                               const std::vector<std::string> &battleLog, int currentActionIndex)
{
    system("cls");

    // ۱. هدر راند
    std::cout << CYAN << "========================================================================\n";
    std::cout << "                         ⚔️  ROUND " << round << "  ⚔️\n";
    std::cout << "========================================================================\n"
              << RESET;

    // ۲. نام پلیرها
    std::cout << BLUE << " [ PLAYER 1: " << p1.name << " ]" << RESET;
    std::cout << std::setw(40) << std::right << RED << "[ PLAYER 2: " << p2.name << " ]\n"
              << RESET;
    std::cout << CYAN << "------------------------------------------------------------------------\n"
              << RESET;

    // ۳. نمایش هر ۳ هیرو به صورت روبه‌روی هم (سطر به سطر)
    for (int i = 0; i < 3; ++i)
    {
        // --- هیروی پلیر ۱ (سمت چپ) ---
        if (p1.team[i].hp > 0)
        {
            std::cout << BLUE << " 🛡️ " << std::setw(15) << std::left << p1.team[i].name << RESET;
            std::cout << GREEN << "HP: " << std::setw(3) << p1.team[i].hp << "/" << p1.team[i].maxHp << RESET;
        }
        else
        {
            // هیرو مرده است
            std::cout << RED << " 💀 " << std::setw(15) << std::left << p1.team[i].name << " [DEAD]    " << RESET;
        }

        // فاصله بین دو ستون
        std::cout << "   VS   ";

        // --- هیروی پلیر ۲ (سمت راست) ---
        if (p2.team[i].hp > 0)
        {
            std::cout << RED << " 🛡️ " << std::setw(15) << std::left << p2.team[i].name << RESET;
            std::cout << RED << "HP: " << std::setw(3) << p2.team[i].hp << "/" << p2.team[i].maxHp << RESET << "\n";
        }
        else
        {
            // هیرو مرده است
            std::cout << RED << " 💀 " << std::setw(15) << std::left << p2.team[i].name << " [DEAD]\n"
                      << RESET;
        }
    }

    std::cout << CYAN << "========================================================================\n"
              << RESET;

    // ۴. بخش لاگ‌های بازی
    std::cout << YELLOW << " 📜 BATTLE LOG:\n"
              << RESET;
    if (battleLog.empty())
    {
        std::cout << "   The battle has just begun! Waiting for moves...\n";
    }
    else
    {
        int start = std::max(0, (int)battleLog.size() - 3);
        for (size_t i = start; i < battleLog.size(); ++i)
        {
            std::cout << "   » " << battleLog[i] << "\n";
        }
    }

    std::cout << CYAN << "------------------------------------------------------------------------\n"
              << RESET;

    // ۵. منوی انتخاب حرکت در پایین صفحه
    std::cout << WHITE << " YOUR TURN! Choose your tactical action:\n\n"
              << RESET;
    std::vector<std::string> actions = {
        "Standard Attack (All Alive Heroes)",
        "Activate Hero Abilities",
        "Defensive Maneuver",
        "Surrender Match"};

    for (size_t i = 0; i < actions.size(); ++i)
    {
        if ((int)i == currentActionIndex)
        {
            std::cout << GREEN << "  👉 [ " << actions[i] << " ]\n"
                      << RESET;
        }
        else
        {
            std::cout << "     [ " << actions[i] << " ]\n";
        }
    }
    std::cout << "\n Controls: [Up/Down] Navigate | [Enter] Execute Command\n";
}