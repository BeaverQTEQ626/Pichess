#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Board {
public:
    Board();
    void draw(sf::RenderWindow& window);
    void handleEvent(sf::Event& event, sf::RenderWindow& window);

private:
    sf::RectangleShape squares[8][8];
    sf::Texture piecesTexture;
    sf::Sprite pieces[8][8];

    sf::Vector2i selected{-1, -1};
};
