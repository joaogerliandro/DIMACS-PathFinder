#pragma once

#include <entities.h>

using namespace Entities;

namespace Algorithm
{
    class BFS
    {
        public:
            static void bfs_algorithm(Node *first_node, Node *last_node)
            {
                auto start_time = std::chrono::high_resolution_clock::now();

                std::vector<Node *> *fifo_vec = new std::vector<Node *>;

                first_node->color = GREY;

                fifo_vec->push_back(first_node);

                bool found = false;
                
                while (!(fifo_vec->empty()))
                {
                    auto current_time = std::chrono::high_resolution_clock::now();
                    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time);

                    if(((elapsed_time.count() / 1000) / 60) >= 5)
                    {
                        std::cout << "[BFS]: Not Found !" << std::endl;
                        std::cout << "[BFS]: Elapsed Time: " << ((elapsed_time.count() / 1000) / 60)
                                  << " minutes and " << ((elapsed_time.count() / 1000) & 60) << " seconds "<< (elapsed_time.count() % 1000) << " milliseconds !" << std::endl;
                        break;
                    }

                    if((*fifo_vec)[0]->id == last_node->id)
                    {
                        std::cout << "[BFS]: Found !" << std::endl;
                        auto end_time = std::chrono::high_resolution_clock::now();
                        elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
                        std::cout << "[BFS]: Elapsed Time: " << ((elapsed_time.count() / 1000) / 60)
                                  << " minutes and " << ((elapsed_time.count() / 1000) & 60) << " seconds "<< (elapsed_time.count() % 1000) << " milliseconds !" << std::endl;
                        break;
                    }

                    Node *first_node_fifo = (*fifo_vec)[0];

                    fifo_vec->erase(fifo_vec->begin());

                    for(Node *other_node : first_node_fifo->neighbors)
                    {
                        found = other_node->id == last_node->id ? true : false;

                        if(other_node->color == WHITE)
                        {
                            other_node->color = GREY;
                            fifo_vec->push_back(other_node);
                        }

                        if(found)
                            break;
                    }

                    if(fifo_vec->back()->id == first_node_fifo->neighbors.back()->id)
                        first_node_fifo->color = BLACK;

                    if(found)
                    {
                        std::cout << "[BFS]: Found !" << std::endl;
                        auto end_time = std::chrono::high_resolution_clock::now();
                        elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
                        std::cout << "[BFS]: Elapsed Time: " << ((elapsed_time.count() / 1000) / 60)
                                  << " minutes and " << ((elapsed_time.count() / 1000) & 60) << " seconds "<< (elapsed_time.count() % 1000) << " milliseconds !" << std::endl;
                        break;
                    }
                }

                delete fifo_vec; 
            }
    };
}