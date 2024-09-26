#ifndef POLICECAR_H
#define POLICECAR_H

#include <GL/glut.h>
#include <ctime>

class PoliceCar {
private:
    float posX, posY, posZ;   // Position of the tree
    bool sirenState = true;
    time_t lastSwitchTime = time(NULL);


public:
    // Constructor
    PoliceCar(float x, float y, float z);

    // Method to draw the fan
    void draw();

private:

    void drawPoliceCar();
//    void timer();

    };

#endif // POLICECAR_H
