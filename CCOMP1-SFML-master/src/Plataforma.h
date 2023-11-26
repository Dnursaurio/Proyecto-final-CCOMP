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

    sf::FloatRect getGlobalBounds();

    void draw(sf::RenderTarget& target)const;
};

