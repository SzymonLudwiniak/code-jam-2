#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../physics/particle.hpp"


class Explosion : public sf::Drawable
{
public:
    static bool setSoundBuffer(const std::string &path);
    static void setGlobalDelay(float *globalDelay);

    Explosion();
    ~Explosion();

    void update();

    bool igniteExplosion(std::vector<PhysicalObject *> &objects);

    void setForce(float force);
    void setPosition(const sf::Vector2f &vec);

    float getForce();
    sf::Vector2f getPosition();

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    static inline sf::SoundBuffer soundBuffer;
    static inline float *globalDelay = nullptr;

    sf::Vector2f position;

    float force;
    float radius = 100.f;

    std::vector<Particle> explosionParticles;

    sf::Sound sound;

    float cooldown;

};