#include "../header/Tree.h"

Tree::Tree(float x, float y, float z)
    : posX(x), posY(y), posZ(z){}



void Tree::draw(){

    GLUquadricObj *pObj;
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);
    glPushMatrix();
    // Add code here
    glScalef(0.5,0.5,0.5);
    glRotatef(-90,1,0,0);
    glColor3f(1,0,0);
    gluCylinder(pObj, 0.5,0,15,26,13);

    glPushMatrix();
    glColor3f(0,1,0);
    glTranslatef(0,0,3.5);
    gluCylinder(pObj, 5,0,5,26,13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,1,0);
    glTranslatef(0,0,10);
    gluCylinder(pObj, 2,0,5,26,13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,1,0);
    glTranslatef(0,0,6.5);
    gluCylinder(pObj, 3.5,0,6,26,13);
    glPopMatrix();




    glPopMatrix();
    gluDeleteQuadric(pObj);

}
