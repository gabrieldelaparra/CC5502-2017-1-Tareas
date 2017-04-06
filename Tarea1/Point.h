//
// Created by wororo on 06-04-17.
//
#include <iostream>
#include <stdio.h>

using namespace std;

#ifndef TAREA1_POINT_H
#define TAREA1_POINT_H


class Point{
public:
    double X = 0;
    double Y = 0;
    double Z = 0;


    bool operator== (Point& otherPoint) {
        return X == otherPoint.X && Y == otherPoint.Y && Z == otherPoint.Z;
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

    void ToString() const {
        printf("X: %.3f Y: %.3f Z: %.3f\n ", X, Y, Z);
    }
};


#endif //TAREA1_POINT_H
