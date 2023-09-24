#ifndef GAME_HPP
#define GAME_HPP
#include "Snake_Player.h"
#include "Menu.h"
#include "Futter.h"
#include <conio.h>

void warten()
{
	std::cin.sync();
	std::cin.clear();
}

void StartGame()
{
	clrscr(BG_BLACK);
	ic::shorties::textcolor(FG_WHITE);

	short GMinWidth = 2;
	short GMaxWidth = 50;
	short GMinHeigth = 2;
	short GMaxHeigth = 15;

	short SMinWidth = 2;
	short SMaxWidth = 20;
	short SMaxHeigth = 5;

	short points = 0;

	GameMenu FensterMenu(GMinWidth, GMinHeigth, GMaxWidth,
						 GMaxHeigth, SMinWidth, SMaxWidth, SMaxHeigth);
	FensterMenu.DrawGameMenu();
	FensterMenu.DrawStatusMenu();

	Snake_Player Spieler(FensterMenu.GetMindestX(), FensterMenu.GetMaximalX(),
						 FensterMenu.GetMindestY(), FensterMenu.GetMaximalY());
	
	Futter Essen(FensterMenu.GetMindestX(), FensterMenu.GetMaximalX(),
				 FensterMenu.GetMindestY(), FensterMenu.GetMaximalY());

	Spieler.Draw_Snake();
	Essen.initializeFutterPos(Spieler.GetSnakePosX(), Spieler.GetSnakePosY());
	Essen.DisplayFutter();

	bool go_up	  = false;
	bool go_down  = true;
	bool go_right = false;
	bool go_left  = false;
	
	for (int i = 3; i != 0; --i)
	{
		gotoxy(GMinWidth, GMinHeigth-1);
		std::cout << "Spiel startet in " << i << " Sekunden";
		Sleep(1000);
	}

	gotoxy(GMinWidth, GMinHeigth-1);
	std::cout << "                             ";
	gotoxy(GMinWidth, GMinHeigth-1);
	std::cout << "Go!";

	while (true)
	{
		Spieler.Remove_Draw();
		if (Spieler.kollision() == true)
		{
			clrscr(BG_BROWN);
			textbackground(BG_BROWN);
			textcolor(FG_WHITE);

			FensterMenu.DrawStatusMenu();

			gotoxy(30, 5);
			std::cout << "Sie sich selbst berührt!" << std::endl;
			break;
		}
		
		if (Spieler.GetSnakePosY() == FensterMenu.GetMindestY() || Spieler.GetSnakePosY() == FensterMenu.GetMaximalY()||
			     Spieler.GetSnakePosX() == FensterMenu.GetMaximalX() || Spieler.GetSnakePosX() == FensterMenu.GetMindestX())
		{
			clrscr(BG_BROWN);
			textbackground(BG_BROWN);
			textcolor(FG_WHITE);

			gotoxy(30, 5);
			std::cout << "Sie haben den Rand beruehrt!" << std::endl;
			break;
		}



		if (GetAsyncKeyState(VK_UP) && go_up == false && go_down == false)
		{
			Spieler.Gehe_Hoch();
			Spieler.Draw_Snake();

			go_up    = true;
			go_down  = false;
			go_right = false;
			go_left  = false;

		}
		else if (GetAsyncKeyState(VK_DOWN) && go_down == false && go_up == false)
		{
			Spieler.Gehe_Runter();
			Spieler.Draw_Snake();

			go_up    = false;
			go_down  = true;
			go_right = false;
			go_left  = false;
		}
		else if (GetAsyncKeyState(VK_LEFT) && go_left == false && go_right == false)
		{
			Spieler.Gehe_Links();
			Spieler.Draw_Snake();

			go_up    = false;
			go_down  = false;
			go_right = false;
			go_left  = true;
		}
		else if (GetAsyncKeyState(VK_RIGHT) && go_right == false && go_left == false)
		{
			Spieler.Gehe_Rechts();
			Spieler.Draw_Snake();

			go_up    = false;
			go_down  = false;
			go_right = true;
			go_left  = false;
		}
		else if (go_up)
		{
			Spieler.Gehe_Hoch();
			Spieler.Draw_Snake();
		}
		else if (go_down)
		{
			Spieler.Gehe_Runter();
			Spieler.Draw_Snake();
		}
		else if (go_left)
		{
			Spieler.Gehe_Links();
			Spieler.Draw_Snake();
		}
		else if (go_right)
		{
			Spieler.Gehe_Rechts();
			Spieler.Draw_Snake();
		}


		if (Spieler.GetSnakePosX() == Essen.GetFutterXPos() && Spieler.GetSnakePosY() == Essen.GetFutterYPos())
		{
			Essen.RemoveFutter();

			if (go_down)
				Spieler.Add_Snake(0, 1, 0, 0);
			else if (go_up)
				Spieler.Add_Snake(1, 0, 0, 0);
			else if (go_right)
				Spieler.Add_Snake(0, 0, 1, 0);
			else if (go_left)
				Spieler.Add_Snake(0, 0, 0, 1);

			FensterMenu.increaseGamePoints();
			FensterMenu.DrawStatusMenu();
			FensterMenu.DrawGameMenu();

			Essen.initializeFutterPos(Spieler.GetSnakePosX(), Spieler.GetSnakePosY());
			Essen.DisplayFutter();
		}


		Sleep(170);
	}
	
	warten();
	std::cin.get();
}

