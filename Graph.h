//
// Created by Isaac on 5/1/2020.
//

#ifndef GRAPHTHEORYPROJECT_GRAPH_H
#define GRAPHTHEORYPROJECT_GRAPH_H
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::string;
class Graph{

private:

    int V,counter,E;
    int ** adj_matrix;
    bool allEvenDegree = true;
    std::vector<int> vertexDegrees;

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
    void getEulerCycle(int start, std::vector<bool>& visited);

    //returns the Euler trail that the graph contains
    void getEulerTrail();

    //goes through the graph via a depth first search and returns the number of
    //vertices in the resulting spanning tree
    int depthfirstSearch(int start, std::vector<bool>& visited);

    void printNumEdges(){cout << E;}


};

#endif //GRAPHTHEORYPROJECT_GRAPH_H
