#pragma once
#include "Plataforma.h"

class Mapa
{
private:
    //mapa_plataformas = matriz = vector de vectores
    std::vector<std::vector < Plataforma* > > mapa_plataformas;
    sf::Texture* plataformaSheet;
    unsigned plataformaSize;

public:
    //Constructor
    Mapa();
    //Constructor específico
    Mapa(unsigned ancho, unsigned alto, sf::Texture* plataformaSheet, unsigned plataformaSize);
    //Destructor
    ~Mapa();

    //Funciones
    void agregarPlataforma(unsigned x, unsigned y);
    void removerPlataforma(unsigned x, unsigned y);
    void update();
    void render(sf::RenderTarget& target);
};

