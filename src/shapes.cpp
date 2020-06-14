#include <stdint.h>

#include "shape/Shape.h"
#include "shapes.h"

// Z Left - Shape
//
//template <typename T=uint8_t>
const uint8_t g_z_left_shape_mask[SHAPE_GRID_W][SHAPE_GRID_H] =
{
	{ 1,0,0,0 },
	{ 1,1,0,0 },
	{ 0,1,0,0 },
	{ 0,0,0,0 } 
};
const uint8_t g_z_left_shape_size[] = { 2, 3 };

// Z Right - Shape
//
const uint8_t g_z_right_shape_mask[SHAPE_GRID_W][SHAPE_GRID_H] =
{
	{ 0,1,0,0 },
	{ 1,1,0,0 },
	{ 1,0,0,0 },
	{ 0,0,0,0 }
};
const uint8_t g_z_right_shape_size[] = { 2, 3 };


// T - Shape
//
const uint8_t g_t_shape_mask[SHAPE_GRID_W][SHAPE_GRID_H] =
{
	{ 0,1,0,0 },
	{ 1,1,1,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 }
};
const uint8_t g_t_shape_size[] = { 3, 2 };

// L Left - Shape
//
const uint8_t g_l_left_shape_mask[SHAPE_GRID_W][SHAPE_GRID_H] =
{
	{ 1,1,0,0 },
	{ 1,0,0,0 },
	{ 1,0,0,0 },
	{ 0,0,0,0 }
};
const uint8_t g_l_left_shape_size[] = { 2, 3 };

// L Right - Shape
//
const uint8_t g_l_right_shape_mask[SHAPE_GRID_W][SHAPE_GRID_H] =
{
	{ 1,1,0,0 },
	{ 0,1,0,0 },
	{ 0,1,0,0 },
	{ 0,0,0,0 }
};
const uint8_t g_l_right_shape_size[] = { 2, 3 };

// I - Shape
//
const uint8_t g_i_shape_mask[SHAPE_GRID_W][SHAPE_GRID_H] =
{
	{ 1,1,1,1 },
	{ 0,0,0,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 }
};
const uint8_t g_i_shape_size[] = { 4, 1 };

// Square - Shape
//
const uint8_t g_square_shape_mask[SHAPE_GRID_W][SHAPE_GRID_H] =
{
	{ 1,1,0,0 },
	{ 1,1,0,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 }
};
const uint8_t g_square_shape_size[] = { 2, 2 };

