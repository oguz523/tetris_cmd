#pragma once

#include <stdint.h>

#define SHAPE_GRID_W	4
#define SHAPE_GRID_H	4
#define SHAPE_DIM		SHAPE_GRID_W * SHAPE_GRID_H

// Z Left - Shape
extern const uint8_t g_z_left_shape_mask[SHAPE_GRID_W][SHAPE_GRID_H];
extern const uint8_t g_z_left_shape_size[];

// Z Right- Shape

extern const uint8_t g_z_right_shape_mask[SHAPE_GRID_W][SHAPE_GRID_H];
extern const uint8_t g_z_right_shape_size[];

// T - Shape
//
extern const uint8_t g_t_shape_mask[SHAPE_GRID_W][SHAPE_GRID_H];
extern const uint8_t g_t_shape_size[];

// L Left - Shape
//
extern const uint8_t g_l_left_shape_mask[SHAPE_GRID_W][SHAPE_GRID_H];
extern const uint8_t g_l_left_shape_size[];

// L Right - Shape
//
extern const uint8_t g_l_right_shape_mask[SHAPE_GRID_W][SHAPE_GRID_H];
extern const uint8_t g_l_right_shape_size[];

// I - Shape
//
extern const uint8_t g_l_right_shape_mask[SHAPE_GRID_W][SHAPE_GRID_H];
extern const uint8_t g_l_right_shape_size[];

// Square - Shape
//
extern const uint8_t g_square_shape_mask[SHAPE_GRID_W][SHAPE_GRID_H];
extern const uint8_t g_square_shape_size[];

extern const std::vector<const Shape_t*> g_shapes_vector;