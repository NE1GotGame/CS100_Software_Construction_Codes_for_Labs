#include <iostream>

void foo(int x)
{
    std::cout<<x<<std::endl;
}

int main()
{
    int x;
    int r=4;
    int y=x+r;

    foo(y);
    
    return 0;
}
