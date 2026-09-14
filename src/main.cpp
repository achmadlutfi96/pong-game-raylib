/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/

#include "raylib.h"

#include "resource_dir.h"	// utility header for SearchAndSetResourceDir

#include <iostream>

using namespace std;

class Ball {
	public:
		float x, y;
		int speed_x, speed_y;
		int radius;
	
		void Draw() {
			DrawCircle(x, y, radius, WHITE);
		}

		void Update() {
			x += speed_x;
			y += speed_y;

			if (y+radius >= GetScreenHeight() || y-radius <= 0 )
			{
				speed_y *= -1;
			}
			if (x+radius >= GetScreenWidth() || x-radius <= 0) {
				speed_x *= -1;
			}
		}
};

Ball ball;

int main ()
{
	cout << "Starting the game" << endl;
	const int screen_width = 1280;
	const int screen_height = 800;
	InitWindow(screen_width, screen_height, "My Pong Game!");
	SetTargetFPS(60);

	ball.radius = 20;
	ball.x = screen_width/2;
	ball.y = screen_height/2;
	ball.speed_x = 7;
	ball.speed_y = 7;

	while (WindowShouldClose() == false)
	{
		/* code */
		BeginDrawing();

		// Updating
		ball.Update();

		// Drawing
		ClearBackground(BLACK);
		DrawLine(screen_width/2, 0, screen_width/2, screen_height, WHITE);
		ball.Draw();
		DrawRectangle(10, screen_height/2-60, 25, 120, WHITE);
		DrawRectangle(screen_width - 35, screen_height/2-60, 25, 120, WHITE);

		EndDrawing();
	}
	
	

	CloseWindow();
	return 0;
}
