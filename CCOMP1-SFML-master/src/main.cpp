#include "libs.h"
#include "Juego.h"
using namespace std;
int main()
{
    Juego juego;

    while(juego.getVentana().isOpen())
    {
        juego.update();
        juego.render();
    }
    return 0;
}
