#ifndef CMAKESFMLPROJECT_JUEGO_H
#define CMAKESFMLPROJECT_JUEGO_H
#include "libs.h"
#include "Jugador.h"
class Juego{
private:
    sf::RenderWindow ventana;
    sf::Event evento;

    Jugador* jugador;

    void Iniciarventana();
    void IniciarJugador();
public:
    //Funciones
    Juego();
    virtual ~Juego();
    //mas funciones
    void updatePlayer();
    void update();
    void render();
    const sf::RenderWindow& getVentana() const;
};


#endif //CMAKESFMLPROJECT_JUEGO_H
