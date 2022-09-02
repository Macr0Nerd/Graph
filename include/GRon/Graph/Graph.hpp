#ifndef GRON_GRAPH_HPP
#define GRON_GRAPH_HPP

#include <optional>
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

        Vertex(const Vertex&) = default;
        Vertex(Vertex&&) noexcept = default;
        Vertex& operator=(const Vertex&) = default;
        Vertex& operator=(Vertex&&) noexcept = default;
        virtual ~Vertex() = default;

        bool operator==(const Vertex& other) const;
        bool operator==(const T& uid) const;
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

    Graph(const Graph&) = default;
    Graph<T>(Graph<T>&&) noexcept = default;
    Graph& operator=(const Graph&) = default;
    Graph<T>& operator=(Graph<T>&&) noexcept = default;
    virtual ~Graph() = default;

    template<class Y> friend std::ostream& operator<<(std::ostream& os, const Graph<Y>& obj);

    bool addEdge(const Vertex& v, Vertex* w);
    bool addVertex(const T& uid);
    bool addVertex(const T& uid, std::vector<Vertex*> adj_list);
    decltype(auto) adj(const Vertex& v);

    std::optional<Vertex*> getVertex(const T& uid);
    std::optional<Vertex*> getVertex(const Vertex& v);

    Graph<T> reverse();
};

#include "GRon/Graph/template/Graph.tpp"
#endif //GRON_GRAPH_HPP
