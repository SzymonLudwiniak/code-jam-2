#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class Explosion : sf::Drawable
{
public:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    sf::Vector2f position;
};