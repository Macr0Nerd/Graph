#ifndef GRAPH_TPP
#define GRAPH_TPP

#include "Graph.hpp"
#include <algorithm>

/// Vertex
template<Printable T>
bool Graph<T>::Vertex::operator==(const Vertex &other) const {
    return id == other.id;
}

template<Printable T>
bool Graph<T>::Vertex::operator==(const T &uid) const {
    return id == uid;
}

template<Printable T>
typename Graph<T>::Vertex &Graph<T>::Vertex::operator=(const Vertex &other) {
    id = other.id;
    adjacent = other.adj;
}

template<Printable T>
typename Graph<T>::Vertex* Graph<T>::Vertex::operator[](int index) const {
    return adjacent.at(index);
}

template<Printable T>
Graph<T>::Vertex::operator std::string() {
    std::string ret;

    ret += (std::string) id + ": ";

    for (auto& i : adjacent) {
        ret += (std::string) i->id + ' ';
    }

    return ret;
}

/// Graph
template<Printable T>
Graph<T>::Graph(bool digraph) : V(0), E(0), vertices(), directed(digraph) {}

template<Printable T>
Graph<T>::Graph(int v, bool digraph) : V(v), E(0), vertices(v), directed(digraph) {}

template<Printable T>
bool Graph<T>::addEdge(const Vertex& v, Vertex* w) {
    Vertex* res = getVertex(v);

    if (res != nullptr) {
        res->adjacent.push_back(w);
        E++;

        if (!directed) {
            w->adjacent.push_back(&(*res));
        }

        return true;
    }

    return false;
}

template<Printable T>
bool Graph<T>::addVertex(const T &uid) {
    if (getVertex(uid) == nullptr) {
        vertices.push_back(Vertex(uid));
        V++;
        return true;
    }

    return false;
}

template<Printable T>
bool Graph<T>::addVertex(const T &uid, std::vector<Vertex *> adj_list) {
    if (getVertex(uid) == nullptr) {
        vertices.push_back(Vertex(uid, adj_list));
        V++;
        return true;
    }

    return false;
}

template<Printable T>
auto Graph<T>::adj(const Vertex &v) -> decltype(Graph<T>::Vertex::adjacent) {
    return getVertex(v)->adjacent;
}

template<Printable T>
Graph<T>::operator std::string() {
    std::string ret;
    ret += "Vertices: " + std::to_string(V) + '\n';
    ret += "Edges: " + std::to_string(E) + '\n';

    for (Vertex& i : vertices) {
        ret += (std::string)i + '\n';
    }

    return ret;
}

template<Printable T>
typename Graph<T>::Vertex* Graph<T>::getVertex(const T &uid) {
    auto res = std::find(vertices.begin(), vertices.end(), uid);
    if (res == vertices.end()) return nullptr;

    return &(*res);
}

template<Printable T>
typename Graph<T>::Vertex* Graph<T>::getVertex(const Vertex &v) {
    auto res = std::find(vertices.begin(), vertices.end(), v);
    if (res == vertices.end()) return nullptr;

    return &(*res);
}

template<Printable T>
Graph<T> Graph<T>::reverse() {
    Graph ret = Graph<T>(directed);

    for (Vertex& i : vertices) {
        ret.addVertex(i.id);
    }

    for (Vertex& i : vertices) {
        for (Vertex* j : i.adjacent) {
            ret.addEdge(*ret.getVertex(j->id), ret.getVertex(i.id));
        }
    }

    return ret;
}

#endif //GRAPH_TPP
