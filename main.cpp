#include <GL/glut.h>
#include <math.h>
#include "imageloader.h"


static int head = 0, body = 0,Rshoulder = 0, Relbow = 0, RfingerBase = 0,
RfingerUp = 0, RpointerBase = 0, RpointerUp = 0, RmiddleBase = 0,  RmiddleUp = 0,
RringBase = 0, RringUp = 0, RpinkyBase = 0, RpinkyUp = 0, Lshoulder = 0, Lelbow = 0,
LfingerBase = 0, LfingerUp = 0, LpointerBase = 0, LpointerUp = 0, LmiddleBase = 0,lthigh = 0,rthigh = 0,
LmiddleUp = 0, LringBase = 0, LringUp = 0, LpinkyBase = 0, LpinkyUp = 0, Rthigh = 0, Rleg = 0, Lthigh = 0, Lleg = 0;
int moving, startx, starty;
double eye[] = { 0, 0, -20 };
double center[] = { 0, 0, 1 };
double up[] = { 0, 1, 0 };
double direction[3];
GLfloat angle = 0.0;   /* in degrees */
int windowWidth = 1024;
int windowHeight = 768;
float aspect = float(windowWidth) / float(windowHeight);
Image* image;

float VRot =0.0;


GLuint loadTexture(Image* image) {
      GLuint textureId;
      glGenTextures(1, &textureId); //Make room for our texture
      glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
      //Map the image to the texture
      glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
                               0,                            //0 for now
                               GL_RGB,                       //Format OpenGL uses for image
                               image->width, image->height,  //Width and height
                               0,                            //The border of the image
                               GL_RGB, //GL_RGB, because pixels are stored in RGB format
                               GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
                                                 //as unsigned numbers
                               image->pixels);               //The actual pixel data
      return textureId; //Returns the id of the texture
}

GLuint _textureId; //The id of the texture


GLuint startList;

//Initializes 3D rendering
void initRendering() {
   if (!image) {
		image = loadBMP("data/floor2.bmp");
   if (!image) exit(0);
	}
   _textureId = loadTexture(image);
   delete image;
}

void init(void)
{
   glMatrixMode(GL_PROJECTION);
	gluPerspective(60.0, aspect, 1.0, 60.0);
}

void crossProduct(double a[], double b[], double c[])
{
	c[0] = a[1] * b[2] - a[2] * b[1];
	c[1] = a[2] * b[0] - a[0] * b[2];
	c[2] = a[0] * b[1] - a[1] * b[0];
}

void normalize(double a[])
{
	double norm;
	norm = a[0] * a[0] + a[1] * a[1] + a[2] * a[2];
	norm = sqrt(norm);
	a[0] /= norm;
	a[1] /= norm;
	a[2] /= norm;
}

void rotatePoint(double a[], double theta, double p[])
{

	double temp[3];
	temp[0] = p[0];
	temp[1] = p[1];
	temp[2] = p[2];

	temp[0] = -a[2] * p[1] + a[1] * p[2];
	temp[1] = a[2] * p[0] - a[0] * p[2];
	temp[2] = -a[1] * p[0] + a[0] * p[1];

	temp[0] *= sin(theta);
	temp[1] *= sin(theta);
	temp[2] *= sin(theta);

	temp[0] += (1 - cos(theta))*(a[0] * a[0] * p[0] + a[0] * a[1] * p[1] + a[0] * a[2] * p[2]);
	temp[1] += (1 - cos(theta))*(a[0] * a[1] * p[0] + a[1] * a[1] * p[1] + a[1] * a[2] * p[2]);
	temp[2] += (1 - cos(theta))*(a[0] * a[2] * p[0] + a[1] * a[2] * p[1] + a[2] * a[2] * p[2]);

	temp[0] += cos(theta)*p[0];
	temp[1] += cos(theta)*p[1];
	temp[2] += cos(theta)*p[2];

	p[0] = temp[0];
	p[1] = temp[1];
	p[2] = temp[2];

}

