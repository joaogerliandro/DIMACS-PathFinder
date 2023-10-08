#pragma once

#include <entities.h>

using namespace Entities;

namespace Algorithm
{
    class DFS
    {
        public:
            static void dfs_algorithm(Node *first_node, uint64_t last_value)
            {
                for (Node *node : first_node->neighbors)
                {
                    if(node->color == WHITE)
                    {
                        bool found = dfs_visit(node, last_value);

                        if(found)
                        {
                            std::cout << "Encontrado !" << std::endl;
                            break;
                        }
                    }
                }
            }

            static bool dfs_visit(Node *node, uint64_t last_value)
            {
                bool found = false;

                node->color = GREY;

                if(node->id == last_value)
                    return true;

                for (Node *other_node : node->neighbors)
                {
                    if(other_node->color == WHITE)
                    {
                        found = dfs_visit(other_node, last_value);
                        
                        if(found)
                            break;
                    }
                }

                node->color = BLACK;
                return found;
            }
    };
}