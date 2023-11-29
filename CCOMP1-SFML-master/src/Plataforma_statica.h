#include "Includes/libs.h"
#include "Plataforma.h"

#ifndef CMAKESFMLPROJECT_PLATAFORMA_STATICA_H
#define CMAKESFMLPROJECT_PLATAFORMA_STATICA_H

class Plataforma_static: public Plataforma
{
public:
    explicit Plataforma_static(float x, float y, float width, float height, const bool puedemoverse): Plataforma(x,y,width,height,puedemoverse)
    {
        shape.setPosition(x, y);
        shape.setSize(sf::Vector2f(width, height));
        shape.setFillColor(sf::Color::Green);
    };
    sf::FloatRect getGlobalBounds() const override;

    void draw(sf::RenderTarget &target) const override;
};
#endif //CMAKESFMLPROJECT_PLATAFORMA_STATICA_H
