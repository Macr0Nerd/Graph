#ifndef UNDIRECTEDGRAPH_UNDIRECTEDGRAPH_HPP
#define UNDIRECTEDGRAPH_UNDIRECTEDGRAPH_HPP

#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <concepts>

template <typename T>
concept Printable = requires (T a) {
    std::string(a);
};

template <Printable T>
struct UndirectedGraph {
    int V{};
    int E{};

    struct Vertex {
        T id;
        std::vector<Vertex*> adjacent;

        Vertex() : adjacent(), id() {};
        explicit Vertex(T uid) : adjacent(), id(uid) {};
        Vertex(T uid, std::vector<Vertex*> adj_list) : adjacent(adj_list), id(uid) {};

        bool operator==(const Vertex& other) const = default;
        Vertex& operator=(const Vertex& other);
        Vertex* operator[](int index) const;
        explicit operator std::string() const;
    };

    std::vector<Vertex> vertices;

    UndirectedGraph() = default;
    explicit UndirectedGraph(size_t v);

    explicit operator std::string() const;

    void addEdge(const Vertex& v, Vertex* w);
    void addVertex(const T& uid);
    void addVertex(const T& uid, std::vector<Vertex*> adj_list);
    auto adj(const Vertex& v) -> decltype(Vertex::adjacent);
};

#include "UndirectedGraph.tpp"
#endif //UNDIRECTEDGRAPH_UNDIRECTEDGRAPH_HPP
