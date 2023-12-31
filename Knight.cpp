#include<SFML/Graphics.hpp>

#include<algorithm>
#include<vector>
#include<ranges>

#include "Knight.h"
#include "ChessBoardPos.h"

Knight::Knight(const std::string& filename, const ChessBoardPos pos, const int AssocNum)
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

    AssociatedNum = AssocNum;
}

void Knight::draw(sf::RenderWindow& window)
{
    if (IsAlive)
    {
        window.draw(piece_sprite);
    }
}

auto Knight::GetAllPositionsAllowedToMoveTo() const noexcept -> std::vector<ChessBoardPos>
{
    std::vector<ChessBoardPos> positions{}; 

    positions.push_back(ChessBoardPos(position.x + 2, position.y - 1));
    positions.push_back(ChessBoardPos(position.x + 2, position.y + 1));
    positions.push_back(ChessBoardPos(position.x - 2, position.y - 1));
    positions.push_back(ChessBoardPos(position.x - 2, position.y + 1));
    positions.push_back(ChessBoardPos(position.x - 1, position.y + 2));
    positions.push_back(ChessBoardPos(position.x + 1, position.y + 2));
    positions.push_back(ChessBoardPos(position.x + 1, position.y - 2));
    positions.push_back(ChessBoardPos(position.x - 1, position.y - 2));

    positions.push_back(ChessBoardPos(10, 10));
    return positions;
}

auto Knight::MoveTo(const ChessBoardPos& position_) noexcept -> bool
{
    std::vector<ChessBoardPos> AllPositions = GetAllPositionsAllowedToMoveTo();
    if (std::ranges::find_if(AllPositions, [&](const ChessBoardPos& pos) {return ((pos.x == position_.x) && (pos.y == position_.y)); }) != AllPositions.end())
    {
        position.x = position_.x;
        position.y = position_.y;

        const sf::Vector2u position_piece = position_.ToPixelPosition();
        piece_sprite.setPosition(position_piece.x, position_piece.y);
        return true;
    }
    return false;
}

auto Knight::CanMoveToPosition(const ChessBoardPos& position_) const noexcept -> bool
{
    if ((position_.x == position.x) || (position_.y == position.y)) { return true; }
    else { return false; }
}
