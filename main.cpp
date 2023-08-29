#include<SFML/Graphics.hpp>

#include<string>
#include<iostream>

#include "ChessBoardPos.h"
#include "Castle.h"
#include "Knight.h"
#include "Board.h"
#include "Pawn.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"

void print_pawns(sf::RenderWindow& window, std::vector<int>& vec)
{
    sf::Texture t_black_pawn; t_black_pawn.loadFromFile("black_pawn.png");
    sf::Texture t_white_pawn; t_white_pawn.loadFromFile("white_pawn.png");

    sf::Sprite s_black_pawn(t_black_pawn);
    sf::Sprite s_white_pawn(t_white_pawn);

    for (int i = 0; i < vec.size(); i++)
    {
        int current_x = 0;
        int current_y = i % 8;
        if ((i - current_y) > 0)
        {
            current_x = (i - current_y) / 8;
        }
        int copy_of_x = current_x;
        current_x = current_y * 25;
        current_y = copy_of_x * 25;
        if (vec[i] == 1)
        {
            s_black_pawn.setPosition(current_x, current_y);
            window.draw(s_black_pawn);
        }
        if (vec[i] == 2)
        {
            s_white_pawn.setPosition(current_x, current_y);
            window.draw(s_white_pawn);
        }
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "Snake");

    sf::Texture board_texture;
    board_texture.loadFromFile("chess_board.png");
    sf::Sprite board_sprite(board_texture);

    Board board;

    bool should_move = false;

    bool white_black_move = true;

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
        2, 2, 2, 2, 2, 2, 2, 2,
        0, 0, 0, 0, 0, 0, 0, 0
    };

    Castle castle_black_left("black_castle.png", ChessBoardPos(0, 0), 1);
    Castle castle_black_right("black_castle.png", ChessBoardPos(7, 0), 8);
    Castle castle_white_left("white_castle.png", ChessBoardPos(0, 7), 25);
    Castle castle_white_right("white_castle.png", ChessBoardPos(7, 7), 32);

    Knight knight_black_left("black_knight.png", ChessBoardPos(1, 0), 2);
    Knight knight_black_right("black_knight.png", ChessBoardPos(6, 0), 7);
    Knight knight_white_left("white_knight.png", ChessBoardPos(1, 7), 26);
    Knight knight_white_right("white_knight.png", ChessBoardPos(6, 7), 31);

    Bishop bishop_black_left("black_bishop.png", ChessBoardPos(2, 0), 3);
    Bishop bishop_black_right("black_bishop.png", ChessBoardPos(5, 0), 6);
    Bishop bishop_white_left("white_bishop.png", ChessBoardPos(2, 7), 27);
    Bishop bishop_white_right("white_bishop.png", ChessBoardPos(5, 7), 30); 

    King king_black("black_king.png", ChessBoardPos(3, 0), 4);
    King king_white("white_king.png", ChessBoardPos(4, 7), 29);

    Queen queen_black("black_queen.png", ChessBoardPos(4, 0), 5);
    Queen queen_white("white_queen.png", ChessBoardPos(3, 7), 28);

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
                        if (std::find(chess_pieces_positions.begin(), chess_pieces_positions.end(), castle_black_left.AssociatedNum) != chess_pieces_positions.end())
                        {
							if (castle_black_left.MoveTo(wherePressedOnBoard))
							{
								int current_x = wherePressedOnBoard.x;
								int current_y = wherePressedOnBoard.y * 8;
								int position = current_x + current_y;
								chess_pieces_positions[position] = castle_black_left.AssociatedNum;

								int current_x_ = CurrentPositionSelected.x;
								int current_y_ = CurrentPositionSelected.y * 8;
								int position_ = current_x_ + current_y_;
								chess_pieces_positions[position_] = 0;
							}
                        }
                    }
                    if (castle_black_right.position == CurrentPositionSelected)
                    {
                        if (std::find(chess_pieces_positions.begin(), chess_pieces_positions.end(), castle_black_right.AssociatedNum) != chess_pieces_positions.end())
                        {
                            if (castle_black_right.MoveTo(wherePressedOnBoard))
                            {
                                int current_x = wherePressedOnBoard.x;
                                int current_y = wherePressedOnBoard.y * 8;
                                int position = current_x + current_y;
                                chess_pieces_positions[position] = castle_black_right.AssociatedNum;

                                int current_x_ = CurrentPositionSelected.x;
                                int current_y_ = CurrentPositionSelected.y * 8;
                                int position_ = current_x_ + current_y_;
                                chess_pieces_positions[position_] = 0;
                            }
                        }
                    }
                    if (castle_white_left.position == CurrentPositionSelected)
                    {
                        if (std::find(chess_pieces_positions.begin(), chess_pieces_positions.end(), castle_white_left.AssociatedNum) != chess_pieces_positions.end())
                        {
                            if (castle_white_left.MoveTo(wherePressedOnBoard))
                            {
                                int current_x = wherePressedOnBoard.x;
                                int current_y = wherePressedOnBoard.y * 8;
                                int position = current_x + current_y;
                                chess_pieces_positions[position] = castle_white_left.AssociatedNum;

                                int current_x_ = CurrentPositionSelected.x;
                                int current_y_ = CurrentPositionSelected.y * 8;
                                int position_ = current_x_ + current_y_;
                                chess_pieces_positions[position_] = 0;
                            }
                        }
                    }
                    if (castle_white_right.position == CurrentPositionSelected)
                    {
                        if (std::find(chess_pieces_positions.begin(), chess_pieces_positions.end(), castle_white_right.AssociatedNum) != chess_pieces_positions.end())
                        {
                            if (castle_white_right.MoveTo(wherePressedOnBoard))
                            {
                                int current_x = wherePressedOnBoard.x;
                                int current_y = wherePressedOnBoard.y * 8;
                                int position = current_x + current_y;
                                chess_pieces_positions[position] = castle_white_right.AssociatedNum;

                                int current_x_ = CurrentPositionSelected.x;
                                int current_y_ = CurrentPositionSelected.y * 8;
                                int position_ = current_x_ + current_y_;
                                chess_pieces_positions[position_] = 0;
                            }
                        }
                    }
                    if (knight_black_left.position == CurrentPositionSelected)
                    {
                        if (std::find(chess_pieces_positions.begin(), chess_pieces_positions.end(), knight_black_left.AssociatedNum) != chess_pieces_positions.end())
                        {
                            if (knight_black_left.MoveTo(wherePressedOnBoard))
                            {
                                int current_x = wherePressedOnBoard.x;
                                int current_y = wherePressedOnBoard.y * 8;
                                int position = current_x + current_y;
                                chess_pieces_positions[position] = knight_black_left.AssociatedNum;

                                int current_x_ = CurrentPositionSelected.x;
                                int current_y_ = CurrentPositionSelected.y * 8;
                                int position_ = current_x_ + current_y_;
                                chess_pieces_positions[position_] = 0;
                            }
                        }
                    }
                    if (knight_black_right.position == CurrentPositionSelected)
                    {
                        if (std::find(chess_pieces_positions.begin(), chess_pieces_positions.end(), knight_black_right.AssociatedNum) != chess_pieces_positions.end())
                        {
                            if (knight_black_right.MoveTo(wherePressedOnBoard))
                            {
                                int current_x = wherePressedOnBoard.x;
                                int current_y = wherePressedOnBoard.y * 8;
                                int position = current_x + current_y;
                                chess_pieces_positions[position] = knight_black_right.AssociatedNum;

                                int current_x_ = CurrentPositionSelected.x;
                                int current_y_ = CurrentPositionSelected.y * 8;
                                int position_ = current_x_ + current_y_;
                                chess_pieces_positions[position_] = 0;
                            }
                        }
                    }
                    if (knight_white_left.position == CurrentPositionSelected)
                    {
                    if (std::find(chess_pieces_positions.begin(), chess_pieces_positions.end(), knight_white_left.AssociatedNum) != chess_pieces_positions.end())
                    {
                        if (knight_white_left.MoveTo(wherePressedOnBoard))
                        {
                            int current_x = wherePressedOnBoard.x;
                            int current_y = wherePressedOnBoard.y * 8;
                            int position = current_x + current_y;
                            chess_pieces_positions[position] = knight_white_left.AssociatedNum;

                            int current_x_ = CurrentPositionSelected.x;
                            int current_y_ = CurrentPositionSelected.y * 8;
                            int position_ = current_x_ + current_y_;
                            chess_pieces_positions[position_] = 0;
                        }
                    }
                    }
                    if (knight_white_right.position == CurrentPositionSelected)
                    {
                    if (std::find(chess_pieces_positions.begin(), chess_pieces_positions.end(), knight_white_right.AssociatedNum) != chess_pieces_positions.end())
                    {
                        if (knight_white_right.MoveTo(wherePressedOnBoard))
                        {
                            int current_x = wherePressedOnBoard.x;
                            int current_y = wherePressedOnBoard.y * 8;
                            int position = current_x + current_y;
                            chess_pieces_positions[position] = knight_white_right.AssociatedNum;

                            int current_x_ = CurrentPositionSelected.x;
                            int current_y_ = CurrentPositionSelected.y * 8;
                            int position_ = current_x_ + current_y_;
                            chess_pieces_positions[position_] = 0;
                        }
                    }
                    }
                    if (bishop_black_left.position == CurrentPositionSelected)
                    {
                    if (std::find(chess_pieces_positions.begin(), chess_pieces_positions.end(), bishop_black_left.AssociatedNum) != chess_pieces_positions.end())
                    {
                        if (bishop_black_left.MoveTo(wherePressedOnBoard))
                        {
                            int current_x = wherePressedOnBoard.x;
                            int current_y = wherePressedOnBoard.y * 8;
                            int position = current_x + current_y;
                            chess_pieces_positions[position] = bishop_black_left.AssociatedNum;

                            int current_x_ = CurrentPositionSelected.x;
                            int current_y_ = CurrentPositionSelected.y * 8;
                            int position_ = current_x_ + current_y_;
                            chess_pieces_positions[position_] = 0;
                        }
                    }
                    }
                    if (bishop_black_right.position == CurrentPositionSelected)
                    {
                    if (std::find(chess_pieces_positions.begin(), chess_pieces_positions.end(), bishop_black_right.AssociatedNum) != chess_pieces_positions.end())
                    {
                        if (bishop_black_right.MoveTo(wherePressedOnBoard))
                        {
                            int current_x = wherePressedOnBoard.x;
                            int current_y = wherePressedOnBoard.y * 8;
                            int position = current_x + current_y;
                            chess_pieces_positions[position] = bishop_black_right.AssociatedNum;

                            int current_x_ = CurrentPositionSelected.x;
                            int current_y_ = CurrentPositionSelected.y * 8;
                            int position_ = current_x_ + current_y_;
                            chess_pieces_positions[position_] = 0;
                        }
                    }
                    }
                    if (bishop_white_left.position == CurrentPositionSelected)
                    {
                    if (std::find(chess_pieces_positions.begin(), chess_pieces_positions.end(), bishop_white_left.AssociatedNum) != chess_pieces_positions.end())
                    {
                        if (bishop_white_left.MoveTo(wherePressedOnBoard))
                        {
                            int current_x = wherePressedOnBoard.x;
                            int current_y = wherePressedOnBoard.y * 8;
                            int position = current_x + current_y;
                            chess_pieces_positions[position] = bishop_white_left.AssociatedNum;

                            int current_x_ = CurrentPositionSelected.x;
                            int current_y_ = CurrentPositionSelected.y * 8;
                            int position_ = current_x_ + current_y_;
                            chess_pieces_positions[position_] = 0;
                        }
                    }
                    }
                    if (bishop_white_right.position == CurrentPositionSelected)
                    {
                    if (std::find(chess_pieces_positions.begin(), chess_pieces_positions.end(), bishop_white_right.AssociatedNum) != chess_pieces_positions.end())
                    {
                        if (bishop_white_right.MoveTo(wherePressedOnBoard))
                        {
                            int current_x = wherePressedOnBoard.x;
                            int current_y = wherePressedOnBoard.y * 8;
                            int position = current_x + current_y;
                            chess_pieces_positions[position] = bishop_white_right.AssociatedNum;

                            int current_x_ = CurrentPositionSelected.x;
                            int current_y_ = CurrentPositionSelected.y * 8;
                            int position_ = current_x_ + current_y_;
                            chess_pieces_positions[position_] = 0;
                        }
                    }
                    }
                    if (king_black.position == CurrentPositionSelected)
                    {
                    if (std::find(chess_pieces_positions.begin(), chess_pieces_positions.end(), king_black.AssociatedNum) != chess_pieces_positions.end())
                    {
                        if (king_black.MoveTo(wherePressedOnBoard))
                        {
                            int current_x = wherePressedOnBoard.x;
                            int current_y = wherePressedOnBoard.y * 8;
                            int position = current_x + current_y;
                            chess_pieces_positions[position] = king_black.AssociatedNum;

                            int current_x_ = CurrentPositionSelected.x;
                            int current_y_ = CurrentPositionSelected.y * 8;
                            int position_ = current_x_ + current_y_;
                            chess_pieces_positions[position_] = 0;
                        }
                    }
                    }
                    if (king_white.position == CurrentPositionSelected)
                    {
                    if (std::find(chess_pieces_positions.begin(), chess_pieces_positions.end(), king_white.AssociatedNum) != chess_pieces_positions.end())
                    {
                        if (king_white.MoveTo(wherePressedOnBoard))
                        {
                            int current_x = wherePressedOnBoard.x;
                            int current_y = wherePressedOnBoard.y * 8;
                            int position = current_x + current_y;
                            chess_pieces_positions[position] = king_white.AssociatedNum;

                            int current_x_ = CurrentPositionSelected.x;
                            int current_y_ = CurrentPositionSelected.y * 8;
                            int position_ = current_x_ + current_y_;
                            chess_pieces_positions[position_] = 0;
                        }
                    }
                    }
                    if (queen_black.position == CurrentPositionSelected)
                    {
                    if (std::find(chess_pieces_positions.begin(), chess_pieces_positions.end(), queen_black.AssociatedNum) != chess_pieces_positions.end())
                    {
                        if (queen_black.MoveTo(wherePressedOnBoard, chess_pieces_positions))
                        {
                            int current_x = wherePressedOnBoard.x;
                            int current_y = wherePressedOnBoard.y * 8;
                            int position = current_x + current_y;
                            chess_pieces_positions[position] = queen_black.AssociatedNum;

                            int current_x_ = CurrentPositionSelected.x;
                            int current_y_ = CurrentPositionSelected.y * 8;
                            int position_ = current_x_ + current_y_;
                            chess_pieces_positions[position_] = 0;
                        }
                    }
                    }
                    if (queen_white.position == CurrentPositionSelected)
                    {
                    if (std::find(chess_pieces_positions.begin(), chess_pieces_positions.end(), queen_white.AssociatedNum) != chess_pieces_positions.end())
                    {
                        if (queen_white.MoveTo(wherePressedOnBoard, chess_pieces_positions))
                        {
                            int current_x = wherePressedOnBoard.x;
                            int current_y = wherePressedOnBoard.y * 8;
                            int position = current_x + current_y;
                            chess_pieces_positions[position] = queen_white.AssociatedNum;

                            int current_x_ = CurrentPositionSelected.x;
                            int current_y_ = CurrentPositionSelected.y * 8;
                            int position_ = current_x_ + current_y_;
                            chess_pieces_positions[position_] = 0;
                        }
                    }
                    }
                    else
                    {
                        int x = CurrentPositionSelected.y;
                        int y = CurrentPositionSelected.x;

                        int position_of_pawn = (x * 8) + y;
                        if (pawn_pieces[position_of_pawn] == 1)
                        {
                            int x_ = wherePressedOnBoard.y;
                            int y_ = wherePressedOnBoard.x;
                            int position_of_pawn_to_go = (x_ * 8) + y_;
                            pawn_pieces[position_of_pawn] = 0;
                            pawn_pieces[position_of_pawn_to_go] = 1;
                        }
                        if (pawn_pieces[position_of_pawn] == 2)
                        {
                            int x_ = wherePressedOnBoard.y;
                            int y_ = wherePressedOnBoard.x;
                            int position_of_pawn_to_go = (x_ * 8) + y_;
                            pawn_pieces[position_of_pawn] = 0;
                            pawn_pieces[position_of_pawn_to_go] = 2;
                        }
                    }
                    should_move = false;
                }
            }
        }
        window.clear();
        window.draw(board_sprite);
        //castle_black_left.draw(window);
        //castle_black_right.draw(window);
        //castle_white_left.draw(window);
        //castle_white_right.draw(window);
        //knight_black_left.draw(window);
        //knight_black_right.draw(window);
        //knight_white_left.draw(window);
        //knight_white_right.draw(window);
        //bishop_black_left.draw(window);
        //bishop_black_right.draw(window);
        //bishop_white_left.draw(window);
        //bishop_white_right.draw(window);
        //king_black.draw(window);
        //king_white.draw(window);
        //queen_black.draw(window);
        //queen_white.draw(window);
        for (const auto i : chess_pieces_positions)
        {
            if (i == 1)
            {
                castle_black_left.draw(window);
            }
            else if (i == 2)
            {
                knight_black_left.draw(window);
            }
            else if (i == 3)
            {
                bishop_black_left.draw(window);
            }
            else if (i == 4)
            {
                king_black.draw(window);
            }
            else if (i == 5)
            {
                queen_black.draw(window);
            }
            else if (i == 6)
            {
                castle_black_right.draw(window);
            }
            else if (i == 7)
            {
                knight_black_right.draw(window);
            }
            else if (i == 8)
            {
                bishop_black_right.draw(window);
            }
            else if (i == 25)
            {
                castle_white_left.draw(window);
            }
            else if (i == 26)
            {
                knight_white_left.draw(window);
            }
            else if (i == 27)
            {
                bishop_white_left.draw(window);
            }
            else if (i == 28)
            {
                queen_white.draw(window);
            }
            else if (i == 29)
            {
                king_white.draw(window);
            }
            else if (i == 30)
            {
                bishop_white_right.draw(window);
            }
            else if (i == 31)
            {
                knight_white_right.draw(window);
            }
            
            else if (i == 32)
            {
                castle_white_right.draw(window);
            }
        }
        print_pawns(window, pawn_pieces);
        window.display();
    }
}