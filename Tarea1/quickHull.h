//
// Created by wororo on 27-05-17.
//

#ifndef TAREA1_QUICKHULL_H
#define TAREA1_QUICKHULL_H


#include <vector>
#include "Point.h"
#include "Polygon.h"

template<class T>
class QuickHull {

public:
    QuickHull() {};

    Point <T> leftMost(std::vector <Point<T>> points) {
        T minX = points[0].X;
        Point <T> result = points[0];
        for (int i = 1; i < points.size(); i++) {
            if (minX > points[i].X) {
                result = points[i];
                minX = result.X;
            }
        }
        return result;
    }

    Point <T> rightMost(std::vector <Point<T>> points) {
        T maxX = points[0].X;
        Point <T> result = points[0];
        for (int i = 1; i < points.size(); i++) {
            if (maxX < points[i].X) {
                result = points[i];
                maxX = result.X;
            }
        }
        return result;
    }

    double distance(Segment<T> s, Point<T> p){
        double x1 = s.Point1.X, y1 = s.Point1.Y,
                x2 = s.Point2.X, y2 = s.Point2.Y,
                x0 = p.X, y0 = p.Y;
        return abs((y2 - y1)*x0 - (x2 - x1)*y0 + x2*y1 - y2*x1)/(sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2)));
    }

    Point<T> farthestPoint(std::vector<Point<T>> Sk, Point<T> P, Point<T> Q){
        Segment<T> s(P,Q);
        double maxDistance = -1;
        Point<T> p;
        for (int i = 0; i < Sk.size(); ++i) {
            double tmp = distance(s,Sk[i]);
            if(tmp >maxDistance){
                maxDistance =tmp;
                p = Sk[i];
            }
        }
        return p;
    }

    std::vector<Point<T>> FindHull(std::vector<Point<T>> Sk, Point<T> P, Point<T> Q){
        std::vector<Point<T>> s;
        if(Sk.size() == 0)
            return s;
        Point<T> C = farthestPoint(Sk, P, Q);

    }

    Polygon<T> quickHull(std::vector<Point<T>> points) {
        Polygon<T> convex;
        Point<T> left = leftMost(points);
        Point<T> right = rightMost(points);
        convex.add(left);
        convex.add(right);

        std::vector<Point<T>> S1;
        std::vector<Point<T>> S2;

        Segment<T> s(left, right);

        for (int i = 0; i < points.size(); ++i) {
            if(points[i] == left) continue;
            if(points[i] == right) continue;

            if(s.isRight(points[i]))
                S1.push_back(points[i]);
            if(s.isLeft(points[i]))
                S2.push_back(points[i]);
        }
        std::vector<Point<T>> hull1 = FindHull(S1, left, right);
        std::vector<Point<T>> hull2 = FindHull(S2, right, left);
        //TODO: Agregar esas weas al hull;
    }

//    FindHull (Sk, P, Q)
//    {
//        // Find points on convex hull from the set Sk of points
//        // that are on the right side of the oriented line from P to Q
//        If Sk has no point, then return.

//        From the given set of points in Sk, find farthest point, say C, from segment PQ

//        Add point C to convex hull at the location between P and Q
//        Three points P, Q, and C partition the remaining points of Sk into 3 subsets: S0, S1, and S2
//        where S0 are points inside triangle PCQ, S1 are points on the right side of the oriented
//        line from  P to C, and S2 are points on the right side of the oriented line from C to Q.
//                FindHull(S1, P, C)
//        FindHull(S2, C, Q)
//    }
//    Output = convex hull



//    QuickHull (S)
//    {
//        // Find convex hull from the set S of n points
//        Convex Hull := {}
//        Find left and right most points, say A & B, and add A & B to convex hull

//        Segment AB divides the remaining (n-2) points into 2 groups S1 and S2
//        where S1 are points in S that are on the right side of the oriented line from A to B,
//        and S2 are points in S that are on the right side of the oriented line from B to A
//        FindHull (S1, A, B)
//        FindHull (S2, B, A)
//    }
};

#endif //TAREA1_QUICKHULL_H
