//
// Created by Isaac on 5/1/2020.
//

#ifndef GRAPHTHEORYPROJECT_GRAPH_H
#define GRAPHTHEORYPROJECT_GRAPH_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::cout;
using std::string;
class Graph{

private:

    int V,counter;

    int ** adj_matrix;

    bool allEvenDegree = true;

    std::vector<int> vertexDegrees;

    std::vector<std::pair<int,int>> edges;

public:

    //constructor that takes in the graph and sets it equal to the graph in the class
    Graph(int ** adj_matrix, int V);

    //checks whether or not the graph is connected via depth first search and returns a boolean result
    bool isConnected();

    //checks whether or not the graph contains an Euler cycle and returns a boolean result
    bool containsEulerCycle();

    //checks whether or not the graph contains an Euler trail and returns a boolean result
    bool containsEulerTrail();

    //returns the Euler cycle that the graph contains
    void getEulerCycle();

    //returns the Euler trail that the graph contains
    void getEulerTrail();

    //goes through the graph via a depth first search and returns the number of
    //vertices in the resulting spanning tree
    int depthfirstSearch(int prev, int start, std::vector<bool>& visited);

    //checks for a bridge at the given edge
    bool isBridge(int u, int v);

    //runs the fluery algorithm which finds Euler cycles, and trails
    void flueryAlgorithm(int start);

    //counts the number of edges in the graph
    int countEdges();

};

#endif //GRAPHTHEORYPROJECT_GRAPH_H
