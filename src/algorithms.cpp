#include "algorithms.h"


void top_sort(G::Graph& gr, std::vector<int>& sorted,
              std::vector<int>& tree_size,
              std::vector<int>& prev,
              int curr_v) {
    gr.set_visited(curr_v);
    for (int neig : gr[curr_v]) {
        if (!gr.is_visited(neig)) {
            top_sort(gr, sorted, tree_size, prev, neig);
            tree_size[curr_v] += tree_size[neig];
            prev[neig] = curr_v;
        }
    }
    sorted.push_back(curr_v);
}


int count_total_paths_len(G::Graph& gr) {
    std::vector<int> n(gr.size()); // total lenght of paths from root
    // to children in subtree

    std::vector<int> m(gr.size()); // paths between children without root
    std::vector<int> k(gr.size()); // paths between children through root

    std::vector<int> tree_size(gr.size(), 1);
    std::vector<int> prevs(gr.size(), -1);
    std::vector<int> dinamics_order;
    dinamics_order.reserve(gr.size());
    top_sort(gr, dinamics_order, tree_size, prevs, 0);
    for (int v : dinamics_order) {
        for (int i : gr[v]) {
            if (prevs[v] == i) {
                continue;
            }
            n[v] += n[i] + tree_size[i];
            m[v] += n[i] + m[i] + k[i];

            // there should be sum calculation optimization

            for (int j : gr[v]) {
                if (prevs[v] == j) {
                    continue;
                }
                if (i != j) {
                    k[v] += n[i] * tree_size[j] + n[j] * tree_size[i] +
                            2 * tree_size[i] * tree_size[j];
                }
            }
        }
        k[v] /= 2;
    }
    return n[0] + m[0] + k[0];
}

