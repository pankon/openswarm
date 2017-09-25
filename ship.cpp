/*
 * ship.cpp
 *
 *  Created on: Sep 13, 2017
 *      Author: Nathan Pankowsky
 */
#include <cmath>
#include <GL/glut.h>

#include "logger.hpp"
#include "ship.hpp"

namespace objects {

const int Ship::m_firing_range = RANGE;
int Ship::m_id = 0;
logic::Pos* Ship::s_pos = NULL;
logic::Pos* Ship::s_d_pos = NULL;

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
    if (!empty()) {
        const logic::Pos& next = peek();

        double x(m_pos->get_x()), y(m_pos->get_y());
        double distance(next.distance(*m_pos));

        PRINT_INFO("next_d_pos (x): " << (next.get_x() - x) / distance);

        if (distance) {
            m_d_pos->set_x((next.get_x() - x) / distance);
            m_d_pos->set_y((next.get_y() - y) / distance);
            m_pos->set_x(m_pos->get_x() + m_d_pos->get_x());
            m_pos->set_y(m_pos->get_y() + m_d_pos->get_y());
        }

        PRINT_INFO("distance: " << distance << ", next" << next << ", m_pos" << *m_pos << ", m_d_pos" << *m_d_pos);

        if (distance < 10) {
            next_waypt();
        }
    }
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

static void DrawCircle(double x, double y, double radius)
{
    glBegin(GL_POLYGON);
    for (double i = 0; M_PI * 2 > i;) {
        glVertex2f(x + radius * cos(i), y + radius * sin(i));
        i += (M_PI / 10);
    }
    glEnd();
}

void Ship::s_display(void)
{
    double radius = 10;
    double body_radius = 5;
    double prop_radius = 3;
    double angles[4] = {
        0, 90, 180, 270//0, 120, 180, 240
    };
    double offset = 0.0;


    for (int i = 0; 4 > i; ++i) {
        angles[i] *= M_PI / 180;

        if (s_d_pos->get_x() && s_d_pos->get_y()) {
            offset = atan(s_d_pos->get_y() / s_d_pos->get_x());
            angles[i] += offset;

            PRINT_INFO("atan, display: " << atan(s_d_pos->get_y() / s_d_pos->get_x()));
        }
        else if (s_d_pos->get_y()) {
            angles[i] += 90.0 / 180.0 * M_PI;
        }

        DrawCircle(s_pos->get_x() + radius * cos(angles[i]),
                   s_pos->get_y() + radius * sin(angles[i]), prop_radius);
    }

    glBegin(GL_POLYGON);
    for (int i = 0; 4 > i; ++i) {
        glVertex2f(s_pos->get_x() + body_radius * cos(angles[i]),
                   s_pos->get_y() + body_radius * sin(angles[i]));
    }
    glEnd();
}

void Ship::display() const
{
    s_pos = m_pos;
    s_d_pos = m_d_pos;
    s_display();
}

} /* namespace objects */
