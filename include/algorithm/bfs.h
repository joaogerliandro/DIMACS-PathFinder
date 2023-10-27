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
                std::vector<Node *> *fifo_vec = new std::vector<Node *>;

                first_node->color = GREY;

                fifo_vec->push_back(first_node);

                bool found = false;
                
                while (!(fifo_vec->empty()))
                {
                    if((*fifo_vec)[0]->id == last_node->id)
                    {
                        std::cout << "Encontrou !" << std::endl;
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
                        std::cout << "Encontrou !" << std::endl;
                        break;
                    }
                }

                delete fifo_vec; 
            }
    };
}