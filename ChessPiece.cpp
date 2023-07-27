#include<SFML/Graphics.hpp>

#include<algorithm>

#include "ChessPiece.h"
#include "ChessBoardPos.h"

ChessPiece::ChessPiece(std::string filename, ChessBoardPos pos, auto canMoveToPos, auto getAllPosAllowedToMove)
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

    m_canMoveToPos = canMoveToPos;
    m_getAllPosAllowedToMove = getAllPosAllowedToMove;
}

void ChessPiece::draw(sf::RenderWindow& window)
{
    if (IsAlive)
    {
        window.draw(piece_sprite);
    }
}

auto ChessPiece::MoveTo(const ChessBoardPos& position_) noexcept -> void
{
    std::vector<ChessBoardPos> AllPositions = GetAllPositionsAllowedToMoveTo();
    if (std::find_if(AllPositions.begin(), AllPositions.end(), [&](const ChessBoardPos& pos) {return ((pos.x == position_.x) && (pos.y == position_.y)); }) != AllPositions.end())
    {
        position.x = position_.x;
        position.y = position_.y;

        const sf::Vector2u position_piece = position_.ToPixelPosition();
        piece_sprite.setPosition(position_piece.x, position_piece.y);
    }
}

auto ChessPiece::CanMoveToPosition(const ChessBoardPos& position_) const noexcept -> bool
{
    return m_canMoveToPos(position_, position);
}

auto ChessPiece::GetAllPositionsAllowedToMoveTo() const noexcept -> std::vector<ChessBoardPos>
{
    return m_getAllPosAllowedToMove(position);
}
