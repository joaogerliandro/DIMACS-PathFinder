#pragma once

#include <entities.h>

using namespace Entities;

namespace Algorithm
{
    class UCS
    {
        public:
            static void ucs_algorithm(Node *first_node, uint64_t last_value)
            {
                //A logica é a mesma do BFS quase
                std::vector<Node *> *border = new std::vector<Node *>;

                first_node->color = GREY;

                border->push_back(first_node);

                bool found = false;
                
                while (!(border->empty()))
                {
                    if((*border)[0]->id == last_value)
                    {
                        std::cout << "Encontrou !" << std::endl;
                        break;
                    }

                    Node *first_node_border = (*border)[0];

                    border->erase(border->begin());

                    for(Node *other_node : first_node_border->neighbors)
                    {
                        found = other_node->id == last_value ? true : false;

                        if(other_node->color == WHITE)
                        {
                            other_node->color = GREY;
                            border->push_back(other_node);
                        }

                        if(found)
                            break;
                    }

                    //antes de ir pro próximo no de border tem que ordenar pela distância do menor pro maior

                    if(border->back()->id == first_node_fifo->neighbors.back()->id)
                        first_node_fifo->color = BLACK;

                    if(found)
                    {
                        std::cout << "Encontrou !" << std::endl;
                        break;
                    }
                }

                delete border; 
            }
            }
    };
}