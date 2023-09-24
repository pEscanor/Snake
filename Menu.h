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
    // Constructors
    GameMenu();
    GameMenu(short mindestX, short mindestY, short maximalX, short maximalY);
    GameMenu(short mindestX, short mindestY, short maximalX, short maximalY, short minimalStatusX, short maximalStatusX);
    GameMenu(short mindestX, short mindestY, short maximalX, short maximalY, short minimalStatusX, short maximalStatusX, short maximalStautsY);
    
    // Destructor
    ~GameMenu();

    // Draw game menu and status menu
    void DrawGameMenu() const;
    void DrawStatusMenu() const;

    // Accessor methods for dimensions
    inline short GetMindestX() const;
    inline short GetMindestY() const;
    inline short GetMaximalX() const;
    inline short GetMaximalY() const;

    // Increase game points and level
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

// Default constructor
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

// Constructor with game menu dimensions
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

// Constructor with game menu and status menu dimensions
GameMenu::GameMenu(short mindestX, short mindestY, short maximalX, short maximalY, short minimalStatusX, short maximalStatusX)
{
    gamepoints = 0;
    GameMindestX = mindestX;
    GameMaximalX = maximalX;
    GameMaximalY = maximalY;
    GameMindestY = mindestY;

    StatusMindestX = GameMaximalX + minimalStatusX;
    StatusMaximalY = 0;
    StatusMaximalX = StatusMindestX + maximalStatusX;
}

// Constructor with game menu, status menu, and status menu height dimensions
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

// Draw the game menu
void GameMenu::DrawGameMenu() const
{
    // Draw the upper game menu line
    gotoxy(GameMindestX, GameMindestY);
    std::cout << (char)201;

    for (short i = GameMindestX + 1; i != GameMaximalX; ++i)
    {
        gotoxy(i, GameMindestY);
        std::cout << (char)205;
    }

    gotoxy(GameMaximalX, GameMindestY);
    std::cout << (char)187;

    // Draw the left game menu line
    for (short i = GameMindestY + 1; i != GameMaximalY; ++i)
    {
        gotoxy(GameMindestX, i);
        std::cout << (char)186;
    }

    gotoxy(GameMindestX, GameMaximalY);
    std::cout << (char)200;

    // Draw the lower game menu line
    for (short i = GameMindestX + 1; i != GameMaximalX; ++i)
    {
        gotoxy(i, GameMaximalY);
        std::cout << (char)205;
    }

    gotoxy(GameMaximalX, GameMaximalY);
    std::cout << (char)188;

    // Draw the right game menu line
    for (short i = GameMindestY + 1; i != GameMaximalY; ++i)
    {
        gotoxy(GameMaximalX, i);
        std::cout << (char)186;
    }
}

// Draw the status menu
void GameMenu::DrawStatusMenu() const
{
    // Draw the upper status menu line
    gotoxy(StatusMindestX, GameMindestY);
    std::cout << (char)201;

    for (short i = StatusMindestX + 1; i != StatusMaximalX; ++i)
    {
        gotoxy(i, GameMindestY);
        std::cout << (char)205;
    }

    gotoxy(StatusMaximalX, GameMindestY);
    std::cout << (char)187;

    // Draw the left status menu line
    for (short i = GameMindestY + 1; i != StatusMaximalY; ++i)
    {
        gotoxy(StatusMindestX, i);
        std::cout << (char)186;
    }

    gotoxy(StatusMindestX, StatusMaximalY);
    std::cout << (char)200;

    // Draw the lower status menu line
    for (short i = StatusMindestX + 1; i != StatusMaximalX; ++i)
    {
        gotoxy(i, StatusMaximalY);
        std::cout << (char)205;
    }

    gotoxy(StatusMaximalX, StatusMaximalY);
    std::cout << (char)188;

    // Draw the right status menu line
    for (short i = GameMindestY + 1; i != StatusMaximalY ; ++i)
    {
        gotoxy(StatusMaximalX, i);
        std::cout << (char)186;
    }

    // Set the content
    gotoxy(StatusMindestX + 2, GameMindestY + 1);
    std::cout << "Points: " << gamepoints;

    gotoxy(StatusMindestX + 2, GameMindestY + 3);
    std::cout << "Level: " << level;
}

// Getters for dimensions
short GameMenu::GetMaximalX() const { return GameMaximalX; }
short GameMenu::GetMaximalY() const { return GameMaximalY; }
short GameMenu::GetMindestX() const { return GameMindestX; }
short GameMenu::GetMindestY() const { return GameMindestY; }

// Increase game points and level
void GameMenu::increaseGamePoints()
{
    ++gamepoints;
    if (gamepoints % 2 == 0 & gamepoints != 0)
    {
        level++;
    }
}

// Destructor
GameMenu::~GameMenu()
{

}

