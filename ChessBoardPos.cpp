#include "ChessBoardPos.h"

ChessBoardPos::ChessBoardPos(int x_, int y_)
{
    x = x_;
    y = y_;
}

auto ChessBoardPos::ToPixelPosition() const noexcept -> sf::Vector2u
{
    return sf::Vector2u(x * 25, y * 25);
}
