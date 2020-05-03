#include "Graph.h"

bool Graph::isConnected(){

    //a vector that is filled with false to be put into the depth first search function
    std::vector<bool> visited(V,false);

    //if the depth first search creating a spanning tree with V vertices
    //return true, otherwise return false
    if(depthfirstSearch(0,visited) == V){

        return true;

    } else{

        return false;
    }
}


Graph::Graph(int ** adj_matrix, int V) {

    //initializing the matrix and vertices values
    this->adj_matrix = adj_matrix;
    this->V = V;
}

//idea from: https://www.geeksforgeeks.org/implementation-of-dfs-using-adjacency-matrix/
int Graph::depthfirstSearch(int start, std::vector<bool>& visited){

    //sets the first vertex to true because we know we at least visited that one
    visited[start] = true;
    //increase the counter of vertices visited
    counter++;

    //now we go through and see if there is a vertex that hasn't been visited, if so we
    //use recursion to repeat the function
    for(int i = 0; i < V; i++){
        if(adj_matrix[start][i] == 1 && (!visited[i])){
            depthfirstSearch(i,visited);

        }
    }


    //returns the number of vertices visited
    return counter;
}



