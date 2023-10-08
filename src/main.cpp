#include <common.h>
#include <entities.h>
#include <util.h>

#include <algorithm/dfs.h>
#include <algorithm/bfs.h>

int main()
{
    Util::GraphHandle graph_loader;

    Entities::Node *first_node = nullptr;
    
    try
    {
        graph_loader.load_graph(std::string("USA-road-d.NY"));

        uint64_t first_value = 1;
        uint64_t last_value = 6;

        if(first_value == last_value)
            throw new std::runtime_error("The values no can't be equal !");

        first_node = graph_loader.get_node(first_value);

        //Algorithm::DFS::dfs_algorithm(first_node, last_value);

        Algorithm::BFS::bfs_algorithm(first_node, last_value);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return EXIT_SUCCESS;
}