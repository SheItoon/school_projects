/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Vector.inl
*/

template<typename T>
inline arc::Vector<T>::Vector(T xVal, T yVal) :
    x(xVal),
    y(yVal)
{}

template<typename T>
inline arc::Vector<T> arc::Vector<T>::operator+(const arc::Vector<T>& other)
{
    return (arc::Vector<T>{x + other.x, y + other.y});
}

template<typename T>
inline arc::Vector<T> arc::Vector<T>::operator-(const arc::Vector<T>& other)
{
    return (arc::Vector<T>{x - other.x, y - other.y});
}

template<typename T>
inline arc::Vector<T> arc::Vector<T>::operator*(const arc::Vector<T>& other)
{
    return (arc::Vector<T>{x * other.x, y * other.y});
}

template<typename T>
inline arc::Vector<T> arc::Vector<T>::operator/(const arc::Vector<T>& other)
{
    return (arc::Vector<T>{x / other.x, y / other.y});
}

template<typename T>
inline arc::Vector<T> arc::Vector<T>::operator%(const arc::Vector<T>& other)
{
    return (arc::Vector<T>{x % other.x, y % other.y});
}

template<typename T>
inline arc::Vector<T>& arc::Vector<T>::operator=(const arc::Vector<T>& other)
{
    x = other.x;
    y = other.y;
    return (*this);
}

template<typename T>
inline arc::Vector<T>& arc::Vector<T>::operator+=(const arc::Vector<T>& other)
{
    x += other.x;
    y += other.y;
    return (*this);
}

template<typename T>
inline arc::Vector<T>& arc::Vector<T>::operator-=(const arc::Vector<T>& other)
{
    x -= other.x;
    y -= other.y;
    return (*this);
}

template<typename T>
inline arc::Vector<T>& arc::Vector<T>::operator*=(const arc::Vector<T>& other)
{
    x *= other.x;
    y *= other.y;
    return (*this);
}

template<typename T>
inline arc::Vector<T>& arc::Vector<T>::operator/=(const arc::Vector<T>& other)
{
    x /= other.x;
    y /= other.y;
    return (*this);
}

template<typename T>
inline arc::Vector<T>& arc::Vector<T>::operator%=(const arc::Vector<T>& other)
{
    x %= other.x;
    y %= other.y;
    return (*this);
}

template<typename T>
inline bool arc::Vector<T>::operator<(const arc::Vector<T>& other)
{
    return (std::sqrt(std::pow(x, 2) + std::pow(y, 2)) < std::sqrt(std::pow(other.x, 2) + std::pow(other.y, 2)));
}

template<typename T>
inline bool arc::Vector<T>::operator>(const arc::Vector<T>& other)
{
    return (std::sqrt(std::pow(x, 2) + std::pow(y, 2)) > std::sqrt(std::pow(other.x, 2) + std::pow(other.y, 2)));
}

template<typename T>
inline bool arc::Vector<T>::operator<=(const arc::Vector<T>& other)
{
    return (std::sqrt(std::pow(x, 2) + std::pow(y, 2)) <= std::sqrt(std::pow(other.x, 2) + std::pow(other.y, 2)));
}

template<typename T>
inline bool arc::Vector<T>::operator>=(const arc::Vector<T>& other)
{
    return (std::sqrt(std::pow(x, 2) + std::pow(y, 2)) >= std::sqrt(std::pow(other.x, 2) + std::pow(other.y, 2)));
}

template<typename T>
inline std::ostream& operator<<(std::ostream& os, const arc::Vector<T>& vec)
{
    os << vec.x << "/" << vec.y;
    return (os);
}