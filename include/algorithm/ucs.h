#pragma once

#include <entities.h>
#include <util.h>

using namespace Entities;

namespace Algorithm
{
    class UCS
    {
        public:
            static void ucs_algorithm(Node *first_node, Node *last_node)
            {
                auto start_time = std::chrono::high_resolution_clock::now();

                std::vector<Node *> *border = new std::vector<Node *>;

                first_node->color = GREY;

                border->push_back(first_node);

                bool found = false;
                
                while (!(border->empty()))
                {
                    auto current_time = std::chrono::high_resolution_clock::now();
                    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time);

                    if(((elapsed_time.count() / 1000) / 60) >= 5)
                    {
                        std::cout << "[UCS]: Not Found !" << std::endl;
                        std::cout << "[UCS]: Elapsed Time: " << ((elapsed_time.count() / 1000) / 60)
                                  << " minutes and " << ((elapsed_time.count() / 1000) & 60) << " seconds "<< (elapsed_time.count() % 1000) << " milliseconds !" << std::endl;
                        break;
                    }

                    if((*border)[0]->id == last_node->id)
                    {
                        std::cout << "[UCS]: Found !" << std::endl;
                        auto end_time = std::chrono::high_resolution_clock::now();
                        elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
                        std::cout << "[UCS]: Elapsed Time: " << ((elapsed_time.count() / 1000) / 60)
                                  << " minutes and " << ((elapsed_time.count() / 1000) & 60) << " seconds "<< (elapsed_time.count() % 1000) << " milliseconds !" << std::endl;
                        break;
                    }

                    Node *first_node_border = (*border)[0];

                    border->erase(border->begin());

                    for(Node *other_node : first_node_border->neighbors)
                    {
                        found = other_node->id == last_node->id ? true : false;

                        if(other_node->color == WHITE)
                        {
                            other_node->color = GREY;
                            border->push_back(other_node);
                        }

                        if(found)
                            break;
                    }

                    if(border->back()->id == first_node_border->neighbors.back()->id)
                        first_node_border->color = BLACK;

                    if(found)
                    {
                        std::cout << "[UCS]: Found !" << std::endl;
                        auto end_time = std::chrono::high_resolution_clock::now();
                        elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
                        std::cout << "[UCS]: Elapsed Time: " << ((elapsed_time.count() / 1000) / 60)
                                  << " minutes and " << ((elapsed_time.count() / 1000) & 60) << " seconds "<< (elapsed_time.count() % 1000) << " milliseconds !" << std::endl;
                        break;
                    }

                    Util::Sort::sort_by_distance(border, first_node_border);
                }

                delete border; 
            }
    };
}