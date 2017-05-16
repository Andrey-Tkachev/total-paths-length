#include <stdexcept>
#include "graph.h"

// ADJACENCY LIST IMPLEMENTATION
G::Graph::Graph(size_t n)
        : data(n), visited(n) {}

G::Graph::Graph(TEXTERNAL data_)
        : data(data_), visited(data_.size()) {}

void G::Graph::add_edge(int x, int y) {
    data[x].push_back(y);
    data[y].push_back(x);
}

void G::Graph::remove_edge(int x, int y) {
    auto it = std::find(data[x].begin(), data[x].end(), y);
    if (it != data[x].end()) {
        data[x].erase(it);
    }

    it = std::find(data[y].begin(), data[y].end(), x);
    if (it != data[x].end()) {
        data[y].erase(it);
    }
}


G::Graph::TINNER
G::Graph::operator[](int x) {
    if (x > data.size()) {
        std::string error = "Invalid argument. Passed x = " +
                            std::to_string(x) +
                            ", size = " +
                            std::to_string(data.size());
        throw std::invalid_argument(error);
    }
    return data[x];
}

bool G::Graph::operator()(int x, int y) {
    if (x >= data.size() || y >= data.size()) {
        std::string error = "Invalid argument. Passed x = " +
                            std::to_string(x) +
                            ", y = " +
                            std::to_string(y) +
                            ", size = " +
                            std::to_string(data.size());
        throw std::invalid_argument(error);
    }

    auto it = std::find(data[x].begin(), data[x].end(), y);
    if (it != data[x].end()) {
        return true;
    }
}

size_t G::Graph::size() {
    return data.size();
}

void G::Graph::set_visited(int x) {
    if (x >= data.size()) {
        std::string error = "Invalid argument. Passed x = " +
                            std::to_string(x) +
                            ", size = " +
                            std::to_string(data.size());
        throw std::invalid_argument(error);
    }
    visited[x] = true;
}

void G::Graph::unset_visited(int x) {
    if (x >= data.size()) {
        std::string error = "Invalid argument. Passed x = " +
                            std::to_string(x) +
                            ", size = " +
                            std::to_string(data.size());
        throw std::invalid_argument(error);
    }
    visited[x] = false;
}

void G::Graph::reset_visited() {
    for (size_t i = 0; i != visited.size(); ++i) {
        visited[i] = false;
    }
}

bool G::Graph::is_visited(int x) {
    if (x >= data.size()) {
        std::string error = "Invalid argument. Passed x = " +
                            std::to_string(x) +
                            ", size = " +
                            std::to_string(data.size());
        throw std::invalid_argument(error);
    }
    return visited[x];
}

size_t G::Graph::vertices_num() {
    return data.size();
}