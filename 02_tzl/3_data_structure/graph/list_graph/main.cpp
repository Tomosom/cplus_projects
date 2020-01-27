#include <iostream>
#include "list_graph.h"

using namespace std;
using namespace DTLib;

int main(int argc, char **argv)
{
    // ListGraph<char, int> g(4);
    // g.setVertex(0, 'A');
    // g.setVertex(1, 'B');
    // g.setVertex(2, 'C');
    // g.setVertex(3, 'D');
    
    ListGraph<char, int> g;
    g.addVertex('A');
    g.addVertex('B');
    g.addVertex('C');
    g.addVertex('D');
    
    // g.removeVertex();

    for (int i = 0; i < g.vCount(); i++) {
        cout << i << " : " << g.getVertex(i) << endl;
    }

    g.setEdge(0, 1, 5);
    g.setEdge(0, 3, 6);
    g.setEdge(1, 2, 8);
    g.setEdge(2, 3, 2);
    g.setEdge(3, 1, 9);

    cout << "W(0, 1) : " << g.getEdge(0, 1) << endl;
    cout << "W(0, 3) : " << g.getEdge(0, 3) << endl;
    cout << "W(1, 2) : " << g.getEdge(1, 2) << endl;
    cout << "W(2, 3) : " << g.getEdge(2, 3) << endl;
    cout << "W(3, 1) : " << g.getEdge(3, 1) << endl;

    cout << "eCount : " << g.eCount() << endl;

    // g.removeEdge(3, 1);
    cout << "eCount : " << g.eCount() << endl;
    // cout << "W(3, 1) : " << g.getEdge(3, 1) << endl; // 抛异常

    SharedPointer< Array<int> > aj = g.getAdjacent(0);
    for (int i = 0; i < aj->length(); i++) {
        cout << (*aj)[i] << endl;
    }

    cout << "ID(1) : " << g.ID(1) << endl;
    cout << "OD(1) : " << g.OD(1) << endl;
    cout << "TD(1) : " << g.TD(1) << endl;

    g.removeVertex();

    cout << "eCount : " << g.eCount() << endl;
    cout << "W(0, 1) : " << g.getEdge(0, 1) << endl;
    cout << "W(1, 2) : " << g.getEdge(1, 2) << endl;
    // cout << "W(2, 3) : " << g.getEdge(2, 3) << endl;
    return 0;
}

