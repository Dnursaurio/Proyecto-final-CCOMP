#include "Includes/libs.h"
#include "Juego.h"

void Juego::iniciarVentana()
{
    this->ventana.create(sf::VideoMode(1280,720),"Byteland",sf::Style::Close | sf::Style::Titlebar);
    this->ventana.setFramerateLimit(60); //Establecer el límite de frames para el movimiento
}

void Juego::iniciarPlataformaSheet()
{
    if (!this->plataformaSheet.loadFromFile("Textures/plataforma_Sheet.png"))
    {
        std::cout << "ERROR::GAME::No se puede cargar el plataforma_Sheet.png!" << std::endl;
    }
}

void Juego::iniciarJugador()
{
    this->jugador = new Jugador();
}

void Juego::iniciarMapaPlataformas()
{
    this->mapa_plataformas = new Mapa(20, 20, &this->plataformaSheet, 30);
    this->mapa_plataformas->agregarPlataforma(0, 0);
}

Juego::Juego()
{
    this->iniciarVentana();
    this->iniciarPlataformaSheet();
    this->iniciarJugador();
    this->iniciarMapaPlataformas();
}

Juego::~Juego()
{
    delete this->jugador;
    delete this->mapa_plataformas;
}

void Juego::updatePlayer()
{
    this->jugador->update();
}

void Juego::updateColision()
{

    //Colisión con la base de la ventana
    if(this->jugador->getPosition().y + this->jugador->getGlobalValores().height > this->ventana.getSize().y )
    {
        this->jugador->setPuedeSaltar(true);
        this->jugador->restveloY();
        this->jugador->setPosition(
                this->jugador->getPosition().x,
                this->ventana.getSize().y - this->jugador->getGlobalValores().height);
    }
    //Colisión con el lado derecho de la ventana
    if(this->jugador->getPosition().x + this->jugador->getGlobalValores().width > this->ventana.getSize().x)
    {
        this->jugador->setPuedeSaltar(true);
        this->jugador->restveloX();
        this->jugador->setPosition(
                this->jugador->getPosition().x - this->jugador->getGlobalValores().width,
                this->ventana.getSize().y);
        //std::cout << this->jugador->getGlobalValores().width<<":";
    }

}

void Juego::updateMapaPlataformas()
{
    this->mapa_plataformas->update();
}

void Juego::update()
{
    //agrupando los eventos de la ventana
    while(this->ventana.pollEvent(this->evento))
    {
        if (this->evento.type == sf::Event::Closed)
        {
            this->ventana.close();
        }

        if (this->evento.type == sf::Event::KeyPressed && this-> evento.key.code == sf::Keyboard::Escape)
        {
            this->ventana.close();
        }

        if (this->evento.type == sf::Event::KeyReleased &&
            (
                    this-> evento.key.code == sf::Keyboard::A ||
                    this-> evento.key.code == sf::Keyboard::D ||
                    this-> evento.key.code == sf::Keyboard::W ||
                    this-> evento.key.code == sf::Keyboard::S
            )
            )
        {
            this->jugador->resetTimerAnimacion();
        }
    }

    this->updatePlayer();
    this->updateColision();
    this->updateMapaPlataformas();
}

void Juego::renderPlayer()
{
    this->jugador->render(this->ventana);
}

void Juego::renderMapaPlataformas()
{
    this->mapa_plataformas->render(this->ventana);
}

void Juego::render()
{
    this->ventana.clear(sf::Color::Blue);

    //renderizar el juego
    this->renderMapaPlataformas();
    this->renderPlayer();
    this->ventana.display();
}

const sf::RenderWindow& Juego::getVentana() const
{
    return this->ventana;
}





