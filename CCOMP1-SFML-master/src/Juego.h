#pragma once
#include "Jugador.h"
#include "Mapa.h"

class Juego
{
private:
    sf::RenderWindow ventana;
    sf::Event evento;
    sf::Texture plataformaSheet;

    Jugador* jugador;
    Mapa mapaPlataformas;

    // Funciones privadas de inicialización
    void iniciarVentana();
    void iniciarJugador();
    void iniciarMapaPlataformas();

public:
    // Constructores y destructor
    Juego();
    ~Juego();

    // Funciones de actualización
    void updatePlayer();
    void updateColision();
    void update();

    // Funciones de renderizado
    void renderPlayer();
    void render();

    // Acceso a la ventana
    const sf::RenderWindow& getVentana() const;
};
