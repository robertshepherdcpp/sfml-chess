#include "Castle.h"

#include "ChessBoardPos.h"

Castle::Castle(std::string filename, ChessBoardPos pos, auto, auto)
{
    if (!piece_texture.loadFromFile(filename))
    {
        // Handle the error
    }
    piece_sprite.setTexture(piece_texture);

    sf::Vector2u position_pixel = pos.ToPixelPosition();
    piece_sprite.setPosition(position_pixel.x, position_pixel.y);

    position.x = pos.x;
    position.y = pos.y;
}

//auto Castle::CanMoveToPosition(const ChessBoardPos& position_) const noexcept -> bool
//{
//    if ((position.x == position.x) || (position.y == position.y)) { return true;} else {return false;}
//}
//
//auto Castle::GetAllPositionsAllowedToMoveTo() const noexcept -> std::vector<ChessBoardPos>
//{
//    std::vector<ChessBoardPos> positions{};
//
//    for (int i = this->position.x; i <= 7; i++)
//    {
//        positions.push_back(ChessBoardPos(i, position.y));
//    }
//
//    for (int i = position.x; i >= 0; i--)
//    {
//        positions.push_back(ChessBoardPos(i, position.y));
//    }
//
//    for (int i = position.x; i <= 7; i++)
//    {
//        positions.push_back(ChessBoardPos(position.x, i));
//    }
//
//    for (int i = position.x; i >= 0; i--)
//    {
//        positions.push_back(ChessBoardPos(position.x, i));
//    }
//
//    return positions;
//}

/*
    std::vector<ChessBoardPos> positions{}; for(int i = 0; i <= 7; i++) {positions.push_back(ChessBoardPos(i, position.y)); positions.push_back(ChessBoardPos(position.x, i));}
*/