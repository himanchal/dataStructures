#include <iostream>
void function(int x)
{
    if (x > 0)
    {
        function(x - 1); //head recursion
        std::cout<<x<<"\n";
    }
}
void function2(int x)
{
    if (x > 0)
    {
        std::cout<<x<<"\n";
        function2(x - 1); //tail recursion
    }
}
int main(int argc, const char * argv[])
{
    function(3);
    std::cout<<"=======================\n";
    function2(3);
    return 0;
}
