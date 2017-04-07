#include <iostream>
#include "Point.h"
#include "Vector.h"

int main() {

    printf("\nPuntos:\n\n");

    Point<double> p1;
    p1.X = 2.4;
    p1.Y = 4.5;

    printf("P1: ");
    p1.ToString();

    Point<double> pEq;
    pEq.X = 2.4;
    pEq.Y = 4.5;

    printf("PEQ: ");
    p1.ToString();

    printf("OP: p1 == pEq: ");
    printf("%s\n",p1==pEq ? "true" : "false");

    Point<int> p2 (3,5);

    printf("P2: ");
    p2.ToString();

    printf("OP: p2 == pEq: ");
    printf("%s\n",p2==pEq ? "true" : "false");

    printf("OP: p1 += p2:\n");
    p1 += p2;

    printf("P1: ");
    p1.ToString();

    printf("OP: p3 = p1 + p2:\n");
    Point<double> p3 = p1 + p2;

    printf("P1: ");
    p1.ToString();

    printf("P2: ");
    p2.ToString();

    printf("P3: ");
    p3.ToString();

    printf("\nVectores:\n\n");

    Vector<double> v1 (3,4);

    Vector<double> vP (p1);
    printf("vP1: ");
    vP.ToString();

    printf("v1: ");
    v1.ToString();

    printf("Magnitude v1: %.2f\n", v1.Magnitude());

    Vector<double> unit;
    unit = v1.UnitVector();
    unit.ToString();
    printf("Magnitude unit: %.2f\n", unit.Magnitude());

    return 0;
}