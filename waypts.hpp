/*
 * waypts.h
 *
 *  Created on: Sep 13, 2017
 *      Author: super29
 */

#ifndef WAYPTS_HPP_
#define WAYPTS_HPP_

#include <queue>
#include "pos.hpp"

namespace containers {

class Waypts
{
public:
    explicit Waypts();
    virtual ~Waypts();

    bool EnqueuePt(const logic::Pos &pos);
    logic::Pos& DequeuePt();
    bool Empty() const;
private:
    std::queue<logic::Pos> m_waypts;
};

} /* namespace containers */

#endif /* WAYPTS_HPP_ */
