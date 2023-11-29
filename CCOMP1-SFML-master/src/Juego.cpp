#include "Includes/libs.h"
#include "Juego.h"
#include "Mapa.h"
<<<<<<< HEAD

=======
>>>>>>> f9de81e045e5e1c243ca8d1a46d1e6f10ad4c40e

// Funciones privadas de inicialización
void Juego::iniciarVentana()
{
<<<<<<< HEAD
    this->ventana.create(sf::VideoMode(1280,720),"Plataformas",sf::Style::Close | sf::Style::Titlebar);
    this->ventana.setFramerateLimit(60); //Establecer el límite de frames para el movimiento
=======
    this->ventana.create(sf::VideoMode(1280, 720), "Byteland-main", sf::Style::Close | sf::Style::Titlebar);
    this->ventana.setFramerateLimit(60); // Establecer el límite de frames para el movimiento
>>>>>>> f9de81e045e5e1c243ca8d1a46d1e6f10ad4c40e
}

void Juego::iniciarJugador()
{
    this->jugador = new Jugador();
}

<<<<<<< HEAD
=======
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
>>>>>>> f9de81e045e5e1c243ca8d1a46d1e6f10ad4c40e

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
<<<<<<< HEAD
<<<<<<< HEAD

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
=======
    if(this->jugador->getPosition().x >= 150 && this->jugador->getPosition().x < 350) {
        this->jugador->setPuedeSaltar(false);
    } //si el jugador esta debajo de la plataforma entonces no puede salta
    else if(this->jugador->getPosition().x >= 168 && this->jugador->getPosition().x < 368)
    {
        this->jugador->setPuedeSaltar(true);
        this->jugador->restveloY();
>>>>>>> 8e8e26cc331140c29784c919740dcd58c453ee90
    }
}

=======

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
>>>>>>> f9de81e045e5e1c243ca8d1a46d1e6f10ad4c40e

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
<<<<<<< HEAD
=======

    this->updatePlayer();
    this->updateColision();
>>>>>>> f9de81e045e5e1c243ca8d1a46d1e6f10ad4c40e
}

// Funciones de renderizado
void Juego::renderPlayer()
{
    this->jugador->render(this->ventana);
}

<<<<<<< HEAD


=======
>>>>>>> f9de81e045e5e1c243ca8d1a46d1e6f10ad4c40e
void Juego::render()
{
    this->ventana.clear(sf::Color::Black);

    // Dibuja las plataformas del mapa
<<<<<<< HEAD
    this->mapa_plataformas.render(this->ventana);
=======
    this->mapaPlataformas.render(this->ventana); // Ajuste: Cambiado el nombre de la variable a camelCase
>>>>>>> f9de81e045e5e1c243ca8d1a46d1e6f10ad4c40e

    // Dibuja al jugador
    this->renderPlayer();

    this->ventana.display();
}

// Acceso a la ventana
const sf::RenderWindow& Juego::getVentana() const
{
    return this->ventana;
}
<<<<<<< HEAD

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








=======
>>>>>>> f9de81e045e5e1c243ca8d1a46d1e6f10ad4c40e
