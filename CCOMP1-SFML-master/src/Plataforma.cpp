# include "Includes/libs.h"
# include "Plataforma.h"

sf::FloatRect Plataforma::getGlobalBounds() const {
    return shape.getGlobalBounds();
}

void Plataforma::draw(sf::RenderTarget &target)const{
    target.draw(shape);
}
