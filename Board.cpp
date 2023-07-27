#include<SFML/Graphics.hpp>

#include "Board.h"
#include "ChessBoardPos.h"

auto Board::WhereHasBeenSelected(sf::Event& event)->ChessBoardPos
{
	// TODO make a better implementation of this

	int final_x = 0;
	int final_y = 0;
	if (event.mouseButton.x > 175) {
		final_x = 7;
    }
	else if (event.mouseButton.x > 150)
	{
		final_x = 6;
	}
	else if (event.mouseButton.x > 125)
	{
		final_x = 5;
	}
	else if (event.mouseButton.x > 100)
	{
		final_x = 4;
	}
	else if (event.mouseButton.x > 75)
	{
		final_x = 3;
	}
	else if (event.mouseButton.x > 50)
	{
		final_x = 2;
	}
	else if (event.mouseButton.x > 25)
	{
		final_x = 1;
	}
	else if (event.mouseButton.x > 0)
	{
		final_x = 0;
	}

	if (event.mouseButton.y > 175) {
		final_x = 7;
	}
	else if (event.mouseButton.y > 150)
	{
		final_y = 6;
	}
	else if (event.mouseButton.y > 125)
	{
		final_y = 5;
	}
	else if (event.mouseButton.y > 100)
	{
		final_y = 4;
	}
	else if (event.mouseButton.y > 75)
	{
		final_y = 3;
	}
	else if (event.mouseButton.y > 50)
	{
		final_y = 2;
	}
	else if (event.mouseButton.y > 25)
	{
		final_y = 1;
	}
	else if (event.mouseButton.y > 0)
	{
		final_y = 0;
	}

	return ChessBoardPos(final_x, final_y);
}