# include "Includes/libs.h"
# include "Plataforma.h"

Plataforma::Plataforma(sf::Texture* texture_sheet, sf::IntRect texture_rect)
{
    this->sprite.setTexture(*texture_sheet);
    this->sprite.setTextureRect(texture_rect);
    this->plataformaSheet = NULL; //Oportunidad de aplicar sobrecarga
    this->plataformaSize = 0;
}

Plataforma::Plataforma(int ancho, int alto, sf::Texture* plataformaSheet, unsigned plataformaSize)
{
    this->plataformaSheet = plataformaSheet;
    this->plataformaSize = plataformaSize;

    this->mapa_plataformas.resize(ancho);
    for (int i = 0; i < this->mapa_plataformas.size(); i++)
    {
        this->mapa_plataformas[i].resize(alto, nullptr);
    }
}

Plataforma::~Plataforma()
{
    for (int i = 0; i < this->mapa_plataformas.size(); i++)
    {
        for (int k = 0; k < this->mapa_plataformas[i].size(); k++)
        {
            delete this->mapa_plataformas[i][k];
            this->mapa_plataformas[i][k] = nullptr;
        }
    }
}

const sf::FloatRect Plataforma::getGlobalValores() const
{
    return this->sprite.getGlobalBounds();

}

const sf::Vector2f Plataforma::getPosition() const
{
    return this->sprite.getPosition();
}

void Plataforma::setPosition(int x, int y)
{
    this->sprite.setPosition(x, y);
}

void Plataforma::agregarPlataforma(float x, float y)
{
    if (x <= this->mapa_plataformas.size() || x > this->mapa_plataformas.size())
    {
        if (y <= this->mapa_plataformas[x].size() || y > this->mapa_plataformas[x].size())
        {
            if (this->mapa_plataformas[x][y] == nullptr)
                this->mapa_plataformas[x][y] = new Plataforma(this->plataformaSheet, sf::IntRect(0, 0, this->plataformaSize, this->plataformaSize));
        }
    }
}

void Plataforma::removerPlataforma(unsigned x, unsigned y)
{
    if (x < this->mapa_plataformas.size())
    {
        if (y < this->mapa_plataformas[x].size())
        {
            if (this->mapa_plataformas[x][y] != nullptr)
            {
                delete this->mapa_plataformas[x][y];
                this->mapa_plataformas[x][y] = nullptr;
            }
        }
    }
}


void Plataforma::update()
{
    for (int i = 0; i < this->mapa_plataformas.size(); i++)
    {
        for (int k = 0; k < this->mapa_plataformas[i].size(); k++)
        {
            if (this->mapa_plataformas[i][k] != nullptr)
                this->mapa_plataformas[i][k]->update();
        }
    }
}

void Plataforma::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);
}
