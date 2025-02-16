
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

    void addEdge ( int from_vertex, int to_vertex );

    void printGraph();

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

};



#endif //_GRAPH_