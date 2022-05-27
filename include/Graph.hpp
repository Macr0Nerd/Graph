#ifndef GRAPH_HPP
#define GRAPH_HPP

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
struct Graph {
    int V{0};
    int E{0};
    bool directed{false};

    struct Vertex {
        T id;
        std::vector<Vertex*> adjacent;

        Vertex() : adjacent(), id() {};
        explicit Vertex(T uid) : adjacent(), id(uid) {};
        Vertex(T uid, std::vector<Vertex*> adj_list) : adjacent(adj_list), id(uid) {};
        virtual ~Vertex() = default;

        bool operator==(const Vertex& other) const;
        bool operator==(const T& uid) const;
        Vertex& operator=(const Vertex& other);
        Vertex* operator[](int index) const;
        explicit operator std::string();
    };

    std::vector<Vertex> vertices;

    Graph() = default;
    explicit Graph(bool digraph = false);
    explicit Graph(int v, bool digraph = false);
    virtual ~Graph() = default;

    explicit operator std::string();

    bool addEdge(const Vertex& v, Vertex* w);
    bool addVertex(const T& uid);
    bool addVertex(const T& uid, std::vector<Vertex*> adj_list);
    auto adj(const Vertex& v) -> decltype(Vertex::adjacent);

    Vertex* getVertex(const T& uid);
    Vertex* getVertex(const Vertex& v);

    Graph<T> reverse();
};

#include "Graph.tpp"
#endif //GRAPH_HPP
