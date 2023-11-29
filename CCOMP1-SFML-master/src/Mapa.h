#pragma once
#include <vector>
#include "Plataforma.h"
#include "Plataforma_statica.h"

class Mapa {
private:
<<<<<<< HEAD
    std::vector<Plataforma_static> plataformas;

public:
    const std::vector<Plataforma_static>& getPlataformas() const;
    virtual void agregarPlataforma(float x, float y, float width, float height, const bool puedemoverse);
=======
    std::vector<Plataforma> plataformas;

public:
    const std::vector<Plataforma>& getPlataformas() const;
    virtual void agregarPlataforma(float x, float y, float width, float height);
>>>>>>> f9de81e045e5e1c243ca8d1a46d1e6f10ad4c40e
    void render(sf::RenderTarget& target);
};

