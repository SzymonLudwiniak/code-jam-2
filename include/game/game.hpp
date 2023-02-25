#include <SFML/Graphics.hpp>
#include <cstdint>

class Game : 
public sf::RenderWindow 
{
public:
    Game(sf::VideoMode mode, const std::string &title,  unsigned int style = sf::Style::Default, 
        const sf::ContextSettings &settings = sf::ContextSettings());
    ~Game();

    virtual void init();
    virtual void update();
    
    void run();
private:
    virtual void handleEvents();
};