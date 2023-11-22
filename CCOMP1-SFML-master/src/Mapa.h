#pragma once
#include "Plataforma.h"

class Mapa
{
private:
    //mapa_plataformas = matriz = vector de vectores
    std::vector< std::vector < Plataforma* > > mapa_plataformas;
    sf::Texture* plataformaSheet;
    unsigned plataformaSize;

    // {1,1,1,1,1,1,2,2,2,2,1
    // colisión
    // matriz vacía, método dibujar, a nivel
    // protected por private:
    // mapa a filas y columnas, matriz bidimensional,
    // a través de punteros se lea la matriz con bucles

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

