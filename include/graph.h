#ifndef GRAPH_LIBRARY_H
#define GRAPH_LIBRARY_H

#include <list>
#include <vector>
#include <cstddef>
#include <algorithm>
#include <exception>

#pragma once

namespace G {
    class Graph{
     public:
        using TINNER = std::list<int>;
        using TEXTERNAL = std::vector<TINNER>;

     private:
        TEXTERNAL data;
        std::vector<bool> visited;

     public:
        Graph(TEXTERNAL data);

        Graph(size_t n);


     public:
        /**
         * Adds edge between specified verticies, without checking
         * whether verticies are already connected.
         * Complexity: O(1)
         *
         * @param x vertex number
         * @param y vertex number
         */
        void add_edge(int x, int y);

        /**
         * Removes edge between specified verticies. If edge is not found,
         * does nothing.
         * Complexity: O(|V|)
         *
         * @param x vertex number
         * @param y vertex number
         */
        void remove_edge(int x, int y);

        /**
         * Returns list of verticies. If x is greater than size(),
         * then exception is thrown.
         * Complexity: O(1)
         *
         * @param x vertex number
         * @return TINNER of verticies, смежных with x
         */

        TINNER operator[](int x);

        /**
         * Checks whether there is an edge between x and y
         * Complexity: O(|V|)
         * @param x number of vertex
         * @param y number of vertex
         * @return true if edge exists, false otherwise
         */

        bool operator()(int x, int y);

        /**
         * Return size of verticies set
         * @return size
         */

        size_t size();

        /**
         * Used for DFS, setting vertex X as visited
         * @param x vertex number
         */
        void set_visited(int x);

        /**
         * Used for DFS, setting vertex X as not visited
         * @param x vertex number
         */
        void unset_visited(int x);

        /**
         * Clears list of visited vertecies
         */
        void reset_visited();

        /**
         * Checks if vertex x is visited from last reset_visited() call
         * Throws invalud_argument exception in case of invalid vertex
         * @param x vertex number
         * @return true if visited, false otherwise
         */
        bool is_visited(int x);

        /**
         * @return number of vertices in the graph
         */
        size_t vertices_num();
    };

}
#endif