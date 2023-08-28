#include<SFML/Graphics.hpp>

#include<algorithm>
#include<vector>
#include<iostream>
#include<ranges>

#include "Pawn.h"
#include "ChessBoardPos.h"

Pawn::Pawn(const std::string& filename, ChessBoardPos pos, int AssocNum)
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

    file_name = filename;

    AssociatedNum = AssocNum;
}

void Pawn::draw(sf::RenderWindow& window)
{
    if (IsAlive)
    {
        window.draw(piece_sprite);
    }
}

auto Pawn::GetAllPositionsAllowedToMoveTo() const noexcept -> std::vector<ChessBoardPos>
{
    std::vector<ChessBoardPos> positions{};

    if (file_name == "white_pawn.png")
    {
        positions.push_back(ChessBoardPos(position.x, position.y + 1));
    }
    else if (file_name == "black_pawn.png")
    {
        positions.push_back(ChessBoardPos(position.x, position.y - 1));
    }

    for (const auto& x : positions) { std::cout << x.x << ", " << x.y << "\n"; }
    return positions;
}

auto Pawn::MoveTo(const ChessBoardPos& position_) noexcept -> bool
{
    if (std::ranges::find_if(GetAllPositionsAllowedToMoveTo(), [&](const ChessBoardPos& pos) {return ((pos.x == position_.x) && (pos.y == position_.y)); }) != AllPositions.end())
    {
        position.x = position_.x;
        position.y = position_.y;

        const sf::Vector2u position_piece = position_.ToPixelPosition();
        piece_sprite.setPosition(static_cast<float>(position_piece.x), static_cast<int>(position_piece.y));
        return true;
    }
    return false;
}

auto Pawn::CanMoveToPosition(const ChessBoardPos& position_) const noexcept -> bool
{
    if ((position_.x == position.x) || (position_.y == position.y)) { return true; }
    else { return false; }
}