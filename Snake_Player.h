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
    // Constructor to initialize the snake
    Snake_Player(short GMIX, short GMAX, short GMIY, short GMAY);
    
    // Destructor
    ~Snake_Player();

    // Draw the snake on the screen
    void Draw_Snake();
    
    // Remove the snake from the screen
    void Remove_Draw();

    // Move the snake up, down, left, and right
    void Gehe_Hoch();
    void Gehe_Runter();
    void Gehe_Links();
    void Gehe_Rechts();

    // Get the position of the snake
    short GetSnakePosX() const;
    short GetSnakePosY() const;

    // Check for collisions
    bool kollision();

    // Add a segment to the snake
    void Add_Snake(int OBEN = 0, int UNTEN = 0, int RECHTS = 0, int LINKS = 0);

private:
    // Game window properties
    short GameWindowMinHeigth;
    short GameWindowMaxWidth;
    short GameWindowMaxHeigth;
    short GameWindowMinWidth;

    // Snake properties
    int SnakeSize;
    std::multimap<char, std::pair<short, short>> Snake;
};

// Constructor to initialize the snake
Snake_Player::Snake_Player(short GMIX, short GMAX, short GMIY, short GMAY)
{
    SnakeSize = 0;

    GameWindowMinHeigth = GMIY;
    GameWindowMaxWidth  = GMAX;
    GameWindowMaxHeigth = GMAY;
    GameWindowMinWidth  = GMIX;
    
    // Initialize the snake with default positions
    Snake.insert({  '*', std::make_pair(GameWindowMaxWidth / 2, GameWindowMaxHeigth / 2) });
    Snake.insert({  'O', std::make_pair(GameWindowMaxWidth / 2, GameWindowMaxHeigth / 2 - 1) });
    Snake.insert({  'O', std::make_pair(GameWindowMaxWidth / 2, GameWindowMaxHeigth / 2 - 2) });
    Snake.insert({  'O', std::make_pair(GameWindowMaxWidth / 2, GameWindowMaxHeigth / 2 - 3) });
}

// Draw the snake on the screen
void Snake_Player::Draw_Snake()
{
    for (auto Schlange : Snake)
    {
        gotoxy(Schlange.second.first, Schlange.second.second);
        std::cout << Schlange.first;
    }
}

// Remove the snake from the screen
void Snake_Player::Remove_Draw()
{
    for (auto Schlange : Snake)
    {
        gotoxy(Schlange.second.first, Schlange.second.second);
        std::cout << ' ';
    }
}

// Move the snake up
void Snake_Player::Gehe_Hoch()
{
    // Logic to move the snake up
}

// Move the snake left
void Snake_Player::Gehe_Links()
{
    // Logic to move the snake left
}

// Move the snake right
void Snake_Player::Gehe_Rechts()
{
    // Logic to move the snake right
}

// Move the snake down
void Snake_Player::Gehe_Runter()
{
    // Logic to move the snake down
}

// Check for collisions
bool Snake_Player::kollision()
{
    // Logic to check for collisions
    return false;
}

// Get the X position of the snake's head
short Snake_Player::GetSnakePosX() const
{
    return Snake.begin()->second.first;
}

// Get the Y position of the snake's head
short Snake_Player::GetSnakePosY() const
{
    return Snake.begin()->second.second;
}

// Destructor
Snake_Player::~Snake_Player()
{

}

// Add a segment to the snake
void Snake_Player::Add_Snake(int OBEN, int UNTEN, int RECHTS, int LINKS)
{
    // Logic to add a segment to the snake
}

#endif
