#include <common.h>
#include <entities.h>
#include <util.h>

#include <algorithms.h>

int main()
{
    Util::GraphHandle graph_loader;

    Entities::Node *first_node = nullptr;
    Entities::Node *last_node = nullptr;
    
    try
    {
        graph_loader.load_graph(std::string("USA-road-d.NY"));

        Point first_point;
        Point last_point;

        while(true)
        {
            std::cout << "Enter the longitude of first Point: ";
            std::cin >> first_point.longitude;

            std::cout << "Enter the latitude of first Point: ";
            std::cin >> first_point.latitude;

            std::cout << "Enter the longitude of last Point: ";
            std::cin >> last_point.longitude;

            std::cout << "Enter the latitude of last Point: ";
            std::cin >> last_point.latitude;

            if(first_point == last_point)
            {
                std::cout << "[Error]: The point's no can't be equal !" << std::endl;
                continue;
            }

            first_node = graph_loader.get_node(first_point);

            if(first_node == nullptr)
            {
                std::cout << "[Error]: The first point was not found !" << std::endl;
                continue;
            }

            last_node = graph_loader.get_node(last_point);

            if(last_node == nullptr)
            {
                std::cout << "[Error]: The last point was not found !" << std::endl;
                continue;
            }

            break;
        }

        Algorithm::DFS::dfs_algorithm(first_node, last_node);

        graph_loader.expanded_nodes("[DFS]");

        graph_loader.expanded_ramification_factor("[DFS]");

        graph_loader.reset_nodes();

        Algorithm::BFS::bfs_algorithm(first_node, last_node);

        graph_loader.expanded_nodes("[BFS]");

        graph_loader.expanded_ramification_factor("[BFS]");

        graph_loader.reset_nodes();

        Algorithm::UCS::ucs_algorithm(first_node, last_node);
        
        graph_loader.expanded_nodes("[UCS]");

        graph_loader.expanded_ramification_factor("[UCS]");

        graph_loader.reset_nodes();

        Algorithm::ASTAR::astar_algorithm(first_node, last_node);

        graph_loader.expanded_nodes("[ASTAR]");

        graph_loader.expanded_ramification_factor("[ASTAR]");

        graph_loader.reset_nodes();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return EXIT_SUCCESS;
}