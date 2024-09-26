#ifndef SUN_H // Header guard to avoid multiple inclusions
#define SUN_H

#include <GL/glut.h>
#include <unistd.h>
#include <ctime>

class Sun {
private:
    float posX, posY, posZ;   // Position of the sun
    bool useOuterRing1 = true;
    time_t lastSwitchTime = time(NULL);  // Store the initial time


public:
    // Constructor
    Sun(float x, float y, float z);

    // Method to draw the fan
    void draw();

private:
    void triangleaPolyhedronBig();
    void triangleaPolyhedronSmall();
    void sunCentre();
    void outerRing1();
    void outerRing2();
    void drawSun();

    };

#endif // SUN_H
