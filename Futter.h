#ifndef FUTTER_HPP
#define FUTTER_HPP

#include <random>
#include <iostream>
#include "ic.hpp"

class Futter
{
public:
	Futter(short GameMinXPos, short GameMaxXPos, short GameMinYPos, short GameMaxYPos);
	~Futter();

	void DisplayFutter() const;
	void RemoveFutter();

	short GetFutterXPos() const;
	short GetFutterYPos() const;

	void initializeFutterPos(short PlayerXPos, short PlayerYPos);
private:
	short Xpos;
	short Ypos;

	short MinXPos, MaxXPos;
	short MinYPos, MaxYPos;
};

Futter::Futter(short GameMinXPos, short GameMaxXPos, short GameMinYPos, short GameMaxYPos)
{
	MinXPos = GameMinXPos+1;
	MaxXPos = GameMaxXPos -1;

	MinYPos = GameMinYPos+1;
	MaxYPos = GameMaxYPos -1;
}

void Futter::DisplayFutter() const
{
	gotoxy(Xpos, Ypos);
	std::cout << (char)254;
}

void Futter::RemoveFutter()
{
	gotoxy(Xpos, Ypos);
	std::cout << ' ';
}

void Futter::initializeFutterPos(short PlayerXPos, short PlayerYPos)
{
	std::default_random_engine XRandom(time(0));
	std::uniform_int_distribution<int> Xbereich(MinXPos, MaxXPos);

	std::default_random_engine YRandom(time(0));
	std::uniform_int_distribution<int> Ybereich(MinYPos, MaxYPos);

	do{

		Xpos = Xbereich(XRandom);
		Ypos = Ybereich(YRandom);
	} while (Xpos == PlayerXPos && Ypos == PlayerYPos);
}

short Futter::GetFutterXPos() const { return Xpos; }
short Futter::GetFutterYPos() const { return Ypos; }


Futter::~Futter()
{

}

#endif