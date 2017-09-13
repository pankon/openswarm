/*
 * object_test.cpp
 *
 *  Created on: Sep 12, 2017
 *      Author: pankon
 */

#include <iostream>
#include "object.hpp"

int main()
{
    logic::Object sample;
    logic::Object sample2(3, 4);

    sample.SetDPos(3, 5);
    logic::Object sample3(sample);

    std::cout << sample << ", " << sample2 << ", " << sample3 << std::endl;
    std::cout << "Distance: " << sample.Distance(sample2) <<
                ", Speed diff: " << sample.SpeedDiff(sample2) <<
                std::endl;

    return 0;
}
