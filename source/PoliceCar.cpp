#include "../header/PoliceCar.h"

PoliceCar::PoliceCar(float x, float y, float z)
    : posX(x), posY(y), posZ(z){}


// Function to draw a police car (simplified model)
void PoliceCar::drawPoliceCar() {

    // Get the current time in seconds
    time_t currentTime = time(NULL);

    // Check if 2 seconds have passed since the last switch
    if (difftime(currentTime, lastSwitchTime) >= 0.5) {
        sirenState = !sirenState;  // Toggle between rings
        lastSwitchTime = currentTime;    // Update the last switch time
    }

    // Draw car body
    glPushMatrix();
    glColor3f(0.1f, 0.1f, 0.1f); // Black car body
    glScalef(4.0f, 1.5f, 2.0f);  // Scale the body to match a car shape
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1f, 0.1f, 0.1f); // Black car body
    glTranslatef(2.0f,-0.35f,0);
    glScalef(1.0f, 0.75f, 2.0f);  // Scale the body to match a car shape
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1f, 0.1f, 0.1f); // Black car body
    //glScalef(4.0f, 1.5f, 2.0f);  // Scale the body to match a car shape
    glutSolidCube(1.0f);
    glPopMatrix();

    // Draw wheels
    glColor3f(0.0f, 0.0f, 0.0f); // Black wheels
    for (float x = -1.5f; x <= 1.5f; x += 3.0f) {
        for (float z = -1.0f; z <= 1.0f; z += 2.0f) {
            glPushMatrix();
            glTranslatef(x, -0.75f, z);
            glutSolidTorus(0.1f, 0.3f, 10, 20);
            glPopMatrix();
        }
    }

    // Draw police markings (just a simple white side stripe for now)
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f); // White stripe
    glTranslatef(-0.4f, 0.4f, 1.05f); // Left side
    glPushMatrix();

    glScalef(2.75f, 0.5f, 0.1f);
    glutSolidCube(1.0f);

    glColor3f(0.0f,0.2f,0.5f);
    glTranslatef(0.7,0,0);
    glScalef(0.2,1,0.25);
    glutSolidCube(1.0f);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f); // White stripe
    glTranslatef(-0.4f, 0.4f, -1.05f); // Right side

    glPushMatrix();
    glScalef(2.75f, 0.5f, 0.1f);
    glutSolidCube(1.0f);

    glColor3f(0.0f,0.2f,0.5f);
    glTranslatef(0.7,0,0);
    glScalef(0.2,1,0.25);
    glutSolidCube(1.0f);



    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0f,0.2f,0.5f);
    glTranslatef(2,0.4,0);
    glRotatef(90,0,1,0);
    glScalef(1.75f, 0.5f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Draw sirens (blinking red and blue)
    glPushMatrix();
    if (sirenState) {
        glColor3f(1.0f, 0.0f, 0.0f); // Red siren
    } else {
        glColor3f(0.0f, 0.0f, 1.0f); // Blue siren
    }
    glTranslatef(1.25f, 0.8f, 0.4f); // Position on top of car
    glScalef(0.5f, 0.2f, 0.2f); // Small siren shape
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    if (!sirenState) {
        glColor3f(1.0f, 0.0f, 0.0f); // Red siren
    } else {
        glColor3f(0.0f, 0.0f, 1.0f); // Blue siren
    }
    glTranslatef(1.25f, 0.8f, -0.4f); // Another siren
    glScalef(0.5f, 0.2f, 0.2f);
    glutSolidCube(1.0f);
    glPopMatrix();
}

void PoliceCar::draw(){
    glTranslatef(posX,posY+1.2,posZ);
    drawPoliceCar();

//    posX+=0.06;
//
//    if(posX>=13){
//        posX=0;
//    }

}


