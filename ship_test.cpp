/*
 * ship_test.cpp
 *
 *  Created on: Sep 13, 2017
 *      Author: pankon
 */

#include <iostream>

#include "pos.hpp"
#include "ship.hpp"

int main()
{
    objects::Ship ship;
    logic::Pos pos(3, 4);

    ship.enqueue(pos);

    std::cout << "Ship pos: " << ship << std::endl;

    return 0;
}
