/*
 * ship.h
 *
 *  Created on: Sep 13, 2017
 *      Author: super29
 */

#ifndef SHIP_HPP_
#define SHIP_HPP_

#include "object.hpp"
#include "waypts.hpp"

namespace objects {

class Ship: public logic::Object,
            public containers::Waypts
{
public:
    Ship();
    virtual ~Ship();

    void display() const;
};

} /* namespace objects */

#endif /* SHIP_HPP_ */
