#pragma once

#include<string>

#include "ChessPiece.h"

struct Castle : ChessPiece
{
	Castle(std::string filename, ChessBoardPos pos, auto, auto);
};