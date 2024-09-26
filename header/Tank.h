#ifndef TANK_H
#define TANK_H

#include <GL/glut.h>

class Tank {
private:
    float posX, posY, posZ, cannonAngle, bombPosX, bombPosY, bombPosZ, bombSpeed = 0.2f;   // Position of the tree
    bool isBombLaunched = false;

public:
    // Constructor
    Tank(float x, float y, float z);

    // Method to draw the fan
    void draw();
    void cannonUp();
    void cannonDown();
    void launchBomb();

private:
    void drawBomb();
    void drawTank();

    };

#endif // TANK_H_INCLUDED
