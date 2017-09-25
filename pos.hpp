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
    explicit Pos(long x, long y);
    explicit Pos(const Pos &pos);
    Pos& operator=(const Pos &pos);
    virtual ~Pos();

    long get_x() const;
    void set_x(long x);
    long get_y() const;
    void set_y(long y);
    double distance(const Pos &Pos) const;

private:
    friend std::ostream& operator<<(std::ostream& os_, const Pos& pos_);
    long m_x;
    long m_y;
};

} /* namespace logic */

#endif /* POS_HPP_ */
