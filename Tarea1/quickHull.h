//
// Created by wororo on 27-05-17.
//

#ifndef TAREA1_QUICKHULL_H
#define TAREA1_QUICKHULL_H


#include <vector>
#include <algorithm>
#include <ctime>
#include "Point.h"
#include "Polygon.h"

template<class T>
class QuickHull {

    #define BILLION 1E9

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
            if(tmp >= maxDistance){
                maxDistance =tmp;
                p = Sk[i];
            }
        }
        return p;
    }

    void FindHull(std::vector<Point<T>> Sk, Point<T> P, Point<T> Q, Polygon<T> *convex){
        if(Sk.size() == 0)
            return;

        Point<T> C = farthestPoint(Sk, P, Q);

        std::vector<Point<T>> S1;
        Segment<T> s1(P, C);
        for (int i = 0; i < Sk.size(); ++i) {
            if (Sk[i] == P) continue;
            if (Sk[i] == C) continue;

            if (s1.isRight(Sk[i]))
                S1.push_back(Sk[i]);
        }

        if(std::find(convex->Points.begin(), convex->Points.end(), P) == convex->Points.end()) {
            convex->add(P);
        }
        FindHull(S1, P, C, convex);

        std::vector<Point<T>> S2;
        Segment<T> s2(C, Q);
        for (int i = 0; i < Sk.size(); ++i) {
            if (Sk[i] == Q) continue;
            if (Sk[i] == C) continue;

            if (s2.isRight(Sk[i]))
                S2.push_back(Sk[i]);
        }

        if(std::find(convex->Points.begin(), convex->Points.end(), C) == convex->Points.end()) {
            convex->add(C);
        }

        FindHull(S2, C, Q, convex);

        if(std::find(convex->Points.begin(), convex->Points.end(), Q) == convex->Points.end()) {
            convex->add(Q);
        }
    }

    Polygon<T> quickHull(std::vector<Point<T>> points) {
        struct timespec requestStart, requestEnd;
        clock_gettime(CLOCK_REALTIME,&requestStart);

        Polygon<T> convex;
        Point<T> left = leftMost(points);
        Point<T> right = rightMost(points);

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

        FindHull(S1, left, right, &convex);
        FindHull(S2, right, left, &convex);

        clock_gettime(CLOCK_REALTIME,&requestEnd);
        double accum = ( requestEnd.tv_sec - requestStart.tv_sec )
                       + ( requestEnd.tv_nsec - requestStart.tv_nsec )
                         / BILLION;
        printf("QuickHull elapsed time: %lf (ms)\n", accum*1000);

        return convex;
    }
};

#endif //TAREA1_QUICKHULL_H