void Left()
{
   rotatePoint(up, 0.1, eye);
}

void Right()
{
   rotatePoint(up, -0.1, eye);
}

void Up()
{
   crossProduct(eye, up, direction);
   normalize(direction);
   rotatePoint(direction, -0.1, eye);
   rotatePoint(direction, -0.1, up);
}

void Down()
{	
   crossProduct(eye, up, direction);
   normalize(direction);
   rotatePoint(direction, 0.1, eye);
   rotatePoint(direction, 0.1, up);
}

void moveForward()
{
   direction[0] = center[0] - eye[0];
	direction[1] = center[1] - eye[1];
	direction[2] = center[2] - eye[2];
   eye[0] += direction[0] * 0.01;
	eye[1] += direction[1] * 0.01;
	eye[2] += direction[2] * 0.01;
	center[0] += direction[0] * 0.01;
	center[1] += direction[1] * 0.01;
	center[2] += direction[2] * 0.01;
}

void moveBack()
{
   direction[0] = center[0] - eye[0];
	direction[1] = center[1] - eye[1];
	direction[2] = center[2] - eye[2];
   eye[0] -= direction[0] * 0.01;
	eye[1] -= direction[1] * 0.01;
	eye[2] -= direction[2] * 0.01;
	center[0] -= direction[0] * 0.01;
	center[1] -= direction[1] * 0.01;
	center[2] -= direction[2] * 0.01;
}
void floorTexture()
{
   //floortextureId
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D, _textureId);

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

   glBegin(GL_QUADS);      
	glNormal3f(0.0,-1.0,0.0);
	glTexCoord2f(0.0f, 0.0f);
   glVertex3f(-10,10,10);
   glTexCoord2f(5.0f,  0.0f);
   glVertex3f(10,10,10);
   glTexCoord2f(5.0f,  20.0f);
   glVertex3f(10,10,-10);
   glTexCoord2f(0.0f, 20.0f);
   glVertex3f(-10,10,-10);
   glEnd();

   glBegin(GL_QUADS);      
	glNormal3f(0.0,0.0,-1.0);
	glTexCoord2f(0.0f, 0.0f);
   glVertex3f(10,10,10);
   glTexCoord2f(5.0f,  0.0f);
   glVertex3f(10,-3.35,10);
   glTexCoord2f(5.0f,  20.0f);
   glVertex3f(-10,-3.35,10);
   glTexCoord2f(0.0f, 20.0f);
   glVertex3f(-10,10,10);
   glEnd();

   glBegin(GL_QUADS);       
	glNormal3f(-1.0,0.0,0.0);
	glTexCoord2f(0.0f, 0.0f);
   glVertex3f(10,-3.35,10);
   glTexCoord2f(5.0f,  0.0f);
   glVertex3f(10,10,10);
   glTexCoord2f(5.0f,  20.0f);
   glVertex3f(10,10,-10);
   glTexCoord2f(0.0f, 20.0f);
   glVertex3f(10,-3.35,-10);
   glEnd();

   glBegin(GL_QUADS);       
	glNormal3f(-1.0,0.0,0.0);
	glTexCoord2f(0.0f, 0.0f);
   glVertex3f(-10,-3.35,10);
   glTexCoord2f(5.0f,  0.0f);
   glVertex3f(-10,10,10);
   glTexCoord2f(5.0f,  20.0f);
   glVertex3f(-10,10,-10);
   glTexCoord2f(0.0f, 20.0f);
   glVertex3f(-10,-3.35,-10);
   glEnd();

   glBegin(GL_QUADS);      
	glNormal3f(0.0,-1.0,0.0);
	glTexCoord2f(0.0f, 0.0f);
   glVertex3f(-10,-3.35,10);
   glTexCoord2f(5.0f,  0.0f);
   glVertex3f(10,-3.35,10);
   glTexCoord2f(5.0f,  20.0f);
   glVertex3f(10,-3.35,-10);
   glTexCoord2f(0.0f, 20.0f);
   glVertex3f(-10,-3.35,-10);
   glEnd();
	glDisable(GL_TEXTURE_2D);
   glPopMatrix();
   //
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glMatrixMode(GL_MODELVIEW);
	glShadeModel(GL_FLAT);
	glLoadIdentity();
	gluLookAt(eye[0], eye[1], eye[2], center[0], center[1], center[2], up[0], up[1], up[2]);
   floorTexture();
	//head
   glPushMatrix();
   glRotatef ((GLfloat) head, 0.0, 1.0, 0.0);
   glTranslatef(0, 0.0, 1.5);
   glPushMatrix();
   glTranslatef(0, 3.5, 0.0);
   glutWireSphere(0.5, 20, 20);
   glPopMatrix();
   //body  
   glTranslatef(0, 0.5, 0.0);
   glRotatef ((GLfloat) body, 0.0, 1.0, 0.0);
   glTranslatef(0.0, 1.0, 0.0);
   glPushMatrix();
   glScalef (1.0, 2.0, 0.4);
   glutSolidCube (1.5);
   glPopMatrix();
   //left shoulder
   glPushMatrix();
   glTranslatef (0.25, 1.0, 0.0);
   glRotatef ((GLfloat) Lshoulder, 0.0, 0.0, 1.0);
   glTranslatef (1.0, 0.0, 0.0);
   glPushMatrix();
   glScalef (1.0, 0.4, 0.4);
   glutSolidCube (1.0);
   glPopMatrix();
   //left elbow
   glTranslatef (0.5, 0.0, 0.0);
   glRotatef ((GLfloat) Lelbow, 0.0, 0.0, 1.0);
   glTranslatef (0.5, 0.0, 0.0);
   glPushMatrix();
   glScalef (1.0, 0.4, 0.4);
   glutSolidCube (1.0);
   glPopMatrix();
