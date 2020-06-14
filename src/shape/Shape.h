#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <vector>

class Shape_t
{

public:
	uint8_t * mask;
	uint8_t locked;
	std::vector<uint8_t> pos;
private:
	uint16_t rotation;
	std::vector<uint8_t> size;

public:
	Shape_t(uint8_t* mask_t, uint16_t rotation_t, uint8_t* size_t, std::vector<uint8_t> pos_t);
	~Shape_t();
		
	std::vector<uint8_t> get_size();
};

