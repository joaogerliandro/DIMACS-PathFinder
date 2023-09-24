#include <common.h>
#include <entities.h>

int main()
{
    Entities::Node *test_node = new Entities::Node;

    test_node->value = 10; // Test value
    test_node->next = NULL; // Test next node
    test_node->prev = NULL;

    test_node->to_string();

    return EXIT_SUCCESS;
}