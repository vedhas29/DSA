
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
                q.push( it );
                visited[ it ] = true;
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

void Graph::dfsCaller() {
    std::vector <int> dfsElements;
    std::vector <bool> visited( graph.size(), false );

    int source = 0; //assuming the start of traversal is 0

    DFS( source, dfsElements, visited, graph );
}

void Graph::DFS( int node, std::vector <int> dfsElements, 
        std::vector <bool>& visited, std::vector<std::vector<int>>& adj ) {
    
    //to mark whether vertex is visited or not
    visited[ node ] = true;
    
    dfsElements.push_back( node );

    //traverse the nodes in depth
    for ( auto it : adj[ node ] ) {
        if ( visited[ it ] == false ) {
            visited[ it ] = true;
            DFS( node, dfsElements, visited, adj );
        }
    }
}

int Graph::countNumberOfProvinces( std::vector<std::vector <int>> &adj, 
            int vertex ) {
    
    //convert adj matrix to list
    std::vector<std::vector <int>> adjList( vertex );
    for ( int i = 0; i < adj.size(); i++ ) {
        for ( int j = 0; j < adj.size(); j++ ) {

            if ( adj[ i ][ j ] == 1 and i != j ) {
                adjList[ i ].push_back( j );
            }
        }
    }

    std::vector <bool> visited ( vertex+1, false );
    int number_of_provinces = 0;

    for ( int i = 0; i < vertex; i++ ) {

        if ( visited[ i ] == false ) {
            dfsHelper( i, visited, adjList );
            number_of_provinces += 1;
        }
    }
    return number_of_provinces;
}

void Graph::dfsHelper( int node, std::vector <bool>& visited, 
            std::vector<std::vector <int>>& adjList ) {
    
    visited[ node ] = true;

    for ( auto it: adjList[ node ] ) {
        if ( visited[ it ] == false ) {
            visited[ it ] = true;
            dfsHelper( it, visited, adjList );
        }
    }
}