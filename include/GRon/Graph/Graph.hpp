#ifndef GRON_GRAPH_HPP
#define GRON_GRAPH_HPP

#include <ostream>
#include <string>
#include <vector>

template<typename T>
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

        friend std::ostream& operator<<(std::ostream& os, const Vertex& obj) {
            return obj.streamInsertion(os);
        }

    private:
        std::ostream& streamInsertion(std::ostream& os) const;
    };

    std::vector<Vertex> vertices;

    Graph() = default;
    explicit Graph(bool digraph = false);
    explicit Graph(int v, bool digraph = false);
    Graph(const Graph& other) = default;
    Graph(const Graph&& other)  noexcept = default;
    Graph& operator=(const Graph& other) = default;
    Graph& operator=(Graph&& other)  noexcept = default;
    virtual ~Graph() = default;

    template<class Y> friend std::ostream& operator<<(std::ostream& os, const Graph<Y>& obj);

    bool addEdge(const Vertex& v, Vertex* w);
    bool addVertex(const T& uid);
    bool addVertex(const T& uid, std::vector<Vertex*> adj_list);
    auto adj(const Vertex& v) -> decltype(Vertex::adjacent);

    Vertex* getVertex(const T& uid);
    Vertex* getVertex(const Vertex& v);

    Graph<T> reverse();
};

#include "GRon/Graph/template/Graph.tpp"
#endif //GRON_GRAPH_HPP
