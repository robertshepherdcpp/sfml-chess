#include "ChessBoardPos.h"

ChessBoardPos::ChessBoardPos(const int x_, const int y_)
{
    x = x_;
    y = y_;
}

auto ChessBoardPos::ToPixelPosition() const noexcept -> sf::Vector2u
{
    return sf::Vector2u(x * 25, y * 25);
}
