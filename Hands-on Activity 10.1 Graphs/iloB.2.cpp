#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <queue>

template <typename T>
class Graph;

template <typename T>
struct Edge
{
    size_t src;
    size_t dest;
    T weight;

    inline bool operator<(const Edge<T> &e) const
    {
        return this->weight < e.weight;
    }
    inline bool operator>(const Edge<T> &e) const
    {
        return this->weight > e.weight;
    }
};

// Forward declaration of stream operator
template <typename U>
std::ostream &operator<<(std::ostream &os, const Graph<U> &G);

template <typename T>
class Graph
{
public:
    Graph(size_t N) : V(N) {}

    size_t vertices() const
    {
        return V;
    }

    const std::vector<Edge<T>> &edges() const
    {
        return edge_list;
    }

    void add_edge(const Edge<T> &e)
    {
        // 1-based indexing check: 1 <= src/dest <= V
        if (e.src >= 1 && e.src <= V && e.dest >= 1 && e.dest <= V)
        {
            edge_list.emplace_back(e);
        }
        else
        {
            std::cerr << "Vertex out of bounds: (" << e.src << " -> " << e.dest << ")" << std::endl;
        }
    }

    std::vector<Edge<T>> outgoing_edges(size_t v) const
    {
        std::vector<Edge<T>> edges_from_v;
        for (const auto &e : edge_list)
        {
            if (e.src == v)
            {
                edges_from_v.emplace_back(e);
            }
        }
        return edges_from_v;
    }

    // Friend declaration using U to avoid template shadowing warnings
    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const Graph<U> &G);

private:
    size_t V;
    std::vector<Edge<T>> edge_list;
};

// Fixed operator<< to iterate through all vertices and return os
template <typename T>
std::ostream &operator<<(std::ostream &os, const Graph<T> &G)
{
    for (size_t i = 1; i <= G.vertices(); i++)
    {
        os << i << ":\t";
        auto edges = G.outgoing_edges(i);
        for (const auto &e : edges)
        {
            os << "{" << e.dest << ": " << e.weight << "}, ";
        }
        os << "\n";
    }
    return os;
}

template <typename T>
auto create_reference_graph()
{
    // Max vertex ID is 8, so graph size is 8
    Graph<T> G(8);

    std::map<unsigned, std::vector<std::pair<size_t, T>>> edges;
    edges[1] = {{2, 2}, {5, 3}};
    edges[2] = {{1, 2}, {5, 5}, {4, 1}};
    edges[3] = {{4, 2}, {7, 3}};
    edges[4] = {{2, 1}, {3, 2}, {5, 2}, {6, 4}, {8, 5}};
    edges[5] = {{1, 3}, {2, 5}, {4, 2}, {8, 3}};
    edges[6] = {{4, 4}, {7, 4}, {8, 1}};
    edges[7] = {{3, 3}, {6, 4}};
    edges[8] = {{4, 5}, {5, 3}, {6, 1}};

    for (const auto &i : edges)
    {
        for (const auto &j : i.second)
        {
            G.add_edge(Edge<T>{i.first, j.first, j.second});
        }
    }

    return G;
}

// Fixed BFS to insert into visited set when pushing to queue (prevents duplicate processing)
template <typename T>
auto breadth_first_search(const Graph<T> &G, size_t start_node = 1)
{
    std::queue<size_t> queue;
    std::vector<size_t> visit_order;
    std::set<size_t> visited;

    queue.push(start_node);
    visited.insert(start_node);

    while (!queue.empty())
    {
        auto current_vertex = queue.front();
        queue.pop();
        visit_order.push_back(current_vertex);

        for (const auto &e : G.outgoing_edges(current_vertex))
        {
            if (visited.find(e.dest) == visited.end())
            {
                visited.insert(e.dest);
                queue.push(e.dest);
            }
        }
    }
    return visit_order;
}

template <typename T>
void test_BFS()
{
    auto G = create_reference_graph<unsigned>();
    std::cout << G << std::endl;

    std::cout << "BFS Order of vertices starting from 1: " << std::endl;
    auto bfs_visit_order = breadth_first_search(G, 1);
    for (auto v : bfs_visit_order)
    {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

int main()
{
    using T = unsigned;
    test_BFS<T>();
    return 0;
}