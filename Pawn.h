#pragma once

#include<string>
#include<vector>

#include "ChessBoardPos.h"

struct Pawn
{
	Pawn(const std::string& filename, const ChessBoardPos pos, const int AssocNum);

	void draw(sf::RenderWindow& window);

	auto MoveTo(const ChessBoardPos& position) noexcept -> bool;

	auto CanMoveToPosition(const ChessBoardPos& position) const noexcept -> bool;
	auto GetAllPositionsAllowedToMoveTo() const noexcept -> std::vector<ChessBoardPos>;

	ChessBoardPos position;

	bool IsAlive{ true };
	int AssociatedNum{};

	std::string file_name{};

	sf::Texture piece_texture;
	sf::Sprite piece_sprite;
};