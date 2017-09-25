/*
 * Object.cpp
 *
 *  Created on: Sep 12, 2017
 *      Author: Nathan Pankowsky
 */

#include "object.hpp"

namespace logic {

Object::Object()
{
    m_pos = new Pos(0, 0);
    m_d_pos = new Pos(0, 0);
}

Object::Object(double x, double y)
{
    m_pos = new Pos(x, y);
    m_d_pos = new Pos(0, 0);
}

Object::Object(double x, double y, double d_x = 0,
        double d_y = 0)
{
    m_pos = new Pos(x, y);
    m_d_pos = new Pos(d_x, d_y);
}

Object::Object(const Object &object)
{
    double x = 0;
    double y = 0;
    double d_x = 0;
    double d_y = 0;

    object.get_dpos(&d_x, &d_y);
    object.get_pos(&x, &y);

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
    double x = 0;
    double y = 0;
    double d_x = 0;
    double d_y = 0;

    object.get_dpos(&d_x, &d_y);
    object.get_pos(&x, &y);

    set_dpos(d_x, d_y);
    set_pos(x, y);
}

void Object::get_dpos(double *d_x, double *d_y) const
{
    *d_x = m_d_pos->get_x();
    *d_y = m_d_pos->get_y();
}

void Object::get_pos(double *x, double *y) const
{
    *x = m_pos->get_x();
    *y = m_pos->get_y();
}

void Object::set_dpos(double d_x, double d_y)
{
    m_d_pos->set_x(d_x);
    m_d_pos->set_y(d_y);
}

void Object::set_pos(double x, double y)
{
    m_pos->set_x(x);
    m_pos->set_y(y);
}

double Object::distance(const Object& object) const
{
    return m_pos->distance(*object.m_pos);
}

double Object::speed_diff(const Object& object) const
{
    return m_d_pos->distance(*object.m_d_pos);
}

std::ostream& operator<<(std::ostream& os_, const Object& object)
{
    os_ << "<";
    os_ << "pos = " << *object.m_pos;
    os_ << ", ";
    os_ << "d_pos = " << *object.m_d_pos;
    os_ << ">";

    return os_;
}

} /* namespace logic */
