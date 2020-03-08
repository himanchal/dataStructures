#include <iostream>
class Diagonal{
private:
    int *A;
    int n;
public:
    Diagonal(){
        n = 2;
        A = new int[2];
    }
    Diagonal(int n){
        this->n = n;
        A = new int[n];
    }
    ~Diagonal(){
        delete []A;
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};

void Diagonal::Set(int i, int j, int x){
    if (i == j) A[i- 1] = x;
}
int Diagonal::Get(int i, int j){
    if (i == j) return A[i - 1];
    else return 0;
}
void Diagonal::Display(){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) std::cout<<A[i]<<" ";
            else std::cout<<"0 ";
        }
        std::cout<<"\n";
    }
}
int main(int argc, const char * argv[]) {
    Diagonal d(4);
    d.Set(1, 1, 5);
    d.Set(2, 2, 2);
    d.Set(3, 3, 6);
    d.Set(4, 4, 8);
    d.Display();
    return 0;
}
