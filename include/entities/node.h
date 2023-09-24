#pragma once

#include <common.h>

namespace Entities
{
    class Node
    {
        public:
            int32_t value;
            Node *next;    
            Node *prev;

            Node() { };

            ~Node() { };

            void to_string();
    };
}
