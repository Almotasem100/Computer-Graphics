#include <GL/glut.h>
#include "imageloader.h"
#include "robot.cpp"
#include <iostream> 

int moving, startx, starty;
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

//Initializes 3D rendering
void initRendering() {
   if (!image) {
		image = loadBMP("data/floor.bmp");
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

void floorTexture()
{
   //floortextureId
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
   
   glBindTexture(GL_TEXTURE_2D, loadTexture(loadBMP("data/floor5.bmp")));
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

   //glDisable(GL_TEXTURE_2D);
   //glBindTexture(GL_TEXTURE_2D, loadTexture(loadBMP("data/floor3.bmp")));
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

   glBindTexture(GL_TEXTURE_2D, _textureId);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

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
   //glTranslatef(0.0, 2.0, 0.0);
   robot();
   // legx =-15, legx2 = -15, knee = 15, knee2 = 15;
   body = 50;
   glutPostRedisplay();
	glutSwapBuffers();
}
static void mouse(int button, int state, int x, int y)
{
  if (button == GLUT_LEFT_BUTTON) {
    if (state == GLUT_DOWN) {
      moving = 1;
      startx = x;
      starty = y;
    }
    if (state == GLUT_UP) {
      moving = 0;
    }
  }
}

static void motion(int x, int y)
{
  if (moving) {
	int xx = x-startx;
	int yy = y-starty;
    if(xx > 3){Left();}
	else if(xx < -3){Right();}
	if(yy > 3){Up();}
	else if(yy < -3){Down();}
    startx = x;
    starty = y;
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
	case 1:
		image = loadBMP("data/floor.bmp");
		break;
	case 2:
		image = loadBMP("data/floor2.bmp");
		break;
   // case 3:
	// 	image = loadBMP("data/floor3.bmp");
	// 	break;
	case 4:
		image = loadBMP("data/floor4.bmp");
		break;
	case 5:
		image = loadBMP("data/floor3.bmp");
		break;
   case 6:
		image = loadBMP("data/floor6.bmp");
		break;
	case 7:
		image = loadBMP("data/floor7.bmp");
		break;
	}
	if (!image) exit(0);
   initRendering();
	glutPostRedisplay();
}
int state = 0;
int step_j = 1;
void timerica(int)
{

   switch (state)
   {
      case 0:
      {
         if(legx > -60)
         {
            legx -= step_j;
            legx2 -= step_j;
            knee += step_j;
            knee2 += step_j;
            shoulderlx += step_j;
            shoulderrx -= step_j;
            elbow += 2*step_j;
            elbow2 -= 2*step_j;
            if(legx < -15)
               elevation -= 0.01;
         }
         else
            state = 1;
      }break;
      case 1:
      {
         if(legx < -15)
         {
            legx += step_j;
            legx2 += step_j;
            knee -= step_j;
            knee2 -= step_j;
            shoulderlx += step_j;
            shoulderrx -= step_j;
            elevation += 0.03;
         }
         else
            state = 2;
      }break;
      case 2:
      {
         if(legx < 0)
         {
            legx += step_j;
            legx2 += step_j;
            knee -= step_j;
            knee2 -= step_j;
            shoulderlx += step_j;
            shoulderrx -= step_j;
            elbow -= 4*step_j;
            elbow2 += 4*step_j;
            elevation += 0.03;
         }
         else
            state = 3;
      }break;
      case 3:
      {
         if(elevation > 0.025)
         {
            elevation -= 0.025;
            if(elbow > 0)
            {
               elbow -= step_j;
               elbow2 += step_j;
            }
            if(shoulderlx > 0)
            {
               shoulderlx -= step_j;
               shoulderrx += step_j; 
            }
         }
         else
            state = 4;
      }
      case 4:
      {
         if(elbow > 0)
         {
            elbow -= step_j;
            elbow2 += step_j;
         }
         if(shoulderlx > 0)
         {
            shoulderlx -= step_j;
            shoulderrx += step_j; 
         }
         if (elbow == 0 && shoulderlx == 0)
         {
            state = 5;
            elevation = 0;
         }
      }
   }
   glutPostRedisplay();
   
   if(state == 5)
      state = 0;
   else
      glutTimerFunc(1000/60, timerica, 0);
   
}
void keyboard(unsigned char key, int x, int y)
{
   keyboard2(key, x, y);
   switch (key)
   {
   case 'z':
      state = 0;
      glutTimerFunc(1000/60, timerica, 0);
      break;
   // case 'Z':
   //    elevation -= 0.5;
   //    glutPostRedisplay();
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
	// glutAddMenuEntry("Floors:", 0);
	// glutAddMenuEntry("", 0);
   // glutAddMenuEntry("floor3", 3);
	glutAddMenuEntry("         Floor1         ", 1);
	glutAddMenuEntry("         Floor2", 2);
	glutAddMenuEntry("         Floor3", 4);
	glutAddMenuEntry("         Floor4", 5);
   glutAddMenuEntry("         Floor5", 6);
	glutAddMenuEntry("         Floor6", 7);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
   glutSpecialFunc(specialKeys);
	glutKeyboardFunc(keyboard);
   glutMouseFunc(mouse);
   glutMotionFunc(motion);
   // glutTimerFunc(1000/60, timerica, 0);
	glutMainLoop();
	return 0;
}