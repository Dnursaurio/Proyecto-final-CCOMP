#pragma once
#include <SFML/Graphics.hpp>
class Plataforma {
protected:
    sf::RectangleShape shape;
    //coordenadas:
    float x;
    float y;
    float width;
    float height;
    const bool puedemoverse;
public:
    Plataforma(float x, float y, float width, float height, const bool puedemoverse): x(x), y(y), width(width), height(height), puedemoverse(puedemoverse) {
        shape.setPosition(x, y);
        shape.setSize(sf::Vector2f(width, height));
        shape.setFillColor(sf::Color::Green);
    }

    virtual sf::FloatRect getGlobalBounds()const;

    virtual void draw(sf::RenderTarget& target)const;
    float getX() const { return x; }
    float getY() const { return y; }
    float getWidth() const { return width; }
    float getHeight() const { return height; }

    virtual bool movimientoplataforma() const;
};

