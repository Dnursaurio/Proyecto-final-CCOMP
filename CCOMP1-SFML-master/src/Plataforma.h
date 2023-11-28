#pragma once
#include <SFML/Graphics.hpp>
class Plataforma {
private:
    sf::RectangleShape shape;
    //coordenadas:
    float x;
    float y;
    float width;
    float height;
public:
    Plataforma(float x, float y, float width, float height): x(x), y(y), width(width), height(height) {
        shape.setPosition(x, y);
        shape.setSize(sf::Vector2f(width, height));
        shape.setFillColor(sf::Color::Green);
    }

    sf::FloatRect getGlobalBounds()const;

    void draw(sf::RenderTarget& target)const;
    float getX() const { return x; }
    float getY() const { return y; }
    float getWidth() const { return width; }
    float getHeight() const { return height; }
};

