/*
 * ship.h
 *
 *  Created on: Sep 13, 2017
 *      Author: Nathan Pankowsky
 */

#ifndef SHIP_HPP_
#define SHIP_HPP_

#include "config.hpp" // Configuration header
#include "pos.hpp"
#include "object.hpp"
#include "waypts.hpp"

namespace objects {

class Ship: public logic::Object, public containers::Waypts {
public:
    Ship();
    virtual ~Ship();

    void update();
    bool add_waypt(const logic::Pos &pos);
    logic::Pos& next_waypt();

    void set_target(const logic::Object &obj);
    logic::Object& get_target() const;

    void display();
    static void s_display();

protected:
    const static int m_firing_range;
    static int s_id;

private:
    int m_health;
    int m_unit_id;

    bool m_firing;
    logic::Object& m_target;

    // Display objects
    static logic::Pos* s_pos;
    static logic::Pos* s_d_pos;
    static logic::Pos& s_next;
    static int s_current_id;

    // TODO extract into formation class
    //logic::Pos& formation_center;
    //logic::Pos& formation_offset;
    //logic::Pos& formation_speed;

    // TODO check environment for collision events
};

} /* namespace objects */

#endif /* SHIP_HPP_ */
