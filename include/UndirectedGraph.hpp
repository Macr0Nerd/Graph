#ifndef UNDIRECTEDGRAPH_UNDIRECTEDGRAPH_HPP
#define UNDIRECTEDGRAPH_UNDIRECTEDGRAPH_HPP

#include <vector>
#include <map>
#include <iostream>

struct UndirectedGraph {
    int V;
    int E;

    struct Vertex {
        std::vector<Vertex*> adj;

        bool operator==(const Vertex& other) const = default;
    };

    std::vector<Vertex> vertices;

    UndirectedGraph() = default;
    UndirectedGraph(int v);

    void addEdge(const Vertex& v, Vertex* w);
    std::vector<Vertex*> adj(const Vertex& v);
};

#endif //UNDIRECTEDGRAPH_UNDIRECTEDGRAPH_HPP
