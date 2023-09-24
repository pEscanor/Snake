#ifndef FUTTER_HPP
#define FUTTER_HPP

#include <random>
#include <iostream>
#include "ic.hpp"  // Include necessary header files

class Futter
{
public:
	// Constructor to initialize Futter object
	Futter(short GameMinXPos, short GameMaxXPos, short GameMinYPos, short GameMaxYPos);

	// Destructor
	~Futter();

	// Display the Futter on the screen
	void DisplayFutter() const;

	// Remove the Futter from the screen
	void RemoveFutter();

	// Get the X position of the Futter
	short GetFutterXPos() const;

	// Get the Y position of the Futter
	short GetFutterYPos() const;

	// Initialize the position of the Futter while avoiding the player's position
	void initializeFutterPos(short PlayerXPos, short PlayerYPos);

private:
	short Xpos;        // X position of the Futter
	short Ypos;        // Y position of the Futter

	short MinXPos, MaxXPos;  // Minimum and maximum X positions for the Futter
	short MinYPos, MaxYPos;  // Minimum and maximum Y positions for the Futter
};

Futter::Futter(short GameMinXPos, short GameMaxXPos, short GameMinYPos, short GameMaxYPos)
{
	// Initialize the minimum and maximum positions for the Futter
	MinXPos = GameMinXPos + 1;
	MaxXPos = GameMaxXPos - 1;
	MinYPos = GameMinYPos + 1;
	MaxYPos = GameMaxYPos - 1;
}

void Futter::DisplayFutter() const
{
	// Display the Futter symbol at its current position
	gotoxy(Xpos, Ypos);
	std::cout << (char)254;
}

void Futter::RemoveFutter()
{
	// Remove the Futter symbol from the screen by printing a space at its position
	gotoxy(Xpos, Ypos);
	std::cout << ' ';
}

void Futter::initializeFutterPos(short PlayerXPos, short PlayerYPos)
{
	// Initialize the position of the Futter while avoiding the player's position
	std::default_random_engine XRandom(time(0));
	std::uniform_int_distribution<int> Xbereich(MinXPos, MaxXPos);

	std::default_random_engine YRandom(time(0));
	std::uniform_int_distribution<int> Ybereich(MinYPos, MaxYPos);

	do {
		Xpos = Xbereich(XRandom);
		Ypos = Ybereich(YRandom);
	} while (Xpos == PlayerXPos && Ypos == PlayerYPos);
}

short Futter::GetFutterXPos() const { return Xpos; }
short Futter::GetFutterYPos() const { return Ypos; }

Futter::~Futter()
{
	// Destructor implementation (if needed)
}

#endif
