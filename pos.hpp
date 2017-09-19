/*
 * pos.h
 *
 *  Created on: Sep 12, 2017
 *      Author: Nathan Pankowsky
 */

#ifndef POS_HPP_
#define POS_HPP_

#include <iosfwd>

namespace logic {

class Pos {
public:
    explicit Pos();
    explicit Pos(unsigned long x, unsigned long y);
    explicit Pos(const Pos &pos);
    Pos& operator=(const Pos &pos);
    virtual ~Pos();

    unsigned long get_x() const;
    void set_x(unsigned long x);
    unsigned long get_y() const;
    void set_y(unsigned long y);
    double distance(const Pos &Pos) const;

private:
    friend std::ostream& operator<<(std::ostream& os_, const Pos& pos_);
    unsigned long m_x;
    unsigned long m_y;
};

} /* namespace logic */

#endif /* POS_HPP_ */