// left hand
   //Draw finger flang 1 
   glPushMatrix();
   glTranslatef(0.45, 0.0, 0.0);
   glRotatef((GLfloat)LfingerBase, 0.0, 1.0, 0.0);
   glTranslatef(0.1, -0.15, 0.1);
   glPushMatrix();
   glScalef(0.15, 0.05, 0.05);
   glutSolidCube(1);
   glPopMatrix();
   //Draw finger flang 1 
   glTranslatef(0.15, 0.0, 0.0);
   glRotatef((GLfloat)LfingerUp, 0.0, 1.0, 0.0);
   glPushMatrix();
   glScalef(0.15, 0.05, 0.05);
   glutSolidCube(1);
   glPopMatrix();
   glPopMatrix();
   //pointer
   glPushMatrix();
   glTranslatef(0.5, 0.15, -0.25);
   glRotatef((GLfloat)LpointerBase, 0.0, 0.0, 1.0);
   glTranslatef(0.05, 0.0, 0.4);
   glPushMatrix();
   glScalef(0.15, 0.05, 0.05);
   glutSolidCube(1);
   glPopMatrix();

   glTranslatef(0.15, 0.0, 0.0);
   glRotatef((GLfloat)LpointerUp, 0.0, 0.0, 1.0);
   glTranslatef(0.0, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.15, 0.05, 0.05);
   glutSolidCube(1);
   glPopMatrix();
   glPopMatrix();
   //middle
   glPushMatrix();
   glTranslatef(0.5, 0.15, -0.35);
   glRotatef((GLfloat)LmiddleBase, 0.0, 0.0, 1.0);
   glTranslatef(0.05, 0.0, 0.4);
   glPushMatrix();
   glScalef(0.15, 0.05, 0.05);
   glutSolidCube(1);
   glPopMatrix();

   glTranslatef(0.15, 0.0, 0.0);
   glRotatef((GLfloat)LmiddleUp, 0.0, 0.0, 1.0);
   glTranslatef(0.0, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.15, 0.05, 0.05);
   glutSolidCube(1);
   glPopMatrix();
   glPopMatrix();
   //ring
   glPushMatrix();
   glTranslatef(0.5, 0.15, -0.45);
   glRotatef((GLfloat)LringBase, 0.0, 0.0, 1.0);
   glTranslatef(0.05, 0.0, 0.4);
   glPushMatrix();
   glScalef(0.15, 0.05, 0.05);
   glutSolidCube(1);
   glPopMatrix();

   glTranslatef(0.15, 0.0, 0.0);
   glRotatef((GLfloat)LringUp, 0.0, 0.0, 1.0);
   glTranslatef(0.0, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.15, 0.05, 0.05);
   glutSolidCube(1);
   glPopMatrix();
   glPopMatrix();
   //pinky
   glPushMatrix();
   glTranslatef(0.5, 0.15, -0.55);
   glRotatef((GLfloat)LpinkyBase, 0.0, 0.0, 1.0);
   glTranslatef(0.05, 0.0, 0.4);
   glPushMatrix();
   glScalef(0.15, 0.05, 0.05);
   glutSolidCube(1);
   glPopMatrix();

   glTranslatef(0.15, 0.0, 0.0);
   glRotatef((GLfloat)LpinkyUp, 0.0, 0.0, 1.0);
   glTranslatef(0.0, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.15, 0.05, 0.05);
   glutSolidCube(1);
   glPopMatrix();
   glPopMatrix();
   //
   glPopMatrix();
