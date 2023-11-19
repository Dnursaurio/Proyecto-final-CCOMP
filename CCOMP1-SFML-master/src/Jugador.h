#ifndef CMAKESFMLPROJECT_JUGADOR_H
#define CMAKESFMLPROJECT_JUGADOR_H

enum ESTADOS_DE_NIMACION_JUGADOR{IZQ=1,INAC=0,DERE=2,ARRIBA,BAJO};
class Jugador{
private:
    sf::Sprite sprite;
    sf::Texture textureSheet;
    sf::Clock timerAnimacion;

    //Animación
    short fotogramas;
    sf::IntRect frameActual;

    //Gravedad
    sf::Vector2f velo;
    float velomx;
    float velomin;
    float ace;
    float desa;

    //Centro

    void inicializarVariables();
    void inicializartextura();
    void inicializarsprite();
    void inicializarAnimaciones();
    void inicializarGravedad();

public:
    //Constructor
    Jugador();
    //Destructor
    virtual ~Jugador();
    //Funciones
    void move(const float dir_x,const float dir_y);
    void updateGravedad();
    void updateMovJugador();
    void updateAnimaciones();
    void update();
    void render(sf::RenderTarget& target);
};


#endif //CMAKESFMLPROJECT_JUGADOR_H
