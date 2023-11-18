#ifndef CMAKESFMLPROJECT_JUEGO_H
#define CMAKESFMLPROJECT_JUEGO_H
#include "Includes/libs.h"
#include "Jugador.h"
class Juego{
private:
    sf::RenderWindow ventana;
    sf::Event evento;

    Jugador* jugador;

    void Iniciarventana();
    void IniciarJugador();
public:
    //Constructor
    Juego();
    //Destructor
    virtual ~Juego();
    //Funciones
    void updatePlayer();
    void update();
    void renderPlayer();
    void render();
    const sf::RenderWindow& getVentana() const;
};


#endif //CMAKESFMLPROJECT_JUEGO_H
