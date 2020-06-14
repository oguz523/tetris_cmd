#pragma once
#include <stdint.h>
#include <vector>

#include <src/shape/Shape.h>

class Block
{
public:
    Shape_t * shape;
    uint16_t rotation; 
    std::vector<uint8_t> pos;
    uint8_t locked;

private:



public:
    Block(Shape_t * shape_t, uint16_t rotation_t, std::vector<uint8_t> pos_t);
    ~Block();

private:


};

