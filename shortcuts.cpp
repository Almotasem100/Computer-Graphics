#include <GL/glut.h>
#include <math.h>

static int head = 0, body = 0,Rshoulder = 0, Relbow = 0, RfingerBase = 0,
RfingerUp = 0, RpointerBase = 0, RpointerUp = 0, RmiddleBase = 0,  RmiddleUp = 0,
RringBase = 0, RringUp = 0, RpinkyBase = 0, RpinkyUp = 0, Lshoulder = 0, Lelbow = 0,
LfingerBase = 0, LfingerUp = 0, LpointerBase = 0, LpointerUp = 0, LmiddleBase = 0,lthigh = 0,rthigh = 0,
LmiddleUp = 0, LringBase = 0, LringUp = 0, LpinkyBase = 0, LpinkyUp = 0, Rthigh = 0, Rleg = 0, Lthigh = 0, Lleg = 0;
double eye[] = { 0, 0, -20 };
double center[] = { 0, 0, 1 };
double up[] = { 0, 1, 0 };
double direction[3];

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