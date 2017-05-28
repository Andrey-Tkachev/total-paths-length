#include <iostream>
#include <vector>

#include "graph.h"
#include "algorithms.h"


int main() {
   std::ios::sync_with_stdio(false);
   std::cout << "Enter vertexes number: ";

   int N;
   std::cin >> N;
   G::Graph graph(N);

   std::cout << "\nDescribe the graph as adjacency list:\n";

   for (size_t i = 0; i < N - 1; ++i) {
       int u, v;
       std::cin >> u >> v;
       graph.add_edge(--u, --v);
   }

   std::cout << "Total length of all paths is "
             << count_total_paths_len(graph) << std::endl;   
}
