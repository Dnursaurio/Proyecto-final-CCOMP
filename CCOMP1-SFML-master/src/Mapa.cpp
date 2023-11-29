
#include "Mapa.h"


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
}