//right side
   //shoulder
   glPushMatrix();
   glTranslatef (-0.25, 1.0, 0.0);
   glRotatef ((GLfloat) Rshoulder, 0.0, 0.0, 1.0);
   glTranslatef (-1.0, 0.0, 0.0);
   glPushMatrix();
   glScalef (1.0, 0.4, 0.4);
   glutSolidCube (1.0);
   glPopMatrix();
   //elbow
   glTranslatef (-0.5, 0.0, 0.0);
   glRotatef ((GLfloat) Relbow, 0.0, 0.0, 1.0);
   glTranslatef (-0.5, 0.0, 0.0);
   glPushMatrix();
   glScalef (1.0, 0.4, 0.4);
   glutSolidCube (1.0);
   glPopMatrix();

   //Draw finger flang 1 
   glPushMatrix();
   glTranslatef(-0.35, 0.0, -0.3);
   glRotatef((GLfloat)RfingerBase, 0.0, 1.0, 0.0);
   glTranslatef(-0.2, -0.15, 0.4);
   glPushMatrix();
   glScalef(0.15, 0.05, 0.05);
   glutSolidCube(1);
   glPopMatrix();
   //Draw finger flang 1 
   glTranslatef(-0.15, 0.0, 0.0);
   glRotatef((GLfloat)RfingerUp, 0.0, 1.0, 0.0);
   glPushMatrix();
   glScalef(0.15, 0.05, 0.05);
   glutSolidCube(1);
   glPopMatrix();
   glPopMatrix();
   //pointer
   glPushMatrix();
   glTranslatef(-0.5, 0.15, -0.25);
   glRotatef((GLfloat)RpointerBase, 0.0, 0.0, 1.0);
   glTranslatef(-0.05, 0.0, 0.4);
   glPushMatrix();
   glScalef(0.15, 0.05, 0.05);
   glutSolidCube(1);
   glPopMatrix();

   glTranslatef(-0.15, 0.0, 0.0);
   glRotatef((GLfloat)RpointerUp, 0.0, 0.0, 1.0);
   glPushMatrix();
   glScalef(0.15, 0.05, 0.05);
   glutSolidCube(1);
   glPopMatrix();
   glPopMatrix();
   //middle
   glPushMatrix();
   glTranslatef(-0.5, 0.15, -0.35);
   glRotatef((GLfloat)RmiddleBase, 0.0, 0.0, 1.0);
   glTranslatef(-0.05, 0.0, 0.4);
   glPushMatrix();
   glScalef(0.15, 0.05, 0.05);
   glutSolidCube(1);
   glPopMatrix();

   glTranslatef(-0.15, 0.0, 0.0);
   glRotatef((GLfloat)RmiddleUp, 0.0, 0.0, 1.0);
   glPushMatrix();
   glScalef(-0.15, 0.05, 0.05);
   glutSolidCube(1);
   glPopMatrix();
   glPopMatrix();
   //ring
   glPushMatrix();
   glTranslatef(-0.5, 0.15, -0.45);
   glRotatef((GLfloat)RringBase, 0.0, 0.0, 1.0);
   glTranslatef(-0.05, 0.0, 0.4);
   glPushMatrix();
   glScalef(0.15, 0.05, 0.05);
   glutSolidCube(1);
   glPopMatrix();

   glTranslatef(-0.15, 0.0, 0.0);
   glRotatef((GLfloat)RringUp, 0.0, 0.0, 1.0);
   glPushMatrix();
   glScalef(-0.15, 0.05, 0.05);
   glutSolidCube(1);
   glPopMatrix();
   glPopMatrix();
   //pinky
   glPushMatrix();
   glTranslatef(-0.5, 0.15, -0.55);
   glRotatef((GLfloat)RpinkyBase, 0.0, 0.0, 1.0);
   glTranslatef(-0.05, 0.0, 0.4);
   glPushMatrix();
   glScalef(0.15, 0.05, 0.05);
   glutSolidCube(1);
   glPopMatrix();

   glTranslatef(-0.15, 0.0, 0.0);
   glRotatef((GLfloat)RpinkyUp, 0.0, 0.0, 1.0);
   glPushMatrix();
   glScalef(-0.15, 0.05, 0.05);
   glutSolidCube(1);
   glPopMatrix();
   glPopMatrix();
   //
   glPopMatrix();
   //left leg
   glPushMatrix();
   glTranslatef(-0.5, -1.75, 0.0);
   glRotatef ((GLfloat) lthigh, 0.0, 0.0, 1.0);
   glRotatef ((GLfloat) Lthigh, 1.0, 0.0, 0.0);
   glTranslatef(0, -0.5, 0.0);
   glPushMatrix();
   glScalef (0.5, 1.5, 0.6);
   glutSolidCube (1.0);
   glPopMatrix();

   glTranslatef(0, -1.0, 0.0);
   glRotatef ((GLfloat) Lleg, 1.0, 0.0, 0.0);
   glTranslatef(0, -0.5, 0.0);
   glPushMatrix();
   glScalef (0.5, 1.5, 0.6);
   glutSolidCube (1.0);
   glPopMatrix();

   glTranslatef(0, -0.9, 0.0);
   glPushMatrix();
   glScalef (0.5, 0.3, 1.2);
   glutSolidCube (1.0);
   glPopMatrix();
   glPopMatrix();

   //right leg
   glPushMatrix();
   glTranslatef(0.5, -1.75, 0.0);
   glRotatef ((GLfloat) rthigh, 0.0, 0.0, 1.0);
   glRotatef ((GLfloat) Rthigh, 1.0, 0.0, 0.0);
   glTranslatef(0, -0.5, 0.0);
   glPushMatrix();
   glScalef (0.5, 1.5, 0.6);
   glutSolidCube (1.0);
   glPopMatrix();

   glTranslatef(0, -1.0, 0.0);
   glRotatef ((GLfloat) Rleg, 1.0, 0.0, 0.0);
   glTranslatef(0, -0.5, 0.0);
   glPushMatrix();
   glScalef (0.5, 1.5, 0.6);
   glutSolidCube (1.0);
   glPopMatrix();

   glTranslatef(0, -0.9, 0.0);
   glPushMatrix();
   glScalef (0.5, 0.3, 1.2);
   glutSolidCube (1.0);
   glPopMatrix();
   glPopMatrix();

   glPopMatrix();
	glutSwapBuffers();
}
static void mouse(int button, int state, int x, int y)
{
  if (button == GLUT_LEFT_BUTTON) {
    if (state == GLUT_DOWN) {
      moving = 1;
      startx = x;
    }
    if (state == GLUT_UP) {
      moving = 0;
    }
  }
}


