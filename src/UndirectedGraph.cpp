#include "UndirectedGraph.hpp"

#include <algorithm>
#include <string>

UndirectedGraph::UndirectedGraph(int v) : V(v), E(0), vertices() {}

void UndirectedGraph::addEdge(const Vertex& v, Vertex* w) {
    std::find(vertices.begin(), vertices.end(), v)->adj.push_back(w);
}

std::vector<UndirectedGraph::Vertex*> UndirectedGraph::adj(const Vertex& v) {
    return std::find(vertices.begin(), vertices.end(), v)->adj;
}