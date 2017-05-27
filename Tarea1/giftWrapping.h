//
// Created by wororo on 23-05-17.
//

#ifndef TAREA1_GIFTWRAPPING_H
#define TAREA1_GIFTWRAPPING_H

#include <vector>
#include "Point.h"
#include "Polygon.h"

template<class T>
class GiftWrapping {

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
        return convex;
    }
};


#endif //TAREA1_GIFTWRAPPING_H