static void motion(int x, int y)
{
  if (moving) {
    angle =  (x - startx);
    startx = x;
    rotatePoint(up, angle/100, eye);
    
    glutPostRedisplay();
  }
}

void specialKeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT: Left(); break;
	case GLUT_KEY_RIGHT: Right(); break;
	case GLUT_KEY_UP:    Up(); break;
	case GLUT_KEY_DOWN:  Down(); break;
	}

	glutPostRedisplay();
}

void screen_menu(int value)
{
	switch (value) {
	case 'a':
		image = loadBMP("data/floor.bmp");
		break;
	case 's':
		image = loadBMP("data/floor2.bmp");
		break;
   case 'd':
		image = loadBMP("data/floor3.bmp");
		break;
	case 'f':
		image = loadBMP("data/floor4.bmp");
		break;
	case 'j':
		image = loadBMP("data/floor5.bmp");
		break;
	}

	if (!image) exit(0);
   initRendering();

	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'f':
		moveForward();
		glutPostRedisplay();
		break;
	case 'b':
		moveBack();
		glutPostRedisplay();
		break;
	case 'h':
      head = (head + 5) % 360;
      glutPostRedisplay();
      break;
   case 'H':
      head = (head - 5) % 360;
      glutPostRedisplay();
      break;
   case 'u':
      if (body < 45)
      body = (body + 5) % 360;
      glutPostRedisplay();
      break;
   case 'U':
      if (body > -45)
      body = (body - 5) % 360;
      glutPostRedisplay();
      break;
   case 's':
   if (Lshoulder < 45)
      Lshoulder = (Lshoulder + 5) % 360;
      glutPostRedisplay();
      break;
   case 'S':
   if (Lshoulder > -45)
      Lshoulder = (Lshoulder - 5) % 360;
      glutPostRedisplay();
      break;
   case 'a':
   if (Rshoulder < 45)
      Rshoulder = (Rshoulder + 5) % 360;
      glutPostRedisplay();
      break;
   case 'A':
      if (Rshoulder > -45)
      Rshoulder = (Rshoulder - 5) % 360;
      glutPostRedisplay();
   case 'e':
      if (Lelbow < 0)
      Lelbow = (Lelbow + 5) % 360;
      glutPostRedisplay();
      break;
   case 'E':
      if (Lelbow > -90)
      Lelbow = (Lelbow - 5) % 360;
      glutPostRedisplay();
      break;
   case 'y':
      if (Relbow < 90)
      Relbow = (Relbow + 5) % 360;
      glutPostRedisplay();
      break;
   case 'Y':
      if (Relbow > 0)
      Relbow = (Relbow - 5) % 360;
      glutPostRedisplay();
      break;
   case 'l':
      if ( LfingerBase < 90)
      LfingerBase = (LfingerBase + 5) % 360;
      glutPostRedisplay();
      break;
   case 'L':
      if (LfingerBase > 0)
      LfingerBase = (LfingerBase - 5) % 360;
      glutPostRedisplay();
      break;
   case 'g':
      if (LfingerUp < 90)
      LfingerUp = (LfingerUp + 5) % 360;
      glutPostRedisplay();
      break;
   case 'G':
      if (LfingerUp > 0)
      LfingerUp = (LfingerUp - 5) % 360;
      glutPostRedisplay();
      break;
   case 'p':
      if (LpointerBase > -90)
      LpointerBase = (LpointerBase - 5) % 360;
      glutPostRedisplay();
      break;
   case 'P':
      if (LpointerBase < 0)
      LpointerBase = (LpointerBase + 5) % 360;
      glutPostRedisplay();
      break;
   case 'q':
      if (LpointerUp > -90)
      LpointerUp = (LpointerUp - 5) % 360;
      glutPostRedisplay();
      break;
   case 'Q':
      if (LpointerUp < 0)
      LpointerUp = (LpointerUp + 5) % 360;
      glutPostRedisplay();
      break;
    case 'm':
      if (LmiddleBase > -90)
      LmiddleBase = (LmiddleBase - 5) % 360;
      glutPostRedisplay();
      break;
   case 'M':
      if (LmiddleBase < 0)
      LmiddleBase = (LmiddleBase + 5) % 360;
      glutPostRedisplay();
      break;
   case 'n':
      if (LmiddleUp > -90)
      LmiddleUp = (LmiddleUp - 5) % 360;
      glutPostRedisplay();
      break;
   case 'N':
      if (LmiddleUp < 0)
      LmiddleUp = (LmiddleUp + 5) % 360;
      glutPostRedisplay();
      break;
   case 'r':
      if (LringBase > -90)
      LringBase = (LringBase - 5) % 360;
      glutPostRedisplay();
      break;
   case 'R':
      if (LringBase < 0)
      LringBase = (LringBase + 5) % 360;
      glutPostRedisplay();
      break;
   case 't':
      if (LringUp > -90)
      LringUp = (LringUp - 5) % 360;
      glutPostRedisplay();
      break;
   case 'T':
      if (LringUp < 0)
      LringUp = (LringUp + 5) % 360;
      glutPostRedisplay();
      break;
   case 'i':
      if (LpinkyBase > -90)
      LpinkyBase = (LpinkyBase - 5) % 360;
      glutPostRedisplay();
      break;
   case 'I':
      if (LpinkyBase < 0)
      LpinkyBase = (LpinkyBase + 5) % 360;
      glutPostRedisplay();
      break;
   case 'o':
      if (LpinkyUp > -90)
      LpinkyUp = (LpinkyUp - 5) % 360;
      glutPostRedisplay();
      break;
   case 'O':
      if (LpinkyUp < 0)
      LpinkyUp = (LpinkyUp + 5) % 360;
      glutPostRedisplay();
      break;
      
   case '1':
      if (RfingerBase <0)
      RfingerBase = (RfingerBase + 5) % 360;
      glutPostRedisplay();
      break;
   case '!':
      if (RfingerBase > -90)
      RfingerBase = (RfingerBase - 5) % 360;
      glutPostRedisplay();
      break;
   case '2':
      if (RfingerUp < 90)
      RfingerUp = (RfingerUp + 5) % 360;
      glutPostRedisplay();
      break;
   case '@':
      if (RfingerUp > 0)
      RfingerUp = (RfingerUp - 5) % 360;
      glutPostRedisplay();
      break;
   case '3':
      if (RpointerBase > 0)
      RpointerBase = (RpointerBase - 5) % 360;
      glutPostRedisplay();
      break;
   case '#':
      if (RpointerBase < 90)
      RpointerBase = (RpointerBase + 5) % 360;
      glutPostRedisplay();
      break;
   case '4':
      if (RpointerUp > 0)
      RpointerUp = (RpointerUp - 5) % 360;
      glutPostRedisplay();
      break;
   case '$':
      if (RpointerUp < 90)
      RpointerUp = (RpointerUp + 5) % 360;
      glutPostRedisplay();
      break;
   case '5':
      if (RmiddleBase > 0)
      RmiddleBase = (RmiddleBase - 5) % 360;
      glutPostRedisplay();
      break;
   case '%':
      if (RmiddleBase < 90)
      RmiddleBase = (RmiddleBase + 5) % 360;
      glutPostRedisplay();
      break;
   case '6':
      if (RmiddleUp > 0)
      RmiddleUp = (RmiddleUp - 5) % 360;
      glutPostRedisplay();
      break;
   case '^':
      if (RmiddleUp < 90)
      RmiddleUp = (RmiddleUp + 5) % 360;
      glutPostRedisplay();
      break;
   case '7':
      if (RringBase > 0)
      RringBase = (RringBase - 5) % 360;
      glutPostRedisplay();
      break;
   case '&':
      if (RringBase < 90)
      RringBase = (RringBase + 5) % 360;
      glutPostRedisplay();
      break;
   case '8':
      if (RringUp > 0)
      RringUp = (RringUp - 5) % 360;
      glutPostRedisplay();
      break;
   case '*':
      if (RringUp < 90)
      RringUp = (RringUp + 5) % 360;
      glutPostRedisplay();
      break;
   case '9':
      if (RpinkyBase > 0)
      RpinkyBase = (RpinkyBase - 5) % 360;
      glutPostRedisplay();
      break;
   case '(':
      if (RpinkyBase < 90)
      RpinkyBase = (RpinkyBase + 5) % 360;
      glutPostRedisplay();
      break;
   case '0':
      if (RpinkyUp > 0)
      RpinkyUp = (RpinkyUp - 5) % 360;
      glutPostRedisplay();
      break;
   case ')':
      if (RpinkyUp < 90)
      RpinkyUp = (RpinkyUp + 5) % 360;
      glutPostRedisplay();
      break;
   case 'z':
      if (lthigh > -90)
      lthigh = (lthigh - 5) % 360;
      glutPostRedisplay();
      break;
   case 'Z':
      if (lthigh < 0)
      lthigh = (lthigh + 5) % 360;
      glutPostRedisplay();
      break;
   case 'x':
      if (Lthigh > -90)
      Lthigh = (Lthigh - 5) % 360;
      glutPostRedisplay();
      break;
   case 'X':
      if (Lthigh < 90)
      Lthigh = (Lthigh + 5) % 360;
      glutPostRedisplay();
      break;
   case 'c':
      if (rthigh > 0)
      rthigh = (rthigh - 5) % 360;
      glutPostRedisplay();
      break;
   case 'C':
      if (rthigh < 90)
      rthigh = (rthigh + 5) % 360;
      glutPostRedisplay();
      break;
   case 'v':
      if (Rthigh > -90)
      Rthigh = (Rthigh - 5) % 360;
      glutPostRedisplay();
      break;
   case 'V':
      if (Rthigh < 90)
      Rthigh = (Rthigh + 5) % 360;
      glutPostRedisplay();
      break;
   case 'd':
      if (Lleg > 0 )
      Lleg = (Lleg - 5) % 360;
      glutPostRedisplay();
      break;
   case 'D':
      if (Lleg < 90)
      Lleg = (Lleg + 5) % 360;
      glutPostRedisplay();
      break;
   case 'k':
      if (Rleg > 0)
      Rleg = (Rleg - 5) % 360;
      glutPostRedisplay();
      break;
   case 'K':
      if (Rleg < 90)
      Rleg = (Rleg + 5) % 360;
      glutPostRedisplay();
      break;
	default:
		break;
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB );
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
   
	glutCreateWindow("ROOM");
	initRendering();
	init();
	glutDisplayFunc(display);
   glutCreateMenu(screen_menu);
	glutAddMenuEntry("Floors", 0);
	glutAddMenuEntry("", 0);
	glutAddMenuEntry("floor1", 'a');
	glutAddMenuEntry("floor2", 's');
	glutAddMenuEntry("floor3", 'd');
	glutAddMenuEntry("floor4", 'f');
	glutAddMenuEntry("floor5", 'j');
	glutAttachMenu(GLUT_RIGHT_BUTTON);
   glutSpecialFunc(specialKeys);
	glutKeyboardFunc(keyboard);
   glutMouseFunc(mouse);
   glutMotionFunc(motion);
	glutMainLoop();
	return 0;
}
