/*
 * object.hpp
 *
 *  Created on: Sep 12, 2017
 *      Author: pankon
 */

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <iostream>
#include "pos.hpp"

namespace logic {

class Object
{
public:
    explicit Object();
    explicit Object(unsigned long x, unsigned long y);
    explicit Object(unsigned long x, unsigned long y,
                    unsigned long d_x, unsigned long d_y);
    explicit Object(const Object &object);
    Object& operator=(const Object &object);
    virtual ~Object();

    void GetDPos(unsigned long *, unsigned long *) const;
    void GetPos(unsigned long *, unsigned long *) const;
    void SetDPos(unsigned long d_x, unsigned long d_y);
    void SetPos(unsigned long x, unsigned long y);

private:
    Pos* m_pos;
    Pos* m_d_pos;
    friend std::ostream& operator<<(std::ostream& os_, const Object& object);
};



} /* namespace logic */

#endif /* OBJECT_HPP_ */
