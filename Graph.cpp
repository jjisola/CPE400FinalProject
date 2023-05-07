#include "Graph.h"



using namespace std;

Graph::Graph(){ // default constructor
    numVertices = 0;
    
    for(int i=0; i<SIZE; i++){ // set adjacency matrix and visited array to all zeros
        visited[i] = 0;
        unique[i] = 0;
        for(int j=0; j<SIZE; j++){
            adjMatrix[i][j] = 0;
        }
    }

}

void Graph::connectEdge(int nodeA, int nodeB, int bandWidth){
    isUnique(nodeA);
    isUnique(nodeB);

    adjMatrix[nodeA][nodeB] = bandWidth;
    adjMatrix[nodeB][nodeA] = bandWidth;
}

void Graph::isUnique(int node){ 
    
    if(unique[node] == 0){
        unique[node] = 1;
        numVertices++;
    }
    
    
}

void Graph::printTable(){
    int width = 1;
    cout << setw(width + 1) << "" << " | ";
    for(int i=1; i<= numVertices; i++){
        cout << setw(width + 1) << i << " | ";
    }
    cout << endl;
    for(int i=1; i<=numVertices; i++){
        cout << setw(width + 1) << i << " | ";
        for(int j=1; j<=numVertices; j++){
            cout << setw(width + 1) << adjMatrix[i][j] << " | ";
        }
        cout << endl;
    }
}