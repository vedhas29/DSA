
#include "graph.h"

Graph::Graph() {
    vertex = 0;
    edges = 0;
}


void Graph::addEdge( int from_vertex, int to_vertex ) {

    graph[ from_vertex ].push_back( to_vertex );
    graph[ to_vertex ].push_back( from_vertex );
}

void Graph::printGraph() {

    //number of vertices
    int vertices = graph.size();

    for ( int i = 0; i < vertices; i++ ) {
        for ( auto it : graph[ i ] ) {
            std::cout << it << " ";
        }
        std::cout << std::endl;
    }

}