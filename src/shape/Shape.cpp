#include <string.h>
#include <stdlib.h>
#include <vector>

#include "Shape.h"

Shape_t::Shape_t(uint8_t* mask_t, uint8_t* size_t, std::vector<uint8_t> palette_size_t)

:mask(mask_t), size({ size_t[0], size_t[1] }), palette_size({ palette_size_t[0], palette_size_t[1] })
{
	
	std::vector<uint8_t> center_point = {
		(uint8_t) (this->get_size()[0] / 2),
		(uint8_t) (this->get_size()[1] / 2) 
	};
	std::vector<std::vector<uint8_t>> mass_points;

	std::vector<int8_t> diff_center = { 0,0 };
	std::vector<int8_t> diff_zero = { 0, 0 };

	for (int8_t i = 0; i < this->palette_size[1]; i++)
	{
		for (int8_t j = 0; j < this->palette_size[0]; j++)
		{
			if (this->mask[(i * this->palette_size[0]) + j])
			{
				int8_t diff_curr_x = (j - (int8_t)center_point[0]);
				if (diff_curr_x == 0)
				{
					diff_zero[0]++;
				}
				else
				{
					diff_center[0] += diff_curr_x;
				}

				int8_t diff_curr_y = i - center_point[0];
				if (diff_curr_y == 0)
				{
					diff_zero[1]++;
				}
				else
				{
					diff_center[1] += diff_curr_y;
				}
			}
		}
	}

	uint8_t x_symmetric = 0;
	if (diff_zero[0] < abs(diff_center[0]))
	{
		if (diff_center[0] > 0)
			center_point[0]++;
		else
			center_point[0]--;
	}
	else if (diff_zero[0] == abs(diff_center[0]))
	{
		x_symmetric = 1;
	}

	uint8_t y_symmetric = 0;
	if (diff_zero[1] < abs(diff_center[1]))
	{
		if (diff_center[1] > 0)
			center_point[1]++;
		else
			center_point[1]--;
	}
	else if (diff_zero[1] == abs(diff_center[1]))
	{
		y_symmetric = 1;
	}

	center = { center_point[0], center_point[1] };

	if ((size[0] == size[1]) && (x_symmetric && y_symmetric))
	{
		is_full_symmetric = 1;
	}
	else
	{
		is_full_symmetric = 0;
	}
		//memcpy(&mask, (const void *)mask_t, SHAPE_DIM);
}

Shape_t::~Shape_t()
{
}

std::vector<uint8_t> Shape_t::get_size()
{
	return size;
}
