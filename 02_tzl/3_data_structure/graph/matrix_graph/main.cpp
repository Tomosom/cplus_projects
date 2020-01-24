#include <iostream>
#include "matrix_graph.h"

using namespace std;
using namespace DTLib;

int main(int argc, char **argv)
{
    MatrixGraph<3, int, int> g;

    g.setEdge(0, 1, 1);
    g.setEdge(1, 0, 2);
    g.setEdge(1, 2, 3);

    cout << "vCount : " <<g.vCount() << endl;
    cout << "eCount : " <<g.eCount() << endl;
    cout << "ID(1) : " << g.ID(1) << endl;
    cout << "OD(1) : " << g.OD(1) << endl; 
    cout << "TD(1) : " << g.TD(1) << endl;
    
    cout << "W(0, 1) : " << g.getEdge(0, 1) << endl;
    cout << "W(1, 0) : " << g.getEdge(1, 0) << endl;
    cout << "W(1, 2) : " << g.getEdge(1, 2) << endl;

    SharedPointer< Array<int> > aj = g.getAdjacent(1);
    for (int i = 0; i < aj->length(); i++) {
        cout << (*aj)[i] << " ";
    }
    cout << endl;

    cout << "delete edge : " << endl;
    g.removeEdge(0, 1);
    cout << "eCount : " <<g.eCount() << endl;

    g.setVertex(0, 100);
    cout << "V(0) : " << g.getVertex(0) << endl;
    cout << "W(0, 1) : " << g.getEdge(0, 1) << endl; // 抛异常
    return 0;
}