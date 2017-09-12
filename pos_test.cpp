/*
 * pos_test.cpp
 *
 *  Created on: Sep 12, 2017
 *      Author: super29
 */

#include <iostream>
#include "pos.hpp"

int main()
{
    logic::Pos sample(3, 4);
    logic::Pos sample2(sample);


    std::cout << sample << ", " << sample2 << std::endl;

    return 0;
}
