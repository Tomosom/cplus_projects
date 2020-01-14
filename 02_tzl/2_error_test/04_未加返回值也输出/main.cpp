#include <iostream>

using namespace std;

int *rrrt()
{
    int *ii = new int;
    *ii = 9;
}

int main()
{
    cout << *( rrrt() ) << endl;
    return 0;
}

