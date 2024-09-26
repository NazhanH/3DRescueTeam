#include "../header/Windmill.h"

Windmill::Windmill(float x, float y, float z)
    : posX(x), posY(y), posZ(z){}

void Windmill::polyhedronHexagon(void){

    glBegin(GL_QUADS);

    glColor3f(1,1,0);
    glVertex3i(0,0,0);
    glVertex3i(3,0,0);
    glVertex3i(3,2,0);
    glVertex3i(0,2,0);

    glVertex3i(3,0,0);
    glVertex3i(3,2,0);
    glVertex3i(5,2,2);
    glVertex3i(5,0,2);

    glVertex3i(5,0,2);
    glVertex3i(5,2,2);
    glVertex3i(5,2,5);
    glVertex3i(5,0,5);

    glVertex3i(5,0,5);
    glVertex3i(5,2,5);
    glVertex3i(3,2,7);
    glVertex3i(3,0,7);

    glVertex3i(3,0,7);
    glVertex3i(3,2,7);
    glVertex3i(0,2,7);
    glVertex3i(0,0,7);

    glVertex3i(0,0,7);
    glVertex3i(0,2,7);
    glVertex3i(-2,2,5);
    glVertex3i(-2,0,5);

    glVertex3i(-2,0,5);
    glVertex3i(-2,2,5);
    glVertex3i(-2,2,2);
    glVertex3i(-2,0,2);

    glVertex3i(-2,0,2);
    glVertex3i(-2,2,2);
    glVertex3i(0,2,0);
    glVertex3i(0,0,0);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(0,1,0);
    glVertex3i(0,2,0);
    glVertex3i(3,2,0);
    glVertex3i(5,2,2);
    glVertex3i(5,2,5);
    glVertex3i(3,2,7);
    glVertex3i(0,2,7);
    glVertex3i(-2,2,5);
    glVertex3i(-2,2,2);

    glEnd();

}

void Windmill::polyhedronPentagon(){

    glBegin(GL_POLYGON);

    glColor3f(0,1,0);
    glVertex3f(0,0,0);
    glVertex3f(-1,3,0);
    glVertex3f(2,5,0);
    glVertex3f(5,3,0);
    glVertex3f(4,0,0);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(0,1,0);
    glVertex3f(0,0,5);
    glVertex3f(-1,3,5);
    glVertex3f(2,5,5);
    glVertex3f(5,3,5);
    glVertex3f(4,0,5);

    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3f(1,1,0);

    glVertex3f(0,0,0);
    glVertex3f(0,0,5);
    glVertex3f(-1,3,0);
    glVertex3f(-1,3,5);
    glVertex3f(2,5,0);
    glVertex3f(2,5,5);
    glVertex3f(5,3,0);
    glVertex3f(5,3,5);
    glVertex3f(4,0,0);
    glVertex3f(4,0,5);
    glVertex3f(0,0,0);
    glVertex3f(0,0,5);

    glEnd();

}

void Windmill::Supporter()
{

glPushMatrix();
//glScalef(2,2,2);
polyhedronHexagon();
glPopMatrix();

glPushMatrix();
glScalef(0.9,0.9,0.9);
glTranslatef(-0.25,10.5,1.25);
polyhedronPentagon();
glPopMatrix();

glPushMatrix();
glTranslatef(0.4,2,0.85);
glScalef(0.75,0.75,0.75);
polyhedronHexagon();
glPopMatrix();

glPushMatrix();
glTranslatef(0.8,3.5,1.75);
glScalef(0.5,3,0.5);
polyhedronHexagon();
glPopMatrix();

}

void Windmill::SingleFan()
{

    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3i(0,0,0);
    glVertex3i(0,7,0);
    glVertex3i(3,7,0);
    glVertex3i(3,0,0);
    glEnd();
}
//-----------------------------------------------------------------
void Windmill::SingleBarSet()
{
    GLUquadricObj *pObj;
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);
    glPushMatrix();
    glColor3f(0,0,0);
    glRotatef(90,0,1,0);
    gluCylinder(pObj, 0.3f, 0.3f, 3, 26, 13);
    glPopMatrix();
    // Add code here
    glPushMatrix();
    glRotatef(-90,1,0,0);
    gluCylinder(pObj, 0.3f, 0.3f, 10, 26, 13);
    glPopMatrix();

    glPushMatrix();
    //glRotatef(180,0,1,0);
    glTranslatef(0,10,0);
    gluCylinder(pObj, 0.3f, 0.3f, 3, 26, 13);
    glPopMatrix();

    glPushMatrix();
    gluSphere(pObj, 0.3f, 26, 13);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,10,0);
    gluSphere(pObj, 0.3f, 26, 13);
    glPopMatrix();

    gluDeleteQuadric(pObj);
}
//-------------------------------------------------------------------
static int duplicate;
void Windmill::WindmillFan(){   // Add code here

    for(duplicate=0;duplicate<360;duplicate += 72){

        glPushMatrix();

        glRotatef(duplicate,0,0,1);
        glPushMatrix();
            glTranslatef(0,-10,0);
            SingleBarSet();
            SingleFan();
        glPopMatrix();
        glPopMatrix();
    }

}
//------------------------------------------------------------------
static float Rotation=0;
void Windmill::draw(){   // Add code here

    glPushMatrix();
    glRotatef(180,0,1,0);
    glTranslatef(posX,posY,posZ);
    Supporter();
    glPushMatrix();
    glTranslatef(1.5,11.5,0);
    glRotatef(Rotation,0,0,1);
    glScalef(0.85,0.85,0.85);

    WindmillFan();
    glPopMatrix();
    glPopMatrix();
    Rotation -=0.9;

}

//-------------------------------------------------------------------
