#include "../header/Sun.h"

Sun::Sun(float x, float y, float z)
    : posX(x), posY(y), posZ(z){}

    void Sun::triangleaPolyhedronBig(){

    glColor3f(1,1,0);

    glBegin(GL_TRIANGLES);

    glVertex3f(0,0,0);
    glVertex3f(4,0,0);
    glVertex3f(2,5,0);

    glVertex3f(0,0,-1);
    glVertex3f(4,0,-1);
    glVertex3f(2,5,-1);

    glEnd();

    glBegin(GL_QUAD_STRIP);

    glVertex3f(0,0,0);
    glVertex3f(0,0,-1);
    glVertex3f(4,0,0);
    glVertex3f(4,0,-1);
    glVertex3f(2,5,0);
    glVertex3f(2,5,-1);
    glVertex3f(0,0,0);
    glVertex3f(0,0,-1);

    glEnd();

    }

    void Sun::triangleaPolyhedronSmall(){

    glColor3f(1.0f,0.6f,0.0f);

    glBegin(GL_TRIANGLES);

    glVertex3f(0,0,0);
    glVertex3f(2,0,0);
    glVertex3f(1,2,0);

    glVertex3f(0,0,-1);
    glVertex3f(2,0,-1);
    glVertex3f(1,2,-1);

    glEnd();

    glBegin(GL_QUAD_STRIP);

    glVertex3f(0,0,0);
    glVertex3f(0,0,-1);
    glVertex3f(2,0,0);
    glVertex3f(2,0,-1);
    glVertex3f(1,2,0);
    glVertex3f(1,2,-1);
    glVertex3f(0,0,0);
    glVertex3f(0,0,-1);
    glEnd();

    }

    void Sun::sunCentre(){

    GLUquadricObj *pObj;
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);

    glColor3f(1,1,0);

    gluDisk(pObj, 0, 2, 26, 13);
    gluCylinder(pObj,2,2,1,26,13);

    glTranslatef(0,0,1);
    gluDisk(pObj, 0, 2, 26, 13);

    gluDeleteQuadric(pObj);

    }

    static int duplicate;
    void Sun::outerRing1(){

        for(duplicate=0;duplicate<360;duplicate += 72){

            glPushMatrix();

            glRotatef(duplicate,0,0,1);
            glPushMatrix();
                glTranslatef(-1,2.5,1);
                glScalef(0.5,0.5,0.5);
                triangleaPolyhedronBig();
            glPopMatrix();
            glPushMatrix();
                glRotatef(36,0,0,1);
                glTranslatef(-0.75,2.25,0.5);
                glScalef(0.75,0.75,0.5);
                triangleaPolyhedronSmall();
            glPopMatrix();
            glPopMatrix();
        }

    }
    void Sun::outerRing2(){

            for(duplicate=0;duplicate<360;duplicate += 72){

            glPushMatrix();

            glRotatef(duplicate,0,0,1);
            glPushMatrix();
                glRotatef(36,0,0,1);
                glTranslatef(-1,2.5,1);
                glScalef(0.5,0.5,0.5);
                triangleaPolyhedronBig();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(-0.75,2.25,0.5);
                glScalef(0.75,0.75,0.5);
                triangleaPolyhedronSmall();
            glPopMatrix();
            glPopMatrix();
        }

    }

    void Sun::drawSun(){

    // Get the current time in seconds
    time_t currentTime = time(NULL);

    // Check if 2 seconds have passed since the last switch
    if (difftime(currentTime, lastSwitchTime) >= 2) {
        useOuterRing1 = !useOuterRing1;  // Toggle between rings
        lastSwitchTime = currentTime;    // Update the last switch time
    }

    // Call the appropriate outer ring function
    if (useOuterRing1) {
        outerRing1();
    } else {
        outerRing2();
    }

    sunCentre();

    //Sleep(200);

    }


    void Sun::draw(){
    glPushMatrix();
    glTranslatef(posX,posY,posZ);
    drawSun();
    glPopMatrix();

    }

