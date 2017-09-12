/*
 * object.hpp
 *
 *  Created on: Sep 12, 2017
 *      Author: super29
 */

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <iostream>
#include "pos.hpp"

namespace logic {

template <class T>
class Object : public Pos
{
public:
    explicit Object();
    explicit Object(unsigned long x, unsigned long y);
    virtual ~Object();
    T getObj() const;
    void setObj(T obj);

private:
    T obj;
};

} /* namespace logic */

#endif /* OBJECT_HPP_ */
