/*
 * Object.cpp
 *
 *  Created on: Sep 12, 2017
 *      Author: super29
 */

#include "object.hpp"

namespace logic {

template <class T>
Object<T>::Object() : Pos(0, 0)
{
    // TODO Auto-generated constructor stub
}

template <class T>
Object<T>::Object(unsigned long x, unsigned long y) : Pos(x, y)
{
    // TODO Auto-generated constructor stub
}

template <class T>
Object<T>::~Object()
{
    // TODO Auto-generated destructor stub
}

template <class T>
inline T Object<T>::getObj() const
{
    return obj;
}

template <class T>
inline void Object<T>::setObj(T obj)
{
    this->obj = obj;
}

} /* namespace logic */
