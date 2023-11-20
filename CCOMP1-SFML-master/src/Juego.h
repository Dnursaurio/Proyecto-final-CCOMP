#pragma once
#include "Jugador.h"
#include "Mapa.h"

class Juego{
private:
    sf::RenderWindow ventana;
    sf::Event evento;
    sf::Texture plataformaSheet;

    Jugador* jugador;
    Mapa* mapa_plataformas;

    void iniciarVentana();
    void iniciarPlataformaSheet();
    void iniciarJugador();
    void iniciarMapaPlataformas();
public:
    //Constructor
    Juego();
    //Destructor
    virtual ~Juego();
    //Funciones
    void updatePlayer();
    void updateColision();
    void updateMapaPlataformas();
    void update();

    void renderPlayer();
    void renderMapaPlataformas();
    void render();

    const sf::RenderWindow& getVentana() const;
};


