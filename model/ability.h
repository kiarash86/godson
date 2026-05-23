#include <functional>
#include <vector>
#include<string>
#include"card.h"
struct ability
{
    std::string name ;
    int energy{};
    std::function<void(std::vector<card>& myTeam, std::vector<card>& enemy)> act;
};
