#pragma once

#include <entities.h>

using namespace Entities;

namespace Algorithm
{
    class ASTAR
    {
        public:
            static void astar_algorithm(Node *first_node, uint64_t last_value)
            {
                std::vector<Node *> *open_nodes = new std::vector<Node *>;
                std::vector<Node *> *closed_nodes = new std::vector<Node *>;

                first_node->color = GREY;

                open_nodes->push_back(first_node);

                bool found = false;
                
                while (!(open_nodes->empty()))
                {
                    
                }

                delete open_nodes; 
            }
    };
}