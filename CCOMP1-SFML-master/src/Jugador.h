#ifndef CMAKESFMLPROJECT_JUGADOR_H
#define CMAKESFMLPROJECT_JUGADOR_H


class Jugador{
private:
    sf::Sprite sprite;
    sf::Texture texturesheet;

    //Animacion

    //Movimiento

    //Centro

    void inizializartextura();
    void inicializarsprite();

public:
    Jugador();
    virtual ~Jugador();

    //funciones
    void update();
    void render(sf::RenderTarget& target);
};


#endif //CMAKESFMLPROJECT_JUGADOR_H
