/*
 * ship.h
 *
 *  Created on: Sep 13, 2017
 *      Author: super29
 */

#ifndef SHIP_HPP_
#define SHIP_HPP_

#include "object.hpp"

namespace objects {

class Ship: public logic::Object
{
public:
    Ship();
    virtual ~Ship();

    void ShipDisplay() const;
};

} /* namespace objects */

#endif /* SHIP_HPP_ */
