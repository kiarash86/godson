#include<iostream>
#include<vector>
#include<utility>
#include<string>
class storitesMenu
{
private:
std::vector<std::pair<std::string , std::string>> cards;
public:
    void cardsMenu()
    {
        for (auto &&cr : cards)
        {
            std::cout<<"name: " <<cr.first << std::endl;
            
        }
        std::cout << "exit" << std::endl;
        
    }
    void showBackStory(std::string name) const {
        for (auto &&crd : cards)
        {
            if (crd.first == name)
            {
                std::cout<<"name: " <<crd.first << "-> story:" << crd.second<<  std::endl;
                
            }
            
        }
        
    }
};
