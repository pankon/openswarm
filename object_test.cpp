/*
 * object_test.cpp
 *
 *  Created on: Sep 12, 2017
 *      Author: super29
 */

#include <iostream>
#include "object.hpp"

int main()
{
    logic::Object sample;
    logic::Object sample2(3, 4);

    std::cout << sample << " " << sample2 << std::endl;

    return 0;
}
