#pragma once

#include<SFML/Graphics.hpp>

#include<compare>

struct ChessBoardPos
{
	ChessBoardPos() = default;
	ChessBoardPos(const int x_, const int y_);

	int x{};
	int y{};

	auto ToPixelPosition() const noexcept -> sf::Vector2u;
	auto ToVector2f() const noexcept -> sf::Vector2f;

	constexpr std::strong_ordering operator<=>(const ChessBoardPos&) const = default;
};