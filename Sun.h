#ifndef SUN_H // Header guard to avoid multiple inclusions
#define SUN_H

#include <GL/glut.h>

class Sun {
private:
    float posX, posY, posZ;   // Position of the sun

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

    };

#endif // SUN_H
