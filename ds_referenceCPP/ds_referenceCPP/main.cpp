//a reference is a nickname or alias given to a variable, why we need?
//this is very useful in parameter passing

#include <iostream>


int main(int argc, const char * argv[]) {
    
    int a = 10;
    int &r = a; //a reference variable to another variable 'a'. and initialized
    
    std::cout <<a <<" = a\n";
    std::cout <<r <<" = r\n";
    a++;
    std::cout <<a <<" = a\n";
    std::cout <<r <<" = r\n";
    r++;
    std::cout <<a <<" = a\n";
    std::cout <<r <<" = r\n";
    
    return 0;
}
