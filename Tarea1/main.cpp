#include <iostream>
#include "Point.h"
#include "Vector.h"
#include "Segment.h"

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

    v1.Point2.X = 2.9999999999999999;
    v1.Point2.Y = 3.9999999999999999;
    unit = v1.UnitVector();
    unit.ToString();
    printf("Magnitude unit: %.2f\n", unit.Magnitude());

    v1.Point2.X = 2.999999999999999999;
    v1.Point2.Y = 3.999999999999999999;
    unit = v1.UnitVector();
    unit.ToString();
    printf("Magnitude unit: %.2f\n", unit.Magnitude());

    Vector<double> v2 (3,4);
    printf("OP: v1 == v2: ");
    printf("%s\n",v1==v2 ? "true" : "false");

    Vector<double> vX (1,0);
    Vector<double> vY (0,1);
    Vector<double> vZ;
    vZ = vX.Cross(vY);
    printf("vX: ");
    vX.ToString();
    printf("vY: ");
    vY.ToString();
    printf("vZ = vX x vY: ");
    vZ.ToString();

    double dot = vX.Dot(vY);
    printf("dot = vX . vY: %.2f\n",dot);

    dot = v1.Dot(vP);
    printf("dot = v1 . vP: %.2f\n",dot);
    printf("vP1: ");
    vP.ToString();

    printf("v1: ");
    v1.ToString();

    printf("\nSegmentos:\n\n");

    //recta diagonal
    Segment<double> s1 (0,0,0,1,1,0);
    printf("Segment: ");
    s1.ToString();

    Point<double> ps1 (1,0);
    printf("L: %d R: %d On: %d\n",s1.isLeft(ps1), s1.isRight(ps1), s1.isOn(ps1));
    ps1.X=0; ps1.Y=1;
    printf("L: %d R: %d On: %d\n",s1.isLeft(ps1), s1.isRight(ps1), s1.isOn(ps1));
    ps1.X=1; ps1.Y=1;
    printf("L: %d R: %d On: %d\n",s1.isLeft(ps1), s1.isRight(ps1), s1.isOn(ps1));

    ps1.X=.9; ps1.Y=1;
    printf("L: %d R: %d On: %d\n",s1.isLeft(ps1), s1.isRight(ps1), s1.isOn(ps1));

    //con 16 decimales acierta. Con más falla.
    ps1.X=.9999999999999999; ps1.Y=1;
    printf("L: %d R: %d On: %d\n",s1.isLeft(ps1), s1.isRight(ps1), s1.isOn(ps1));

    //con >= 17 decimales falla.
    ps1.X=.99999999999999999; ps1.Y=1;
    printf("L: %d R: %d On: %d\n",s1.isLeft(ps1), s1.isRight(ps1), s1.isOn(ps1));
    return 0;
}