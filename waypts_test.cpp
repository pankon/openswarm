/*
 * waypts_test.cpp
 *
 *  Created on: Sep 13, 2017
 *      Author: super29
 */
#include <iostream>

#include "pos.hpp"
#include "waypts.hpp"

int main()
{
    containers::Waypts waypts;
    logic::Pos points[10];

    for (unsigned long i = 0; 10 > i; ++i) {
        points[i].setX(i);
        waypts.EnqueuePt(points[i]);
    }

    std::cout << "{";
    while(!waypts.Empty())
    {
        std::cout << waypts.DequeuePt() << ", ";
    }
    std::cout << "}" << std::endl;

    return 0;
}
