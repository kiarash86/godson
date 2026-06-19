#pragma once
#include <vector>
#include <string>
#include <ncurses.h>

inline void displayLore(const std::string &title, const std::string &bio)
{
    clear();
    printw("==================================================\n");
    printw(" HERO: %s\n", title.c_str());
    printw("==================================================\n\n");
    printw("%s\n\n", bio.c_str());
    printw("--------------------------------------------------\n");
    printw("Press any key to return to the Stories Menu...");
    refresh();
    getch();
}

inline void handleStoriesMenu(int index)
{
    switch (index)
    {
    case 0:
        displayLore("LITTLE TAHA",
                    "A nimble prodigy operating in the shadow of his older brother, specializing in speed and disruption...\n"
                    "Skill: Siphons energy or bypasses shields with lightning-fast tactical strikes.");
        break; 

    case 1:
        displayLore("BIG TAHA",
                    "A grand engineer who dominates the battlefield using calculated psychological pressure...\n"
                    "Skill: Plants a Time Bomb that detonates after 2 rounds, dealing massive fatal damage.");
        break;

    case 2:
        displayLore("DR.WHITE",
                    "Dr. Sefid spent decades in medical labs, mastering the line between life and death...\n"
                    "Ultimate: 'Operating Room Protocol' can revive a fallen teammate with 200 HP.");
        break;

    case 3:
        displayLore("DANI GOLANG",
                    "A hyper-efficient tactician capable of running multiple combat routines with zero latency...\n"
                    "Skill: Executes concurrent strikes on multiple targets or purges system debuffs instantly.");
        break;

    case 4:
        displayLore("AMIN PROTECTOR",
                    "An immovable guardian who wields heavy armor and kinetic shields to absorb massive damage...\n"
                    "Skill: Deploys energy barriers to completely shield allies or intercepts incoming attacks.");
        break;
        
    case 5:
        displayLore("POUYA KAZHDAM",
                    "A deadly assassin nicknamed 'The Scorpion' who strikes silently from the dark...\n"
                    "Skill: Inflicts Active Venom that drains enemy health at the end of every single turn.");
        break;
        
    case 6:
        displayLore("AGHA SHAHRIAR",
                    "A master of illusions who flips the rules of reality using his Joker Deck...\n"
                    "Ultimate: 'World Inversion' turns all damage into healing and vice versa for 2 rounds.");
        break;
        
    case 7:
        break;
    }
}