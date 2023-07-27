#include<SFML/Graphics.hpp>

#include<string>

#include "ChessBoardPos.h"
#include "ChessPiece.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "Snake");

    sf::Texture board_texture;
    board_texture.loadFromFile("chess_board.png");
    sf::Sprite board_sprite(board_texture);

    ChessPiece castle_black_left(std::string{ "black_castle.png" }, ChessBoardPos(0, 0), [&](ChessBoardPos pos, ChessBoardPos m_pos) -> bool  {if ((pos.x == m_pos.x) || (pos.y == m_pos.y)) { return true; } else { return false; }},
                                                                                         [&](ChessBoardPos pos) -> std::vector<ChessBoardPos> {std::vector<ChessBoardPos> positions{}; for (int i = 0; i <= 7; i++) { positions.push_back(ChessBoardPos(i, pos.y)); positions.push_back(ChessBoardPos(pos.x, i)); }});
    ChessPiece castle_black_right("black_castle.png", ChessBoardPos(175, 0),             [&](ChessBoardPos pos, ChessBoardPos m_pos) -> bool  {if ((pos.x == m_pos.x) || (pos.y == m_pos.y)) { return true; } else { return false; }},
                                                                                         [&](ChessBoardPos pos) -> std::vector<ChessBoardPos> {std::vector<ChessBoardPos> positions{}; for (int i = 0; i <= 7; i++) { positions.push_back(ChessBoardPos(i, pos.y)); positions.push_back(ChessBoardPos(pos.x, i)); }});
    ChessPiece castle_white_left("white_castle.png", ChessBoardPos(0, 175),              [&](ChessBoardPos pos, ChessBoardPos m_pos) -> bool  {if ((pos.x == m_pos.x) || (pos.y == m_pos.y)) { return true; } else { return false; }},
                                                                                         [&](ChessBoardPos pos) -> std::vector<ChessBoardPos> {std::vector<ChessBoardPos> positions{}; for (int i = 0; i <= 7; i++) { positions.push_back(ChessBoardPos(i, pos.y)); positions.push_back(ChessBoardPos(pos.x, i)); }});
    ChessPiece castle_white_right("white_castle.png", ChessBoardPos(175, 175),           [&](ChessBoardPos pos, ChessBoardPos m_pos) -> bool  {if ((pos.x == m_pos.x) || (pos.y == m_pos.y)) { return true; } else { return false; }},
                                                                                         [&](ChessBoardPos pos) -> std::vector<ChessBoardPos> {std::vector<ChessBoardPos> positions{}; for (int i = 0; i <= 7; i++) { positions.push_back(ChessBoardPos(i, pos.y)); positions.push_back(ChessBoardPos(pos.x, i)); }});

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