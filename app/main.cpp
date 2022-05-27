#include "Graph.hpp"
#include <iostream>
#include <string>

int main() {
    Graph test = Graph<std::string>(true);

    test.addVertex("1");
    std::cout << (std::string)test << std::endl;
    test.addVertex("2");
    std::cout << (std::string)test << std::endl;
    test.addVertex("1");
    test.addEdge(test.vertices[0], &test.vertices[1]);
    std::cout << (std::string)test << std::endl;
    std::cout << (std::string)test.reverse() << std::endl;

    return 0;
}
