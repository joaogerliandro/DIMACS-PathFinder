#pragma once

#include <common.h>
#include <entities.h>

namespace Util
{
    class GraphHandle
    {
        public:
            std::vector<Entities::Node *> graph_nodes;

            void load_graph(std::string file_name);

            Entities::Node* get_node(uint64_t key);
        private:
            void load_graph_coordinates(std::string_view file_name);

            void read_graph_coordinates(std::fstream &coordinates_file);

            void load_graph_distances(std::string_view file_name);

            void read_graph_distances(std::fstream &coordinates_file);
    };

    class Sort
    {
        public:
            static void sort_by_distance(std::vector<Entities::Node *> *nodes, Entities::Node *target);

            static void sort_by_f_score(std::vector<Entities::Node *> *nodes);

        private:
            static bool compare_by_distance(Entities::Node *target, Entities::Node *node1, Entities::Node *node2)
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