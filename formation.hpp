/*
 * formation.hpp
 *
 *  Created on: Sep 19, 2017
 *      Author: Nathan Pankowsky
 */

#ifndef FORMATION_HPP_
#define FORMATION_HPP_

#include "ship.hpp"

namespace objects {

class Formation: public Ship {
public:
    Formation();
    virtual ~Formation();
};

} /* namespace objects */

#endif /* FORMATION_HPP_ */
