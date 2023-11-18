#include "Includes/libs.h"
#include "Juego.h"

void Juego::Iniciarventana()
{
    this->ventana.create(sf::VideoMode(1280,720),"Byteland",sf::Style::Close | sf::Style::Titlebar);
    this->ventana.setFramerateLimit(144); //Establecer el límite de frames para el movimiento
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
        switch (evento.type) {
            case sf::Event::Closed:
            {
                ventana.close();
                break;
            }
            case sf::Event::KeyPressed:
            {
                switch (evento.key.code){
                    case sf::Keyboard::Escape:
                    {
                        ventana.close();
                        break;
                    }
                }

            }
        }
    }

    this->updatePlayer();
}

void Juego::renderPlayer()
{
    this->jugador->render(this->ventana);
}

void Juego::render()
{
    this->ventana.clear(sf::Color::Blue);

    //renderizar el juego
    this->renderPlayer();
    this->ventana.display();
}

const sf::RenderWindow& Juego::getVentana() const
{
    return this->ventana;
}



