/*
 * pos.cpp
 *
 *  Created on: Sep 12, 2017
 *      Author: pankon
 */

#include <iostream>
#include "pos.hpp"

namespace logic {

Pos::Pos() : m_x(0), m_y(0)
{
    // TODO Auto-generated constructor stub
}

Pos::Pos(unsigned long x, unsigned long y) : m_x(x), m_y(y)
{

}

Pos::~Pos()
{
    // TODO Auto-generated destructor stub
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

std::ostream& operator<<(std::ostream& os_, const logic::Pos& pos_)
{
    os_ << "(" << pos_.getX() << ", " << pos_.getY() << ")";

    return os_;
}

} /* namespace logic */


