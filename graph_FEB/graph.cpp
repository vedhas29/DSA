
#include "graph.h"

Graph::Graph() {
    vertex = 0;
    edges = 0;
}

void Graph::createGraph( int vertices ) {
    graph.resize( vertices );
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

void Graph::BFS( int source ) {

    //vector to mark if the vertex is visited or not
    std::vector <bool> visited ( graph.size(), false );
    
    //queue to hold the current processing node
    std::queue <int> q;

    visited [ source ] = true;

    q.push( source );

    while ( !q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back( node );

        for ( auto it : graph[ node ] ) {
            if ( visited[ it ] == false ) {
                visited[ it ] = true;
                q.push( it );
            }
        }
    }

}

void Graph::printBFS() {

    for ( int i = 0; i < bfs.size(); i++ ) {
        std::cout << bfs[ i ] << " " ;
    }
}


std::vector<std::vector<int>> Graph::getGraph() {
    return graph;
}