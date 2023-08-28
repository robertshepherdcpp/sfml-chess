#include<SFML/Graphics.hpp>

#include<algorithm>
#include<vector>
#include<ranges>

#include "Castle.h"
#include "Bishop.h"
#include "Queen.h"
#include "ChessBoardPos.h"

Queen::Queen(const std::string& filename, ChessBoardPos pos, int AssocNum)
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

void Queen::draw(sf::RenderWindow& window) noexcept
{
    if (IsAlive)
    {
        window.draw(piece_sprite);
    }
}

auto Queen::GetAllPositionsAllowedToMoveTo() const noexcept -> std::vector<ChessBoardPos>
{
    std::vector<ChessBoardPos> positions{};
    positions = Castle("black_castle.png", ChessBoardPos(5, 5), 33).GetAllPositionsAllowedToMoveTo();
    std::vector<ChessBoardPos> bishop_positions =  Bishop( "black_bishop.png", ChessBoardPos(5, 5), 33).GetAllPositionsAllowedToMoveTo();
    for (const auto& x : bishop_positions)
    {
        positions.push_back(x);
    }
    return positions;
}

auto Queen::MoveTo(const ChessBoardPos& position_) noexcept -> bool
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

auto Queen::CanMoveToPosition(const ChessBoardPos& position_) const noexcept -> bool
{
    if ((position_.x == position.x) || (position_.y == position.y)) { return true; }
    else { return false; }
}