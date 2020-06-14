// tetris_cmd.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdint.h>
#include <iostream>
#include <string.h>
#include <ctime>
#include <vector>
#include <conio.h>
#include <thread>

#include <Windows.h>

#include "block/Block.h"
#include "shape/Shape.h"
#include "shapes.h"

#define GAME_FPS				60
#define WINDOW_REFRESH			1.0f / GAME_FPS

#define WINDOW_W				20
#define WINDOW_H				20
#define FRAME_THICKNESS			1

#define GAME_WINDOW_W	(WINDOW_W) - (2 *(FRAME_THICKNESS))
#define GAME_WINDOW_H	(WINDOW_H) - (2 *(FRAME_THICKNESS))

#define WINDOW_DIM   WINDOW_W * WINDOW_H

#define BLOCK_RENDERED		'#'
#define FRAME_RENDERER		0xDB    // █

#define DROP_INTERVAL		1000.0f

typedef uint8_t Window_t;


#define CAST(x, type)	((type)(x))

Window_t g_window[WINDOW_DIM] = { " " };

Shape_t * g_curr_shape;
std::vector<Block *>g_blocks_all;

template<typename F=Window_t, typename T=uint8_t, typename K=uint8_t>
void Draw_Frame(F * p_window, T window_w, T window_h, T frame_thickness, K frame_render)
{
	for (T h = 0; h < window_h; h++)
	{
		if ((h < FRAME_THICKNESS) || (h >= (window_h - FRAME_THICKNESS)))
		{
			for (T w = 0; w < window_w; w++)
			{
				p_window[(h * window_w) + w] = frame_render;
			}
		}
		else
		{
			for (T i = 0; i < FRAME_THICKNESS; i++)
				p_window[(h * window_w) + i] = frame_render;
	
			for (T i = (window_w - FRAME_THICKNESS); i < window_w; i++)
				p_window[(h * window_w) + i] = frame_render;
		}
	}
}

void Clear_Buffer()
{
	memset(g_window, ' ' , WINDOW_DIM);
}

void Clear_Screen()
{
	//std::cout << std::flush;
	system("CLS");
}

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

void Render_Shape(Window_t * p_window, Shape_t * p_shape)
{
	uint16_t shape_offset = (WINDOW_W * (p_shape->pos[1] + FRAME_THICKNESS)) +
		(p_shape->pos[0] + FRAME_THICKNESS);
	std::vector<uint8_t> shape_size = p_shape->get_size();

	uint16_t frame_point;
	for (int i = 0; i < SHAPE_GRID_H; i++)
	{
		for (int j = 0; j < SHAPE_GRID_W; j++)
		{
			frame_point = shape_offset + ((i * WINDOW_W) + j);
			if (p_shape->mask[(i * SHAPE_GRID_W) + j])
				p_window[frame_point] = BLOCK_RENDERED;
		}
	}
}

void Display_Window()
{
	for (int i = 0; i < WINDOW_H; i++)
	{
		for (int j = 0; j < WINDOW_W; j++)
		{
			std::cout << g_window[(i * WINDOW_W) + j];
		}
		std::cout << std::endl;
	}
}

void Detect_Key()
{
	while (1)
	{
		int a = _getch();
		if (!g_curr_shape->locked)
		switch (a)
		{
		case 'a':
			if (g_curr_shape->pos[0] > FRAME_THICKNESS - 1)
				g_curr_shape->pos[0]--;
			break;
		case 'd':
			if (g_curr_shape->pos[0] + g_curr_shape->get_size()[0] < (WINDOW_W - 1) - FRAME_THICKNESS)
				g_curr_shape->pos[0]++;
			break;
		case ' ':
			
			break;
		default:
			break;
		}
	}
}

/*
 * Detects a drop if the time interval is reached
 *
 *
 * 
 *
 * @return: 0, no drop
 *			1, block is dropped by 1 unit
 *			2, block hit bottom (no drops afterwards)
 */
uint8_t Detect_Drop(clock_t * p_time_ref, float_t time_interval, Shape_t * p_curr)
{
	uint8_t ans = 0;

	float_t time_diff = CAST(clock() - (*p_time_ref), float_t);

	if (time_diff >= time_interval)
	{
		if (p_curr->pos[1] + p_curr->get_size()[1] < (WINDOW_H - 1) - FRAME_THICKNESS)
		{
			p_curr->pos[1]++;
			ans = 1;
		}
		else
		{
			p_curr->locked = true;
			ans = 2;
		}

		*p_time_ref = clock();
	}

	return ans;
}

int main()
{
	//printf("\e[?25l");
	
	// Make it ifdefine PLATFORM IS WIN
	//
	ShowConsoleCursor(false);

	Clear_Screen();

	Shape_t z_left_shape(
		(uint8_t*) &g_z_left_shape_mask,
		0,
		(uint8_t*) g_z_left_shape_size,
		{ 0,0 }
	);

	g_blocks_all.push_back(new Block(&z_left_shape, 0, { 0,0 }));

	Shape_t z_right_shape(
		(uint8_t*) &g_z_right_shape_mask,
		0,
		(uint8_t*) g_z_right_shape_size,
		{0,0}
	);
	Shape_t t_shape(
		(uint8_t*)&g_t_shape_mask,
		0,
		(uint8_t*)g_t_shape_size,
		{0,0}
	);

	g_curr_shape = &t_shape;

	Draw_Frame<>(g_window, WINDOW_W, WINDOW_H, FRAME_THICKNESS, FRAME_RENDERER);
	Render_Shape(g_window, g_curr_shape);
	
	std::thread key_handle(Detect_Key);

	clock_t refresh_time;
	clock_t drop_time;

	refresh_time = clock();
	drop_time = clock();

	while (1)
	{

		// Game Logic
		//
		
		// Dropping Blocks one by one
		//
		uint8_t is_dropped;
		is_dropped = Detect_Drop(&drop_time, DROP_INTERVAL, g_curr_shape);
		if (is_dropped)
		{
			// Save the Window for future prints
			;
		}
		// TODO Game Logic: Collision Detection


		// Draw Frame and Shapes 
		//		TODO: Do not clear buffer everytime, only the 
		//			  affected areas.
		//
		Clear_Buffer();
		Draw_Frame<>(g_window, WINDOW_W, WINDOW_H, FRAME_THICKNESS, FRAME_RENDERER);
		Render_Shape(g_window, g_curr_shape);

		// FPS Based Screen Refresh
		//
		if ((CAST(clock() - refresh_time, float_t) / CLOCKS_PER_SEC) >= WINDOW_REFRESH);
		{
			//std::cout << clock() - refresh_time << std::endl;
			Clear_Screen();
			Display_Window();	
			refresh_time = clock();
		}
		//break;
	}
	getchar();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
