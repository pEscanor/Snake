#ifndef SNAKEPPLAYER_HPP
#define SNAKEPLAYER_HPP
#include <map>
#include <string>
#include <iomanip>
#include <iostream>
#include "ic.hpp"


using namespace ic;
using namespace ic::shorties;

class Snake_Player
{
public:
	// Snake intialisieren
	Snake_Player(short GMIX, short GMAX, short GMIY, short GMAY);
	~Snake_Player();

	// Snake ausgeben
	void Draw_Snake();
	void Remove_Draw();

	// Snake Bewegungen
	void Gehe_Hoch();
	void Gehe_Runter();
	void Gehe_Links();
	void Gehe_Rechts();

	// Position von Snake
	short GetSnakePosX() const;
	short GetSnakePosY() const;

	// Kollision testen
	bool kollision();
	
	void Add_Snake(int OBEN, int UNTEN, int RECHTS, int LINKS);
private:
	
	// Gamefenster Eigenschaften
	short GameWindowMinHeigth;
	short GameWindowMaxWidth;
	short GameWindowMaxHeigth;
	short GameWindowMinWidth;

	// Schlange
	int SnakeSize;
	std::multimap<char, std::pair<short, short>> Snake;
};

Snake_Player::Snake_Player(short GMIX, short GMAX, short GMIY, short GMAY)
{
	SnakeSize = 0;

	GameWindowMinHeigth = GMIY;
	GameWindowMaxWidth  = GMAX;
	GameWindowMaxHeigth = GMAY;
	GameWindowMinWidth  = GMIX;
	
	Snake.insert({  '*', std::make_pair(GameWindowMaxWidth / 2, GameWindowMaxHeigth / 2) });
	Snake.insert({  'O', std::make_pair(GameWindowMaxWidth / 2, GameWindowMaxHeigth / 2 - 1) });
	Snake.insert({  'O', std::make_pair(GameWindowMaxWidth / 2, GameWindowMaxHeigth / 2 - 2) });
	Snake.insert({  'O', std::make_pair(GameWindowMaxWidth / 2, GameWindowMaxHeigth / 2 - 3) });
}

void Snake_Player::Draw_Snake()
{
	for (auto Schlange : Snake)
	{
		gotoxy(Schlange.second.first, Schlange.second.second);
		std::cout << Schlange.first;
	}

}

void Snake_Player::Remove_Draw()
{
	for (auto Schlange : Snake)
	{
		gotoxy(Schlange.second.first, Schlange.second.second);
		std::cout << ' ';
	}
}

void Snake_Player::Gehe_Hoch()
{
	short OldPostempX = Snake.begin()->second.first, OldPostempY = Snake.begin()->second.second;
	short NewPostempX, NewPostempY;

	short i = 2;
	bool frun = true;
	for (auto& Schlange : Snake)
	{
		if (frun)
		{
			frun = false;
		}
		else
		{
			if (i % 2 == 0)
			{
				NewPostempX = Schlange.second.first;
				NewPostempY = Schlange.second.second;

				Schlange.second.first = OldPostempX;
				Schlange.second.second = OldPostempY;
			}
			else if (i % 2 != 0)
			{
				OldPostempX = Schlange.second.first;
				OldPostempY = Schlange.second.second;

				Schlange.second.first = NewPostempX;
				Schlange.second.second = NewPostempY;
			}
			++i;

		}
	}

	--Snake.begin()->second.second;
}

void Snake_Player::Gehe_Links()
{
	short OldPostempX = Snake.begin()->second.first, OldPostempY = Snake.begin()->second.second;
	short NewPostempX, NewPostempY;

	short i = 2;
	bool frun = true;
	for (auto& Schlange : Snake)
	{
		if (frun)
		{
			frun = false;
		}
		else
		{
			if (i % 2 == 0)
			{
				NewPostempX = Schlange.second.first;
				NewPostempY = Schlange.second.second;

				Schlange.second.first = OldPostempX;
				Schlange.second.second = OldPostempY;
			}
			else if (i % 2 != 0)
			{
				OldPostempX = Schlange.second.first;
				OldPostempY = Schlange.second.second;

				Schlange.second.first = NewPostempX;
				Schlange.second.second = NewPostempY;
			}
			++i;

		}
	}

	--Snake.begin()->second.first;
}

