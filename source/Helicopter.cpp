#include"../header/Helicopter.h"

Helicopter::Helicopter(float x, float y, float z)
    : posX(x), posY(y), posZ(z){}

// Helicopter movement variables
//static float heliPosX = -15.0f;  // X position of the helicopter (left-right)
//static float heliPosY = 0.0f;    // Y position of the helicopter (up-down)
//static float heliPosZ = 0.0f;    // Z position of the helicopter (forward-backward)

// Rotor rotation
static float rotorAngle = 0.0f;  // For rotor rotation speed

// Function to draw the rotor
void Helicopter::drawRotor() {
    glPushMatrix();
    //glColor3f(0.1f, 0.1f, 0.1f);  // Rotor color (black/grey)
    glRotatef(rotorAngle, 0.0, 1.0, 0.0); // Spin around Y-axis
    glScalef(0.1, 0.1, 5.0); // Flatten into rotor shape
    glutSolidCube(1.0);
    glPopMatrix();
}

// Function to draw the tail rotor
void Helicopter::drawTailRotor() {
    glPushMatrix();
    //glColor3f(0.1f, 0.1f, 0.1f);  // Tail rotor color
    glRotatef(rotorAngle, 1.0, 0.0, 0.0); // Spin around X-axis
    glScalef(0.05, 2.0, 0.05); // Flatten into rotor shape
    glutSolidCube(1.0);
    glPopMatrix();
}

// Function to draw the helicopter landing skids (legs)
void Helicopter::drawLandingSkids() {
    glPushMatrix();
    glColor3f(0.3f, 0.3f, 0.3f); // Skids color (dark grey)

    // Left skid
    glPushMatrix();
    glTranslatef(-0.8f, -1.0f, 0.0f);  // Position below helicopter
    glScalef(0.1f, 0.1f, 4.0f);  // Length and width of skid
    glutSolidCube(1.0);
    glPopMatrix();

    // Right skid
    glPushMatrix();
    glTranslatef(0.8f, -1.0f, 0.0f);  // Position below helicopter
    glScalef(0.1f, 0.1f, 4.0f);  // Length and width of skid
    glutSolidCube(1.0);
    glPopMatrix();

    // Connecting bars between skids
    for (int i = -1; i <= 1; i += 2) {
        glPushMatrix();
        glTranslatef(0.0f, -1.0f, i * 1.5f);  // Position front and rear bars
        glScalef(2.0f, 0.1f, 0.1f);  // Length and thickness
        glutSolidCube(1.0);
        glPopMatrix();
    }

    glPopMatrix();
}

// Function to draw the helicopter doors
void Helicopter::drawDoors() {
    glPushMatrix();
    glColor3f(0.3f, 0.3f, 0.3f);  // Door color (dark grey)

    // Left side doors
    glPushMatrix();
    glTranslatef(-1.01f, 0.0f, 0.5f);  // Position doors on left side
    glScalef(0.05f, 0.8f, 1.0f);  // Size of door
    glutSolidCube(1.0);
    glPopMatrix();

    // Right side doors
    glPushMatrix();
    glTranslatef(1.01f, 0.0f, 0.5f);  // Position doors on right side
    glScalef(0.05f, 0.8f, 1.0f);  // Size of door
    glutSolidCube(1.0);
    glPopMatrix();

    glPopMatrix();
}

// Function to draw the helicopter
void Helicopter::drawHelicopter() {
    // Helicopter body
    glPushMatrix();
    glColor3f(0.0f, 1.0f, 0.5f); // Body color (light grey)
    glScalef(1.0, 0.5, 2.0); // Stretch into helicopter shape
    glutSolidCube(2.0); // Body cube
    glPopMatrix();

    // Helicopter nose
    glPushMatrix();
    glTranslatef(0.0, 0.0, 2.0);  // Position the nose in front
    glColor3f(0.0f, 0.0f, 0.0f); // Nose color (slightly darker)
    glutSolidSphere(0.8, 20, 20); // Nose sphere
    glPopMatrix();

    // Tail boom
    glPushMatrix();
    glTranslatef(0.0, 0.0, -3.0);  // Position tail at the back
    glScalef(0.2, 0.2, 4.0);       // Stretch to make tail
    glColor3f(0.0f, 1.0f, 0.5f);   // Tail color (grey)
    glutSolidCube(1.0);
    glPopMatrix();

    // Tail rotor
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);
    glTranslatef(0.0, 0.0, -5.0);  // Position at the end of tail boom
    drawTailRotor();
    glPopMatrix();

    // Main rotor
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);
    glTranslatef(0.0, 1.0, 0.0);  // Position rotor on top
    drawRotor();
    glPopMatrix();

    // Draw the landing skids (legs)
    glPushMatrix();
    glColor3f(0.3f, 0.3f, 0.3f);
    drawLandingSkids();
    glPopMatrix();

    // Draw the doors
    drawDoors();
}

void Helicopter::draw() {

    // Draw the helicopter
    glPushMatrix();
    glTranslatef(posX, posY, posZ); // Apply position

    // Rotate the helicopter to face the 9 o'clock direction
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);  // 90 degrees around the Y-axis (clockwise)

    drawHelicopter();
    glPopMatrix();

    // Simulate horizontal movement (move the helicopter along the X-axis)
    posX += 0.02f; // Move to the right along the X-axis (horizontal)

    if (posX > 15.0f) { // Reset position when off screen
        posX = -15.0f;
    }

    rotorAngle += 10.0f; // Rotate the rotors

    if (rotorAngle > 360.0f) {
        rotorAngle -= 360.0f;
    }

    //glutSwapBuffers(); // Swap buffers for double buffering
}
