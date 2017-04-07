//
// Template Tutorial:
// https://www.codeproject.com/Articles/257589/An-Idiots-Guide-to-Cplusplus-Templates-Part
//
// Created by wororo on 06-04-17.
//

#ifndef TAREA1_POINT_H
#define TAREA1_POINT_H

template<class T>
class Point {
public:
    Point() : X(T()), Y(T()) {};

    Point(T x, T y) : X(x), Y(y) {};

    Point(T x, T y, T z) : X(x), Y(y), Z(z) {};

    T X = 0;
    T Y = 0;
    T Z = 0;

    //TODO: Fix Posibles problemas con == entre <double> e <int>;
    template<class T2>
    bool operator==(Point<T2> &p2) {
        return X == T(p2.X)
               && Y == T(p2.Y)
               && Z == T(p2.Z);
    }

    template<class T2>
    Point<T> operator+(Point<T2> &p2) {
        Point<T> newPoint(X + T(p2.X),
                          Y + T(p2.Y),
                          Z + T(p2.Z));

        return newPoint;
    }

    template<class T2>
    Point<T> operator-(Point<T2> &p2) {
        Point<T> newPoint(X - T(p2.X),
                          Y - T(p2.Y),
                          Z - T(p2.Z));

        return newPoint;
    }

    template<class T2>
    Point<T> &operator+=(Point<T2> &p2) {
        X = X + T(p2.X);
        Y = Y + T(p2.Y);
        Z = Z + T(p2.Z);

        return (*this);
    }

    template<class T2>
    Point<T> &operator-=(Point<T2> &p2) {
        X = X - T(p2.X);
        Y = Y - T(p2.Y);
        Z = Z - T(p2.Z);

        return (*this);
    }

    void ToString() const {
        std::cout << "X: " << X
                  << " Y: " << Y
                  << " Z: " << Z
                  << std::endl;
    }
};

#endif //TAREA1_POINT_H
