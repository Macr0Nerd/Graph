#include "Graph.hpp"
#include <iostream>

int main() {
    Graph test = Graph<int>(true);

    test.addVertex(1);
    std::cout << test << std::endl;
    test.addVertex(2);
    std::cout << test << std::endl;
    test.addVertex(1);
    test.addEdge(test.vertices[0], &test.vertices[1]);
    std::cout << test << std::endl;
    std::cout << test.reverse() << std::endl;

    return 0;
}
