/*
 * waypts.h
 *
 *  Created on: Sep 13, 2017
 *      Author: Nathan Pankowsky
 */

#ifndef WAYPTS_HPP_
#define WAYPTS_HPP_

#include <queue>
#include "pos.hpp"

namespace containers {

class Waypts {
public:
    explicit Waypts();
    virtual ~Waypts();

    bool enqueue(const logic::Pos &pos);
    logic::Pos& dequeue();
    logic::Pos& peek();
    bool empty() const;
    bool erase();
private:
    std::queue<logic::Pos> m_waypts;
};

} /* namespace containers */

#endif /* WAYPTS_HPP_ */
