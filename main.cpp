#include <iostream>
#include "Full.h"
int main()
{
    Full<int> f(5);
    f.print();

    f.pushBack(14);
    f.print();
    f.pushBack(4);
    f.print();
    f.pushFront(2001);
    f.print();
    f.popFront(2);
    f.print();

    Full<char> f1(5);
    f.pushBack('L');
    f.pushBack('A');
    f.pushBack('B');
    f.pushBack('A');
    f.pushBack('4');
    f.print();

    return 0;
}
