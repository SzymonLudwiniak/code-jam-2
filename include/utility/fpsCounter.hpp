#include <SFML/Graphics.hpp>

class FpsCounter : public sf::Text
{
public:
    FpsCounter();
    ~FpsCounter();

    void saveTime();

    double getDrawTime();

private:
    sf::Font font;

    sf::Clock clock;

    sf::Time previousTime;
    sf::Time currentTime;

    double drawTime;
};