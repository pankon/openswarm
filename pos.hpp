/*
 * pos.h
 *
 *  Created on: Sep 12, 2017
 *      Author: super29
 */

#ifndef POS_HPP_
#define POS_HPP_

#include <iosfwd>

namespace logic {

class Pos
{
public:
    explicit Pos();
    explicit Pos(unsigned long x, unsigned long y);
    explicit Pos(const Pos &pos);
    Pos& operator=(const Pos &pos);
    virtual ~Pos();

    unsigned long getX() const;
    void setX(unsigned long x);
    unsigned long getY() const;
    void setY(unsigned long y);

private:
    friend std::ostream& operator<<(std::ostream& os_, const Pos& pos_);
    unsigned long m_x;
    unsigned long m_y;
};

} /* namespace logic */

#endif /* POS_HPP_ */
