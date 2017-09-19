/*
 * pos.cpp
 *
 *  Created on: Sep 12, 2017
 *      Author: Nathan Pankowsky
 */

#include <iostream> // ostream
#include <cmath>    // sqrt

#include "pos.hpp"

namespace logic {

Pos::Pos() :
        m_x(0), m_y(0)
{
}

Pos::Pos(unsigned long x, unsigned long y) :
        m_x(x), m_y(y)
{
}

Pos::~Pos()
{
}

Pos::Pos(const Pos &pos) :
        m_x(pos.get_x()), m_y(pos.get_y())
{
}

Pos& Pos::operator=(const Pos &pos)
{
    m_x = pos.get_x();
    m_y = pos.get_y();
}

unsigned long Pos::get_x() const
{
    return m_x;
}

void Pos::set_x(unsigned long x)
{
    this->m_x = x;
}

unsigned long Pos::get_y() const
{
    return m_y;
}

void Pos::set_y(unsigned long y)
{
    this->m_y = y;
}

double Pos::distance(const Pos &Pos) const
{
    unsigned long d_x = (m_x - Pos.get_x());
    unsigned long d_y = (m_y - Pos.get_y());

    return sqrt((d_x * d_x) + (d_y * d_y));
}

std::ostream& operator<<(std::ostream& os_, const logic::Pos& pos_)
{
    os_ << "(" << pos_.get_x() << ", " << pos_.get_y() << ")";

    return os_;
}

} /* namespace logic */

