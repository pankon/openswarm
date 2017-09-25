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
    explicit Object(long x, long y);
    explicit Object(long x, long y, long d_x,
            long d_y);
    explicit Object(const Object &object);
    Object& operator=(const Object &object);
    virtual ~Object();

    void get_dpos(long *, long *) const;
    void get_pos(long *, long *) const;
    void set_dpos(long d_x, long d_y);
    void set_pos(long x, long y);

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
