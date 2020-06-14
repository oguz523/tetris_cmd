#include <stdint.h>

#include "shape/Shape.h"
#include "shapes.h"
#include <map>

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

const Shape_t g_z_left_shape (
	(uint8_t*) g_z_left_shape_mask,
	(uint8_t*) g_z_left_shape_size,
	{ SHAPE_GRID_W, SHAPE_GRID_H }
);

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

const Shape_t g_z_right_shape (
	(uint8_t*) g_z_right_shape_mask,
	(uint8_t*) g_z_right_shape_size,
	{ SHAPE_GRID_W, SHAPE_GRID_H }
);

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

const Shape_t g_t_shape (
	(uint8_t*) g_t_shape_mask,
	(uint8_t*) g_t_shape_size,
	{ SHAPE_GRID_W, SHAPE_GRID_H }
);

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

const Shape_t g_l_left_shape (
	(uint8_t*) g_l_left_shape_mask,
	(uint8_t*) g_l_left_shape_size,
	{ SHAPE_GRID_W, SHAPE_GRID_H }
);

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

const Shape_t g_l_right_shape (
	(uint8_t*) g_l_right_shape_mask,
	(uint8_t*) g_l_right_shape_size,
	{ SHAPE_GRID_W, SHAPE_GRID_H }
);

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

const Shape_t g_i_shape (
	(uint8_t*) g_i_shape_mask,
	(uint8_t*) g_i_shape_size,
	{ SHAPE_GRID_W, SHAPE_GRID_H }
);

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

const Shape_t g_square_shape (
	(uint8_t*) g_square_shape_mask,
	(uint8_t*) g_square_shape_size,
	{ SHAPE_GRID_W, SHAPE_GRID_H }
);

const std::vector<const Shape_t *> g_shapes_vector =
{ 
	&g_z_left_shape,
	&g_z_right_shape,
	&g_i_shape,
	&g_l_left_shape,
	&g_l_right_shape,
	&g_t_shape,
	&g_square_shape 
};