#pragma once

class Plataforma
{
private:
    sf::Sprite sprite;
    std::vector< std::vector < Plataforma* > > mapa_plataformas;
    sf::Texture* plataformaSheet;
    unsigned plataformaSize;

public:
    //Constructor
    Plataforma(sf::Texture* texture_sheet,sf::IntRect texture_rect);
    //Otro constructor
    Plataforma(int ancho, int alto, sf::Texture* plataformaSheet, unsigned plataformaSize);
    //Destructor
    ~Plataforma();
    //Accesos
    const sf::Vector2f getPosition() const;
    //Funciones
    void setPosition(int x,int y);
    const sf::FloatRect getGlobalValores() const;
    void agregarPlataforma(float x, float y);
    void removerPlataforma(unsigned x, unsigned y);
    void update();
    void render(sf::RenderTarget& target);
};

