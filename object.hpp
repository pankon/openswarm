/*
 * object.hpp
 *
 *  Created on: Sep 12, 2017
 *      Author: Nathan Pankowsky
 */

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <iostream>
#include "pos.hpp"

namespace logic {

class Object {
public:
    explicit Object();
    explicit Object(double x, double y);
    explicit Object(double x, double y, double d_x,
            double d_y);
    explicit Object(const Object &object);
    Object& operator=(const Object &object);
    virtual ~Object();

    void get_dpos(double *, double *) const;
    void get_pos(double *, double *) const;
    void set_dpos(double d_x, double d_y);
    void set_pos(double x, double y);

    double distance(const Object& object) const;
    double speed_diff(const Object& object) const;

    void update();

protected:
    Pos* m_pos;
    Pos* m_d_pos;

private:
    friend std::ostream& operator<<(std::ostream& os_, const Object& object);
};

} /* namespace logic */

#endif /* OBJECT_HPP_ */
