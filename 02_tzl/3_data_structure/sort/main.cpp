#include <iostream>
#include "sort.h"

using namespace std;
using namespace DTLib;

int main(int argc, char **argv)
{
    int array[] = {3,1,2,5,4,9,8,7};

    int len = sizeof(array) / sizeof(int);

    //Sort::Select(array, len, true);
    //Sort::Select(array, len, false);

    //Sort::Insert(array, len, true);
    //Sort::Insert(array, len, false);

    //Sort::Bubble(array, len, true);
    //Sort::Bubble(array, len, false);

    //Sort::Shell_from_insert(array, len, true);
    //Sort::Shell_from_insert(array, len, false);
    //Sort::Shell_from_bubble(array, len, true);
    //Sort::Shell_from_bubble(array, len, false);

    //Sort::Merge(array, len, true);
    Sort::Merge(array, len, false);

    for (int i = 0; i < len; i++) {
        cout << array[i] << endl;
    }


    return 0;
}
