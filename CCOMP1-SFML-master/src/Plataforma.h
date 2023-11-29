#pragma once
<<<<<<< HEAD
#include <SFML/Graphics.hpp>
class Plataforma {
protected:
    sf::RectangleShape shape;
=======

class Plataforma
{
private:
    sf::RectangleShape shape;

>>>>>>> f9de81e045e5e1c243ca8d1a46d1e6f10ad4c40e
    //coordenadas:
    float x;
    float y;
    float width;
    float height;
<<<<<<< HEAD
    const bool puedemoverse;
public:
    Plataforma(float x, float y, float width, float height, const bool puedemoverse): x(x), y(y), width(width), height(height), puedemoverse(puedemoverse) {
=======
public:
    Plataforma(float x, float y, float width, float height): x(x), y(y), width(width), height(height) {
>>>>>>> f9de81e045e5e1c243ca8d1a46d1e6f10ad4c40e
        shape.setPosition(x, y);
        shape.setSize(sf::Vector2f(width, height));
        shape.setFillColor(sf::Color::Green);
    }
<<<<<<< HEAD

    virtual sf::FloatRect getGlobalBounds()const;

    virtual void draw(sf::RenderTarget& target)const;
    float getX() const { return x; }
    float getY() const { return y; }
    float getWidth() const { return width; }
    float getHeight() const { return height; }

    virtual bool movimientoplataforma() const;
=======

    sf::FloatRect getGlobalBounds() const;

    void draw(sf::RenderTarget& target)const;

>>>>>>> f9de81e045e5e1c243ca8d1a46d1e6f10ad4c40e
};

