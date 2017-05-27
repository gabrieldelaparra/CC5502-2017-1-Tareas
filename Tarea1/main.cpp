#include <iostream>
#include "Point.h"
#include "Vector.h"
#include "Segment.h"
#include "Polygon.h"
#include "giftWrapping.h"
#include "quickHull.h"

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
    printf("%s\n", p1 == pEq ? "true" : "false");

    Point<int> p2(3, 5);

    printf("P2: ");
    p2.ToString();

    printf("OP: p2 == pEq: ");
    printf("%s\n", p2 == pEq ? "true" : "false");

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

    Vector<double> v1(3, 4);

    Vector<double> vP(p1);
    printf("vP1: ");
    vP.ToString();

    printf("v1: ");
    v1.ToString();

    printf("Length v1: %.2f\n", v1.Length());

    Vector<double> unit;
    unit = v1.UnitVector();
    unit.ToString();
    printf("Length unit: %.2f\n", unit.Length());

    v1.Point2.X = 2.9999999999999999;
    v1.Point2.Y = 3.9999999999999999;
    unit = v1.UnitVector();
    unit.ToString();
    printf("Length unit: %.2f\n", unit.Length());

    v1.Point2.X = 2.999999999999999999;
    v1.Point2.Y = 3.999999999999999999;
    unit = v1.UnitVector();
    unit.ToString();
    printf("Length unit: %.2f\n", unit.Length());

    Vector<double> v2(3, 4);
    printf("OP: v1 == v2: ");
    printf("%s\n", v1 == v2 ? "true" : "false");

    Vector<double> vX(1, 0);
    Vector<double> vY(0, 1);
    Vector<double> vZ;
    vZ = vX.Cross(vY);
    printf("vX: ");
    vX.ToString();
    printf("vY: ");
    vY.ToString();
    printf("vZ = vX x vY: ");
    vZ.ToString();

    double dot = vX.Dot(vY);
    printf("dot = vX . vY: %.2f\n", dot);

    dot = v1.Dot(vP);
    printf("dot = v1 . vP: %.2f\n", dot);
    printf("vP1: ");
    vP.ToString();

    printf("v1: ");
    v1.ToString();


    //double, mantisa 16, funciona
    v1.Point2.X = 2.999999999999999;
    v1.Point2.Y = 3.999999999999999;

    v2.Point2.X = 2.999999999999999;
    v2.Point2.Y = 3.999999999999999;

    dot = v1.Dot(v2);
    printf("dot = v1 . v2: %.20f\n", dot);

    //double, mantisa 17, explota
    v1.Point2.X = 2.9999999999999999;
    v1.Point2.Y = 3.9999999999999999;

    v2.Point2.X = 2.9999999999999999;
    v2.Point2.Y = 3.9999999999999999;

    dot = v1.Dot(v2);
    printf("dot = v1 . v2: %.20f\n", dot);

    //TODO: Falta probar con primos grandes


    printf("\nSegmentos:\n\n");

    //recta diagonal (1,1)
    Segment<double> s1(0, 0, 0, 1, 1, 0);
    printf("Segment: ");
    s1.ToString();

    Point<double> ps1(1, 0);
    printf("L: %d R*: %d On: %d\n", s1.isLeft(ps1), s1.isRight(ps1), s1.isOn(ps1));
    ps1.X = 0;
    ps1.Y = 1;
    printf("L*: %d R: %d On: %d\n", s1.isLeft(ps1), s1.isRight(ps1), s1.isOn(ps1));
    ps1.X = 1;
    ps1.Y = 1;
    printf("L: %d R: %d On*: %d\n", s1.isLeft(ps1), s1.isRight(ps1), s1.isOn(ps1));

    ps1.X = 2;
    ps1.Y = 2;
    printf("L: %d R: %d On*: %d\n", s1.isLeft(ps1), s1.isRight(ps1), s1.isOn(ps1));

    ps1.X = .9;
    ps1.Y = 1;
    printf("L*: %d R: %d On: %d\n", s1.isLeft(ps1), s1.isRight(ps1), s1.isOn(ps1));

    //double, manstisa 16 acierta.
    ps1.X = 0.9999999999999999;
    ps1.Y = 1;
    printf("L*: %d R: %d On: %d\n", s1.isLeft(ps1), s1.isRight(ps1), s1.isOn(ps1));

    //double, mantisa 16 acierta.
    ps1.X = 1;
    ps1.Y = 1.000000000000001;
    printf("L*: %d R: %d On: %d\n", s1.isLeft(ps1), s1.isRight(ps1), s1.isOn(ps1));

    //double, manstisa 17 falla.
    ps1.X = 0.99999999999999999;
    ps1.Y = 1;
    printf("L*: %d R: %d On: %d\n", s1.isLeft(ps1), s1.isRight(ps1), s1.isOn(ps1));

    //double, manstisa 17 falla.
    ps1.X = 1;
    ps1.Y = 1.0000000000000001;
    printf("L*: %d R: %d On: %d\n", s1.isLeft(ps1), s1.isRight(ps1), s1.isOn(ps1));

    //Valores grandes:
    Segment<double> s2(0, 0, 0, 1234567890123456, 1234567890123456, 0);
    printf("Segment2: ");
    s1.ToString();

    Point<double> ps2(1, 0);
    printf("L: %d R*: %d On: %d\n", s1.isLeft(ps1), s1.isRight(ps1), s1.isOn(ps1));

    //Prueba con primos:
    ps1.X = 961748941;
    ps1.Y = 961748941;
    printf("L: %d R: %d On*: %d\n", s1.isLeft(ps1), s1.isRight(ps1), s1.isOn(ps1));

    Segment<double> is1(1, 0, 0, 1, 2, 0);
    Segment<double> is2(0, 1, 0, 2, 1, 0);

    is1.ToString();
    is2.ToString();
    printf("Intersects: %d\n", is1.Intersects(is2));

    printf("\nPolygon:\n\n");

    Polygon<double> pol1;

    pol1.Points = {Point<double>(1, 1), Point<double>(3, 1), Point<double>(3, 3), Point<double>(1, 1)};
    printf("isCCW*: %d\n", pol1.isCCW());

    pol1.Points = {Point<double>(1, 3), Point<double>(3, 3), Point<double>(3, 1), Point<double>(1, 1)};
    printf("isCCW: %d\n", pol1.isCCW());

    pol1.Points = {Point<double>(1, 1), Point<double>(3, 1), Point<double>(3, 3), Point<double>(1, 1)};
    ps1.X = 1;
    ps1.Y = 1;
    ps1.ToString();
    printf("pol1.isInside(ps1): %d\n", pol1.isInside(ps1));

    ps1.X = 3;
    ps1.Y = 3;
    ps1.ToString();
    printf("pol1.isInside(ps1): %d\n", pol1.isInside(ps1));

    ps1.X = 2;
    ps1.Y = 2;
    ps1.ToString();
    printf("pol1.isInside(ps1): %d\n", pol1.isInside(ps1));

    ps1.X = 0;
    ps1.Y = 0;
    ps1.ToString();
    printf("pol1.isInside(ps1): %d\n", pol1.isInside(ps1));

    ps1.X = 4;
    ps1.Y = 4;
    ps1.ToString();
    printf("pol1.isInside(ps1): %d\n", pol1.isInside(ps1));

    ps1.X = -1;
    ps1.Y = -1;
    ps1.ToString();
    printf("pol1.isInside(ps1): %d\n", pol1.isInside(ps1));

    ps1.X = -1;
    ps1.Y = 2;
    ps1.ToString();
    printf("pol1.isInside(ps1): %d\n", pol1.isInside(ps1));

    std::vector<Point<double>> d = {Point<double>(1, 1), Point<double>(3, 1), Point<double>(2, 3), Point<double>(2, 2)};
    GiftWrapping<double> gw;
    printf("Leftmost:");
    gw.leftMost(d).ToString();
    printf("CH\n");
    gw.giftWrapping(d).ToString();


    std::vector<Point<double>> d2 = {Point<double>(5, 5),
                                     Point<double>(1, 1),
                                     Point<double>(3, 2),
                                     Point<double>(0, 10),
                                     Point<double>(2, 3),
                                     Point<double>(4, 7),
                                     Point<double>(11, 1),
                                     Point<double>(5, 2),
                                     Point<double>(8, 4),
                                     Point<double>(10, 11),
                                     Point<double>(8, 8)};
    printf("CH\n");
    gw.giftWrapping(d2).ToString();
    QuickHull<double> qh;

    printf("QH\n");
    qh.quickHull(d2).ToString();


    return 0;
}