void Snake_Player::Gehe_Rechts()
{
	
	short OldPostempX = Snake.begin()->second.first, OldPostempY = Snake.begin()->second.second;
	short NewPostempX, NewPostempY;

	short i = 2;
	bool frun = true;
	for (auto& Schlange : Snake)
	{
		if (frun)
		{
			frun = false;
		}
		else
		{
			if (i % 2 == 0)
			{
				NewPostempX = Schlange.second.first;
				NewPostempY = Schlange.second.second;

				Schlange.second.first = OldPostempX;
				Schlange.second.second = OldPostempY;
			}
			else if (i % 2 != 0)
			{
				OldPostempX = Schlange.second.first;
				OldPostempY = Schlange.second.second;

				Schlange.second.first = NewPostempX;
				Schlange.second.second = NewPostempY;
			}
			++i;

		}
	}

	++Snake.begin()->second.first;

}

void Snake_Player::Gehe_Runter()
{
	short OldPostempX = Snake.begin()->second.first, OldPostempY = Snake.begin()->second.second;
	short NewPostempX, NewPostempY;

	short i = 2;
	bool frun = true;
	for (auto& Schlange : Snake)
	{
		if (frun)
		{
			frun = false;
		}
		else
		{
			if (i % 2 == 0)
			{
				NewPostempX = Schlange.second.first;
				NewPostempY = Schlange.second.second;

				Schlange.second.first = OldPostempX;
				Schlange.second.second = OldPostempY;
			}
			else if (i % 2 != 0)
			{
				OldPostempX = Schlange.second.first;
				OldPostempY = Schlange.second.second;

				Schlange.second.first = NewPostempX;
				Schlange.second.second = NewPostempY;
			}
			++i;

		}
	}

	++Snake.begin()->second.second;
}

bool Snake_Player::kollision()
{
	std::multimap<char, std::pair<short, short>> SnakeCopy = Snake;
	for (auto Schlange : Snake)
	{
		auto it = SnakeCopy.find('O');
		if (it != SnakeCopy.end())
		{
			if (it->second.first == Snake.begin()->second.first &&
				it->second.second == Snake.begin()->second.second)
			{
				return true;
			}
			else
			{
				SnakeCopy.erase(it);
			}
		}
	}
	return false;
}

short Snake_Player::GetSnakePosX() const { return Snake.begin()->second.first;  }
short Snake_Player::GetSnakePosY() const { return Snake.begin()->second.second; }

Snake_Player::~Snake_Player()
{

}

void Snake_Player::Add_Snake(int OBEN = 0, int UNTEN = 0, int RECHTS = 0, int LINKS = 0)
{
	if (OBEN != 0 && UNTEN == 0 && RECHTS == 0 && LINKS == 0)
	{
		Snake.insert({ 'O', std::make_pair(Snake.end().operator--()->second.first, Snake.end().operator--()->second.second - 1) });

	}
	else if (OBEN == 0 && UNTEN != 0 && RECHTS == 0 && LINKS == 0)
	{
		Snake.insert({'O', std::make_pair(Snake.end().operator--()->second.first, Snake.end().operator--()->second.second + 1) });

	}
	else if (OBEN == 0 && UNTEN == 0 && RECHTS != 0 && LINKS == 0)
	{
		Snake.insert({ 'O', std::make_pair(Snake.end().operator--()->second.first + 1, Snake.end().operator--()->second.second) });

	}
	else if (OBEN == 0 && UNTEN == 0 && RECHTS == 0 && LINKS != 0)
	{
		Snake.insert({ 'O', std::make_pair(Snake.end().operator--()->second.first -1, Snake.end().operator--()->second.second - 1) });
	}
}

#endif
