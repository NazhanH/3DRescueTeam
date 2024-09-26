#include "../header/Tank.h"

Tank::Tank(float x, float y, float z)
    : posX(x), posY(y), posZ(z){}


 //Function to draw the bomb (if launched)
void Tank::drawBomb() {
    if (isBombLaunched) {
        glPushMatrix();
        glColor3f(1.0f, 0.0f, 0.0f); // Red color for the bomb
        glTranslatef(bombPosX, bombPosY, bombPosZ); // Position the bomb
        glutSolidSphere(0.2, 20, 20); // Small sphere representing the bomb
        glPopMatrix();
    }
}

void Tank::cannonUp(){

    cannonAngle += 2.0f;
            if (cannonAngle > 45.0f) cannonAngle = 45.0f; // Limit angle to 45 degrees
}

void Tank::cannonDown(){
    cannonAngle -= 2.0f;
            if (cannonAngle < -10.0f) cannonAngle = -10.0f; // Limit angle to -10 degrees
}

void Tank::launchBomb(){

    // Set bomb position to the cannon's tip and launch it
        bombPosX = posX + 5.0f; // Position the bomb at the cannon
        bombPosY = posY + 1.0f;
        bombPosZ = posZ;
        isBombLaunched = true;

}

// Function to draw the tank (simplified model)
void Tank::drawTank() {
    glPushMatrix();
    glColor3f(0.2f, 0.5f, 0.2f); // Military green color

    // Tank body
    glPushMatrix();
    glScalef(5.0f, 1.5f, 3.0f); // Scale into a tank body shape
    glutSolidCube(1.0);
    glPopMatrix();

    // Tank turret
    glPushMatrix();
    glColor3f(0.3f, 0.3f, 0.3f); // Darker grey for turret
    glTranslatef(0.0f, 1.0f, 0.0f); // Position turret on top
    glScalef(2.5f, 1.0f, 2.0f); // Shape the turret
    glutSolidCube(1.0);
    glPopMatrix();

    // Tank cannon (GLU cylinder)
    glPushMatrix();
    GLUquadric *cylinder = gluNewQuadric(); // Create a new quadric object
    glColor3f(0.3f, 0.3f, 0.3f); // Darker grey for the cannon
    glTranslatef(1.25f, 1.0f, 0.0f); // Position at the front of the turret

    // Rotate the cannon for up and down movement (using cannonAngle)
    glRotatef(cannonAngle, 0.0f, 0.0f, 1.0f); // Rotate around the Z-axis

    glRotatef(90, 0.0f, 1.0f, 0.0f); // Rotate it forward
    gluCylinder(cylinder, 0.2, 0.2, 4.0, 20, 20); // Draw the cannon using GLU
    gluDeleteQuadric(cylinder); // Delete the quadric object after use
    glPopMatrix();

    // Tank wheels (GLU cylinders)
    glColor3f(0.1f, 0.1f, 0.1f); // Black wheels
    for (float x = -2.0f; x <= 2.0f; x += 1.0f) {
        glPushMatrix();
        GLUquadric *wheel = gluNewQuadric(); // Create a new quadric object
        glTranslatef(x, -0.75f, -1.5f); // Position left side wheels
        glRotatef(90, 0.0f, 1.0f, 0.0f); // Rotate the wheels to face forward
        gluCylinder(wheel, 0.4, 0.4, 0.4, 20, 20); // Draw the wheel using GLU
        gluDeleteQuadric(wheel); // Delete the quadric object after use
        glPopMatrix();

        glPushMatrix();
        wheel = gluNewQuadric(); // Re-create quadric for the right side
        glTranslatef(x, -0.75f, 1.5f); // Position right side wheels
        glRotatef(90, 0.0f, 1.0f, 0.0f); // Rotate the wheels to face forward
        gluCylinder(wheel, 0.4, 0.4, 0.4, 20, 20); // Draw the wheel using GLU
        gluDeleteQuadric(wheel); // Delete the quadric object after use
        glPopMatrix();
    }

    glPopMatrix();
}

void Tank::draw(){

    glPushMatrix();
    glScalef(2,2,2);
    glTranslatef(posX,posY+1.25,posZ);
    drawTank();
    drawBomb();
    glPopMatrix();

    posX += 0.02f; // Move the tank along the X-axis

    if (posX > 10.0f) { // Reset position when it moves out of view
        posX = -10.0f;
    }

    // Animate the bomb if it's launched
    if (isBombLaunched) {
        bombPosX += bombSpeed;
        if (bombPosX > 20.0f) { // Reset the bomb after it moves out of view
            isBombLaunched = false;
        }
    }
}
