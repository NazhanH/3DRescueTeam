//--------------------------------------------
//Lab: 3D Modelling
//--------------------------------------------

#include <GL\glut.h>
#include <math.h>
#include <stdlib.h>

#include "Windmill.h"
#include "Tree.h"

static int windowWidth=800;
static int windowHeight=500;
static float fieldOfView= 60.0;
static float aspectRatio = static_cast<GLdouble> (windowWidth)/windowHeight;
double rotateX  = 0.0;
double rotateY  = 0.0;
double rotateZ  = 0.0;
double posX     = 0.0;
double posY     = 0.0;
double posZ     = 0.0;
double scaleX   = 1.0;
double scaleY   = 1.0;
double scaleZ   = 1.0;
static bool mousePanMode=false;
static bool mouseZoomMode=false;
static bool mouseRotationMode=false;
int mouseX, mouseY;

Windmill win1(0,0,0);
Tree t1(0,0,0);

void myInit(void)
{
   static GLfloat  ambient[] = { 0.0f,  0.0f,  0.0f, 1.0f };
   static GLfloat  diffuse[] = { 1.0f,  1.0f,  1.0f, 1.0f };
   static GLfloat specular[] = { 0.0f,  0.0f,  0.0f, 1.0f };
   static GLfloat  ref[] = { 1.0f,  1.0f,  1.0f, 1.0f };
   static GLfloat position[] = {10.0f, 10.0f, 10.0f, 1.0f };
   short shininess = 128;

	glEnable(GL_DEPTH_TEST);
	glShadeModel (GL_SMOOTH);
	glClearColor(0.8f, 0.8f, 0.8f, 0.0f);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glEnable(GL_LIGHT0);

    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);

    glMaterialfv(GL_FRONT, GL_SPECULAR, ref);
    glMateriali(GL_FRONT, GL_SHININESS, shininess);

	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,aspectRatio, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,15,20, 0,0,0, 0,1,0);
}
//--------------------------------------------------------------------------
void MyModelAxis(void)
{
 float lengthX=15.0,lengthY=15.0,lengthZ=15.0;
 //glDisable(GL_LIGHTING);

 glEnable(GL_LINE_STIPPLE);
 glLineWidth(1);
 glLineStipple(1, 0xffff);

 glBegin(GL_LINES);
   //x-axis
     glColor3f(1,0,0);

     glVertex3f( 0.0, 0.0, 0.0);
     glVertex3f(lengthX, 0.0, 0.0);
   //x-axis arrow
     glVertex3f(    lengthX, 0.0,  0.0);
     glVertex3f(0.9*lengthX, 0.0,  0.05*lengthX);
     glVertex3f(    lengthX, 0.0,  0.0);
     glVertex3f(0.9*lengthX, 0.0, -0.05*lengthX);

   //y-axis
     glColor3f(0,1,0);
     glVertex3f(0.0,  0.0, 0.0);
     glVertex3f(0.0, lengthY, 0.0);
   //y-axis arrow
     glVertex3f(       0.0,     lengthY, 0.0);
     glVertex3f( 0.05*lengthY, 0.9*lengthY, 0.0);
     glVertex3f(       0.0,     lengthY, 0.0);
     glVertex3f(-0.05*lengthY, 0.9*lengthY, 0.0);

   //z-axis
     glColor3f(0,0,1);
     glVertex3f(0.0, 0.0,  0.0);
     glVertex3f(0.0, 0.0, lengthZ);
   //z-axis arrow
     glVertex3f(0.0, 0.0, lengthZ);
     glVertex3f( 0.05*lengthZ, 0.0, 0.9*lengthZ);
     glVertex3f(       0.0, 0.0,     lengthZ);
     glVertex3f(-0.05*lengthZ, 0.0, 0.9*lengthZ);
 glEnd();
 //glEnable(GL_LIGHTING);
}
//--------------------------------------------------------------------------
void myDisplayFunc(void)
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

 glPushMatrix();
    glTranslatef(posX, posY, posZ);
    glRotatef(rotateX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotateY, 0.0f, 1.0f, 0.0f);
    glRotatef(rotateZ, 0.0f, 0.0f, 1.0f);
    glScalef(scaleX, scaleY, scaleZ);

 MyModelAxis();
 //Add code here

 win1.draw();
 t1.draw();

 glPopMatrix();
 glFlush();
 glutSwapBuffers();
}
void updateScene(){
 glutPostRedisplay();
}

