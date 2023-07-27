#pragma once

#include<SFML/Graphics.hpp>

#include "Castle.h"
#include "ChessBoardPos.h"

struct Board
{
    void draw(sf::RenderWindow& window);

    auto WhereHasBeenSelected(sf::Event& event)->ChessBoardPos;
};