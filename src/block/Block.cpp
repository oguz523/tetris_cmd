#include "Block.h"

Block::Block(Shape_t* shape_t, uint16_t rotation_t, std::vector<uint8_t> pos_t)
    :shape(shape_t), rotation(rotation_t), pos(pos_t), locked(0)
{
}

Block::~Block()
{
}
