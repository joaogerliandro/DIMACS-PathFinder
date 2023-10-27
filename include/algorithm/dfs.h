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
                auto start_time = std::chrono::high_resolution_clock::now();

                for (Node *node : first_node->neighbors)
                {
                    auto current_time = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - start_time);

                    if(current_time.count() >= 5)
                    {
                        std::cout << "[DFS]: Not Found !" << std::endl;
                        std::cout << "[DFS]: Elapsed Time: " << (int32_t) (current_time.count() / 60) 
                                  << " minutes and " << (int32_t) (current_time.count() % 60) << " seconds !" << std::endl;
                        break;
                    }

                    if(node->color == WHITE)
                    {
                        bool found = dfs_visit(node, last_node);

                        if(found)
                        {
                            std::cout << "[DFS]: Found !" << std::endl;
                            auto end_time = std::chrono::high_resolution_clock::now();
                            auto elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
                            std::cout << "[DFS]: Elapsed Time: " << (int32_t) (elapsed_time.count() / 60) 
                                      << " minutes and " << (int32_t) (elapsed_time.count() % 60) << " seconds !" << std::endl;
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