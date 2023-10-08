#pragma once

#include <common.h>
#include <entities/point.h>

namespace Entities
{
    enum COLOR
    {
        WHITE = 0,
        GREY = 1,
        BLACK = 2
    };

    class Node
    {
        public:
            Point coordinate;

            uint64_t id;

            uint8_t color;

            std::vector<Entities::Node *> neighbors;
            std::vector<int32_t> neighbors_distance;

            Node()
            {
                color = WHITE;
            }

            ~Node()
            {

            }

            void reset_color()
            {
                color = WHITE;   
            }
    };
}
