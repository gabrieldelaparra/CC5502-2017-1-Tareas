//
// Left or Right?:
// http://stackoverflow.com/questions/1560492/how-to-tell-whether-a-point-is-to-the-right-or-left-side-of-a-line
// http://stackoverflow.com/questions/22668659/calculate-on-which-side-of-a-line-a-point-is
//
// Created by wororo on 06-04-17.
//

#ifndef TAREA1_SEGMENT_H
#define TAREA1_SEGMENT_H

#include <iostream>
#include <cmath>
#include "Point.h"

template<class T>
class Segment {
private:
    template<class T2>
    double _positionOfPoint(Point<T2> &p) {
        return _positionOfPoint(Point2, Point1, p);
        //return ((Point2.X - Point1.X) * (T(p.Y) - Point1.Y)) - ((Point2.Y - Point1.X) * (T(p.X) - Point1.X));
    }

    template<class T2>
    double _positionOfPoint(Point<T> &p1, Point<T> &p2, Point<T2> &p3) {
        return (p1.X - T(p3.X)) * (p2.Y - T(p3.Y)) - (p2.X - T(p3.X)) * (p1.Y - T(p3.Y));
    }

public:
    Point<T> Point1 = Point<T>(0, 0, 0);
    Point<T> Point2 = Point<T>(0, 0, 0);

    Segment() {};

    Segment(T x1, T y1, T x2, T y2) : Point1(x1, y1, 0), Point2(x2, y2, 0) {};

    Segment(T x1, T y1, T z1, T x2, T y2, T z2) : Point1(x1, y1, z1), Point2(x2, y2, z2) {};

    Segment(Point<T> p1, Point<T> p2) : Point1(p1), Point2(p2) {};

    template<class T2>
    int positionOfPoint(Point<T2> &p) {
        if (isLeft(p))
            return -1;
        else if (isRight(p))
            return 1;
        else return 0;
    }

    template<class T2>
    bool isLeft(Point<T2> &p) {
        return _positionOfPoint(p) < 0;
    }

    template<class T2>
    bool isRight(Point<T2> &p) {
        return _positionOfPoint(p) > 0;
    }

    template<class T2>
    bool isOn(Point<T2> &p) {
        return _positionOfPoint(p) == 0;
    }

    template<class T2>
    bool isBetween(Point<T> &p1, Point<T> &p2, Point<T2> &p){
        return Length(p1, p) + Length(p, p2) == Length(p1, p2);
    }

    template<class T2>
    bool isOver(Point<T2> &p) {
        return isOn(p) &&
                isBetween(Point1, Point2, p);
    }

    template<class T2>
    bool Intersects(Segment<T2> &s) {
        return ((std::max(Point1.X, Point2.X) >= std::min(s.Point1.X, s.Point2.X)) &&
                (std::max(s.Point1.X, s.Point2.X) >= std::min(Point1.X, Point2.X)) &&
                (std::max(Point1.Y, Point2.Y) >= std::min(s.Point1.Y, s.Point2.Y)) &&
                (std::max(s.Point1.Y, s.Point2.Y) >= std::min(Point1.Y, Point2.Y)) &&
                (_positionOfPoint(s.Point1, Point2, Point1) * _positionOfPoint(Point2, s.Point2, Point1) >= 0) &&
                (_positionOfPoint(Point1, s.Point2, s.Point1) * _positionOfPoint(s.Point2, Point2, s.Point1) >= 0)
        );
    }

    double Length(Point<T> &p1, Point<T> &p2){
        return std::sqrt(std::pow(p2.X - p1.X, 2)
                         + std::pow(p2.Y - p1.Y, 2)
                         + std::pow(p2.Z - p1.Z, 2));
    }

    double Length() {
        return Length(Point1, Point2);
    }

    template<class T2>
    bool operator==(Segment<T2> &s2) {
        return Point1.X == T(s2.Point1.X)
               && Point1.Y == T(s2.Point1.Y)
               && Point1.Z == T(s2.Point1.Z)
               && Point2.X == T(s2.Point2.X)
               && Point2.Y == T(s2.Point2.Y)
               && Point2.Z == T(s2.Point2.Z);
    }

    void ToString() const {
        std::cout << "( (" << Point1.X
                  << ", " << Point1.Y
                  << ", " << Point1.Z
                  << "), (" << Point2.X
                  << ", " << Point2.Y
                  << ", " << Point2.Z
                  << ") )"
                  << std::endl;
    }

};

#endif //TAREA1_SEGMENT_H
