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

                    std::sort(border->begin(), border->end(), [first_node_border] (Node *node1, Node *node2) {
                        return compare_by_distance(first_node_border, node1, node2);
                    });
                }

                delete border; 
            }

        private:
            static bool compare_by_distance(Node *target, Node *node1, Node *node2)
            {
                int32_t node1_distance = 0;
                int32_t node2_distance = 0;

                for(size_t i = 0; i < node1->neighbors.size(); i++)
                {
                    if(node1->neighbors[i]->id == target->id)
                    {
                        node1_distance = node1->neighbors_distance[i];
                        break;
                    }
                }

                for(size_t i = 0; i < node2->neighbors.size(); i++)
                {
                    if(node2->neighbors[i]->id == target->id)
                    {
                        node2_distance = node2->neighbors_distance[i];
                        break;
                    }
                }

                return node1_distance < node2_distance;
            }
    };
}