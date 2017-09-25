/*
 * ship_test.cpp
 *
 *  Created on: Sep 13, 2017
 *      Author: Nathan Pankowsky
 */

#include <iostream>

#include <GL/glut.h>

#include "pos.hpp"
#include "ship.hpp"

size_t n = 2;
objects::Ship *ship;

#define SIZE (1000)

void display()
{
    gluOrtho2D(0.0, SIZE * 2, 0.0, SIZE * 2);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glPointSize(1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    for (int i = 0; n > i; ++i) {
        ship[i].display();
        std::cout << "Ship [" << i << "] pos: " << ship[i] << std::endl;
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

int main(int argc, char **argv)
{

    if (1 < argc) {
        std::cout << argv[1] << std::endl;
        n = atoi(argv[1]);
    }

    logic::Pos pos[n];
    ship = new objects::Ship[n];

    for (int i = 0; n > i; ++i) {
        for (int j = 0; n > j; ++j) {
            pos[j].set_x(j * 100);
            pos[j].set_y(j * 100);
            ship[i].enqueue(pos[j]);
        }
        ship[i].set_pos(SIZE / n, i * SIZE / n + SIZE / n);
        ship[i].set_dpos(10, 1);
        ship[i].update();
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(SIZE, SIZE);
    glutCreateWindow("Ship Test");
    glutDisplayFunc(display);
    glutTimerFunc(200, time_event, 0.5);

    glutMainLoop();

    return 0;
}
