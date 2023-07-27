#pragma once

#include<string>
#include<vector>

#include "ChessBoardPos.h"

struct Bishop
{
	Bishop(const std::string& filename, ChessBoardPos pos);

	void draw(sf::RenderWindow& window);

	auto MoveTo(const ChessBoardPos& position) noexcept -> bool;

	auto CanMoveToPosition(const ChessBoardPos& position) const noexcept -> bool;
	auto GetAllPositionsAllowedToMoveTo() const noexcept -> std::vector<ChessBoardPos>;

	ChessBoardPos position;

	bool IsAlive{ true };

	sf::Texture piece_texture;
	sf::Sprite piece_sprite;
};