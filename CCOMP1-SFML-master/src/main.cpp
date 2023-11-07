#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML Example");

    // Crear un círculo
    sf::CircleShape circle(100); // Radio del círculo

    // Configurar el color del círculo
    circle.setFillColor(sf::Color::White);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Borrar la ventana
        window.clear();

        // Dibujar el círculo en la ventana
        window.draw(circle);

        // Mostrar el contenido de la ventana
        window.display();
    }

    return 0;
}
