#include "Graph.h"


using namespace std;

void makeGraph(string, Graph*);

int main(){

    Graph routers;
    makeGraph("data.txt", &routers);

    routers.printTable();




    return 0;
}

void makeGraph(string fileName, Graph* g){
    string line;
    ifstream file(fileName.c_str());

    int a, b, c;

    while(!file.eof()){
        file >> a >> b >> c;
        g->connectEdge(a, b, c);
    }

    file.close();

}
