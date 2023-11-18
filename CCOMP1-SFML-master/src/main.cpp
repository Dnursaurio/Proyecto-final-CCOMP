#include "Includes/libs.h"
#include "Juego.h"
using namespace std;
int main()
{
    srand(time(static_cast<unsigned>(0)));

    Juego juego;

    while(juego.getVentana().isOpen())
    {
        juego.update();
        juego.render();
    }
    return 0;
}
