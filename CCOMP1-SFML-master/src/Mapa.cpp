#include "Includes/libs.h"
#include "Mapa.h"

Mapa::Mapa()
{
    this->plataformaSheet = NULL; //Oportunidad de aplicar sobrecarga
    this->plataformaSize = 0;
}

Mapa::Mapa(unsigned int ancho, unsigned int alto, sf::Texture* plataformaSheet, unsigned plataformaSize)
{
    this->plataformaSheet = plataformaSheet;
    this->plataformaSize = plataformaSize;

    this->mapa_plataformas.resize(ancho);
    for (int i = 0; i < this->mapa_plataformas.size(); i++)
    {
        this->mapa_plataformas[i].resize(alto, nullptr);
    }
}

Mapa::~Mapa()
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

void Mapa::agregarPlataforma(unsigned x, unsigned y)
{
    if (x < this->mapa_plataformas.size())
    {
        if (y < this->mapa_plataformas[x].size())
        {
            if (this->mapa_plataformas[x][y] == nullptr)
                this->mapa_plataformas[x][y] = new Plataforma(this->plataformaSheet, sf::IntRect(0, 0, this->plataformaSize, this->plataformaSize), false);
        }
    }
}

void Mapa::removerPlataforma(unsigned x, unsigned y)
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

void Mapa::update()
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

void Mapa::render(sf::RenderTarget& target)
{
    for (int i = 0; i < this->mapa_plataformas.size(); i++)
    {
        for (int k = 0; k < this->mapa_plataformas[i].size(); k++)
        {
            if (this->mapa_plataformas[i][k] != nullptr)
                this->mapa_plataformas[i][k]->render(target);
        }
    }
}
