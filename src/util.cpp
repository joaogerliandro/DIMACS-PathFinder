#include <util.h>

namespace Util
{
    void GraphHandle::load_graph(std::string file_name)
    {
        load_graph_coordinates(file_name + ".co");

        load_graph_distances(file_name + ".gr");
    }

    void GraphHandle::load_graph_coordinates(std::string_view file_name)
    {
        std::fstream coordinates_file(file_name.data());

        if (!coordinates_file.is_open())
        {
            throw "[ERROR]: Unable to open tue file ! Leaving the program ...";
        }
        else
            read_graph_coordinates(coordinates_file);
    }

    void GraphHandle::read_graph_coordinates(std::fstream &coordinates_file)
    {
        uint32_t counter = 0;

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
                counter++;

                Entities::Node *new_node = new Entities::Node;

                if (stream >> new_node->id >> new_node->coordinate.longitude >> new_node->coordinate.latitude)
                    graph_nodes->push_back(new_node);

                stream.ignore('\n');
            }
        }

        std::cout << "Graph Node Size: " << graph_nodes->size() << std::endl;
    }

    void GraphHandle::load_graph_distances(std::string_view file_name)
    {
        std::fstream coordinates_file(file_name.data());

        if (!coordinates_file.is_open())
        {
            throw "[ERROR]: Unable to open tue file ! Leaving the program ...";
        }
        else
            read_graph_distances(coordinates_file);
    }

    void GraphHandle::read_graph_distances(std::fstream &coordinates_file)
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
                    (*graph_nodes)[resident - 1]->neighbors.push_back((*graph_nodes)[neighbor - 1]);
                    (*graph_nodes)[resident - 1]->neighbors_distance.push_back(distance);
                }
            }
        }
    }

    Entities::Node* GraphHandle::get_node(Entities::Point point)
    {
        Entities::Node *return_node = nullptr;

        for (Entities::Node *node : *graph_nodes)
        {
            if (node->coordinate == point)
            {
                return_node = node;
                break;
            }
        }

        return return_node;
    }

    void GraphHandle::reset_nodes()
    {
        for(Entities::Node *node : *graph_nodes)
        {
            node->reset_node();
        }
    }

    void GraphHandle::expanded_nodes(std::string log_prefix)
    {
        uint32_t count = 0;

        for(Entities::Node *node : *graph_nodes)
        {
            if(node->color == Entities::BLACK || node -> color == Entities::GREY)
                count++;
        }

        std::cout << log_prefix << ": Expanded Nodes: " << count << std::endl;
    }

    void GraphHandle::expanded_ramification_factor(std::string log_prefix)
    {
        uint32_t count = 0;
        uint32_t major = 0;

        for(Entities::Node *node : *graph_nodes)
        {
            for(Entities::Node *node_adj : node->neighbors){
                if(node_adj->color == Entities::BLACK || node_adj -> color == Entities::GREY)
                    count++;
            }

            if(major < count)
                major = count;

            count = 0;
        }

        std::cout << log_prefix << ": Ramification Factor Nodes: " << major << std::endl;
    }

    void Sort::sort_by_distance(std::vector<Entities::Node *> *nodes, Entities::Node *target)
    {
        std::sort(nodes->begin(), nodes->end(), [target] (Entities::Node *node1, Entities::Node *node2) 
        {
            return compare_by_distance(target, node1, node2);
        });
    }

    void Sort::sort_by_f_score(std::vector<Entities::Node *> *open_nodes)
    {
        std::sort(open_nodes->begin(), open_nodes->end(), [] (Entities::Node *node1, Entities::Node *node2) 
        {
            return node1->f_score < node2->f_score;
        });
    }
}