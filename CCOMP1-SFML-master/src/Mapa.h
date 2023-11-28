#pragma once
#include <vector>
#include "Plataforma.h"

class Mapa {
private:
    std::vector<Plataforma> plataformas;

public:
    const std::vector<Plataforma>& getPlataformas() const;
    virtual void agregarPlataforma(float x, float y, float width, float height);
    void render(sf::RenderTarget& target);
};