void Startseite()
{
	std::string tastendruck = "Druecke eine Taste um das Spiel zu starten...";

	clrscr(BG_BLACK);
	textcolor(ic::FG_LIGHTGREEN);

	gotoxy(22, 2);
	std::cout << "pEscanor Snake Game Test";

	short GMIX = 10; 
	short GMIY = 9; 
	short GMAY = 18;
	short GMAX = 40;

	Snake_Player StartMenuSnake(GMIX, GMAX, GMIY, GMAY);
	StartMenuSnake.Add_Snake(1, 0, 0, 0);
	StartMenuSnake.Add_Snake(1, 0, 0, 0);
	StartMenuSnake.Add_Snake(1, 0, 0, 0);
	StartMenuSnake.Add_Snake(1, 0, 0, 0);
	StartMenuSnake.Add_Snake(1, 0, 0, 0);
	StartMenuSnake.Add_Snake(1, 0, 0, 0);
	StartMenuSnake.Add_Snake(1, 0, 0, 0);
	StartMenuSnake.Add_Snake(1, 0, 0, 0);
	StartMenuSnake.Add_Snake(1, 0, 0, 0);

	gotoxy(GMIX, 22);
	std::cout << tastendruck;

	textcolor(FG_LIGHTBLUE);

	while (true)
	{
		for (int i = GMIY; i != GMAY; ++i)
		{
			StartMenuSnake.Remove_Draw();
			StartMenuSnake.Gehe_Runter();
			StartMenuSnake.Draw_Snake();

			if (_kbhit()) // Nur wenn auch eine Taste gedrückt ist 
			{
				warten();
				return;
			}
			Sleep(20);
		}

		for (int i = GMIX; i != GMAX; ++i)
		{
			StartMenuSnake.Remove_Draw();
			StartMenuSnake.Gehe_Rechts();
			StartMenuSnake.Draw_Snake();

			if (_kbhit()) // Nur wenn auch eine Taste gedrückt ist 
			{
				warten();
				return;
			}

			Sleep(20);
		}

		for (int i = GMAY; i != GMIY; --i)
		{
			StartMenuSnake.Remove_Draw();
			StartMenuSnake.Gehe_Hoch();
			StartMenuSnake.Draw_Snake();

			if (_kbhit()) // Nur wenn auch eine Taste gedrückt ist 
			{
				warten();
				return;
			}
			Sleep(20);
		}

		for (int i = GMAX; i != GMIX; --i)
		{
			StartMenuSnake.Remove_Draw();
			StartMenuSnake.Gehe_Links();
			StartMenuSnake.Draw_Snake();

			if (_kbhit()) // Nur wenn auch eine Taste gedrückt ist 
			{
				warten();
				return;
			}
			Sleep(20);

		}


	}
}



#endif