//--------------------------------------------------------------------------
void myReshapeFunc(int width, int height)
{
 windowWidth  = width;
 windowHeight = height;
 glViewport(0, 0, width, height);
}
//--------------------------------------------------------------------------
void myKeyboardFunc(unsigned char key, int x, int y)
{
  switch (key)
  {

    case 27  : exit(1); break;
  }
  glutPostRedisplay();
}
//--------------------------------------------------------------------------
void mySpecialFunc(int key, int x, int y)
{
  switch (key)
  {

 	case GLUT_KEY_F1    : glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                             break;
	case GLUT_KEY_F2    : glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                             break;
  }
  glutPostRedisplay();
}
//--------------------------------------------------------------------------
void myMouseFunc(int button, int state, int x, int y)
{
    y = windowHeight-y;
    switch (button) {
      case GLUT_MIDDLE_BUTTON:
          if (state==GLUT_DOWN && !mousePanMode) {
              mouseX = x;
              mouseY = y;
              mousePanMode = true;
          }
          if (state==GLUT_UP &&  mousePanMode) {
              mousePanMode = false;
          }
          break;
      case GLUT_RIGHT_BUTTON:
          if (state==GLUT_DOWN && !mouseZoomMode) {
              mouseY = y;
              mouseZoomMode = true;
          }
          if (state==GLUT_UP && mouseZoomMode) {
              mouseZoomMode = false;
          }
          break;
      case GLUT_LEFT_BUTTON:
          if (state==GLUT_DOWN && !mouseRotationMode) {
              mouseX = x;
              mouseY = y;
              mouseRotationMode = true;
          }
          if (state==GLUT_UP &&  mouseRotationMode) {
              mouseRotationMode = false;
          }
		  break;
    }

}
//--------------------------------------------------------------------------
void myMotionFunc(int x, int y) {
    y = windowHeight - y;
    if(mousePanMode) {
        posX += (x - mouseX)*0.01;
        posY += (y - mouseY)*0.01;
        mouseX = x;
        mouseY = y;
        glutPostRedisplay();
    }
    if(mouseZoomMode) {
        GLdouble inc = (mouseY - y)*0.01;
        scaleX += inc;
        scaleY += inc;
        scaleZ += inc;
        if(scaleX < 0.1) scaleX = 0.1;
        if(scaleY < 0.1) scaleY = 0.1;
        if(scaleZ < 0.1) scaleZ = 0.1;
        mouseY = y;
        glutPostRedisplay();
    }
    if(mouseRotationMode) {
        rotateX += (mouseY - y)*0.5;
        rotateY += (x - mouseX)*0.5;
        mouseX = x;
        mouseY = y;
        glutPostRedisplay();
    }

}
//--------------------------------------------------------------------------
int main( int argc, char **argv)
{
 glutInit(&argc, argv);

 glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );
 glutInitWindowPosition(100, 100);
 glutInitWindowSize(windowWidth, windowHeight);
 glutCreateWindow("CompGraphicsProject");

 myInit();
 glutDisplayFunc(myDisplayFunc);
 glutIdleFunc(updateScene);
 glutReshapeFunc(myReshapeFunc);
 glutKeyboardFunc(myKeyboardFunc);
 glutSpecialFunc(mySpecialFunc);
 glutMotionFunc(myMotionFunc);
 glutMouseFunc(myMouseFunc);

 glutMainLoop(); // Display everything and wait
 return 0;
}
