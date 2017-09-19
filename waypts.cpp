/*
 * waypts.cpp
 *
 *  Created on: Sep 13, 2017
 *      Author: pankon
 */

#include "waypts.hpp"

namespace containers {

Waypts::Waypts()
{
}

Waypts::~Waypts()
{
    erase();
}

bool Waypts::erase()
{
    while (!m_waypts.empty()) {
        m_waypts.pop();
    }
}

bool Waypts::empty() const
{
    return m_waypts.empty();
}

bool Waypts::enqueue(const logic::Pos &pos)
{
    m_waypts.push(pos);
}

logic::Pos& Waypts::dequeue()
{
    logic::Pos &head = m_waypts.front();
    m_waypts.pop();
    return head;
}

} /* namespace containers */
