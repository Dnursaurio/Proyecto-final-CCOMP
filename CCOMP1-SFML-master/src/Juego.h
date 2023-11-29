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
<<<<<<< HEAD
    Mapa mapa_plataformas;
=======
    Mapa mapaPlataformas;
>>>>>>> f9de81e045e5e1c243ca8d1a46d1e6f10ad4c40e

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
