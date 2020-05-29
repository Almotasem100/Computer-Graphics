#include <GL/glut.h>
#include "imageloader.h"
#include "robot.cpp"
#include <iostream> 
#include "glm.h"
#include <math.h>

int moving, startx, starty;
int windowWidth = 1024;
int windowHeight = 768;
float aspect = float(windowWidth) / float(windowHeight);
Image* image;
float VRot =0.0;
// RGBA
GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 0.0 };
GLfloat light_diffuse[] = { 0.5, 0.5, 0.5,1.0 };
GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0 };
// x , y, z, w
GLfloat light_position[] = {0.5,5.0, 2.0, 1.0 };
GLfloat lightPos1[] = {-0.5,-5.0,-2.0, 1.0 };
// Material Properties
GLfloat mat_amb_diff[] = {0.643, 0.753, 0.934, 1.0 };
GLfloat mat_specular[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat shininess[] = {100.0 };  
//left teapot specular
GLfloat teapotl_diff[] = { 0.0,0.0, 1.0, 1.0 };
GLfloat teapotl_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat teapotl_shininess[] = {10.0 };  
//middle teapot diffuse
GLfloat teapotm_diff[] = { 1.0, 0, 0.0, 1.0 };
GLfloat teapotm_specular[] = { 0.0, 0.0, 0.0, 0.0 };
GLfloat teapotm_shininess[] = {1.0 };  
//right teapot glosy
GLfloat teapotr_diff[] = { 1.0, .0, 0.0, 1.0 };
GLfloat teapotr_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat teapotr_shininess[] = {1000.0 };  
//cube
GLfloat cube_diff[] = {1.0,0.0, 0.0, 1.0 };
GLfloat cube_specular[] = { 0.5, 0.5, 0.5, 1.0 };
GLfloat cube_shininess[] = {10.0 }; 
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
   // Turn on the power
   glEnable(GL_LIGHTING);
   // Flip light switch
   glEnable(GL_LIGHT0);
   glEnable(GL_LIGHT1);
   // assign light parameters
   glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
   glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
   glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
   glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
   glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
   // Material Properties         
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE,mat_amb_diff);
   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
   GLfloat lightColor1[] = {1.0f, 1.0f,  1.0f, 1.0f };
   glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
   glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor1);
   glEnable(GL_NORMALIZE);
   //Enable smooth shading
   glShadeModel(GL_SMOOTH);
   // Enable Depth buffer
   glEnable(GL_DEPTH_TEST);
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
   glVertex3f(10,10,-10);
   glTexCoord2f(5.0f,  0.0f);
   glVertex3f(10,-3.35,-10);
   glTexCoord2f(5.0f,  20.0f);
   glVertex3f(-10,-3.35,-10);
   glTexCoord2f(0.0f, 20.0f);
   glVertex3f(-10,10,-10);
   glEnd();

// glBegin(GL_QUADS);      
// 	glNormal3f(0.0,0.0,-1.0);
// 	glTexCoord2f(0.0f, 0.0f);
//    glVertex3f(10,10,10);
//    glTexCoord2f(5.0f,  0.0f);
//    glVertex3f(10,-3.35,10);
//    glTexCoord2f(5.0f,  20.0f);
//    glVertex3f(-10,-3.35,10);
//    glTexCoord2f(0.0f, 20.0f);
//    glVertex3f(-10,10,10);
//    glEnd();

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

}

GLMmodel* pmodel;
void drawmodel1( char* name)
{
	
	pmodel = glmReadOBJ(name);
	if (!pmodel) exit(0);
	glmUnitize(pmodel);
	glmFacetNormals(pmodel);
	glmVertexNormals(pmodel, 90.0);
	glmScale(pmodel, .15);

	glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glMatrixMode(GL_MODELVIEW);
	glShadeModel(GL_FLAT);
	glLoadIdentity();
	gluLookAt(eye[0], eye[1], eye[2], center[0], center[1], center[2], up[0], up[1], up[2]);
   glPushMatrix();
   glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);
   glPopMatrix();
   //materials properties
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE,mat_amb_diff);
   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glPushMatrix();
	glTranslatef(0, 0, -1);
   floorTexture();

   // legx =-15, legx2 = -15, knee = 15, knee2 = 15;
   
   // glutPostRedisplay();
   glPushMatrix();
	// glPushMatrix();
   // glTranslatef(-8, -3, -8);
   // glRotatef(45,0,1,0);
   // glScalef(20,20,20);
   // drawmodel1("objects/Bench_HighRes.obj");
	// glPopMatrix();

   glPushMatrix();
   glTranslatef(5, -0.1, 2);
   glRotatef(-90,1,0,0); 
   glRotatef(-90,0,0,1); 
   glScalef(20,20,20);
   drawmodel1("objects/10488_basketball_goal_L3.obj");	
	glPopMatrix();
	
   glPushMatrix();
   glTranslatef(2, -2, 5);	
	glScalef(2,2,2);	
   drawmodel1("objects/soccerball.obj");		
	glPopMatrix();

   glPushMatrix();
   glTranslatef(-12, -2, -15);	
	glScalef(20,20,20);	
   drawmodel1("objects/flowers.obj");		
	glPopMatrix();

   // glPushMatrix();
   // glTranslatef(10, -2, -10);
   // glRotatef(90,0,1,0);
   // glRotatef(30,1,0,0);
   // glScalef(10,10,10);	
   // drawmodel1("objects/11703_skateboard_v1_L3.obj");
	// glPopMatrix();
   glPopMatrix();
   body = 50;
  
   robot();
   glPopMatrix();
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
      glutTimerFunc(5, timerica, 0);
   
}
void keyboard(unsigned char key, int x, int y)
{
   keyboard2(key, x, y);
   switch (key)
   {
   case 'z':
      state = 0;
      glutTimerFunc(5, timerica, 0);
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