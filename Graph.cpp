#include "Graph.h"



using namespace std;

Graph::Graph(){ // default constructor
    numVertices = 0;
    maxBandwidth = -1;
    bestDepth = 9999;
    
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

void Graph::pathsUtility(int aNode, int bNode, vector<int>& path){

    visited[aNode] = 1;
    path.push_back(aNode);

    if (aNode == bNode) allPaths.push_back(path);
    else {
        for(int i=1; i<=numVertices; i++){
            
                if((adjMatrix[aNode][i] != 0) && (visited[i] == 0)){
                    pathsUtility(i, bNode, path);
                }
        }
    }
    path.pop_back();
    visited[aNode] = 0;


}

void Graph::findAllPaths(int sourceNode, int destNode){
    vector<int> path;
    // cout << numVertices;
    pathsUtility(sourceNode, destNode, path);
}

void Graph::printAllPaths(){
    int i=0;
    for(const auto& path: allPaths){
        cout << "Path " << (i + 1) << ": ";
        for(int router : path){
            cout << router << " ";
            
        }
        cout << " Bandwidth: " << pathInfo[i].bandWidth << " Depth: " << pathInfo[i].depth << endl;
        i++;
    }
    cout << endl;
    cout << "Path with Highest Throughput: ";
    int m = bestPath.size();
    for(int j=0; j<m; j++){
        cout << bestPath[j] << " ";
    }
    cout << "Bandwidth: " << maxBandwidth << " Depth: " << bestDepth << endl;
}

void Graph::setInfo(){
    int j = 0;
    for(const auto& path: allPaths){
        info tempInfo;
        int tempMin = 9999;
        tempInfo.depth = path.size();
        // cout << path.size() << endl;
        int num = path.size();
        // cout << path.size() << endl;
        for(int i = 0; i< num - 1; i++ ){
            
            tempMin = min(tempMin, adjMatrix[path[i]][path[i+1]]);
        }

        if(tempMin > maxBandwidth) maxBandwidth = tempMin;
        tempInfo.bandWidth = tempMin;
        tempInfo.id = j;
        j++;
        pathInfo.push_back(tempInfo);

    }
}

void Graph::findBestPath(){
    int minDepth = 999;
    int ans = 0;
    for(const auto& path: pathInfo){
        if(path.bandWidth == maxBandwidth){
            if(minDepth > path.depth){
                minDepth = path.depth;
                ans = path.id;
            }
        }
    }
    bestDepth = minDepth;
    // vector<int> tempBestPath;
    int sz = allPaths[ans].size();
    for(int i=0; i<sz; i++){
        bestPath.push_back(allPaths[ans][i]);
    }
}

void Graph::compile(int source, int dest){
    findAllPaths(source, dest);
    //cout << allPaths.size();
    setInfo();
    findBestPath();
    // printAllPaths();

}

void Graph::clear(){
    for(auto &path : allPaths){
        path.clear();
    }
    allPaths.clear();
    pathInfo.clear();
    bestPath.clear();
    for(int i=0; i<SIZE; i++){
        visited[i] = 0;
    }
    maxBandwidth = -1;
    bestDepth = 999;


}