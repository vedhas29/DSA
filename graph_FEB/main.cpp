

#include "graph.h"
#include "graph.cpp"

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    std::cout << "hello world" << std::endl;

    Graph graph;
    int vertices = 0;
    std::cout << "enter number of vertices for graph = " << std::endl;
    cin >> vertices;
    graph.createGraph( vertices );


    graph.addEdge( 0, 1 );
    graph.addEdge( 0, 2 );
    graph.addEdge( 1, 2 );
    graph.addEdge( 2, 3 );

    std::cout << "printing graph = " << std::endl;
    graph.printGraph();

    return 0;
}