#include <common.h>
#include <entities.h>
#include <util.h>

Entities::Node* dfs(Entities::Node *root, int64_t key)
{
    // Search the start
}

void dfs_metrics(Entities::Node *root, int64_t key)
{
    // Calculate the metrics and print
}

Entities::Node* bfs(Entities::Node *root, int64_t key)
{
    // Search the start
}

void bfs_metrics(Entities::Node *root, int64_t key)
{
    // Calculate the metrics and print
}

int main()
{
    Util::GraphLoader graph_loader;

    Entities::Node *map_graph = nullptr;
    Entities::Node *start_node = nullptr;
    Entities::Node *end_node = nullptr;

    graph_loader.load_graph(std::string("USA-road-d.NY"));

    map_graph = &graph_loader.graph_nodes[0];

    start_node = dfs(map_graph, 4);
    dfs_metrics(start_node, 1);

    return EXIT_SUCCESS;
}