#include <cmath>

#include "../../include/explosion/Explosion.hpp"


bool Explosion::setSoundBuffer(const std::string &path)
{
    return Explosion::soundBuffer.loadFromFile(path);
}

void Explosion::setGlobalDelay(float *globalDelay)
{
    Explosion::globalDelay = globalDelay;
}

Explosion::Explosion()
{
    sound.setBuffer(Explosion::soundBuffer);
    explosionParticles = std::vector<Particle>(50, Particle(sf::Vector2f(0, 0), 5, 30));
}

Explosion::~Explosion()
{

}

void Explosion::update()
{
    if(cooldown > 0)
        cooldown -= *globalDelay;

    if(cooldown > 0.02)
    {
        for(auto &particle : explosionParticles)
        {
            particle.update();
        }
    }
}


bool Explosion::igniteExplosion(std::vector<PhysicalObject *> &objects)
{
    if(cooldown > 0.02)
        return false;
    cooldown = 1.1;
    sound.play();
    for(auto &particle : explosionParticles)
    {
        particle.setVelocity({0.f, 0.f});
        particle.setPosition(position);
        particle.push({float(rand()%100-50)*10, float(rand()%100-50)*10});
        particle.body.setFillColor(sf::Color(rand()%255, rand()%100, rand()%100));
    }

    for(auto &obj : objects)
    {
        auto objPos = obj->getPosition();
        float distance = sqrtf((objPos.x-position.x)*(objPos.x-position.x)+(objPos.y-position.y)*(objPos.y-position.y));

        if(distance < radius)
        {
            auto normal = sf::Vector2f(objPos.x-position.x, objPos.y-position.y) / distance;
            obj->push(100.f*normal*force*radius/distance);
        }
    }
    return true;
}

void Explosion::setForce(float force)
{
    this->force = force;
}

void Explosion::setPosition(const sf::Vector2f &vec)
{
    this->position = vec;
}

float Explosion::getForce()
{
    return force;
}

sf::Vector2f Explosion::getPosition()
{
    return position;
}

void Explosion::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if(cooldown < 0.02)
    {
        return;
    }

    for(auto &particle : explosionParticles)
    {
        target.draw(particle, states);
    }
}