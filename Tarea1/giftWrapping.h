//
// Created by wororo on 23-05-17.
//

#ifndef TAREA1_GIFTWRAPPING_H
#define TAREA1_GIFTWRAPPING_H

#include <vector>
#include <ctime>
#include "Point.h"
#include "Polygon.h"

template<class T>
class GiftWrapping {

    #define BILLION 1E9

public:
    GiftWrapping() {};

    Point<T> leftMost(std::vector<Point<T>> points) {
        T minX = points[0].X;
        Point<T> result = points[0];
        for (int i = 1; i < points.size(); i++){
            if(minX > points[i].X){
                result = points[i];
                minX = result.X;
            }
        }
        return result;
    }

    Polygon<T> giftWrapping(std::vector<Point<T>> points) {
        struct timespec requestStart, requestEnd;
        clock_gettime(CLOCK_REALTIME,&requestStart);

        Point<T> pointOnHull = leftMost(points);
        Point<T> left = pointOnHull;
        Polygon<T> convex;
        do{
            Point<T> endpoint = points[0];
            for(int i= 0;i<points.size();i++){
                Segment<T> s(endpoint, pointOnHull);
                if(endpoint == pointOnHull || s.isLeft(points[i])){
                    endpoint = points[i];
                }
            }
            convex.add(pointOnHull);
            pointOnHull = endpoint;

        } while (left != pointOnHull);

        clock_gettime(CLOCK_REALTIME,&requestEnd);
        double accum = ( requestEnd.tv_sec - requestStart.tv_sec )
                       + ( requestEnd.tv_nsec - requestStart.tv_nsec )
                         / BILLION;
        printf("GiftWrapping elapsed time: %lf (ms)\n", accum*1000);
        return convex;
    }
};


#endif //TAREA1_GIFTWRAPPING_H
