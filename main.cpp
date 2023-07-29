#include<SFML/Graphics.hpp>

#include<string>
#include<iostream>

#include "ChessBoardPos.h"
#include "Castle.h"
#include "Knight.h"
#include "Board.h"
#include "Pawn.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "Snake");

    sf::Texture board_texture;
    board_texture.loadFromFile("chess_board.png");
    sf::Sprite board_sprite(board_texture);

    Board board;

    bool should_move = false;

    ChessBoardPos CurrentPositionSelected = ChessBoardPos(0, 0);

    std::vector<int> chess_pieces_positions
    {
        1,  2,  3,  4,  5,  6,  7,  8,
        9,  10, 11, 12, 13, 14, 15, 16,
        0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,
        17, 18, 19, 20, 21, 22, 23, 24,
        25, 26, 27, 28, 29, 30, 31, 32
    };

    std::vector<int> pawn_pieces
    {
        0, 0, 0, 0, 0, 0, 0, 0, 
        1, 1, 1, 1, 1, 1, 1, 1,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 1, 1, 1, 1,
        0, 0, 0, 0, 0, 0, 0, 0
    };

    Castle castle_black_left("black_castle.png", ChessBoardPos(0, 0));
    Castle castle_black_right("black_castle.png", ChessBoardPos(7, 0));
    Castle castle_white_left("white_castle.png", ChessBoardPos(0, 7));
    Castle castle_white_right("white_castle.png", ChessBoardPos(7, 7));

    Knight knight_black_left("black_knight.png", ChessBoardPos(1, 0));
    Knight knight_black_right("black_knight.png", ChessBoardPos(6, 0));
    Knight knight_white_left("white_knight.png", ChessBoardPos(1, 7));
    Knight knight_white_right("white_knight.png", ChessBoardPos(6, 7));

    Knight bishop_black_left("black_bishop.png", ChessBoardPos(2, 0));
    Knight bishop_black_right("black_bishop.png", ChessBoardPos(6, 0));
    Knight bishop_white_left("white_bishop.png", ChessBoardPos(2, 7));
    Knight bishop_white_right("white_bishop.png", ChessBoardPos(5, 7)); 

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
            if (event.type == sf::Event::MouseButtonReleased)
            {
                ChessBoardPos wherePressedOnBoard = board.WhereHasBeenSelected(event);
                if (!should_move)
                {
                    CurrentPositionSelected = wherePressedOnBoard;
                    should_move = true;
                }
                else
                {
                    if (castle_black_left.position == CurrentPositionSelected)
                    {
                        castle_black_left.MoveTo(wherePressedOnBoard);
                    }
                    else if (castle_black_right.position == CurrentPositionSelected)
                    {
                        castle_black_right.MoveTo(wherePressedOnBoard);
                    }
                    else if (castle_white_left.position == CurrentPositionSelected)
                    {
                        castle_white_left.MoveTo(wherePressedOnBoard);
                    }
                    else if (castle_white_right.position == CurrentPositionSelected)
                    {
                        castle_white_right.MoveTo(wherePressedOnBoard);
                    }
                    else if (knight_black_left.position == CurrentPositionSelected)
                    {
                        knight_black_left.MoveTo(wherePressedOnBoard);
                    }
                    else if (knight_black_right.position == CurrentPositionSelected)
                    {
                        knight_black_right.MoveTo(wherePressedOnBoard);
                    }
                    else if (knight_white_left.position == CurrentPositionSelected)
                    {
                        knight_white_left.MoveTo(wherePressedOnBoard);
                    }
                    else if (knight_white_right.position == CurrentPositionSelected)
                    {
                        knight_white_right.MoveTo(wherePressedOnBoard);
                    }
                    else if (bishop_black_left.position == CurrentPositionSelected)
                    {
                        std::cout << "going to move the bishop\n";
                        bishop_black_left.MoveTo(wherePressedOnBoard);
                    }
                    else if (bishop_black_right.position == CurrentPositionSelected)
                    {
                        std::cout << "going to move the bishop\n";
                        bishop_black_right.MoveTo(wherePressedOnBoard);
                    }
                    else if (bishop_white_left.position == CurrentPositionSelected)
                    {
                        std::cout << "going to move the bishop\n";
                        bishop_white_left.MoveTo(wherePressedOnBoard);
                    }
                    else if (bishop_white_right.position == CurrentPositionSelected)
                    {
                        std::cout << "going to move the bishop\n";
                        bishop_white_right.MoveTo(wherePressedOnBoard);
                    }
                    should_move = false;
                }
            }
        }
        window.clear();
        window.draw(board_sprite);
        castle_black_left.draw(window);
        castle_black_right.draw(window);
        castle_white_left.draw(window);
        castle_white_right.draw(window);
        knight_black_left.draw(window);
        knight_black_right.draw(window);
        knight_white_left.draw(window);
        knight_white_right.draw(window);
        bishop_black_left.draw(window);
        bishop_black_right.draw(window);
        bishop_white_left.draw(window);
        bishop_white_right.draw(window);
        window.display();
    }
}