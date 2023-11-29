#pragma once

enum ESTADOS_DE_NIMACION_JUGADOR{INAC=0,IZQ, DERE,SALTO,CAIDA};

class Jugador {
private:
    // Textura y sprite
    sf::Texture textureSheet;
    sf::Sprite sprite;

    // Animación
    sf::Clock timerAnimacion;
    short fotogramas;
    sf::IntRect frameActual;
    bool cambioAnimaciones;

    // Física
    sf::Vector2f velo;
    float velomax;
    float velomin;
    float ace;
    float desa;
    float gravedad;
    float velomaxY;
    bool puedeSaltar;

    // Funciones privadas de inicialización
    void inicializarVariables();
    void inicializartextura();
    void inicializarsprite();
    void inicializarAnimaciones();
    void inicializarFisica();

public:
    // Constructores y destructores
    Jugador();
    virtual ~Jugador();

    // Accesos
    bool getCambioAnimaciones();
    const sf::Vector2f getPosition() const;
    const sf::FloatRect getGlobalValores() const;

    // Modificadores
    void setPosition(float x, float y);
    void restveloY();
    void restveloX();
    void setPuedeSaltar(bool nuevoEstado)
    {
        this->puedeSaltar = nuevoEstado;
    }

    // Funciones de actualización
    void resetTimerAnimacion();
    void move(const float dir_x, const float dir_y);
    void updateFisica();
    void updateMovJugador();
    void updateAnimaciones();
    void update();

<<<<<<< HEAD
=======
    // Renderizado
>>>>>>> f9de81e045e5e1c243ca8d1a46d1e6f10ad4c40e
    void render(sf::RenderTarget& target);
};
