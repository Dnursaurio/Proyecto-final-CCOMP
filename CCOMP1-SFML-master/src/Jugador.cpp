#include "Includes/libs.h"
#include "Jugador.h"

void Jugador::inicializarVariables()
{
    this->movimiento = false;
}


void Jugador::inicializartextura()
{
    if (this->textureSheet.loadFromFile("Textures/player_sheet.png"))
    {
        std::cout << "Error::Jugador::No se puede cargar el player_sheet!" << std::endl;
    }
}

void Jugador::inicializarsprite()
{
    this->sprite.setTexture(this->textureSheet);
    this->frameActual = sf::IntRect(0,0,40,50);
    this->sprite.setTextureRect(sf::IntRect(this->frameActual));
    this->sprite.setScale(2.5f,2.5f);
}

void Jugador::inicializarAnimaciones()
{
    this->timerAnimacion.restart();
}

Jugador::Jugador()
{
    this->inicializarVariables();
    this->inicializartextura();
    this->inicializarsprite();
    this->inicializarAnimaciones();
}

Jugador::~Jugador()
{

}

void Jugador::updateMovJugador()
{
    this->movimiento = false;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->sprite.move(-1.f, 0.f);
        this->movimiento = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->sprite.move(1.f, 0.f);
        this->movimiento = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->sprite.move(0.f, -1.f);
        this->movimiento = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->sprite.move(0.f, 1.f);
        this->movimiento = true;
    }
}

void Jugador::updateAnimaciones()
{
    if(this->timerAnimacion.getElapsedTime().asSeconds() >= 0.2f) //Velocidad de cambio de frames
    {
        if (this->movimiento == false) //Animación con Frames
        {
            this->frameActual.left += 40.f;
            if (this->frameActual.left >= 160.f) {
                this->frameActual.left = 0;
            }
        }
        this->timerAnimacion.restart();
        this->sprite.setTextureRect(this->frameActual);
    }
}

void Jugador::update()
{
    this->updateMovJugador();
    this->updateAnimaciones();
}

void Jugador::render(sf::RenderTarget &target)
{
    target.draw(this->sprite);
}