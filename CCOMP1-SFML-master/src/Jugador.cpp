#include "Includes/libs.h"
#include "Jugador.h"
void paso() { //ojo
    std::cout << "PASO!!" << ":";
}

void Jugador::inicializarVariables()
{
    this->fotogramas= ESTADOS_DE_NIMACION_JUGADOR::INAC;
}

void Jugador::inicializartextura()
{
    if (!this->textureSheet.loadFromFile("Textures/player_sheet.png"))
    {
        std::cout << "Error::Jugador::No se puede cargar el player_sheet.png!" << std::endl;
    }
}

void Jugador::inicializarsprite()
{
    this->sprite.setTexture(this->textureSheet);
    this->frameActual = sf::IntRect(0, 0, 35, 50);
        this->sprite.setTextureRect(this->frameActual);
    this->sprite.setScale(1.5f, 1.5f);
}

void Jugador::inicializarAnimaciones()
{
    this->timerAnimacion.restart();
    this->cambioAnimaciones = true;
    this->frameActual.left = 0.f;
}

void Jugador::inicializarFisica()
{
    this->velomax = 22.f;
    this->velomin = 2.0f;
    this->ace = 3.0f;
    this->desa = 0.80f;
    this->gravedad = 3.f;
    this->velomaxY = 30.f;
    this->puedeSaltar = false;
}

Jugador::Jugador()
{
    this->inicializarVariables();
    this->inicializartextura();
    this->inicializarsprite();
    this->inicializarAnimaciones();
    this->inicializarFisica();
}

Jugador::~Jugador(){}


bool Jugador::getCambioAnimaciones() //Cambios para evitar problemas un dangling pointer
{
    bool anim_switch = this->cambioAnimaciones;

    this->cambioAnimaciones = !this->cambioAnimaciones;

    return anim_switch;
}

const sf::Vector2f Jugador::getPosition() const
{
    return this->sprite.getPosition();
}

const sf::FloatRect Jugador::getGlobalValores() const
{
    return this->sprite.getGlobalBounds();
}

void Jugador::setPosition(const float x, const float y)
{
    this->sprite.setPosition(x, y);
}

void Jugador::restveloY()
{
    this->velo.y = 0.f;
}

void Jugador::restveloX()
{
    this->velo.x = 0.f;
}

void Jugador::resetTimerAnimacion()
{
    this->timerAnimacion.restart();
    this->cambioAnimaciones = true;
}

void Jugador::move(const float dir_x, const float dir_y)
{
    //Aceleracion
    this->velo.x += dir_x * this->ace;

    //velocidad limite
    if (std::abs(this->velo.x) > this->velomax)
    {
        this->velo.x = this-> velomax * ((this->velo.x < 0.f) ? -1.f : 1.f);
    }
}

void Jugador::updateFisica()
{
    //Gravedad
    this->velo.y += 1.0 * this->gravedad;

    //Desaceleracion
    this->velo *= this->desa;

    //limite de desaceleracion
    if (std::abs(this->velo.x) < this->velomin)
    {
        this->velo.x = 0.f;
    }
    if (std::abs(this->velo.y) < this->velomin)
    {
        this->velo.y = 0.f;
    }
    if (std::abs(this->velo.x) <= 1.f)
    {
        this->velo.x = 0.f;
    }

    this->sprite.move(this->velo);


    //cOLISION CON LOS LATERALES DEL MAPA
    if (this->sprite.getPosition().x < 0)
    {
        this->velo.x = 0;
        this->sprite.setPosition(0, this->sprite.getPosition().y);
    }
    else if (this->sprite.getPosition().x + this->sprite.getGlobalBounds().width > 1280)
    {
        this->velo.x = 0;
        this->sprite.setPosition(1280 - this->sprite.getGlobalBounds().width, this->sprite.getPosition().y);
    }

}

