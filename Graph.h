#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>


#define SIZE 21

using namespace std;

class Graph {
    private: 
        int numVertices; // tracks amount of vertices in graph
        int adjMatrix[SIZE][SIZE]; // adjacency matrix
        int visited[SIZE]; //displays 1 if visited, 0 if not
        int unique[SIZE]; //1 if vertice has been added, 0 if not.
    public:
        Graph(); //default constructor
        
        void connectEdge(int nodeA, int nodeB, int bandWidth); // connects router A with router B with specified bandwidth
        void printTable(); //prints the adjacency table
        void isUnique(int node); //adds 1 to unique[] if it is a new vertice

};

#endif