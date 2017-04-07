//
// Created by wororo on 06-04-17.
//

#ifndef TAREA1_POINT_H
#define TAREA1_POINT_H

template <class T>
class Point{
public:
    Point() :X(T()), Y(T()){};
    Point(T x, T y) : X(x) , Y(y) {};

    T X = 0;
    T Y = 0;

    template <class T2>
    bool operator== (Point<T2>& otherPoint) {
        return X == T(otherPoint.X) && Y == T(otherPoint.Y);
    }

    template <class T2>
    Point<T> operator+ (Point<T2> &otherPoint) {
        Point<T> newPoint;

        newPoint.X = X + T(otherPoint.X);
        newPoint.Y = Y + T(otherPoint.Y);

        return newPoint;
    }

    template <class T2>
    Point<T> operator- (Point<T2> &otherPoint){
        Point<T> newPoint;

        newPoint.X = X - otherPoint.X;
        newPoint.Y = Y - otherPoint.Y;

        return newPoint;
    }

    template <class T2>
    Point<T>& operator+= (Point<T2> &otherPoint) {
        X = X + T(otherPoint.X);
        Y = Y + T(otherPoint.Y);

        return (*this);
    }

    template <class T2>
    Point<T>& operator-= (Point<T2> &otherPoint) {
        X = X - T(otherPoint.X);
        Y = Y - T(otherPoint.Y);

        return (*this);
    }

    void ToString() const {
        std::cout << " X: " << X << " Y: " << Y << std::endl;
    }
};

#endif //TAREA1_POINT_H
