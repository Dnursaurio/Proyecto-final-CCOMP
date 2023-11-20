#pragma once

enum ESTADOS_DE_NIMACION_JUGADOR{INAC=0,IZQ, DERE,SALTO,CAIDA};

class Jugador{
private:
    sf::Sprite sprite;
    sf::Texture textureSheet;
    sf::Clock timerAnimacion;

    //Animación
    short fotogramas;
    sf::IntRect frameActual;
    bool cambioAnimaciones;

    //Fisica
    sf::Vector2f velo;
    float velomax;
    float velomin;
    float ace;
    float desa;
    float gravedad;
    float velomaxY;
    bool puedeSaltar;

    //Centro
    void inicializarVariables();
    void inicializartextura();
    void inicializarsprite();
    void inicializarAnimaciones();
    void inicializarFisica();

public:
    //Constructor
    Jugador();
    //Destructor
    virtual ~Jugador();

    //Accesos
    bool getCambioAnimaciones(); //Cambios para evitar problemas un dangling pointer
    const sf::Vector2f getPosition() const;
    const sf::FloatRect getGlobalValores() const;

    //Modificadores
    void setPosition(const float x,const float y);
    void restveloY();
    void setPuedeSaltar(const bool puedeSaltar)
    {
        this->puedeSaltar = puedeSaltar;
    }

    //Funciones
    void resetTimerAnimacion();
    void move(const float dir_x,const float dir_y);
    void updateFisica();
    void updateMovJugador();
    void updateAnimaciones();
    void update();
    void render(sf::RenderTarget& target);
};