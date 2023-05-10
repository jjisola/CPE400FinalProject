#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>


#define SIZE 21

using namespace std;

struct info{
    int id;
    int depth;
    int bandWidth;
};

class Graph {
    private: 
        int numVertices; // tracks amount of vertices in graph
        int adjMatrix[SIZE][SIZE]; // adjacency matrix
        int visited[SIZE]; //displays 1 if visited, 0 if not
        int unique[SIZE]; //1 if vertice has been added, 0 if not.

        vector<vector<int>> allPaths;
        vector<info> pathInfo;
        vector<int> bestPath;

        int maxBandwidth, bestDepth;


        void pathsUtility(int aNode, int bNode, vector<int>& currentPath); //recursive function for findAllPaths function
        void setInfo();
        void isUnique(int node); //adds 1 to unique[] if it is a new vertice
        void findAllPaths(int sourceNode, int destNode);
        void findBestPath(); // priortitizes bandwidth then depth for allPaths

    public:
        Graph(); //default constructor
        
        void connectEdge(int nodeA, int nodeB, int bandWidth); // connects router A with router B with specified bandwidth
        void printTable(); //prints the adjacency table
        void printAllPaths(); // depth first search for finding all paths
        void compile(int source, int dest);
        void clear();

};

#endif