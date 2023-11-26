#pragma once
#include "Jugador.h"
#include "Plataforma.h"

class Juego{
private:
    sf::RenderWindow ventana;
    sf::Event evento;
    sf::Texture plataformaSheet;

    Jugador* jugador;
    Plataforma* mapa_plataformas;

    void iniciarVentana();
    void iniciarPlataformaSheet();
    void iniciarJugador();
    void iniciarMapaPlataformas();
public:
    //Constructor
    Juego();
    //Destructor
    ~Juego();
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


