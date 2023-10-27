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

            int32_t cost;    
            int32_t heuristic; 
            int32_t f_score;
            Node* parent;
    
            Node()
            {
                color = WHITE;
                heuristic = 0;
                cost = std::numeric_limits<int32_t>::max();
                f_score = std::numeric_limits<int32_t>::max();
                parent = nullptr;
            }

            ~Node()
            {

            }

            void reset_node()
            {
                color = WHITE;
                heuristic = 0;
                cost = std::numeric_limits<int32_t>::max();
                f_score = std::numeric_limits<int32_t>::max();
                parent = nullptr;  
            }
    };
}
