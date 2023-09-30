#include <util.h>

namespace Util
{
    void GraphLoader::load_graph(std::string file_name)
    {
        load_graph_coordinates(file_name + ".co");

        load_graph_distances(file_name + ".gr");
    }

    void GraphLoader::load_graph_coordinates(std::string_view file_name)
    {
        std::fstream coordinates_file(file_name.data());

        if (!coordinates_file.is_open())
        {
            throw "[ERROR]: Unable to open tue file ! Leaving the program ...";
        }
        else
            read_graph_coordinates(coordinates_file);
    }

    void GraphLoader::read_graph_coordinates(std::fstream &coordinates_file)
    {
        for (std::string file_line; std::getline(coordinates_file, file_line);)
        {
            if (file_line.empty())
                continue;

            size_t index{file_line.find_first_of(' ')};

            std::string_view line_view = file_line;

            std::string_view prefix = line_view.substr(0, index);

            std::string_view target = line_view.substr(index);

            std::istringstream stream{target.data()};

            if (prefix == "c" || prefix == "p")
                continue;
            else if (prefix == "v")
            {
                Entities::Node new_node;

                if (stream >> new_node.id >> new_node.coordinate.longitude >> new_node.coordinate.latitude)
                    graph_nodes.push_back(new_node);

                stream.ignore('\n');
            }
        }
    }

    void GraphLoader::load_graph_distances(std::string_view file_name)
    {
        std::fstream coordinates_file(file_name.data());

        if (!coordinates_file.is_open())
        {
            throw "[ERROR]: Unable to open tue file ! Leaving the program ...";
        }
        else
            read_graph_distances(coordinates_file);
    }

    void GraphLoader::read_graph_distances(std::fstream &coordinates_file)
    {
        std::string file_line;
        std::string line_content;
        std::string prefix;

        std::stringstream str_stream;

        while (std::getline(coordinates_file, file_line))
        {
            if (file_line.empty())
                continue;

            size_t index{file_line.find_first_of(' ')};

            std::string_view line_view = file_line;

            std::string_view prefix = line_view.substr(0, index);

            std::string_view target = line_view.substr(index);

            std::istringstream stream{target.data()};

            if (prefix == "c" || prefix == "p")
                continue;
            else if (prefix == "a")
            {
                int64_t resident;
                int64_t neighbor;
                int32_t distance;

                if (stream >> resident >> neighbor >> distance)
                {
                    graph_nodes[resident - 1].neighbors.push_back(graph_nodes[neighbor - 1]);
                    graph_nodes[resident - 1].neighbors_distance.push_back(distance);
                }
            }
        }
    }
}