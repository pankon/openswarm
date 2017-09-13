/*
 * Object.cpp
 *
 *  Created on: Sep 12, 2017
 *      Author: pankon
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

Object::Object(const Object &object)
{
    unsigned long x = 0;
    unsigned long y = 0;
    unsigned long d_x = 0;
    unsigned long d_y = 0;

    object.GetDPos(&d_x, &d_y);
    object.GetPos(&x, &y);

    m_d_pos = new Pos(d_x, d_y);
    m_pos = new Pos(x, y);
}

Object::~Object()
{
    delete m_pos;
    delete m_d_pos;
}

Object& Object::operator=(const Object &object)
{
    unsigned long x = 0;
    unsigned long y = 0;
    unsigned long d_x = 0;
    unsigned long d_y = 0;

    object.GetDPos(&d_x, &d_y);
    object.GetPos(&x, &y);

    SetDPos(d_x, d_y);
    SetPos(x, y);
}

void Object::get_dpos(unsigned long *d_x, unsigned long *d_y) const
{
    *d_x = m_d_pos->getX();
    *d_y = m_d_pos->getY();
}

void Object::get_pos(unsigned long *x, unsigned long *y) const
{
    *x = m_pos->getX();
    *y = m_pos->getY();
}

void Object::set_dpos(unsigned long d_x, unsigned long d_y)
{
    m_d_pos->setX(d_x);
    m_d_pos->setY(d_y);
}

void Object::set_pos(unsigned long x, unsigned long y)
{
    m_pos->setX(x);
    m_pos->setY(y);
}

double Object::distance(const Object& object) const
{
    return m_pos->Distance(*object.m_pos);
}

double Object::speed_diff(const Object& object) const
{
    return m_d_pos->Distance(*object.m_d_pos);
}

std::ostream& operator<<(std::ostream& os_, const Object& object)
{
    os_ << "<d_pos = " << *object.m_d_pos << ", pos = " << *object.m_pos << ">";

    return os_;
}

} /* namespace logic */
