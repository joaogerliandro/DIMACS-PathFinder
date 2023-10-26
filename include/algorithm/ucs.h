#pragma once

#include <entities.h>
#include <util.h>

using namespace Entities;

namespace Algorithm
{
    class UCS
    {
        public:
            static void ucs_algorithm(Node *first_node, uint64_t last_value)
            {
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

                    if(border->back()->id == first_node_border->neighbors.back()->id)
                        first_node_border->color = BLACK;

                    if(found)
                    {
                        std::cout << "Encontrou !" << std::endl;
                        break;
                    }

                    Util::Sort::sort_by_distance(border, first_node_border);
                }

                delete border; 
            }
    };
}