#pragma once

#include<SFML/Graphics.hpp>

#include<compare>

struct ChessBoardPos
{
	ChessBoardPos(int x_, int y_);

	int x{};
	int y{};

	auto ToPixelPosition() const noexcept -> sf::Vector2u;

	constexpr std::strong_ordering operator<=>(const ChessBoardPos&) const = default;
};