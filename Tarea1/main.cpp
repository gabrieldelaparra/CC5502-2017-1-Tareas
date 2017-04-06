#include <iostream>
#include <stdio.h>

using namespace std;

class Point{
public:
    double X = 0;
    double Y = 0;
    double Z = 0;


    bool operator== (Point& otherPoint) {
        return Y == otherPoint.X && Y == otherPoint.Y;
    }

    Point operator+ (Point &otherPoint) {
        Point newPoint;

        newPoint.X = X + otherPoint.X;
        newPoint.Y = Y + otherPoint.Y;
        newPoint.Z = Z + otherPoint.Z;

        return newPoint;
    }

    Point operator- (Point &otherPoint){
        Point newPoint;

        newPoint.X = X - otherPoint.X;
        newPoint.Y = Y - otherPoint.Y;
        newPoint.Z = Z - otherPoint.Z;

        return newPoint;
    }

    Point& operator+= (Point &otherPoint) {
        X = X + otherPoint.X;
        Y = Y + otherPoint.Y;
        Z = Z + otherPoint.Z;

        return (*this);
    }

    Point& operator-= (Point &otherPoint) {
        X = X - otherPoint.X;
        Y = Y - otherPoint.Y;
        Z = Z - otherPoint.Z;

        return (*this);
    }

    Point Substract(Point &p){
        Point newPoint;

        newPoint.X = X - p.X;
        newPoint.Y = Y - p.Y;
        newPoint.Z = Z - p.Z;

        return newPoint;
    }

    void ToString() const {
        printf("X: %.3f Y: %.3f Z: %.3f\n ", X, Y, Z);
    }
};

int main() {
    Point p1;
    p1.X = 2.4;
    p1.Y = 4.5;

    printf("P1");
    p1.ToString();

    Point p2;
    p2.X = 3;
    p2.Y = 3;

    p1 += p2;

    printf("P2");
    p2.ToString();

    Point p3 = p1 + p2;

    printf("P1");
    p1.ToString();

    printf("P2");
    p2.ToString();

    printf("P3");
    p3.ToString();

    return 0;
}