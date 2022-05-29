#ifndef GRAPH_TPP
#define GRAPH_TPP

#include "Graph.hpp"
#include <algorithm>

/// Vertex
template<typename T>
bool Graph<T>::Vertex::operator==(const Vertex &other) const {
    return id == other.id;
}

template<typename T>
bool Graph<T>::Vertex::operator==(const T &uid) const {
    return id == uid;
}

template<typename T>
typename Graph<T>::Vertex &Graph<T>::Vertex::operator=(const Vertex &other) {
    id = other.id;
    adjacent = other.adj;
}

template<typename T>
typename Graph<T>::Vertex* Graph<T>::Vertex::operator[](int index) const {
    return adjacent.at(index);
}

template<typename T>
std::ostream& Graph<T>::Vertex::streamInsertion(std::ostream &os) const {
    os << id << ": ";
    for (auto& i : adjacent) {
        os << i->id << ' ';
    }

    return os;
}

/// Graph
template<typename T>
Graph<T>::Graph(bool digraph) : V(0), E(0), vertices(), directed(digraph) {}

template<typename T>
Graph<T>::Graph(int v, bool digraph) : V(v), E(0), vertices(v), directed(digraph) {}

template<typename T>
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

template<typename T>
bool Graph<T>::addVertex(const T &uid) {
    if (getVertex(uid) == nullptr) {
        vertices.push_back(Vertex(uid));
        V++;
        return true;
    }

    return false;
}

template<typename T>
bool Graph<T>::addVertex(const T &uid, std::vector<Vertex *> adj_list) {
    if (getVertex(uid) == nullptr) {
        vertices.push_back(Vertex(uid, adj_list));
        V++;
        return true;
    }

    return false;
}

template<typename T>
auto Graph<T>::adj(const Vertex &v) -> decltype(Graph<T>::Vertex::adjacent) {
    return getVertex(v)->adjacent;
}

template<typename Y>
std::ostream& operator<<(std::ostream& os, const Graph<Y>& obj) {
    os << "Vertices: " << obj.V << std::endl;
    os << "Edges: " << obj.E << std::endl;

    for (typename Graph<Y>::Vertex i : obj.vertices) {
        os << i << std::endl;
    }

    return os;
}

template<typename T>
typename Graph<T>::Vertex* Graph<T>::getVertex(const T &uid) {
    auto res = std::find(vertices.begin(), vertices.end(), uid);
    if (res == vertices.end()) return nullptr;

    return &(*res);
}

template<typename T>
typename Graph<T>::Vertex* Graph<T>::getVertex(const Vertex &v) {
    auto res = std::find(vertices.begin(), vertices.end(), v);
    if (res == vertices.end()) return nullptr;

    return &(*res);
}

template<typename T>
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
