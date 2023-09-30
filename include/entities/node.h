#pragma once

#include <common.h>
#include <entities/point.h>

namespace Entities
{
    class Node
    {
        public:
            Point coordinate;

            int64_t id;

            std::vector<Entities::Node> *neighbors;
            std::vector<int32_t> *neighbors_distance;

            Node();

            ~Node();
    };
}
