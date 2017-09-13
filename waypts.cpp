/*
 * waypts.cpp
 *
 *  Created on: Sep 13, 2017
 *      Author: super29
 */

#include "waypts.hpp"

namespace containers {

Waypts::Waypts()
{
}

Waypts::~Waypts()
{
    while (!m_waypts.empty())
    {
        m_waypts.pop();
    }
}

bool Waypts::Empty() const
{
    return m_waypts.empty();
}

bool Waypts::EnqueuePt(const logic::Pos &pos)
{
    m_waypts.push(pos);
}

logic::Pos& Waypts::DequeuePt()
{
    logic::Pos &head = m_waypts.front();
    m_waypts.pop();
    return head;
}

} /* namespace containers */
