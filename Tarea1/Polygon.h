//
// Definición y operaciones de un polígono:
// http://www.vitutor.net/2/1/1.html
//
// Inside:
// http://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/
// http://stackoverflow.com/questions/217578/how-can-i-determine-whether-a-2d-point-is-within-a-polygon
//
// Created by wororo on 06-04-17.
//

#ifndef TAREA1_POLYGON_H
#define TAREA1_POLYGON_H


#include <vector>
#include "Point.h"
#include "Segment.h"

//Solo en 2D;
template<class T>
class Polygon {
public:
    std::vector<Point<T>> Points;

    bool isCCW() {
        double sum = 0;
        for (int i = 0; i < Points.size(); ++i) {
            Point<T> p1, p2;
            p1 = Points[i];
            p2 = Points[(i + 1) % Points.size()];
            sum += (p2.X - p1.X) * (p2.Y + p1.Y);
        }
        return sum < 0;
    }

    template<class T2>
    bool isInside(Point<T2> &p) {
        int size = Points.size();

        if (size == 0)
            return false;

        if (size == 1)
            return Points[0] == p;

        if (size == 2) {
            Segment<T> s(Points[0], Points[1]);
            return s.isOn(p);
        }

        //Size > 2: ray casting
        Segment<T> ray(p, Point<T>(p.Y, -INFINITY));


        int count = 0;
        for (int i = 0; i < size; ++i) {
            Segment<T> s1(Points[i], Points[(i + 1) % Points.size()]);
            if (s1.isOver(p))
                return true;

            if (s1.Point1.Y == s1.Point2.Y)
                continue;

            if (ray.isOver(s1.Point1)) {
                if (s1.Point1.Y > s1.Point2.Y)
                    count++;
            } else if (ray.isOver(s1.Point2)) {
                if (s1.Point2.Y > s1.Point1.Y)
                    count++;
            } else if (ray.Intersects(s1))
                count++;

        }
        //Impar:
        return count % 2 == 1;
    }
};

#endif //TAREA1_POLYGON_H
