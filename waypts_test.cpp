/*
 * waypts_test.cpp
 *
 *  Created on: Sep 13, 2017
 *      Author: Nathan Pankowsky
 */
#include <iostream>

#include "pos.hpp"
#include "waypts.hpp"

int main()
{
    containers::Waypts waypts;
    logic::Pos points[10];

    for (double i = 0; 10 > i; ++i) {
        points[(int)i].set_x(i);
        waypts.enqueue(points[(int)i]);
    }

    std::cout << "{";
    while (!waypts.empty()) {
        std::cout << waypts.dequeue() << ", ";
    }
    std::cout << "}" << std::endl;

    return 0;
}
