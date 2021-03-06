/*
 * ship_test.cpp
 *
 *  Created on: Sep 13, 2017
 *      Author: Nathan Pankowsky
 */

#include <iostream>

#include <GL/glut.h>

#include "logger.hpp"
#include "pos.hpp"
#include "ship.hpp"

size_t n = 2;
objects::Ship *ship;
int selected_ship = 0;

#define SIZE (1000)
#define SCALE (1)

void display()
{
    gluOrtho2D(0, SIZE * SCALE, 0, SIZE * SCALE);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    for (int i = 0; n > i; ++i) {
        ship[i].display();
        PRINT_INFO("Ship [" << i << "] pos: " << ship[i]);
    }
    glFlush();
}

void time_event(int v)
{
    for (int i = 0; n > i; ++i) {
        ship[i].update();
    }
    glutTimerFunc(20, time_event, 0.5); // re-add event to glut's scheduler
    glutPostRedisplay();                // schedule calling the display function again
}

void add_waypoint(int button, int state, int x, int y)
{
    logic::Pos pos(x, SIZE - y);

    ship[selected_ship].enqueue(pos);
    PRINT_ERROR("updated ship: " << ship[selected_ship]);
}

void select_ship(unsigned char key, int x, int y)
{
    if (n > key - '0' - 1) {
        selected_ship = key - '0' - 1;
        PRINT_ERROR("selected ship: " << ship[selected_ship]);
    } else if (key == '0' && n > 9) {
        selected_ship = 9;
    }
}

int main(int argc, char **argv)
{

    if (1 < argc) {
        std::cout << argv[1] << std::endl;
        n = atoi(argv[1]);
    }

    logic::Pos pos[n];
    ship = new objects::Ship[n];

    for (int i = 0; n > i; ++i) {
        /*
        for (int j = 0; n > j; ++j) {
            pos[j].set_x(rand() & SIZE);
            pos[j].set_y(rand() & SIZE);
            ship[i].enqueue(pos[j]);
        }
        */
        ship[i].set_pos(SIZE / n, i * SIZE / n + SIZE / n);
        ship[i].set_dpos(10, 1);
        ship[i].update();
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(SIZE, SIZE);
    glutCreateWindow("Ship Test");
    glutDisplayFunc(display);
    glutKeyboardFunc(select_ship);
    glutMouseFunc(add_waypoint);
    glutTimerFunc(200, time_event, 0.5);

    glutMainLoop();

    return 0;
}
