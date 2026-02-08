#include <SFML/Graphics.hpp>
#include "Board.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess Game");

    Board board;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            board.handleEvent(event, window);
        }

        window.clear();
        board.draw(window);
        window.display();
    }

    return 0;
}
