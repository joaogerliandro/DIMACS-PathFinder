#pragma once

#include <entities.h>
#include <util.h>

using namespace Entities;

namespace Algorithm
{
    class ASTAR
    {
        public:
            static void astar_algorithm(Node *first_node, Node * last_node)
            {
                auto start_time = std::chrono::high_resolution_clock::now();

                std::vector<Node *> *open_nodes = new std::vector<Node *>;
                std::vector<Node *> *closed_nodes = new std::vector<Node *>;

                first_node->cost = 0;
                first_node->heuristic = estimate_heuristic(first_node, last_node);
                first_node->f_score = first_node->cost + first_node->heuristic;

                open_nodes->push_back(first_node);

                bool found = false;
                
                while (!(open_nodes->empty()))
                {
                    auto current_time = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - start_time);

                    if(current_time.count() >= 5)
                    {
                        std::cout << "[ASTAR]: Not Found !" << std::endl;
                        std::cout << "[ASTAR]: Elapsed Time: " << (int32_t) (current_time.count() / 60) 
                                  << " minutes and " << (int32_t) (current_time.count() % 60) << " seconds !" << std::endl;
                        break;
                    }

                    Node* current_node = find_node_with_lowest_f_score(open_nodes);

                    if (current_node->id == last_node->id) 
                    {
                        std::cout << "[ASTAR]: Found !" << std::endl;
                        auto end_time = std::chrono::high_resolution_clock::now();
                        auto elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
                        std::cout << "[ASTAR]: Elapsed Time: " << (int32_t) (elapsed_time.count() / 60) 
                                  << " minutes and " << (int32_t) (elapsed_time.count() % 60) << " seconds !" << std::endl;
                        break;
                    }

                    open_nodes->erase(std::remove(open_nodes->begin(), open_nodes->end(), current_node), open_nodes->end());
                    closed_nodes->push_back(current_node);

                    for(Node *other_node : current_node->neighbors)
                    {
                        if (std::find(closed_nodes->begin(), closed_nodes->end(), other_node) != closed_nodes->end()) 
                            continue; // Se tiver na lista de fechados, continua

                        int32_t tentative_g_score = current_node->cost + cost_between(current_node, other_node);

                        if (std::find(open_nodes->begin(), open_nodes->end(), other_node) == open_nodes->end() || tentative_g_score < other_node->cost)
                        {
                            other_node->cost = tentative_g_score;
                            other_node->heuristic = estimate_heuristic(other_node, last_node);
                            other_node->f_score = other_node->cost + other_node->heuristic;
                            other_node->parent = current_node;

                            if (std::find(open_nodes->begin(), open_nodes->end(), other_node) == open_nodes->end()) {
                                open_nodes->push_back(other_node);
                            }
                        }
                    }

                    Util::Sort::sort_by_f_score(open_nodes);
                }

                delete open_nodes; 
                delete closed_nodes; 
            }

        private:
            static int32_t estimate_heuristic(Node* node1, Node* node2) 
            {
                int32_t dx = abs(node1->coordinate.longitude - node2->coordinate.longitude);
                int32_t dy = abs(node1->coordinate.latitude - node2->coordinate.latitude);

                return static_cast<int32_t>(std::sqrt(dx * dx + dy * dy));
            }

            static int32_t cost_between(Node* node1, Node* node2) 
            {
                for (size_t i = 0; i < node1->neighbors.size(); i++) {
                    if (node1->neighbors[i]->id == node2->id)
                        return node1->neighbors_distance[i];
                }

                return estimate_heuristic(node1, node2);
            }

            static Node* find_node_with_lowest_f_score(std::vector<Node *> *open_nodes)
            {
                if (open_nodes->empty()) 
                {
                    return nullptr;
                }

                Node* lowest_f_score_node = (*open_nodes)[0];
                int32_t lowest_f_score = lowest_f_score_node->f_score;

                for (Node* node : *open_nodes) 
                {
                    if (node->f_score < lowest_f_score) 
                    {
                        lowest_f_score_node = node;
                        lowest_f_score = node->f_score;
                    }
                }

                return lowest_f_score_node;
            }
    };
}