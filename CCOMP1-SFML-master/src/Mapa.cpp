
#include "Mapa.h"

<<<<<<< HEAD

void Mapa::agregarPlataforma(float x, float y, float width, float height, const bool puedemoverse) {
    plataformas.push_back(Plataforma_static(x, y, width, height, puedemoverse));
}

void Mapa::render(sf::RenderTarget &target) {
    for (const auto& plataforma : plataformas) {
        plataforma.draw(target);
    }
}

const std::vector<Plataforma_static> &Mapa::getPlataformas() const {
    return plataformas;
=======
const std::vector<Plataforma> &Mapa::getPlataformas() const
{
    return plataformas;
}


void Mapa::agregarPlataforma(float x, float y, float width, float height)
{
    plataformas.push_back(Plataforma(x, y, width, height));
}

void Mapa::render(sf::RenderTarget &target)
{
    for (const auto& plataforma : plataformas)
    {
        plataforma.draw(target);
    }
>>>>>>> f9de81e045e5e1c243ca8d1a46d1e6f10ad4c40e
}
