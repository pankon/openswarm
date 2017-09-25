/*
 * logger.hpp
 *
 *  Created on: Sep 25, 2017
 *      Author: Nathan Pankowsky
 */

#ifndef LOGGER_HPP_
#define LOGGER_HPP_


#include <iostream>

#define DEFAULT     "\033[39m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"

#define STDERR_PRINT_TOKEN(color, token, x) std::cerr << "(" color #token DEFAULT "): " << x << std::endl

#ifdef INFO
#define PRINT_INFO(x) STDERR_PRINT_TOKEN(GREEN, INFO, x)
#else
#define PRINT_INFO(x)
#endif

#ifdef DEBUG
#define PRINT_DEBUG(x) STDERR_PRINT_TOKEN(BLUE, DEBUG, x)
#else
#define PRINT_DEBUG(x)
#endif

#ifdef ERROR
#define PRINT_ERROR(x) STDERR_PRINT_TOKEN(YELLOW, ERROR, x)
#else
#define PRINT_ERROR(x)
#endif

#ifdef CRITICAL
#define PRINT_CRITICAL(x) STDERR_PRINT_TOKEN(RED, CRITICAL, x)
#else
#define PRINT_CRITICAL(x)
#endif


#endif /* LOGGER_HPP_ */
