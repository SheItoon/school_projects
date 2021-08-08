/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Vector.hpp
*/

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <cmath>

namespace arc
{

    template <typename T>
    class Vector
    {

        public:
            T x;
            T y;

        Vector() = default;
        Vector(const Vector<T>&) = default;
        Vector(T xVal, T yVal);
        ~Vector() = default;

        Vector<T> operator+(const Vector<T>& other);
        Vector<T> operator-(const Vector<T>& other);
        Vector<T> operator*(const Vector<T>& other);
        Vector<T> operator/(const Vector<T>& other);
        Vector<T> operator%(const Vector<T>& other);
        Vector<T>& operator=(const Vector<T>& other);
        Vector<T>& operator+=(const Vector<T>& other);
        Vector<T>& operator-=(const Vector<T>& other);
        Vector<T>& operator*=(const Vector<T>& other);
        Vector<T>& operator/=(const Vector<T>& other);
        Vector<T>& operator%=(const Vector<T>& other);
        bool operator<(const Vector<T>& other);
        bool operator>(const Vector<T>& other);
        bool operator<=(const Vector<T>& other);
        bool operator>=(const Vector<T>& other);

    };

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const arc::Vector<T>& vec);

    #include "Vector.inl"
}

#endif // __VECTOR_H__