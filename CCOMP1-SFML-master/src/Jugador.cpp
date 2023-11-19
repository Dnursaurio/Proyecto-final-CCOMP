#include "Includes/libs.h"
#include "Jugador.h"

void Jugador::inicializarVariables()
{
    this->fotogramas= ESTADOS_DE_NIMACION_JUGADOR::INAC;
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
    this->inicializarGravedad();
}
void Jugador::inicializarGravedad() {
    this->velomx=15.f;
    this->velomin = 1.f;
    this->ace=2.f;
    this->desa=0.90f;
}
Jugador::~Jugador()
{

}
void Jugador::updateGravedad() {
    //Desaceleracion
    this->velo *=this->desa;


//limite de desaceleracion

    if(std::abs(this->velo.x)< this->velomin)
        this->velo.x=0.f;
    if(std::abs(this->velo.y)< this->velomin)
        this->velo.y=0.f;

    this->sprite.move(this->velo);

}
    void Jugador::move(const float dir_x, const float dir_y) {

//Alceleracion
    this->velo.x += dir_x * this->ace;
//  this->velo.y += dir_x * this->ace;

//velocidad limite
    if(std::abs(this->velo.x)> this->velomx){
        this->velo.x = this-> velomx *((this->velo.x<0.f) ?  -1.f:1.f);
    }
}

void Jugador::updateMovJugador()
{
    this->fotogramas= ESTADOS_DE_NIMACION_JUGADOR::INAC;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->move(-1.f, 0.f);
        this->fotogramas= ESTADOS_DE_NIMACION_JUGADOR::IZQ;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->move(1.f, 0.f);
        this->fotogramas= ESTADOS_DE_NIMACION_JUGADOR::DERE;
    }


//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
//    {
//        this->sprite.move(0.f, -1.f);
//        this->fotogramas= ESTADOS_DE_NIMACION_JUGADOR::ARRIBA
//    }
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
//    {
//        this->sprite.move(0.f, 1.f);
//        this->fotogramas= ESTADOS_DE_NIMACION_JUGADOR::BAJO
//    }
}

void Jugador::updateAnimaciones() {
    if (this->fotogramas == ESTADOS_DE_NIMACION_JUGADOR::INAC) {
        if (this->timerAnimacion.getElapsedTime().asSeconds() >= 0.2f) //Velocidad de cambio de frames
        {
            this->frameActual.top = 0.f;
            this->frameActual.left += 40.f;
            if (this->frameActual.left >= 160.f)
                this->frameActual.left = 0;

            this->timerAnimacion.restart();
            this->sprite.setTextureRect(this->frameActual);
        }
    }

    else if(this->fotogramas==ESTADOS_DE_NIMACION_JUGADOR::DERE)
    {
        if (this->timerAnimacion.getElapsedTime().asSeconds() >= 0.1f) //Velocidad de cambio de frames
        {
            this->frameActual.top = 50.f;
            this->frameActual.left += 40.f;
            if (this->frameActual.left >= 160.f)
                this->frameActual.left = 0;

            this->timerAnimacion.restart();
            this->sprite.setTextureRect(this->frameActual);
        }
    }
}



void Jugador::update()
{



    this->updateGravedad();
    this->updateMovJugador();
    this->updateAnimaciones();
}

void Jugador::render(sf::RenderTarget &target)
{
    target.draw(this->sprite);
}






