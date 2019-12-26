#include <stdio.h>
struct Rectangle
{
    int length;
    int breadth;
};
int CalculateArea(struct Rectangle rectangle)
{
    return rectangle.breadth * rectangle.length;
}
int main(int argc, const char * argv[]) {
    struct Rectangle r = {12, 23};
    int area = CalculateArea(r);
    printf("%d\n", area);
    return 0;
}
