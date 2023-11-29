#include "Includes/libs.h"
#include "Juego.h"
using namespace std;
int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    Juego juego;

    while(juego.getVentana().isOpen())
    {
        juego.update();
        juego.render();
    }
    return 0;
}
