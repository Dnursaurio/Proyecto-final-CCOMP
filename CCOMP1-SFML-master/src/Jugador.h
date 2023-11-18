#ifndef CMAKESFMLPROJECT_JUGADOR_H
#define CMAKESFMLPROJECT_JUGADOR_H


class Jugador{
private:
    sf::Sprite sprite;
    sf::Texture textureSheet;
    bool movimiento;
    sf::Clock timerAnimacion;

    //Animación
    sf::IntRect frameActual;

    //Movimiento

    //Centro

    void inicializarVariables();
    void inicializartextura();
    void inicializarsprite();
    void inicializarAnimaciones();

public:
    //Constructor
    Jugador();
    //Destructor
    virtual ~Jugador();
    //Funciones
    void updateMovJugador();
    void updateAnimaciones();
    void update();
    void render(sf::RenderTarget& target);
};


#endif //CMAKESFMLPROJECT_JUGADOR_H
