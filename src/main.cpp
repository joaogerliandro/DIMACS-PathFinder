#include <common.h>
#include <entities.h>
#include <util.h>

void dfs_algorithm(Entities::Node *root, int64_t key)
{
    
}

int main()
{
    Util::GraphLoader graph_loader;

    Entities::Node *map_graph = nullptr;

    graph_loader.load_graph(std::string("USA-road-d.NY"));

    map_graph = &graph_loader.graph_nodes[0];

    dfs_algorithm(map_graph, 4);

    return EXIT_SUCCESS;
}