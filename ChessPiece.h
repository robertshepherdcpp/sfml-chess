#pragma once

#include<vector>
#include<string>
#include<functional>

#include "ChessBoardPos.h"

struct ChessPiece
{
	ChessPiece(const std::string filename, const ChessBoardPos pos, const auto canMoveToPos, const auto getAllPosAllowedToMove);

	void draw(sf::RenderWindow& window);

	auto MoveTo(const ChessBoardPos& position) noexcept -> void;

	auto CanMoveToPosition(const ChessBoardPos& position) const noexcept -> bool;
	auto GetAllPositionsAllowedToMoveTo() const noexcept -> std::vector<ChessBoardPos>;

	std::function<bool(ChessBoardPos, ChessBoardPos)> m_canMoveToPos;
	std::function<std::vector<ChessBoardPos>(ChessBoardPos)> m_getAllPosAllowedToMove;

	ChessBoardPos position;

	bool IsAlive{true};

	sf::Texture piece_texture;
	sf::Sprite piece_sprite;
};