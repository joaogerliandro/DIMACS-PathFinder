#include <common.h>
#include <entities.h>
#include <util.h>

#include <algorithms.h>

int main()
{
    Util::GraphHandle graph_loader;

    Entities::Node *first_node = nullptr;
    Entities::Node *last_node = nullptr;

    std::srand(time(NULL));

    try
    {
        graph_loader.load_graph(std::string("USA-road-d.NY"));

        for (uint32_t i = 0; i < 50; i++)
        {
            std::cout << "========== #" << i + 1 << " ==========" << std::endl;

            uint32_t first_point = (std::rand() % graph_loader.graph_size) + 1;
            uint32_t last_point = (std::rand() % graph_loader.graph_size) + 1;

            first_node = graph_loader.get_node(first_point);
            last_node = graph_loader.get_node(last_point);

            std::cout << "First Point: (" << first_node->coordinate.longitude << ", " << first_node->coordinate.latitude << ")" << std::endl;
            std::cout << "Last Point: (" << last_node->coordinate.longitude << ", " << last_node->coordinate.latitude << ")" << std::endl;

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
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return EXIT_SUCCESS;
}