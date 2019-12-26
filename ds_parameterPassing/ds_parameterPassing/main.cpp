
#include <iostream>


void Swap(int &x, int &y) //call by reference,  as one method can't access the variables of another method's,
//the main() method will copy this content inside it. so use this technique carefully.
{
    int temp = x;
    x = y;
    y = temp;
    
}

void Swap2(int *x, int *y) //call by pointer
{
    int temp = *x;
    *x = *y;
    *y = temp;
    
}

int main(int argc, const char * argv[]) {
    int a = 10, b = 12;
    std::cout <<"a = " << a << "b = " <<b;
    Swap(a, b); // call by value but recieved by reference
    Swap2(&a, &b); //call by reference but received by pointer
    std::cout <<"\na = " << a << "b = " <<b;
    std::cout << "\n";
    return 0;
}
