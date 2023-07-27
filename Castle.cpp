#include<SFML/Graphics.hpp>

#include<algorithm>
#include<vector>

#include "Castle.h"
#include "ChessBoardPos.h"

Castle::Castle(const std::string& filename, ChessBoardPos pos)
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

void Castle::draw(sf::RenderWindow& window)
{
    if (IsAlive)
    {
        window.draw(piece_sprite);
    }
}

auto Castle::GetAllPositionsAllowedToMoveTo() const noexcept -> std::vector<ChessBoardPos>
{
    std::vector<ChessBoardPos> positions{}; for (int i = 0; i <= 7; i++) { positions.push_back(ChessBoardPos(i, position.y)); positions.push_back(ChessBoardPos(position.x, i)); }
    return positions;
}

auto Castle::MoveTo(const ChessBoardPos& position_) noexcept -> bool
{
    std::vector<ChessBoardPos> AllPositions = GetAllPositionsAllowedToMoveTo();
    if (std::find_if(AllPositions.begin(), AllPositions.end(), [&](const ChessBoardPos& pos) {return ((pos.x == position_.x) && (pos.y == position_.y)); }) != AllPositions.end())
    {
        position.x = position_.x;
        position.y = position_.y;

        const sf::Vector2u position_piece = position_.ToPixelPosition();
        piece_sprite.setPosition(position_piece.x, position_piece.y);
        return true;
    }
    return false;
}

auto Castle::CanMoveToPosition(const ChessBoardPos& position_) const noexcept -> bool
{
    if ((position_.x == position.x) || (position_.y == position.y)) { return true; }
    else { return false; }
}
