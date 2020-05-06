/* Isaac Angle
 * This is the main class for a program that will get an adjacency matrix
 * from the user and then see if the graph is connected,  and if it contains an Euler cycle or trail */
#include <iostream>
#include "Graph.h"
#include <vector>

using std::cout;
using std::cin;
using std::vector;
using std::endl;

int ** get_adjMatrix(int V, int ** adj_matrix);
void print_adjMatrix(int ** adj_matrix, int V);

int main() {
    //number of vertices
    int V = 0;

    //gets the number of vertices from the user
    cout << "How many vertices are there?" << endl;
    cin >> V;

    //the 2D array that holds the adjacency matrix
    int **adj_matrix;

    //sets the default values for the 2D array
    adj_matrix = new int *[V];
    for(int i = 0; i <V; i++) {
        adj_matrix[i] = new int[V];
    }

    //gets the values of the matrix from the user and sets them equal to the 2D array we created
    adj_matrix = get_adjMatrix(V, adj_matrix);

    //prints out the matrix for the user to see
    cout << "Here is the matrix you entered: " << endl;
    print_adjMatrix(adj_matrix,V);

    //creates the graph object needed to preform the mathematical operations
    Graph graph(adj_matrix, V);

    //checks if the graph is connected or not and then outputs a correct response
    if(graph.isConnected()){
        cout << "the graph is connected!" << endl;
    } else{
        cout << "The graph is not connected" << endl;
    }

    //checks for an Euler cycle and prints it out if there is one
    if(graph.containsEulerCycle()){
        cout << "the graph contains an Euler cycle!" << endl;
        cout << "the Euler cycle is: ";
        graph.getEulerCycle();
        cout << "" << endl;
    }else {
        cout << "the graph does not contain an Euler cycle" << endl;
    }

    //checks for an Euler trail and prints it out if there is one
    if(graph.containsEulerTrail()){
        cout << "the graph contains an Euler trail!" << endl;
        cout << "the Euler trail is: ";
        graph.getEulerTrail();
        cout << "" << endl;
    }else{
        cout << "the graph does not contain an Euler trail" << endl;
    }


    return 0;
}

//this function gets the adjacency matrix from the user by asking them for each value
//and then storing it into the array. It takes in the number of vertices V, and the matrix itself
//returns the filled adjacency matrix
int ** get_adjMatrix(int V, int ** adj_matrix){

    //this value is used to hold the user-given value before storing it into the array
    int temp = 0;

    //gets the matrix number by number from the user
    for(int i  = 0; i < V; i++){
        for(int j = 0; j < V; j++) {
            //some text checks to make sure the grammar is correct
            if (i == 0) {
                cout << "enter your " << (i+1) << "st " << "column, ";
            } else if(i == 1){
                cout << "enter your " << (i+1) << "nd " << "column, ";
            } else if(i == 2){
                cout << "enter your " << (i+1) << "rd " << "column, ";
            }else{
                cout << "enter your " << (i+1) << "th " << "column, ";
            }

            //some text checks to make sure the grammar is correct
            if (j == 0) {
                cout << (j+1) << "st " << "row: ";
            } else if(j == 1){
                cout << (j+1) << "nd " << "row: ";
            } else if(j == 2){
                cout << (j+1) << "rd " << "row: ";
            }else{
                cout << (j+1) << "th " << "row: ";
            }

            //gets the number from the user, and stores it into temp
            cin >> temp;
            //puts the number into the matrix
            adj_matrix[i][j] = temp;
            //add some a new line before continuing
            cout << "" << endl;
        }
    }

    //returns the filled matrix
    return adj_matrix;
}


//this function prints out the adjacency matrix
//takes in the filled matrix and the number of vertices, V
void print_adjMatrix(int ** adj_matrix, int V){

    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){

            cout << adj_matrix[i][j] << " ";
        }

        cout << "" << endl;
    }
}
