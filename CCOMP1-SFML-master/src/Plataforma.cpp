# include "Includes/libs.h"
# include "Plataforma.h"

Plataforma::Plataforma(sf::Texture* texture_sheet, sf::IntRect texture_rect, bool dano):dano(dano)
{
    this->sprite.setTexture(*texture_sheet);
    this->sprite.setTextureRect(texture_rect);
}

const sf::FloatRect Plataforma::getGlobalValores() const
{
    return this->sprite.getGlobalBounds();

}

void Plataforma::update()
{

}

void Plataforma::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);
}