#endif
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
    // Constructors
    GameMenu();
    GameMenu(short mindestX, short mindestY, short maximalX, short maximalY);
    GameMenu(short mindestX, short mindestY, short maximalX, short maximalY, short minimalStatusX, short maximalStatusX);
    GameMenu(short mindestX, short mindestY, short maximalX, short maximalY, short minimalStatusX, short maximalStatusX, short maximalStautsY);
    
    // Destructor
    ~GameMenu();

    // Draw game menu and status menu
    void DrawGameMenu() const;
    void DrawStatusMenu() const;

    // Accessor methods for dimensions
    inline short GetMindestX() const;
    inline short GetMindestY() const;
    inline short GetMaximalX() const;
    inline short GetMaximalY() const;

    // Increase game points and level
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

// Default constructor
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

// Constructor with game menu dimensions
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

// Constructor with game menu and status menu dimensions
GameMenu::GameMenu(short mindestX, short mindestY, short maximalX, short maximalY, short minimalStatusX, short maximalStatusX)
{
    gamepoints = 0;
    GameMindestX = mindestX;
    GameMaximalX = maximalX;
    GameMaximalY = maximalY;
    GameMindestY = mindestY;

    StatusMindestX = GameMaximalX + minimalStatusX;
    StatusMaximalY = 0;
    StatusMaximalX = StatusMindestX + maximalStatusX;
}

// Constructor with game menu, status menu, and status menu height dimensions
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

// Draw the game menu
void GameMenu::DrawGameMenu() const
{
    // Draw the upper game menu line
    gotoxy(GameMindestX, GameMindestY);
    std::cout << (char)201;

    for (short i = GameMindestX + 1; i != GameMaximalX; ++i)
    {
        gotoxy(i, GameMindestY);
        std::cout << (char)205;
    }

    gotoxy(GameMaximalX, GameMindestY);
    std::cout << (char)187;

    // Draw the left game menu line
    for (short i = GameMindestY + 1; i != GameMaximalY; ++i)
    {
        gotoxy(GameMindestX, i);
        std::cout << (char)186;
    }

    gotoxy(GameMindestX, GameMaximalY);
    std::cout << (char)200;

    // Draw the lower game menu line
    for (short i = GameMindestX + 1; i != GameMaximalX; ++i)
    {
        gotoxy(i, GameMaximalY);
        std::cout << (char)205;
    }

    gotoxy(GameMaximalX, GameMaximalY);
    std::cout << (char)188;

    // Draw the right game menu line
    for (short i = GameMindestY + 1; i != GameMaximalY; ++i)
    {
        gotoxy(GameMaximalX, i);
        std::cout << (char)186;
    }
}

// Draw the status menu
void GameMenu::DrawStatusMenu() const
{
    // Draw the upper status menu line
    gotoxy(StatusMindestX, GameMindestY);
    std::cout << (char)201;

    for (short i = StatusMindestX + 1; i != StatusMaximalX; ++i)
    {
        gotoxy(i, GameMindestY);
        std::cout << (char)205;
    }

    gotoxy(StatusMaximalX, GameMindestY);
    std::cout << (char)187;

    // Draw the left status menu line
    for (short i = GameMindestY + 1; i != StatusMaximalY; ++i)
    {
        gotoxy(StatusMindestX, i);
        std::cout << (char)186;
    }

    gotoxy(StatusMindestX, StatusMaximalY);
    std::cout << (char)200;

    // Draw the lower status menu line
    for (short i = StatusMindestX + 1; i != StatusMaximalX; ++i)
    {
        gotoxy(i, StatusMaximalY);
        std::cout << (char)205;
    }

    gotoxy(StatusMaximalX, StatusMaximalY);
    std::cout << (char)188;

    // Draw the right status menu line
    for (short i = GameMindestY + 1; i != StatusMaximalY ; ++i)
    {
        gotoxy(StatusMaximalX, i);
        std::cout << (char)186;
    }

    // Set the content
    gotoxy(StatusMindestX + 2, GameMindestY + 1);
    std::cout << "Points: " << gamepoints;

    gotoxy(StatusMindestX + 2, GameMindestY + 3);
    std::cout << "Level: " << level;
}

// Getters for dimensions
short GameMenu::GetMaximalX() const { return GameMaximalX; }
short GameMenu::GetMaximalY() const { return GameMaximalY; }
short GameMenu::GetMindestX() const { return GameMindestX; }
short GameMenu::GetMindestY() const { return GameMindestY; }

// Increase game points and level
void GameMenu::increaseGamePoints()
{
    ++gamepoints;
    if (gamepoints % 2 == 0 & gamepoints != 0)
    {
        level++;
    }
}

// Destructor
GameMenu::~GameMenu()
{

}

#endif
