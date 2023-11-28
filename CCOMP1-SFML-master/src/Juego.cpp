#include "Includes/libs.h"
#include "Juego.h"
#include "Mapa.h"


void Juego::iniciarVentana()
{
    this->ventana.create(sf::VideoMode(1280,720),"Plataformas",sf::Style::Close | sf::Style::Titlebar);
    this->ventana.setFramerateLimit(60); //Establecer el límite de frames para el movimiento
}

void Juego::iniciarJugador()
{
    this->jugador = new Jugador();
}


Juego::Juego()
{
    this->iniciarVentana();
    this->iniciarJugador();
    this->iniciarMapaPlataformas();
}

Juego::~Juego()
{
    delete this->jugador;
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

    const sf::FloatRect jugadorBounds = this->jugador->getGlobalValores();
    for (auto& plataforma : this->mapa_plataformas.getPlataformas())
    {
        const sf::FloatRect plataformaBounds = plataforma.getGlobalBounds();


        if (jugadorBounds.intersects(plataformaBounds))
        {
            // Colisión por encima
            if (jugadorBounds.top < plataformaBounds.top)
            {
                this->jugador->setPuedeSaltar(true);
                this->jugador->restveloY();
                this->jugador->setPosition(
                        this->jugador->getPosition().x,
                        plataformaBounds.top - jugadorBounds.height);
            }
                // Colisión por debajo
            else if (jugadorBounds.top > plataformaBounds.top)
            {
                this->jugador->setPosition(
                        this->jugador->getPosition().x,
                        plataformaBounds.top + plataformaBounds.height);
                this->jugador->restveloY();
                break;  // Salir del bucle después de ajustar la posición del jugador
            }
        }
    }
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
}

void Juego::renderPlayer()
{
    this->jugador->render(this->ventana);
}



void Juego::render()
{
    this->ventana.clear(sf::Color::Black);

    // Dibuja las plataformas del mapa
    this->mapa_plataformas.render(this->ventana);

    // Dibuja al jugador
    this->renderPlayer();

    this->ventana.display();
}

const sf::RenderWindow& Juego::getVentana() const
{
    return this->ventana;
}

void Juego::iniciarMapaPlataformas() {
    this->mapa_plataformas.agregarPlataforma(-1, 400, 100, 18);


    this->mapa_plataformas.agregarPlataforma(900, 200, 100, 18);
    this->mapa_plataformas.agregarPlataforma(600, 100, 100, 18);

    this->mapa_plataformas.agregarPlataforma(170, 590, 90000, 18);





    this->mapa_plataformas.agregarPlataforma(340, 408, 100, 200);
    this->mapa_plataformas.agregarPlataforma(620, 408, 100, 200);

    this->mapa_plataformas.agregarPlataforma(900, 450, 100, 150);
    this->mapa_plataformas.agregarPlataforma(1180, 408, 100, 200);

}








