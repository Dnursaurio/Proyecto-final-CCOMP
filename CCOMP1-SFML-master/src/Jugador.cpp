#include "libs.h"
#include "Jugador.h"

void Jugador::inizializartextura()
{

}

void Jugador::inicializarsprite()
{

}

Jugador::Jugador()
{
    this->inizializartextura();
    this->inicializarsprite();
}

Jugador::~Jugador()
{

}

void Jugador::update() {

}

void Jugador::render(sf::RenderTarget &target)
{
    target.draw(this->sprite);
}