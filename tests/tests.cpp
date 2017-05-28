#include "graph.h"
#include "algorithms.h"

#include <vector>


#define BOOST_TEST_MAIN

#define BOOST_TEST_MODULE main_test

#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(simpleGraphTests)

    BOOST_AUTO_TEST_CASE(testGraphSize) {
        G::Graph graph(3);
        BOOST_CHECK_EQUAL(graph.vertices_num(), 3);
        BOOST_CHECK_EQUAL(graph.size(), 3);

        BOOST_CHECK_THROW(graph.add_edge(3, -1)   , std::invalid_argument);
        BOOST_CHECK_THROW(graph.add_edge(-1, 3)   , std::invalid_argument);
        BOOST_CHECK_THROW(graph.remove_edge(3, -1), std::invalid_argument);
        BOOST_CHECK_THROW(graph.remove_edge(-1, 3), std::invalid_argument);
        BOOST_CHECK_THROW(graph(3, -1)            , std::invalid_argument);
        BOOST_CHECK_THROW(graph(-1, 3)            , std::invalid_argument);
        BOOST_CHECK_THROW(graph[3]                , std::invalid_argument);
        BOOST_CHECK_THROW(graph[-1]               , std::invalid_argument);
        BOOST_CHECK_THROW(graph.set_visited(3)    , std::invalid_argument);
        BOOST_CHECK_THROW(graph.set_visited(-1)   , std::invalid_argument);
        BOOST_CHECK_THROW(graph.unset_visited(3)  , std::invalid_argument);
        BOOST_CHECK_THROW(graph.unset_visited(-1) , std::invalid_argument);
        BOOST_CHECK_THROW(graph.is_visited(3)     , std::invalid_argument);
        BOOST_CHECK_THROW(graph.is_visited(-1)    , std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE(testGraphEdges) {
        G::Graph graph(3);
        graph.add_edge(0, 2);
        BOOST_CHECK(graph(0, 2));
        BOOST_CHECK(graph(2, 0));
        graph.remove_edge(2, 0);
        BOOST_CHECK(!graph(0, 2));
        BOOST_CHECK(!graph(2, 0));
        graph.remove_edge(2, 0);
        BOOST_CHECK(!graph(0, 2));
        BOOST_CHECK(!graph(2, 0));

        graph.add_edge(1, 1);
        BOOST_CHECK(graph(1, 1));
        graph.remove_edge(1, 1);
        BOOST_CHECK(!graph(1, 1));

        graph.add_edge(1, 0);
        graph.add_edge(2, 1);
        auto vertexes = graph[1];
        auto answ = std::vector<int>({0, 2});
        BOOST_CHECK_EQUAL_COLLECTIONS(vertexes.begin(), vertexes.end(), answ.begin(), answ.end());
    }

    BOOST_AUTO_TEST_CASE(testGraphVisited) {
        G::Graph graph(3);
        BOOST_CHECK(!graph.is_visited(0));
        BOOST_CHECK(!graph.is_visited(1));
        BOOST_CHECK(!graph.is_visited(2));

        graph.set_visited(0);
        BOOST_CHECK(graph.is_visited(0));
        BOOST_CHECK(!graph.is_visited(1));
        BOOST_CHECK(!graph.is_visited(2));
        graph.unset_visited(0);
        BOOST_CHECK(!graph.is_visited(0));
        graph.unset_visited(0);
        BOOST_CHECK(!graph.is_visited(0));

        graph.set_visited(1);
        graph.set_visited(2);
        BOOST_CHECK(graph.is_visited(1));
        BOOST_CHECK(graph.is_visited(2));

        graph.reset_visited();
        BOOST_CHECK(!graph.is_visited(0));
        BOOST_CHECK(!graph.is_visited(1));
        BOOST_CHECK(!graph.is_visited(2));
    }


BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(simpleAlgorithmsTests)

    // TODO: add tests for top_sort()

    BOOST_AUTO_TEST_CASE(count_total_paths_len__trivial) {
        G::Graph tree0(0);
        BOOST_CHECK_EQUAL(count_total_paths_len(tree0), 0);
        G::Graph tree1(1);
        BOOST_CHECK_EQUAL(count_total_paths_len(tree1), 0);
        G::Graph tree2(2);
        tree2.add_edge(0, 1);
        BOOST_CHECK_EQUAL(count_total_paths_len(tree2), 1);
        G::Graph tree3(3);
        tree3.add_edge(0, 1);
        tree3.add_edge(2, 1);
        BOOST_CHECK_EQUAL(count_total_paths_len(tree3), 4);
    }

    // TODO: add more tests for count_total_paths_len()

BOOST_AUTO_TEST_SUITE_END()

