#include <entities/node.h>

namespace Entities
{
    Node::Node()
    {
        neighbors = new std::vector<Entities::Node>;
        neighbors_distance = new std::vector<int32_t>;
    }

    Node::~Node()
    {

    }
}