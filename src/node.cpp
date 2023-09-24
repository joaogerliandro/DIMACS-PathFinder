#include <entities/node.h>

namespace Entities
{
    void Node::to_string()
    {
        std::cout << "Value: " << this->value;
    }
}