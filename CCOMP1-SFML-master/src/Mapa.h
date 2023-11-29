#pragma once
#include <vector>
#include "Plataforma.h"
#include "Plataforma_statica.h"

class Mapa {
private:
    std::vector<Plataforma_static> plataformas;

public:
    const std::vector<Plataforma_static>& getPlataformas() const;
    virtual void agregarPlataforma(float x, float y, float width, float height, const bool puedemoverse);
    void render(sf::RenderTarget& target);
};

