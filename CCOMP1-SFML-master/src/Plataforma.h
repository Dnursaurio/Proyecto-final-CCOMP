#pragma once

class Plataforma
{
private:
    sf::Sprite sprite;
    const bool dano;

public:
    //Constructor
    Plataforma(sf::Texture* texture_sheet,sf::IntRect texture_rect,bool dano = false);

    //Funciones
    const sf::FloatRect getGlobalValores() const;
    void update();
    void render(sf::RenderTarget& target);
};

