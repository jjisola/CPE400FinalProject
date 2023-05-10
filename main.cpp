#include "Graph.h"


using namespace std;

void makeGraph(string, Graph*);
int getSource();
int getDestination();
int getInput();

int main(){

    Graph routers;
    makeGraph("data.txt", &routers);


    int source, destination;

    bool isTrue = true;

    while(isTrue){
        int entry = getInput();
        switch(entry){
            case 0:
                isTrue = false;
                break;
            case 1:
                routers.printTable();
                break;
            case 2:
                routers.clear();
                source = getSource();
                destination = getDestination();
                if (source == destination){
                    cout << "Cannot find router path to itself" << endl;
                    break;
                }
                if ((source > 20) || (destination > 20) || (source < 1) || (destination < 1)){
                    cout << "invalid source/destination." << endl;
                    break;
                }
                routers.compile(source, destination);
                routers.printAllPaths();
                break;
            default:
                cout << "Please enter valid number" << endl;
        }
    }




    return 0;
}

void makeGraph(string fileName, Graph* g){
    string line;
    ifstream file(fileName.c_str());

    int a, b, c;
    cout << "Data entered from " << fileName << endl;
    while(!file.eof()){
        file >> a >> b >> c;
        g->connectEdge(a, b, c);
    }

    file.close();

}

int getSource(){
    int a;
    cout << "Please Enter Source Node: ";
    cin >> a;
    return a;
}

int getDestination(){
    int a;
    cout << "Please Enter Destination Node: ";
    cin >> a;
    return a;
}

int getInput(){
    cout << "1: Print Adjacency Table" << endl;
    cout << "2: find best path from router A to B" << endl;
    cout << "0: Exit" << endl;
    cout << "Please Enter Choice: " << endl;
    int i;
    cin >> i;
    return i;


}