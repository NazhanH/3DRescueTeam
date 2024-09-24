#ifndef WINDMILL_H // Header guard to avoid multiple inclusions
#define WINDMILL_H

#include <GL/glut.h>

class Windmill {
private:
    float posX, posY, posZ;   // Position of the fan

public:
    // Constructor
    Windmill(float x, float y, float z);

    // Method to draw the fan
    void draw();

private:
    // Helper function to draw the fan geometry
    void polyhedronHexagon();
    void polyhedronPentagon();
    void Supporter();
    void SingleBarSet();
    void SingleFan();
    void WindmillFan();
    };

#endif // WINDMILLFAN_H
