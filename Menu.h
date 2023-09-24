#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include "ic.hpp"

/* NOTE
 * FENSTERPROPORTIONEN
 * short GameMindestX; 
 * short GameMaximalX;
 * short GameMindestY;
 * short GameMaximalY;
 * ---------------------
 * SPIELSTANDPROPORTIONEN
 * short StatusMindestX;
 * short StatusMaximalX;
 * short StatusMaximalY;
 */

using namespace ic;
using namespace ic::shorties;

class GameMenu
{
public:
	GameMenu();
	GameMenu(short mindestX, short mindestY, short maximalX, short maximalY);
	GameMenu(short mindestX, short mindestY, short maximalX, short maximalY, short minimalStatusX, short maximalStatusX);
	GameMenu(short mindestX, short mindestY, short maximalX, short maximalY, short minimalStatusX, short maximalStatusX, short maximalStautsY);
	~GameMenu();

	void DrawGameMenu()   const;
	void DrawStatusMenu() const;

	inline short GetMindestX() const;
	inline short GetMindestY() const;
	inline short GetMaximalX() const;
	inline short GetMaximalY() const;

	void increaseGamePoints();

private:
	short level = 0;
	short gamepoints;

	short GameMindestX;
	short GameMaximalX;
	short GameMindestY;
	short GameMaximalY;

	short StatusMindestX;
	short StatusMaximalX;
	short StatusMaximalY;
};

GameMenu::GameMenu()
{
	gamepoints = 0;
	GameMindestX = 0;
	GameMaximalX = 0;
	GameMaximalY = 0;
	GameMindestY = 0;

	StatusMindestX = 0;
	StatusMaximalY = 0;
	StatusMindestX = 0;
}

GameMenu::GameMenu(short mindestX, short mindestY, short maximalX, short maximalY)
{
	gamepoints = 0;
	GameMindestX = mindestX;
	GameMaximalX = maximalX;
	GameMaximalY = maximalY;
	GameMindestY = mindestY;

	StatusMindestX = GameMaximalX + 1;
	StatusMaximalY = 0;
	StatusMaximalX = StatusMindestX + 10;
}

GameMenu::GameMenu(short mindestX, short mindestY, short maximalX, short maximalY, short minimalStatusX, short maximalStatusX)
{
	gamepoints = 0;
	GameMindestX = mindestX;
	GameMaximalX = maximalX;
	GameMaximalY = maximalY;
	GameMindestY = mindestY;

	StatusMindestX =GameMaximalX + minimalStatusX;
	StatusMaximalY = 0;
	StatusMaximalX = StatusMindestX + maximalStatusX;
}

GameMenu::GameMenu(short mindestX, short mindestY, short maximalX, short maximalY, short minimalStatusX, short maximalStatusX, short maximalStautsY)
{
	gamepoints = 0;
	GameMindestX = mindestX;
	GameMaximalX = maximalX;
	GameMaximalY = maximalY;
	GameMindestY = mindestY;

	StatusMindestX = GameMaximalX + minimalStatusX;
	StatusMaximalY = GameMindestY + maximalStautsY;
	StatusMaximalX = StatusMindestX + maximalStatusX;
}

void GameMenu::DrawGameMenu() const
{
	// Obere Gamelinie zeichnen
	gotoxy(GameMindestX, GameMindestY);
	std::cout << (char)201;

	for (short i = GameMindestX + 1; i != GameMaximalX; ++i)
	{
		gotoxy(i, GameMindestY);
		std::cout << (char)205;
	}

	gotoxy(GameMaximalX, GameMindestY);
	std::cout << (char)187;

	// Linke Gamelinie zeichnen
	for (short i = GameMindestY + 1; i != GameMaximalY; ++i)
	{
		gotoxy(GameMindestX, i);
		std::cout << (char)186;
	}

	gotoxy(GameMindestX, GameMaximalY);
	std::cout << (char)200;

	// Untere Gamelinie zeichnen
	for (short i = GameMindestX + 1; i != GameMaximalX; ++i)
	{
		gotoxy(i, GameMaximalY);
		std::cout << (char)205;
	}

	gotoxy(GameMaximalX, GameMaximalY);
	std::cout << (char)188;

	// Rechte Gamelinie zeichnen
	for (short i = GameMindestY + 1; i != GameMaximalY; ++i)
	{
		gotoxy(GameMaximalX, i);
		std::cout << (char)186;
	}
}

void GameMenu::DrawStatusMenu() const
{
	// Obere Statuslinie zeichnen
	gotoxy(StatusMindestX, GameMindestY);
	std::cout << (char)201;

	for (short i = StatusMindestX + 1; i != StatusMaximalX; ++i)
	{
		gotoxy(i, GameMindestY);
		std::cout << (char)205;
	}

	gotoxy(StatusMaximalX, GameMindestY);
	std::cout << (char)187;

	// Linke Statuslinie zeichnen
	for (short i = GameMindestY + 1; i != StatusMaximalY; ++i)
	{
		gotoxy(StatusMindestX, i);
		std::cout << (char)186;
	}

	gotoxy(StatusMindestX, StatusMaximalY);
	std::cout << (char)200;

	// Untere Reihe zeichnen
	for (short i = StatusMindestX + 1; i != StatusMaximalX; ++i)
	{
		gotoxy(i, StatusMaximalY);
		std::cout << (char)205;
	}

	gotoxy(StatusMaximalX, StatusMaximalY);
	std::cout << (char)188;

	// Rechte Reihe zeichnen
	for (short i = GameMindestY + 1; i != StatusMaximalY ; ++i)
	{
		gotoxy(StatusMaximalX, i);
		std::cout << (char)186;
	}


	// Inhalt festlegen
	gotoxy(StatusMindestX + 2, GameMindestY + 1);
	std::cout << "Points: " << gamepoints;

	gotoxy(StatusMindestX + 2, GameMindestY + 3);
	std::cout << "Level: " << level;
}

short GameMenu::GetMaximalX() const { return GameMaximalX; }

short GameMenu::GetMaximalY() const { return GameMaximalY; }

short GameMenu::GetMindestX() const { return GameMindestX; }

short GameMenu::GetMindestY() const { return GameMindestY; }

void GameMenu::increaseGamePoints()
{
	++gamepoints;
	if (gamepoints % 2 == 0 & gamepoints != 0)
	{
		level++;
	}
}
	
GameMenu::~GameMenu()
{

}

#endif