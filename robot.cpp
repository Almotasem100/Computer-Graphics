#include <GL/glut.h>
#include "shortcuts.cpp"


GLfloat angle = 0.0;   /* in degrees */
GLfloat angle2 = 0.0;   /* in degrees */

void robot() {
  
  glPushMatrix();
  glTranslatef(0.0, elevation, 0.0);
  glRotatef(angle2, 1.0, 0.0, 0.0);
  glRotatef(angle, 0.0, 1.0, 0.0);
  glRotatef ((GLfloat) body, 0.0, 1.0, 0.0);
  glPushMatrix();
  glScalef(1.5, 2.5, 0.5);
  glutWireCube(1.0);
  glPopMatrix();

  //LEFT ARM:
  glPushMatrix();

  //SHOULDER
  glTranslatef(0.85, 1.1, 0.0);
  glRotatef ((GLfloat) shoulderlz, 0.0, 0.0, 1.0);
  glRotatef ((GLfloat) shoulderlx, 0.0, -1.0, 0.0);
  glRotatef((GLfloat) elbowx, 1.0, 0.0, 0.0);
  glTranslatef(0.5, 0.0, 0.0);
  glPushMatrix();
  glScalef(1.0, 0.3, 0.5);
  glutWireCube(1.0);
  glPopMatrix();

  //ELBOW
  glTranslatef (0.5 , 0.0 , 0.0);
  glRotatef ((GLfloat) elbow, 0.0, -1.0, 0.0);
  //glRotatef((GLfloat) elbowx, 1.0, 0.0, 0.0);
  glTranslatef (0.5, 0.0, 0.0);
  glPushMatrix();
  glScalef (1.0, 0.3, 0.5);
  //glColor3f(1, 0.5, 0.2);
  glutWireCube (1.0);
  glPopMatrix();
  glPushMatrix();

  //Draw finger flang 1 
  glTranslatef(0.5, 0.1, 0.075);
  glRotatef((GLfloat)fingerBase, 0.0, 0.0, 1.0);
  glTranslatef(0.075, 0.0, 0.0);
  glPushMatrix();
  glScalef(0.15, 0.05, 0.05);
  // glColor3f(0.2, 0.4, 0.8);
  glutWireCube(1);
  glPopMatrix();
  //Draw finger flang 1 
  glTranslatef(0.075, 0.0, 0.0);
  glRotatef((GLfloat)fingerUp, 0.0, 0.0, 1.0);
  glTranslatef(0.075, 0.0, 0.0);
  glPushMatrix();
  glScalef(0.15, 0.05, 0.05);
  glutWireCube(1);
  glPopMatrix();
  glPopMatrix();
  glPushMatrix();
  //Draw finger flang 2 
  glTranslatef(0.5, 0.1, 0.2);
  glRotatef((GLfloat)finger2Base, 0.0, 0.0, 1.0);
  glTranslatef(0.075, 0.0, 0.0);
  glPushMatrix();
  glScalef(0.15, 0.05, 0.05);
  // glColor3f(0.2, 0.4, 0.8);
  glutWireCube(1);
  glPopMatrix();
  //Draw finger flang 2 
  glTranslatef(0.075, 0.0, 0.0);
  glRotatef((GLfloat)finger2Up, 0.0, 0.0, 1.0);
  glTranslatef(0.075, 0.0, 0.0);
  glPushMatrix();
  glScalef(0.15, 0.05, 0.05);
  glutWireCube(1);
  glPopMatrix();
  glPopMatrix();
  glPushMatrix();
  //Draw finger flang 3 
  glTranslatef(0.5, 0.1, -0.2);
  glRotatef((GLfloat)finger3Base, 0.0, 0.0, 1.0);
  glTranslatef(0.075, 0.0, 0.0);
  glPushMatrix();
  glScalef(0.15, 0.05, 0.05);
  // glColor3f(0.2, 0.4, 0.8);
  glutWireCube(1);
  glPopMatrix();
  //Draw finger flang 3 
  glTranslatef(0.075, 0.0, 0.0);
  glRotatef((GLfloat)finger3Up, 0.0, 0.0, 1.0);
  glTranslatef(0.075, 0.0, 0.0);
  glPushMatrix();
  glScalef(0.15, 0.05, 0.05);
  glutWireCube(1);
  glPopMatrix();
  glPopMatrix();
  glPushMatrix();
  //Draw finger flang 4 
  glTranslatef(0.5, 0.1, -0.075);
  glRotatef((GLfloat)finger4Base, 0.0, 0.0, 1.0);
  glTranslatef(0.075, 0.0, 0.0);
  glPushMatrix();
  glScalef(0.15, 0.05, 0.05);
  // glColor3f(0.2, 0.4, 0.8);
  glutWireCube(1);
  glPopMatrix();
  //Draw finger flang 4 
  glTranslatef(0.075, 0.0, 0.0);
  glRotatef((GLfloat)finger4Up, 0.0, 0.0, 1.0);
  glTranslatef(0.075, 0.0, 0.0);
  glPushMatrix();
  glScalef(0.15, 0.05, 0.05);
  glutWireCube(1);
  glPopMatrix();
  glPopMatrix();
  glPushMatrix();
  //Draw finger flang 5 
  glTranslatef(0.5, -0.1, 0.125);
  glRotatef((GLfloat)finger5Base, 0.0, 0.0, 1.0);
  glTranslatef(0.075, 0.0, 0.0);
  glPushMatrix();
  glScalef(0.15, 0.05, 0.05);
  // glColor3f(0.2, 0.4, 0.8);
  glutWireCube(1);
  glPopMatrix();
  //Draw finger flang 5 
  glTranslatef(0.075, 0.0, 0.0);
  glRotatef((GLfloat)finger5Up, 0.0, 0.0, 1.0);
  glTranslatef(0.075, 0.0, 0.0);
  glPushMatrix();
  glScalef(0.15, 0.05, 0.05);
  glutWireCube(1);
  glPopMatrix();
  glPopMatrix();
  glPopMatrix();




  //RIGHT ARM:
  glPushMatrix();

  //SHOULDER
  glTranslatef(-0.85, 1.1, 0.0);
  glRotatef ((GLfloat) shoulderrz, 0.0, 0.0, 1.0);
  glRotatef((GLfloat) shoulderrx, 0.0, -1.0, 0.0);
  glRotatef((GLfloat) elbowx2, 1.0, 0.0, 0.0);
  glTranslatef(-0.5, 0.0, 0.0);
  glPushMatrix();
  glScalef(1.0, 0.3, 0.5);
  glutWireCube(1.0);
  glPopMatrix();

  //ELBOW
  glTranslatef (-0.5 , 0.0 , 0.0);
  glRotatef ((GLfloat) elbow2, 0.0, -1.0, 0.0);
  //glRotatef((GLfloat) elbowx2, 1.0, 0.0, 0.0);
  glTranslatef (-0.5, 0.0, 0.0);
  glPushMatrix();
  glScalef (1.0, 0.3, 0.5);
  //glColor3f(1, 0.5, 0.2);
  glutWireCube (1.0);
  glPopMatrix();
  glPushMatrix();

  //Draw finger flang 1 
  glTranslatef(-0.5, 0.1, 0.075);
  glRotatef((GLfloat)fingerBase2, 0.0, 0.0, 1.0);
  glTranslatef(-0.075, 0.0, 0.0);
  glPushMatrix();
  glScalef(0.15, 0.05, 0.05);
  // glColor3f(0.2, 0.4, 0.8);
  glutWireCube(1);
  glPopMatrix();
  //Draw finger flang 1 
  glTranslatef(-0.075, 0.0, 0.0);
  glRotatef((GLfloat)fingerUp2, 0.0, 0.0, 1.0);
  glTranslatef(-0.075, 0.0, 0.0);
  glPushMatrix();
  glScalef(0.15, 0.05, 0.05);
  glutWireCube(1);
  glPopMatrix();
  glPopMatrix();
  glPushMatrix();
  //Draw finger flang 2 
  glTranslatef(-0.5, 0.1, 0.2);
  glRotatef((GLfloat)finger2Base2, 0.0, 0.0, 1.0);
  glTranslatef(-0.075, 0.0, 0.0);
  glPushMatrix();
  glScalef(0.15, 0.05, 0.05);
  // glColor3f(0.2, 0.4, 0.8);
  glutWireCube(1);
  glPopMatrix();
  //Draw finger flang 2 
  glTranslatef(-0.075, 0.0, 0.0);
  glRotatef((GLfloat)finger2Up2, 0.0, 0.0, 1.0);
  glTranslatef(-0.075, 0.0, 0.0);
  glPushMatrix();
  glScalef(0.15, 0.05, 0.05);
  glutWireCube(1);
  glPopMatrix();
  glPopMatrix();
  glPushMatrix();
  //Draw finger flang 3 
  glTranslatef(-0.5, 0.1, -0.2);
  glRotatef((GLfloat)finger3Base2, 0.0, 0.0, 1.0);
  glTranslatef(-0.075, 0.0, 0.0);
  glPushMatrix();
  glScalef(0.15, 0.05, 0.05);
  // glColor3f(0.2, 0.4, 0.8);
  glutWireCube(1);
  glPopMatrix();
  //Draw finger flang 3 
  glTranslatef(-0.075, 0.0, 0.0);
  glRotatef((GLfloat)finger3Up2, 0.0, 0.0, 1.0);
  glTranslatef(-0.075, 0.0, 0.0);
  glPushMatrix();
  glScalef(0.15, 0.05, 0.05);
  glutWireCube(1);
  glPopMatrix();
  glPopMatrix();
  glPushMatrix();
  //Draw finger flang 4 
  glTranslatef(-0.5, 0.1, -0.075);
  glRotatef((GLfloat)finger4Base2, 0.0, 0.0, 1.0);
  glTranslatef(-0.075, 0.0, 0.0);
  glPushMatrix();
  glScalef(0.15, 0.05, 0.05);
  // glColor3f(0.2, 0.4, 0.8);
  glutWireCube(1);
  glPopMatrix();
  //Draw finger flang 4 
  glTranslatef(-0.075, 0.0, 0.0);
  glRotatef((GLfloat)finger4Up2, 0.0, 0.0, 1.0);
  glTranslatef(-0.075, 0.0, 0.0);
  glPushMatrix();
  glScalef(0.15, 0.05, 0.05);
  glutWireCube(1);
  glPopMatrix();
  glPopMatrix();
  glPushMatrix();
  //Draw finger flang 5 
  glTranslatef(-0.5, -0.1, 0.125);
  glRotatef((GLfloat)finger5Base2, 0.0, 0.0, 1.0);
  glTranslatef(-0.075, 0.0, 0.0);
  glPushMatrix();
  glScalef(0.15, 0.05, 0.05);
  // glColor3f(0.2, 0.4, 0.8);
  glutWireCube(1);
  glPopMatrix();
  //Draw finger flang 5 
  glTranslatef(-0.075, 0.0, 0.0);
  glRotatef((GLfloat)finger5Up2, 0.0, 0.0, 1.0);
  glTranslatef(-0.075, 0.0, 0.0);
  glPushMatrix();
  glScalef(0.15, 0.05, 0.05);
  glutWireCube(1);
  glPopMatrix();
  glPopMatrix();
  glPopMatrix();




  //LEFT LEG:
  glPushMatrix();

  //LEG
  glTranslatef(0.5, -1.35, 0.0);
  glRotatef((GLfloat) legx, 1.0, 0.0, 0.0);
  glRotatef((GLfloat) legz, 0.0, 0.0, 1.0);
  glTranslatef(0.0, -0.5, 0.0);
  glPushMatrix();
  glScalef(0.5, 1, 0.5);
  glutWireCube(1.0);
  glPopMatrix();

  //KNEE
  glTranslatef(0.0, -0.5, 0.0);
  glRotatef((GLfloat) knee, 1.0, 0.0, 0.0);
  glTranslatef(0.0, -0.5, 0.0);
  glPushMatrix();
  glScalef(0.5, 1.0, 0.5);
  glutWireCube(1.0);
  glPopMatrix();

  //ANKLE
  glTranslatef(0.0, -0.5, 0.0);
  glRotatef((GLfloat) ankle, 1.0, 0.0, 0.0);
  glTranslatef(0.0, -0.1, 0.25);
  glPushMatrix();
  glScalef(0.5, 0.2, 1.0);
  glutWireCube(1.0);
  glPopMatrix();
  glPopMatrix();



  //RIGHT LEG:
  glPushMatrix();

  //LEG
  glTranslatef(-0.5, -1.35, 0.0);
  glRotatef((GLfloat) legx2, 1.0, 0.0, 0.0);
  glRotatef((GLfloat) legz2, 0.0, 0.0, 1.0);
  glTranslatef(0.0, -0.5, 0.0);
  glPushMatrix();
  glScalef(0.5, 1, 0.5);
  glutWireCube(1.0);
  glPopMatrix();

  //KNEE
  glTranslatef(0.0, -0.5, 0.0);
  glRotatef((GLfloat) knee2, 1.0, 0.0, 0.0);
  glTranslatef(0.0, -0.5, 0.0);
  glPushMatrix();
  glScalef(0.5, 1.0, 0.5);
  glutWireCube(1.0);
  glPopMatrix();

  //ANKLE
  glTranslatef(0.0, -0.5, 0.0);
  glRotatef((GLfloat) ankle2, 1.0, 0.0, 0.0);
  glTranslatef(0.0, -0.1, 0.25);
  glPushMatrix();
  glScalef(0.5, 0.2, 1.0);
  glutWireCube(1.0);
  glPopMatrix();
  glPopMatrix();


  //HEAD:
  glPushMatrix();
  glTranslatef(0.0, 1.6, 0.0);
  glutWireSphere(0.35, 16, 16);
  glPopMatrix();

  glPopMatrix();
}