#include <GL/glut.h>
#include "shortcuts.cpp"


void robot() {
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
}