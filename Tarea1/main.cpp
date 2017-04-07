#include <iostream>
#include "Point.h"

int main() {
    Point<double> p1;
    p1.X = 2.4;
    p1.Y = 4.5;

    printf("P1");
    p1.ToString();

    Point<int> p2 (3,5);

    p1 += p2;

    printf("P2");
    p2.ToString();

    Point<double> p3 = p1 + p2;

    printf("P1");
    p1.ToString();

    printf("P2");
    p2.ToString();

    printf("P3");
    p3.ToString();

    return 0;
}