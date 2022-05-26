#ifndef UNDIRECTEDGRAPH_UNDIRECTEDGRAPH_TPP
#define UNDIRECTEDGRAPH_UNDIRECTEDGRAPH_TPP

#include "UndirectedGraph.hpp"
#include <algorithm>

/// Vertex
template<Printable T>
typename UndirectedGraph<T>::Vertex &UndirectedGraph<T>::Vertex::operator=(const Vertex &other) {
    id = other.id;
    adjacent = other.adj;
}

template<Printable T>
typename UndirectedGraph<T>::Vertex* UndirectedGraph<T>::Vertex::operator[](int index) const {
    return adjacent.at(index);
}

template<Printable T>
UndirectedGraph<T>::Vertex::operator std::string() const {
    std::string ret;

    ret += (std::string) id + ": ";

    for (auto& i : adjacent) {
        ret += (std::string) i->id + ' ';
    }

    return ret;
}

/// UndirectedGraph

template<Printable T>
UndirectedGraph<T>::UndirectedGraph(size_t v) : V(v), E(0), vertices(v) {}

template<Printable T>
void UndirectedGraph<T>::addEdge(const Vertex& v, Vertex* w) {
    std::find(vertices.begin(), vertices.end(), v)->adjacent.push_back(w);
    E++;
}

template<Printable T>
void UndirectedGraph<T>::addVertex(const T &uid) {
    vertices.push_back(Vertex(uid));
}

template<Printable T>
void UndirectedGraph<T>::addVertex(const T &uid, std::vector<Vertex *> adj_list) {
    vertices.push_back(Vertex(uid, adj_list));
}

template<Printable T>
auto UndirectedGraph<T>::adj(const Vertex &v) -> decltype(UndirectedGraph<T>::Vertex::adjacent) {
    return std::find(vertices.begin(), vertices.end(), v)->adjacent;
}

template<Printable T>
UndirectedGraph<T>::operator std::string() const {
    std::string ret;
    ret += std::to_string(V) + '\n';
    ret += std::to_string(E) + '\n';
}

#endif //UNDIRECTEDGRAPH_UNDIRECTEDGRAPH_TPP