void Jugador::updateMovJugador()
{
    //this->fotogramas = ESTADOS_DE_NIMACION_JUGADOR::INAC;
    //std::cout << this->fotogramas << ":";
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))//Izquierda
    {
        this->move(-1.f, 0.f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))//Derecha
    {
        this->move(1.f, 0.f);
    }

   if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && puedeSaltar)
    {
        this->velo.y = -65.f;
        this->puedeSaltar = false;
    }

   if(this->velo.x > 0.f)
   {
       this->fotogramas = ESTADOS_DE_NIMACION_JUGADOR::DERE;
   }
   if (this->velo.x < 0.f)
   {
       this->fotogramas = ESTADOS_DE_NIMACION_JUGADOR::IZQ;
   }
    if (this->velo.x == 0.f)
    {
        this->fotogramas = ESTADOS_DE_NIMACION_JUGADOR::INAC;
    }
   //else
   //    this->fotogramas = ESTADOS_DE_NIMACION_JUGADOR::INAC;
}

void Jugador::updateAnimaciones()
{
    float porcentajeVelo = (std::abs(this->velo.x) / this->velomax);
    //std::cout << porcentajeVelo << std::endl;

    if (this->fotogramas == ESTADOS_DE_NIMACION_JUGADOR::INAC)
    {

        if (this->timerAnimacion.getElapsedTime().asSeconds() >= 0.02f / porcentajeVelo || this->getCambioAnimaciones()) //Velocidad de cambio de frames
        {
            //paso();
            this->frameActual.top = 0.f;
            this->frameActual.left += 40.f;
            if (this->frameActual.left > 160.f)
                this->frameActual.left = 0;

            this->timerAnimacion.restart();
            this->sprite.setTextureRect(this->frameActual);
        }
    }

    if (this->fotogramas == ESTADOS_DE_NIMACION_JUGADOR::DERE)
    {
        if (this->timerAnimacion.getElapsedTime().asSeconds() >= 0.4f / porcentajeVelo || this->getCambioAnimaciones()) //Velocidad de cambio de frames
        {
            this->frameActual.top = 50.f;
            this->frameActual.left += 40.f;
            if (this->frameActual.left > 360.f)
            {
                this->frameActual.left = 0;
            }
            this->timerAnimacion.restart();
            this->sprite.setTextureRect(this->frameActual);
        }
        this->sprite.setScale(1.5f, 1.5f);
        this->sprite.setOrigin(0.f, 0.f);
    }

    if (this->fotogramas == ESTADOS_DE_NIMACION_JUGADOR::IZQ)
    {
        if (this->timerAnimacion.getElapsedTime().asSeconds() >= 0.4f / porcentajeVelo || this->getCambioAnimaciones()) //Velocidad de cambio de frames
        {
            this->frameActual.top = 50.f;
            this->frameActual.left += 40.f;
            if (this->frameActual.left > 360.f)
            {
                this->frameActual.left = 0;
            }
            this->timerAnimacion.restart();
            this->sprite.setTextureRect(this->frameActual);
        }
        this->sprite.setScale(-1.5f, 1.5f);
        this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 3.f, 0.f);
    }

    if (this->fotogramas == ESTADOS_DE_NIMACION_JUGADOR::SALTO)
    {
        if (this->timerAnimacion.getElapsedTime().asSeconds() >= 0.2f / porcentajeVelo || this->getCambioAnimaciones()) //Velocidad de cambio de frames
        {
            this->frameActual.top = 150.f;
            this->frameActual.left += 40.f;
            if (this->frameActual.left > 80.f)
            {
                this->frameActual.left = 0;
            }
            this->timerAnimacion.restart();
            this->sprite.setTextureRect(this->frameActual);
        }
        this->sprite.setScale(-1.5f, 1.5f);
        this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 3.f, 0.f);
    }

    else
    {
        this->timerAnimacion.restart();
    }
}

void Jugador::update()
{
    this->updateMovJugador();
    this->updateAnimaciones();
    this->updateFisica();
}

void Jugador::render(sf::RenderTarget & target)
{
    target.draw(this->sprite);


}
