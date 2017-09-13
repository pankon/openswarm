/*
 * pos.cpp
 *
 *  Created on: Sep 12, 2017
 *      Author: pankon
 */

#include <iostream> // ostream
#include <cmath>    // sqrt

#include "pos.hpp"

namespace logic {

Pos::Pos() : m_x(0), m_y(0)
{
}

Pos::Pos(unsigned long x, unsigned long y) : m_x(x), m_y(y)
{
}

Pos::~Pos()
{
}

Pos::Pos(const Pos &pos) : m_x(pos.getX()), m_y(pos.getY())
{
}

Pos& Pos::operator=(const Pos &pos)
{
    m_x = pos.getX();
    m_y = pos.getY();
}

unsigned long Pos::getX() const
{
    return m_x;
}

void Pos::setX(unsigned long x)
{
    this->m_x = x;
}

unsigned long Pos::getY() const
{
    return m_y;
}

void Pos::setY(unsigned long y)
{
    this->m_y = y;
}

double Pos::Distance(const Pos &Pos) const
{
    unsigned long d_x = (m_x - Pos.getX());
    unsigned long d_y = (m_y - Pos.getY());

    return sqrt((d_x * d_x) + (d_y * d_y));
}

std::ostream& operator<<(std::ostream& os_, const logic::Pos& pos_)
{
    os_ << "(" << pos_.getX() << ", " << pos_.getY() << ")";

    return os_;
}

} /* namespace logic */


