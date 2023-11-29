# include "Includes/libs.h"
# include "Plataforma.h"

<<<<<<< HEAD
sf::FloatRect Plataforma::getGlobalBounds()const {
=======
sf::FloatRect Plataforma::getGlobalBounds() const {
>>>>>>> f9de81e045e5e1c243ca8d1a46d1e6f10ad4c40e
    return shape.getGlobalBounds();
}

void Plataforma::draw(sf::RenderTarget &target)const{
    target.draw(shape);
}
<<<<<<< HEAD

bool Plataforma::movimientoplataforma() const {
    if(puedemoverse == true)
    {

    }
    return false;
}





// implementacion beta   de la colicion


//void Plataforma::colicion() {

// if (this->sprite.getPosition().x < 0)
//   {
//       this->velo.x = 0;
//        this->sprite.setPosition(0, this->sprite.getPosition().y);
//    }
//    else if (this->sprite.getPosition().x + this->sprite.getGlobalBounds().width > 1280)
//   {
//        this->velo.x = 0;
//        this->sprite.setPosition(1280 - this->sprite.getGlobalBounds().width, this->sprite.getPosition().y);
//   }
//}
=======
>>>>>>> f9de81e045e5e1c243ca8d1a46d1e6f10ad4c40e
