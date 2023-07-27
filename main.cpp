#include<SFML/Graphics.hpp>

#include<string>

#include "ChessBoardPos.h"
#include "Castle.h"
#include "Board.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "Snake");

    sf::Texture board_texture;
    board_texture.loadFromFile("chess_board.png");
    sf::Sprite board_sprite(board_texture);

    Castle castle_black_left("black_castle.png", ChessBoardPos(0, 0));
    Castle castle_black_right("black_castle.png", ChessBoardPos(175, 0));
    Castle castle_white_left("white_castle.png", ChessBoardPos(0, 175));
    Castle castle_white_right("white_castle.png", ChessBoardPos(175, 175));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::Resized)
            {
                window.setSize(sf::Vector2u(200, 200));
            }
        }
        window.clear();
        window.draw(board_sprite);
        castle_black_left.draw(window);
        castle_black_right.draw(window);
        castle_white_left.draw(window);
        castle_white_right.draw(window);
        window.display();
    }
}