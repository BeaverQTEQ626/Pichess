#include "Board.h"

Board::Board() {
    float size = 100;

    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            squares[y][x].setSize({size, size});
            squares[y][x].setPosition(x * size, y * size);

            bool white = (x + y) % 2 == 0;
            squares[y][x].setFillColor(
                white ? sf::Color(240, 217, 181) : sf::Color(181, 136, 99)
            );
        }
    }

    piecesTexture.loadFromFile("assets/pieces.png");

    // demo: đặt quân tốt
    for (int i = 0; i < 8; i++) {
        pieces[1][i].setTexture(piecesTexture);
        pieces[1][i].setTextureRect(sf::IntRect(0, 0, 100, 100));
        pieces[1][i].setPosition(i * 100, 100);
    }
}

void Board::draw(sf::RenderWindow& window) {
    for (auto& row : squares)
        for (auto& s : row)
            window.draw(s);

    for (auto& row : pieces)
        for (auto& p : row)
            window.draw(p);
}

void Board::handleEvent(sf::Event& event, sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        auto pos = sf::Mouse::getPosition(window);
        int x = pos.x / 100;
        int y = pos.y / 100;

        if (x >= 0 && x < 8 && y >= 0 && y < 8) {
            if (selected.x == -1) {
                selected = {x, y};
            } else {
                pieces[y][x] = pieces[selected.y][selected.x];
                pieces[selected.y][selected.x] = sf::Sprite();
                pieces[y][x].setPosition(x * 100, y * 100);
                selected = {-1, -1};
            }
        }
    }
}
