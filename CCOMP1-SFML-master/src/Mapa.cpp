
#include "Mapa.h"


void Mapa::agregarPlataforma(float x, float y, float width, float height) {
    plataformas.push_back(Plataforma(x, y, width, height));
}

void Mapa::render(sf::RenderTarget &target) {
    for (const auto& plataforma : plataformas) {
        plataforma.draw(target);
    }
}

const std::vector<Plataforma> &Mapa::getPlataformas() const {
    return plataformas;
}
