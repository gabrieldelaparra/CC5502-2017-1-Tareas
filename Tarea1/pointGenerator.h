//
// Created by wororo on 27-05-17.
//

#ifndef TAREA1_POINTGENERATOR_H
#define TAREA1_POINTGENERATOR_H

#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Point.h"

template<class T>
class PointGenerator {

public:
    PointGenerator() {};

    std::vector<Point<T>> generatePoints(int size, int max){
        std::vector<Point<T>> points;
        srand (time(NULL));

        for (int i = 0; i < size; i++) {
            Point<T> p(rand() % max, rand() % max);
            points.push_back(p);
        }
        return points;
    }
};

#endif //TAREA1_POINTGENERATOR_H
