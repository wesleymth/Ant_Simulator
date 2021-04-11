#include "Ant.hpp"
#include "../Application.hpp"
#include "../Utility/Utility.hpp"
#include "Pheromone.hpp"

Ant::Ant(const Vec2d& pos, double HP, double LT, Uid id)
    :Animal::Animal(pos, HP, LT), anthillID(id)
{
    //Done
}

Ant::Ant(const Vec2d& pos, Uid id)
    :Animal::Animal(pos), anthillID(id) //calls constructor of Animal using only a position
{
    //Done
}

Ant::Ant()
    :Animal::Animal(), anthillID() //calls default constructor of Animal
{
    //Done
}

double Ant::getSpeed() const
{
    return getAppConfig().ant_speed;
}

void Ant::drawOn(sf::RenderTarget& target) const
{
    auto const animalSprite = getSprite();
        target.draw(animalSprite);
    if (isDebugOn()) //if debug on you can see the healthPoints
    {
        sf::VertexArray line(sf::PrimitiveType::Lines, 2);
            line[0] = { getPosition().toVec2d(), sf::Color::Black };
            line[1] = { getPosition().toVec2d()+200*Vec2d::fromAngle(getDirection()), sf::Color::Black };
            target.draw(line);  //draws line
        auto const text = buildText(to_nice_string(getHP()), getPosition().toVec2d(), getAppFont(), 15, sf::Color::Black);
        target.draw(text); //shows healthPoints via a text
    }
}

void Ant::spreadPheromones() // je pense qu'il faudra rajouter un attribut "last pheromone placed" a Ant.
{
    double dist(toricDistance(getPosition(),lastPheromone));
    Vec2d vect(getPosition().toricVector(lastPheromone));
    for(int i(0); i<=dist; ++i)
    {
        Pheromone phero(getAppConfig().ant_pheromone_energy, getPosition().toVec2d()+i*getAppConfig().ant_pheromone_density*vect/dist);
    }
}
void Ant::move(sf::Time dt)
{
    Animal::move(dt);
    spreadPheromones();
}
