
#ifndef _GRAPH_
#define _GRAPH_

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Graph {
    int vertex = 0;
    int edges = 0;

public:
    Graph();

    void createGraph( int vertices );

    void addEdge ( int from_vertex, int to_vertex );

    void printGraph();

    std::vector<std::vector<int>> getGraph();

    void BFS( int source );

    void printBFS();

    /// @brief function having implementation of DFS
    /// @param source 
    /// @param dfsElements 
    /// @param visited 
    /// @param adj 
    void DFS( int source, std::vector <int> dfsElements, 
            std::vector <bool>& visited, std::vector<std::vector<int>>& adj );
    
    /// @brief function initializin the dfsElements, visited, source required
    /// for DFS() implementation and calling DFS()
    void dfsCaller();

    int countNumberOfProvinces( std::vector<std::vector<int>> adj, int vertex );
    
    void dfsHelper( int node, std::vector <bool>& visited, 
                std::vector<std::vector<int>>& adjList );


private:
    //outer vector represents number of vertices
    //inner vector represents number of edges
    //For example:
    //vertex - list of edges
    //0 - { 1, 2 }
    //1 - { 0, 2 }
    //2 - { 0, 1, 3 }
    //3 - { 2 }
    std::vector <std::vector <int>> graph; 

    std::vector <int> bfs;    //vector to hold the traversal

};



#endif //_GRAPH