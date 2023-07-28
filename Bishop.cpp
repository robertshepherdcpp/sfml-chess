#include<SFML/Graphics.hpp>

#include<algorithm>
#include<vector>
#include<iostream>

#include "Bishop.h"
#include "ChessBoardPos.h"

Bishop::Bishop(const std::string& filename, ChessBoardPos pos)
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

void Bishop::draw(sf::RenderWindow& window)
{
    if (IsAlive)
    {
        window.draw(piece_sprite);
    }
}

auto Bishop::GetAllPositionsAllowedToMoveTo() const noexcept -> std::vector<ChessBoardPos>
{
    std::vector<ChessBoardPos> positions{};

    int x = position.x;
    int y = position.y;
    for (; (x >= 0) && (x <= 7) && (y >= 0) && (y <= 7);)
    {
        x += 1;
        y += 1;
        positions.push_back(ChessBoardPos(x, y));
    }

    x = position.x;
    y = position.y;

    for (; (x >= 0) && (x <= 7) && (y >= 0) && (y <= 7);)
    {
        x -= 1;
        y -= 1;
        positions.push_back(ChessBoardPos(x, y));
    }

    x = position.x;
    y = position.y;

    for (; (x >= 0) && (x <= 7) && (y >= 0) && (y <= 7);)
    {
        x += 1;
        y -= 1;
        positions.push_back(ChessBoardPos(x, y));
    }

    x = position.x;
    y = position.y;

    for (; (x >= 0) && (x <= 7) && (y >= 0) && (y <= 7);)
    {
        x -= 1;
        y += 1;
        positions.push_back(ChessBoardPos(x, y));
    }

    x = position.x;
    y = position.y;

    positions.push_back(ChessBoardPos(10, 10));

    std::cout << "hi\n";
    for (const auto& x : positions) { std::cout << x.x << ", " << x.y << "\n"; }
    return positions;
}

auto Bishop::MoveTo(const ChessBoardPos& position_) noexcept -> bool
{
    std::vector<ChessBoardPos> AllPositions = GetAllPositionsAllowedToMoveTo();
    if (std::find_if(AllPositions.begin(), AllPositions.end(), [&](const ChessBoardPos& pos) {return ((pos.x == position_.x) && (pos.y == position_.y)); }) != AllPositions.end())
    {
        position.x = position_.x;
        position.y = position_.y;

        const sf::Vector2u position_piece = position_.ToPixelPosition();
        piece_sprite.setPosition(static_cast<float>(position_piece.x), static_cast<int>(position_piece.y));
        return true;
    }
    return false;
}

auto Bishop::CanMoveToPosition(const ChessBoardPos& position_) const noexcept -> bool
{
    if ((position_.x == position.x) || (position_.y == position.y)) { return true; }
    else { return false; }
}