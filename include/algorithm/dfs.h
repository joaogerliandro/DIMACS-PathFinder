#pragma once

#include <entities.h>

using namespace Entities;

namespace Algorithm
{
    class DFS
    {
        public:
            static void dfs_algorithm(Node *first_node, Node *last_node)
            {
                for (Node *node : first_node->neighbors)
                {
                    if(node->color == WHITE)
                    {
                        bool found = dfs_visit(node, last_node);

                        if(found)
                        {
                            std::cout << "[DFS]: Encontrou !" << std::endl;
                            break;
                        }
                    }
                }
            }

            static bool dfs_visit(Node *node, Node *last_node)
            {
                bool found = false;

                node->color = GREY;

                if(node->id == last_node->id)
                    return true;

                for (Node *other_node : node->neighbors)
                {
                    if(other_node->color == WHITE)
                    {
                        found = dfs_visit(other_node, last_node);
                        
                        if(found)
                            break;
                    }
                }

                node->color = BLACK;
                return found;
            }
    };
}