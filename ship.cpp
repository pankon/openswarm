/*
 * ship.cpp
 *
 *  Created on: Sep 13, 2017
 *      Author: Nathan Pankowsky
 */

#include "ship.hpp"

namespace objects {

const int Ship::m_firing_range = RANGE;
int Ship::m_id = 0;

logic::Object temp(0, 0, 0, 0);

Ship::Ship() :
        logic::Object(0, 0, 0, 0), containers::Waypts(), m_firing(false), m_unit_id(
                0), m_health(100), m_target(temp)
{
    ++m_id;
    m_unit_id = m_id;

}

Ship::~Ship()
{
}

void Ship::update()
{
    // TODO call update on object?
}

bool Ship::add_waypt(const logic::Pos &pos)
{
    return enqueue(pos);
}

logic::Pos& Ship::next_waypt()
{
    return dequeue();
}

void Ship::set_target(const logic::Object &obj)
{
    m_target = obj;
}

logic::Object& Ship::get_target() const
{
    return m_target;
}

} /* namespace objects */
