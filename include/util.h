#pragma once

#include <common.h>
#include <entities.h>

namespace Util
{
    class GraphLoader
    {
        public:
            std::vector<Entities::Node> graph_nodes;

            void load_graph(std::string file_name);

        private:
            void load_graph_coordinates(std::string_view file_name);

            void read_graph_coordinates(std::fstream &coordinates_file);

            void load_graph_distances(std::string_view file_name);

            void read_graph_distances(std::fstream &coordinates_file);
    };
}