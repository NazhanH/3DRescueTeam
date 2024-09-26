#include "../header/Firetruck.h"


Firetruck::Firetruck(float x, float y, float z)
    : posX(x), posY(y), posZ(z){}

void Firetruck::cube(){
glBegin(GL_QUADS);

glVertex3f(0,0,0);
glVertex3f(0,4,0);
glVertex3f(4,4,0);
glVertex3f(4,0,0);

glVertex3f(0,4,0);
glVertex3f(4,4,0);
glVertex3f(4,4,4);
glVertex3f(0,4,4);

glVertex3f(0,0,4);
glVertex3f(0,4,4);
glVertex3f(4,4,4);
glVertex3f(4,0,4);


glVertex3f(0,0,0);
glVertex3f(4,0,0);
glVertex3f(4,0,4);
glVertex3f(0,0,4);

glVertex3f(0,0,0);
glVertex3f(0,0,4);
glVertex3f(0,4,4);
glVertex3f(0,4,0);

glVertex3f(4,0,0);
glVertex3f(4,0,4);
glVertex3f(4,4,4);
glVertex3f(4,4,0);

glEnd();
}

void Firetruck::cylinder(){
    glPushMatrix();
     //glColor3f(1,0,0);
     GLUquadricObj *pObj;
     pObj = gluNewQuadric();
     gluQuadricNormals(pObj, GLU_SMOOTH);   //specifies what kind of normals are desired for quadrics rendered with quad. 2 vectors that are specifies what kind of normals are desired for quadrics rendered with quad.
     gluCylinder(pObj, 1.5f, 1.5f, 1.0f, 26, 13);// (pObj, Specifies the radius of the cylinder at z = 0,Specifies the height of the cylinder.Specifies the number of subdivisions around the z axis., Specifies the number of subdivisions along the z axis.)
     gluDeleteQuadric(pObj);    //function destroys the quadric object and frees any memory that it used.
    glPopMatrix();
}

void Firetruck::disk(){
    glPushMatrix();
     //glColor3f(1,0,0);
     GLUquadricObj *pObj;
     pObj = gluNewQuadric();
     gluQuadricNormals(pObj, GLU_SMOOTH);
     gluDisk(pObj, 0.0f, 1.5f, 26, 13);
     gluDeleteQuadric(pObj);
    glPopMatrix();
}

void Firetruck::tire(){
    glPushMatrix();
    glColor3f(0,0,0);
    glRotatef(90, 0, 1, 0);
    cylinder();

    disk();
    glPushMatrix();
    glTranslatef(0,0, 1);
    disk();
    glPopMatrix();

    glPushMatrix();
    glColor3f(10,10,13);
    glScalef(0.75,0.75,0.75);
    glTranslatef(0,0,-0.10);
    disk();

    glPushMatrix();
    glTranslatef(0,0,1.5);
    disk();
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
}

void Firetruck::hose(){

    GLUquadricObj *pObj;
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);

    glColor3f(0.5,0.5,0.5);
    glPushMatrix();
    glRotatef(-90,1,0,0);
    glScalef(1,1,0.25);
    gluCylinder(pObj, 0.3f, 0.3f, 3, 26, 13);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0.75,0);
    glScalef(1.7,1.75,1.75);
    gluSphere(pObj, 0.3f, 26, 13);
    glPopMatrix();

    glPushMatrix();
    glRotatef(25,1,0,0);
    glScalef(1,1,0.5);
    glTranslatef(0,0.75,-5);
    gluCylinder(pObj, 0.3f, 0.3f, 4, 26, 13);
    gluCylinder(pObj, 0.3,0.5,1.5,26,13);
    glPopMatrix();


}

void Firetruck::drawFiretruck(){

    glPushMatrix();

    glTranslatef(6,0,0);
    glScalef(0.5,0.5,0.5);
    glRotatef(-90,0,1,0);

    glPushMatrix();
    glColor3f(1,0,0);
    glPushMatrix();
    glScalef(1.5,1.25,1);
    cube();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.5,1.5,2);
    glTranslatef(0,0,2);
    cube();
    glPopMatrix();
    glPopMatrix();

    glColor3f(0,0,0);
    glPushMatrix();
    glScalef(0.5,0.5,0.5);

    glPushMatrix();
    glTranslatef(8.5,4,2);
    cube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.25,4,2);
    cube();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glScalef(1,0.5,0.5);
    glTranslatef(1,4,-0.25);
    cube();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.3,0.3,0.3);
    glTranslatef(2,6,8.5);
    glPushMatrix();
    glScalef(0.5,0.25,0.75);

    cube();
    glPopMatrix();

    glTranslatef(1,0,-4);
    hose();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.75,0.75,0.75);
    glTranslatef(-0.75,0,2.75);
    tire();

    glPushMatrix();
    glTranslatef(0,0,10);
    tire();

    glTranslatef(8.5,0,0);
    tire();
    glPopMatrix();


    glTranslatef(8.5,0,0);
    tire();
    glPopMatrix();

    glPopMatrix();

}

void Firetruck::draw(){

    glPushMatrix();
    glTranslatef(posX,posY,posZ);
    drawFiretruck();
    glPopMatrix();

        posX += 0.1f; // Move to the right along the X-axis (horizontal)

    if (posX > 30.0f) { // Reset position when off screen
        posX = 0;
    }

}
