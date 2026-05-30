#include <iostream>
#include <vector>
#include <utility>
#include <string>
class preparationGameView
{
private:
    std::vector<std::pair<std::string, std::vector<std::string>>> cards;

public:
    void cardsMenu()
    {
        std::cout << "select 3 cards from below options\n";
        for (auto &&cr : cards)
        {
            std::cout << "name: " << cr.first << std::endl;
            for (auto &&abl : cr.second)
            {
                std::cout << "  name of ability: " << abl << std::endl;
            }
            std::cout << std::endl;
        }
    }
};
