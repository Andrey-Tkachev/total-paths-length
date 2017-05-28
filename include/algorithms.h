#pragma once
#include <vector>
#include "graph.h"

/**
 * Topological sorting
 * @param gr graph
 * @param sorted
 * @param tree_size
 * @param prev
 * @param curr_v
 */
void top_sort(G::Graph& gr, std::vector<int>& sorted,
              std::vector<int>& tree_size,
              std::vector<int>& prev,
              int curr_v);

/**
 * Calculates number of all paths in tree
 * @param gr graph (tree)
 * @return number of all paths in tree
 */
int count_total_paths_len(G::Graph& gr);
