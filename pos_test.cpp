/*
 * pos_test.cpp
 *
 *  Created on: Sep 12, 2017
 *      Author: pankon
 */

#include <iostream>
#include "pos.hpp"

int main()
{
    logic::Pos sample(3, 4);
    logic::Pos sample2(sample);

    sample2.set_x(10);

    std::cout << sample << ", " << sample2 << std::endl;
    std::cout << "Distance between: " << sample.distance(sample2) << std::endl;

    return 0;
}
