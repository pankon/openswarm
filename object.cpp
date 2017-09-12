/*
 * Object.cpp
 *
 *  Created on: Sep 12, 2017
 *      Author: super29
 */

#include "object.hpp"

namespace logic {

Object::Object()
{
    m_pos = new Pos(0, 0);
    m_d_pos = new Pos(0, 0);
}

Object::Object(unsigned long x, unsigned long y)
{
    m_pos = new Pos(x, y);
    m_d_pos = new Pos(0, 0);
}

Object::Object(unsigned long x, unsigned long y,
               unsigned long d_x=0, unsigned long d_y=0)
{
    m_pos = new Pos(x, y);
    m_d_pos = new Pos(d_x, d_y);
}

void Object::GetDPos(unsigned long *d_x, unsigned long *d_y) const
{
    *d_x = m_d_pos->getX();
    *d_y = m_d_pos->getY();
}

void Object::GetPos(unsigned long *x, unsigned long *y) const
{
    *x = m_pos->getX();
    *y = m_pos->getY();
}

void Object::SetDPos(unsigned long d_x, unsigned long d_y)
{
    m_d_pos->setX(d_x);
    m_d_pos->setY(d_y);
}

void Object::SetPos(unsigned long x, unsigned long y)
{
    m_pos->setX(x);
    m_pos->setY(y);
}

Object::~Object()
{
    delete m_pos;
    delete m_d_pos;
}

std::ostream& operator<<(std::ostream& os_, const Object& object)
{
    os_ << "<d_pos = " << *object.m_d_pos << ", pos = " << *object.m_pos << ">";

    return os_;
}

} /* namespace logic */
