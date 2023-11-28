#include "Includes/libs.h"
#include "Juego.h"
#include "Mapa.h"

// Funciones privadas de inicialización
void Juego::iniciarVentana()
{
    this->ventana.create(sf::VideoMode(1280, 720), "Byteland-main", sf::Style::Close | sf::Style::Titlebar);
    this->ventana.setFramerateLimit(60); // Establecer el límite de frames para el movimiento
}

void Juego::iniciarJugador()
{
    this->jugador = new Jugador();
}

// Agregar las plataformas
void Juego::iniciarMapaPlataformas()
{
    // Primer mapa:
    // Base
    this->mapaPlataformas.agregarPlataforma(0, 700, 1280, 20);
    //Techo
    this->mapaPlataformas.agregarPlataforma(80, 0, 1300, 20);
   //Plataformas horizontales
    this->mapaPlataformas.agregarPlataforma(100, 560, 1280, 20);// 4
    this->mapaPlataformas.agregarPlataforma(0, 420, 1180, 20);// 3
    this->mapaPlataformas.agregarPlataforma(100, 280, 1280, 20);// 2
    this->mapaPlataformas.agregarPlataforma(0, 140, 1180, 20);// 1

    //Plataformas cuadradas
    this->mapaPlataformas.agregarPlataforma(20, 120, 20, 20);
    this->mapaPlataformas.agregarPlataforma(0, 100, 20, 20);
    this->mapaPlataformas.agregarPlataforma(0, 120, 20, 20);
    //Bordes
    this->mapaPlataformas.agregarPlataforma(1260, 20, 20, 20);
    this->mapaPlataformas.agregarPlataforma(1260, 40, 20, 20);
    this->mapaPlataformas.agregarPlataforma(1240, 20, 20, 20);
    this->mapaPlataformas.agregarPlataforma(1260, 240, 20, 20);
    this->mapaPlataformas.agregarPlataforma(1240, 260, 20, 20);
    this->mapaPlataformas.agregarPlataforma(1260, 260, 20, 20);






}

// Constructor
Juego::Juego()
{
    this->iniciarVentana();
    this->iniciarJugador();
    this->iniciarMapaPlataformas();
}

// Destructor
Juego::~Juego()
{
    delete this->jugador;
}

// Funciones de actualización
void Juego::updatePlayer()
{
    this->jugador->update();
}

void Juego::updateColision()
{
    // Colisión con la base de la ventana
    const sf::FloatRect jugadorBounds = this->jugador->getGlobalValores();

    if (jugadorBounds.top + jugadorBounds.height > this->ventana.getSize().y)
    {
        // Colisión con la base de la ventana
        this->jugador->setPuedeSaltar(true);
        this->jugador->restveloY();
        this->jugador->setPosition(
                this->jugador->getPosition().x,
                this->ventana.getSize().y - jugadorBounds.height
        );
    }

    // Colisión con los lados de la ventana
    if (jugadorBounds.left < 0.f)
    {
        // Colisión con el lado izquierdo de la ventana
        this->jugador->restveloX();
        this->jugador->setPosition(23.f, this->jugador->getPosition().y);
    }
    else if (jugadorBounds.left + jugadorBounds.width > this->ventana.getSize().x)
    {
        // Colisión con el lado derecho de la ventana
        this->jugador->restveloX();
        this->jugador->setPosition(
                this->ventana.getSize().x - jugadorBounds.width,
                this->jugador->getPosition().y
        );
    }

    // Colisión con el lado superior de la ventana
    if (jugadorBounds.top < 0.f)
    {
        // Colisión con el lado superior de la ventana
        this->jugador->restveloY();
        this->jugador->setPosition(
                this->jugador->getPosition().x,
                0.f);
    }

    // Colisión para las plataformas
    for (auto& plataforma : this->mapaPlataformas.getPlataformas()) // Ajuste: Cambiado el nombre de la variable a camelCase
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
            if (jugadorBounds.top > plataformaBounds.top)
            {
                this->jugador->setPosition(
                        this->jugador->getPosition().x,
                        plataformaBounds.top + plataformaBounds.height);
                this->jugador->restveloY();
                break;
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

    this->updatePlayer();
    this->updateColision();
}

// Funciones de renderizado
void Juego::renderPlayer()
{
    this->jugador->render(this->ventana);
}

void Juego::render()
{
    this->ventana.clear(sf::Color::Black);

    // Dibuja las plataformas del mapa
    this->mapaPlataformas.render(this->ventana); // Ajuste: Cambiado el nombre de la variable a camelCase

    // Dibuja al jugador
    this->renderPlayer();
    this->ventana.display();
}

// Acceso a la ventana
const sf::RenderWindow& Juego::getVentana() const
{
    return this->ventana;
}
