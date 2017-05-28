#include <stdexcept>
#include "graph.h"

// ADJACENCY LIST IMPLEMENTATION
G::Graph::Graph(size_t n)
        : data(n), visited(n) {}

G::Graph::Graph(TEXTERNAL data_)
        : data(data_), visited(data_.size()) {}

void G::Graph::add_edge(int x, int y) {
    check_arg_in_range(x, "x");
    check_arg_in_range(y, "y");
    data[x].push_back(y);
    data[y].push_back(x);
}

void G::Graph::remove_edge(int x, int y) {
    check_arg_in_range(x, "x");
    check_arg_in_range(y, "y");
    auto it = std::find(data[x].begin(), data[x].end(), y);
    if (it != data[x].end()) {
        data[x].erase(it);
    }

    it = std::find(data[y].begin(), data[y].end(), x);
    if (it != data[y].end()) {
        data[y].erase(it);
    }
}

void G::Graph::check_arg_in_range(int arg, const std::string& argname) const {
    if (arg < 0 || data.size() <= arg) {
        std::string error = "Invalid argument. Passed " + argname + " = " +
                            std::to_string(arg) +
                            ", size = " +
                            std::to_string(data.size());
        throw std::invalid_argument(error);
    }
}

G::Graph::TINNER
G::Graph::operator[](int x) const {
    check_arg_in_range(x, "x");
    return data[x];
}

bool G::Graph::operator()(int x, int y) const {
    check_arg_in_range(x, "x");
    check_arg_in_range(y, "y");
    auto it = std::find(data[x].begin(), data[x].end(), y);
    if (it != data[x].end()) {
        return true;
    }
}

size_t G::Graph::size() const noexcept {
    return data.size();
}

void G::Graph::set_visited(int x) {
    check_arg_in_range(x, "x");
    visited[x] = true;
}

void G::Graph::unset_visited(int x) {
    check_arg_in_range(x, "x");
    visited[x] = false;
}

void G::Graph::reset_visited() noexcept {
    for (size_t i = 0; i != visited.size(); ++i) {
        visited[i] = false;
    }
}

bool G::Graph::is_visited(int x) const {
    check_arg_in_range(x, "x");
    return visited[x];
}

size_t G::Graph::vertices_num() const noexcept {
    return data.size();
}