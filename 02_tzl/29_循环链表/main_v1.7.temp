#include <iostream>
#include "circle_list.h"

using namespace std;
using namespace DTLib;


 /* 约瑟夫环问题
    n : 多少个人玩这个游戏
    s : 从第几个人开始报数
    m : 报到第几个数
  */
void josephus(int n, int s, int m)
{
    CircleList<int> c;

    for(int i = 1; i <= n; i++) {
        c.insert(i);
    }

//    for (c.move(0); !c.end(); c.next()) {
//        cout << c.current() << endl;
//    }

    //c.move(0);

    cout << "--------" << endl;

    c.move(s-1, m-1);
#if 1

    while (c.length() > 0) {
        c.next();
        cout << c.current() << endl;
        c.remove(c.find(c.current()));
    }
#endif

}

int main(int argc, char **argv)
{

    josephus(41, 1, 3);

	return 0;

}
