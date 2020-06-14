#include <string.h>
#include <stdlib.h>
#include <vector>

#include "Shape.h"

Shape_t::Shape_t(uint8_t * mask_t, uint16_t rotation_t, uint8_t * size_t, std::vector<uint8_t> pos_t)
:mask(mask_t), rotation(rotation_t), locked(0), pos(pos_t)
{
	size = {size_t[0], size_t[1]};
	//memcpy(&mask, (const void *)mask_t, SHAPE_DIM);
}

Shape_t::~Shape_t()
{
}

std::vector<uint8_t> Shape_t::get_size()
{
	return size;
}
