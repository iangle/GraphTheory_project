#include "Graph.h"

bool Graph::isConnected(){

    //a vector that is filled with false to be put into the depth first search function
    std::vector<bool> visited(V,false);

    //if the depth first search creating a spanning tree with V vertices
    //return true, otherwise return false
    if(depthfirstSearch(0,0,visited) == V){

        return true;

    } else{

        return false;
    }
}


Graph::Graph(int ** adj_matrix, int V) {

    //initializing the matrix and vertices values
    this->adj_matrix = adj_matrix;
    this->V = V;

    //creating the vector that holds the visited vertices
    std::vector<int> visited;

    //fills out the vertex degrees
    for(int i = 0; i < V; i++){
        int numDegree = 0;
        for(int j = 0; j < V; j++){
            if(adj_matrix[i][j] == 1){
                numDegree++;
            }
        }
        //puts the vertex degree into the vector of vertex degrees
        vertexDegrees.push_back(numDegree);
    }

    //checks to see if all the vertices have even degree
    for(int i = 0; i < V; i++){
        if(vertexDegrees.at(i) % 2 != 0){
            allEvenDegree = false;
        }
    }

    //gets the number of edges that are in the graph
    for(int i = 0; i < V; i++){
        for(int j = i + 1; j < V; j++) {
            if(adj_matrix[i][j] == 1) {
                edges.push_back(std::make_pair(i,j));
            }
        }
    }
}

//idea from: https://www.geeksforgeeks.org/implementation-of-dfs-using-adjacency-matrix/
int Graph::depthfirstSearch(int prev, int start, std::vector<bool>& visited){

    int counter = 1;
    //sets the first vertex to true because we know we at least visited that one
    visited[start] = true;


    //now we go through and see if there is a vertex that hasn't been visited, if so we
    //use recursion to repeat the function
    for(int i = 0; i < V; i++){
        if(prev != i) {
            if (adj_matrix[start][i] == 1 && (!visited[i])) {
                counter += depthfirstSearch(start, i, visited);

            }
        }
    }


    //returns the number of vertices visited
    return counter;
}

//checks to see if the graph contains an Euler cycle
bool Graph::containsEulerCycle() {

    //first we assume that the graph contains an Euler cycle
    bool eulerCycle = true;

    //now we go through and make sure each vertex degree is even
    //if any of them are odd then we set Euler cycle to false
    for(int i = 0; i < V; i++){
        if(vertexDegrees[i] % 2 != 0){
            eulerCycle = false;
        }
    }

    //return the result
    return eulerCycle;
}

bool Graph::containsEulerTrail() {

    //first we assume that the graph does not contain an Euler trail
    bool euler_trail = false;

    //now we go through the array and look for exactly two odd degree vertices
    //if we find them then there is an Euler trail, otherwise there is not one
    //this first if statement makes sure that all vertices are not of even degree
    if(!allEvenDegree) {
        for (int i = 0; i < V; i++) {
            //checks if there is an odd degree vertex
            if (vertexDegrees[i] % 2 != 0) {
                for (int j = i + 1; j < V; j++) {
                    //if there is an odd degree vertex look for another one
                    if (vertexDegrees[j] % 2 != 0) {
                        for (int k = j + 1; k < V; k++) {
                            //if there is an odd degree vertex look for another one
                            if (vertexDegrees[k] % 2 != 0) {
                                //if there is another odd degree vertex then there is no Euler trail
                                euler_trail = false;
                            } else {
                                //if there isn't another odd degree vertex then there is an Euler trail
                                euler_trail = true;
                            }
                        }
                    }
                }
            }
        }
    }

    //return the result
    return euler_trail;

}

//runs fluerry's algorithm and get the Euler circuit
void Graph::getEulerCycle() {
    flueryAlgorithm(0);
}

//gets the Euler trail and prints it out to the screen
void Graph::getEulerTrail() {

    int start;

    //looks for an odd degree vertex and sets it as the start value
    for(int i = 0; i < vertexDegrees.size(); i++){
        if(vertexDegrees[i] % 2 != 0){
            start = i;
            break;
        }
    }


    //start the program at the odd degree vertex
    flueryAlgorithm(start);
}

//checks whether or not the given edge is a bridge: the only edge that leads to a vertex
bool Graph::isBridge(int u, int v){
    int degree = 0;
    for(int i = 0; i < V; i++) {
        if (adj_matrix[v][i] == 1) {
            degree++;
        }
    }

    if(degree > 1){
        return false;
    }

    return true;
}
//idea from: https://www.tutorialspoint.com/Fleury-s-Algorithm
// this algorithm goes through the matrix and deletes all the edges that have been used
//this makes it faster than trying multiple attempts
void Graph::flueryAlgorithm(int start){
    //number of vertices left in the graph
    static int vertex_count = V;
    //number of edges left in the graph
    static int numEdges = countEdges();

    for(int i = 0; i < V; i++){
        if(adj_matrix[start][i] == 1){
            std::vector<bool> visited(V,false);
            //if it is a bridge vertex we dont want to count it as a choice
            if(isBridge(start, i)){
                vertex_count--;
            }
            //run a depth first search and get the number of remaining vertices
            int count = depthfirstSearch(start,i,visited);

            //subtract the number of total vertices from the number of vertices left
            if(abs(vertex_count - count) < 2){
                cout << start << "-" << i << " ";
                if(isBridge(i,start)){
                    vertex_count--;
                }

                //get rid of the used edges
                adj_matrix[start][i] = adj_matrix[i][start] = 0;
                numEdges--;
                //run the algorithm again from the current vertex
                flueryAlgorithm(i);
            }
        }
    }
}

//counts the number of edges currently in the graph
int Graph::countEdges(){
    int count = 0;

    for(int i = 0; i < V; i++){
        for(int j = i; j < V; j++)
            if(adj_matrix[i][j] == 1){
                count++;
            }
    }

    return count;
}



