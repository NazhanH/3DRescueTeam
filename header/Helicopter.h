#ifndef HELICOPTER_H
#define HELICOPTER_H

#include <GL/glut.h>
#include <math.h>

class Helicopter {
private:
    float posX, posY, posZ;
//    // Helicopter movement variables
//    float heliPosX = -15.0f;  // X position of the helicopter (left-right)
//    float heliPosY = 0.0f;    // Y position of the helicopter (up-down)
//    float heliPosZ = 0.0f;    // Z position of the helicopter (forward-backward)
//
//    // Rotor rotation
//    float rotorAngle = 0.0f;  // For rotor rotation speed

public:
    Helicopter(float x, float y, float z);
    void draw();

private:
    void drawRotor();
    void drawTailRotor();
    void drawLandingSkids();
    void drawDoors();
    void drawHelicopter();

};

#endif // HELICOPTER_H
