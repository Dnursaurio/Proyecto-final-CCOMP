#include "libs.h"
#include "Juego.h"

void Juego::Iniciarventana()
{
    this->ventana.create(sf::VideoMode(1280,720),"Byteland",sf::Style::Close | sf::Style::Titlebar);
}

void Juego::IniciarJugador()
{
    this->jugador = new Jugador();
}


Juego::Juego()
{
    this->Iniciarventana();
    this->IniciarJugador();
}

Juego::~Juego()
{
    delete this->jugador;
}

void Juego::updatePlayer()
{
    this->jugador->update();
}

void Juego::update()
{
    //agrupando los eventos de la ventana
    while(this->ventana.pollEvent(this->evento))
    {
        if(this->evento.type = sf::Event::Closed)
        {
            this->ventana.close();
        }
        else if(this->evento.type == sf::Event::KeyPressed && this->evento.key.code == sf::Keyboard::Escape)
        {
            this->ventana.close();
        }
    }

    this->updatePlayer();
}

void Juego::render()
{
    this->ventana.clear(sf::Color::Blue);

    //renderizar el juego

    this->ventana.display();
}

const sf::RenderWindow& Juego::getVentana() const
{
    return this->ventana;
}



