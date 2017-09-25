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
    explicit Pos(double x, double y);
    explicit Pos(const Pos &pos);
    Pos& operator=(const Pos &pos);
    virtual ~Pos();

    double get_x() const;
    void set_x(double x);
    double get_y() const;
    void set_y(double y);
    double distance(const Pos &Pos) const;

private:
    friend std::ostream& operator<<(std::ostream& os_, const Pos& pos_);
    double m_x;
    double m_y;
};

} /* namespace logic */

#endif /* POS_HPP_ */
