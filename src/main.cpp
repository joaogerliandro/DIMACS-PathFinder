#include <common.h>
#include <entities.h>
#include <util.h>

int main()
{
    Util::GraphLoader graph_loader;

    Entities::Node *map_graph = nullptr;

    graph_loader.load_graph(map_graph, std::string("USA-road-d.NY"));

    return EXIT_SUCCESS;
}