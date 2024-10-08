//--------------------------------------------
//Lab: 3D Modelling
//--------------------------------------------


#include <GL/glu.h>
#include <math.h>
#include <stdlib.h>
//#include <assimp/Importer.hpp>

#include "../header/Windmill.h"
#include "../header/Tree.h"
#include "../header/Sun.h"
#include "../header/Helicopter.h"
#include "../header/Firetruck.h"
#include "../header/Tank.h"
#include "../header/PoliceCar.h"

static int windowWidth=800;
static int windowHeight=500;
static float fieldOfView= 200.0;
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
const int NUM_BUILDINGS = 50;

Windmill win1(0,0,0);
Tree t1(0,0,0);
Helicopter h1(-15,10,0);
Firetruck f1(0,0.6,0);
Sun s1(25,30,-50);
Tank tank1(0,0,0);
PoliceCar p1(0,0,0);

void myInit(void)
{
   static GLfloat  ambient[] = { 0.0f,  0.0f,  0.0f, 0.0f };
   static GLfloat  diffuse[] = { 0.5f,  0.5f,  0.5f, 1.0f };
   static GLfloat specular[] = { 0.0f,  0.0f,  0.0f, 0.0f };
   static GLfloat  ref[] = { 0.0f,  0.0f,  0.0f, 0.0f };
   static GLfloat position[] = {10.0f, 10.0f, 20.0f, 1.0f };
   //short shininess = 128;
   short shininess = 0;

	glEnable(GL_DEPTH_TEST);
	glShadeModel (GL_SMOOTH);
	glClearColor(0.5f, 0.8f, 1.0f, 1.0f); // Sky blue background
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

// Function to draw the road
void drawRoad() {
    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f); // Dark grey road
    glTranslatef(0.0f, 0.0f, 0.0f);
    glScalef(200.0f, 0.1f, 9.0f); // Long road with some width
    glutSolidCube(1.0);
    glPopMatrix();
}

// Function to draw the grass background
void drawGrass() {
    glPushMatrix();
    glColor3f(0.1f, 0.6f, 0.1f); // Green grass
    glTranslatef(0.0f, 0.0f, 0.0f);
    glScalef(200.0f, 0.05f, 200.0f); // Large flat ground
    glutSolidCube(1.0);
    glPopMatrix();
}


// Function to draw a building with darker light blue color (single block skyscraper)
void drawBuilding(float width, float height, float depth) {
    // Set color to darker light blue
    glColor3f(0.4f, 0.6f, 0.8f);  // Darker light blue color

    // Main building block
    glBegin(GL_QUADS);

    // Front face
    glVertex3f(-width / 2, 0, depth / 2);
    glVertex3f(width / 2, 0, depth / 2);
    glVertex3f(width / 2, height, depth / 2);
    glVertex3f(-width / 2, height, depth / 2);

    // Back face
    glVertex3f(-width / 2, 0, -depth / 2);
    glVertex3f(width / 2, 0, -depth / 2);
    glVertex3f(width / 2, height, -depth / 2);
    glVertex3f(-width / 2, height, -depth / 2);

    // Left face
    glVertex3f(-width / 2, 0, -depth / 2);
    glVertex3f(-width / 2, 0, depth / 2);
    glVertex3f(-width / 2, height, depth / 2);
    glVertex3f(-width / 2, height, -depth / 2);

    // Right face
    glVertex3f(width / 2, 0, -depth / 2);
    glVertex3f(width / 2, 0, depth / 2);
    glVertex3f(width / 2, height, depth / 2);
    glVertex3f(width / 2, height, -depth / 2);

    // Top face
    glVertex3f(-width / 2, height, -depth / 2);
    glVertex3f(width / 2, height, -depth / 2);
    glVertex3f(width / 2, height, depth / 2);
    glVertex3f(-width / 2, height, depth / 2);

    glEnd();
}

void drawCityScape(){

    glPushMatrix();
    glScalef(1,0.5,1);

    glTranslatef(-50,0,-50);

 // Place buildings
    srand(time(0));  // Seed random generator for random building placement
    for (int i = 0; i < NUM_BUILDINGS; ++i) {
        float x = rand() % 200 - 50;
        float z = rand() % 50 - 50;
        float width = rand() % 10 + 5;
        float height = rand() % 30 + 10;
        float depth = rand() % 10 + 5;

        glPushMatrix();
        glTranslatef(x, 0, z);
        drawBuilding(width, height, depth);  // Draw simplified building with darker light blue color
        glPopMatrix();
    }
    glPopMatrix();

}



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
 drawGrass();
 drawRoad();
 drawCityScape();

 glPushMatrix();
 win1.draw();
 t1.draw();
 h1.draw();
 f1.draw();
 s1.draw();
 tank1.draw();
p1.draw();
glPopMatrix();

 glPopMatrix();
 glFlush();
 glutSwapBuffers();
}
void updateScene(){
//glutSwapBuffers();
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
    case 't' : tank1.launchBomb(); break;
    case 'r' : tank1.cannonUp(); break;
    case 'y' : tank1.cannonDown(); break;
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
