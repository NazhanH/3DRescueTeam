#ifndef FIRETRUCK_H
#define FIRETRUCK_H

#include <GL/glut.h>

class Firetruck {
private:
    float posX, posY, posZ;   // Position of the firetruck

public:
    // Constructor
    Firetruck(float x, float y, float z);

    // Method to draw the firetruck
    void draw();

private:
    void cube();
    void tire();
    void drawFiretruck();
    void cylinder();
    void disk();
    void hose();

    };

#endif // FIRETRUCK_H
