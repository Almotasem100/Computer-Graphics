#include <GL/glut.h>
#include <math.h>

static int shoulderlz = -75, shoulderrz = 75, elbow = 0, fingerBase = 0, fingerUp = 0,
            finger2Base = 0, finger2Up, finger3Base , finger3Up, finger4Base, finger4Up,
            finger5Base, finger5Up, shoulderlx, shoulderrx,
            fingerBase2, fingerUp2, finger2Base2, finger2Up2, finger3Base2, finger3Up2,
            finger4Base2, finger4Up2, finger5Base2, finger5Up2,
            body, elbow2, legx, legz, legx2, legz2, knee, knee2, ankle, ankle2, elbowx, elbowx2;
double eye[] = { 0, 0, 10 };
double center[] = { 0, 0, 1 };
double up[] = { 0, 1, 0 };
double normal_ax[] = {1, 0, 0};
double course[] = {0, 0, 0}; 
int limit, limit2;
static float theta = 3*M_PI /180;
float step = 0.1;
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
	// implement camera rotation arround vertical window screen axis to the left
	// used by mouse and left arrow
	if(limit >= -30)
	{
		rotatePoint(up, -theta, eye);
		limit--;
	}
}

void Right()
{
	// implement camera rotation arround vertical window screen axis to the right
	// used by mouse and right arrow
	if(limit <= 30){
		rotatePoint(up, theta, eye);
		limit++;
	}
}

void Up()
{
	// implement camera rotation arround horizontal window screen axis +ve
	// used by up arrow
	if(limit2 <= 27)
	{
		crossProduct(eye , up, normal_ax);
		normalize(normal_ax);
		rotatePoint(normal_ax, theta, eye);
		limit2++;
	}
}

void Down()
{	
	// implement camera rotation arround horizontal window screen axis 
	// used by down arrow
	if(limit2 >= -27)
	{
		crossProduct(up , eye, normal_ax);
		normalize(normal_ax);
		rotatePoint(normal_ax, theta, eye);
		limit2--;
	}
}
void set_direc(double a[], double b[], double c[])
{
	c[0] = a[0] - b[0];
	c[1] = a[1] - b[1];
	c[2] = a[2] - b[2];
}
void moveForward()
{
	set_direc(center, eye, course);
	eye[0] += course[0] * step;
	eye[1] += course[1] * step;
	eye[2] += course[2] * step;

	center[0] += course[0] * step;
	center[1] += course[1] * step;
	center[2] += course[2] * step;
}

void moveBack()
{
	set_direc(center, eye, course);
	eye[0] -= course[0] * step;
	eye[1] -= course[1] * step;
	eye[2] -= course[2] * step;

	center[0] -= course[0] * step;
	center[1] -= course[1] * step;
	center[2] -= course[2] * step;
}
void keyboard(unsigned char key, int x, int y)
{
	// List all youe keyboard keys from assignment two her for body movement
	switch (key)
	{
        case 'x':
        body = (body + 5);
        glutPostRedisplay();
        break;
        case 'X':
        body = (body - 5);
        glutPostRedisplay();
        break;
        case 'A':
        if(shoulderlx > - 10){
        shoulderlx = (shoulderlx - 5);
        shoulderrx = (shoulderrx + 5);
        glutPostRedisplay();}
        break;
        case 'a':
        if(shoulderlx < 110){
        shoulderlx = (shoulderlx + 5);
        shoulderrx = (shoulderrx - 5);
        glutPostRedisplay();}
        break;
        case 's':
        if(shoulderlz > -75){
        shoulderlz = (shoulderlz - 5);
        shoulderrz = (shoulderrz + 5);
        glutPostRedisplay();}
        break;
        case 'S':
        if(shoulderlz < 30){
        shoulderlz = (shoulderlz + 5);
        shoulderrz = (shoulderrz - 5);
        glutPostRedisplay();}
        break;
        case 'e':
        if(elbow < 145){
        elbow = (elbow + 5);
        elbow2 = (elbow2 - 5);
        glutPostRedisplay();}
        break;
        case 'E':
        if(elbow > 0){
        elbow = (elbow - 5);
        elbow2 = (elbow2 + 5);
        glutPostRedisplay();}
        break;
        
        case 'g':
        if(fingerUp >  -90){
        fingerUp = (fingerUp - 5);
        finger2Up = (finger2Up - 5);
        finger3Up = (finger3Up - 5);
        finger4Up = (finger4Up - 5);
        fingerUp2 = (fingerUp2 + 5);
        finger2Up2 = (finger2Up2 + 5);
        finger3Up2 = (finger3Up2 + 5);
        finger4Up2 = (finger4Up2 + 5);
        glutPostRedisplay();}
        if(finger5Up < 90 ){
        finger5Up = (finger5Up + 5);
        finger5Up2 = (finger5Up2 - 5);
        glutPostRedisplay();}
        break;
        case 'G':
        if(fingerUp < 0){
        fingerUp = (fingerUp + 5);
        finger2Up = (finger2Up + 5);
        finger3Up = (finger3Up + 5);
        finger4Up = (finger4Up + 5);
        fingerUp2 = (fingerUp2 - 5);
        finger2Up2 = (finger2Up2 - 5);
        finger3Up2 = (finger3Up2 - 5);
        finger4Up2 = (finger4Up2 - 5);
        glutPostRedisplay();}
        if(finger5Up > 0){
        finger5Up = (finger5Up - 5);
        finger5Up2 = (finger5Up2 + 5);
        glutPostRedisplay();}
        break;
        case 't':
        if(legx < 50){
            legx = (legx + 5);
            glutPostRedisplay();}
            break;
        case 'T':
        if(legx > -90){
            legx = (legx - 5);
        glutPostRedisplay();}
        break;
        case 'y':
        if(legx2 < 50){
            legx2 = (legx2 + 5);
            glutPostRedisplay();}
            break;
        case 'Y':
        if(legx2 > -90){
            legx2 = (legx2 - 5);
        glutPostRedisplay();}
        break;
        case 'u':
        if(legz2 > -75){
        legz2 = (legz2 - 5);
        glutPostRedisplay();}
        break;
        case 'U':
        if(legz2 < 0){
            legz2 = (legz2 + 5) %360;
            glutPostRedisplay();}
        break;
        case 'i':
        if(legz < 75){
        legz = (legz + 5);
        glutPostRedisplay();}
        break;
        case 'I':
        if(legz > 0){
            legz = (legz - 5) %360;
            glutPostRedisplay();}
        break;
        case 'h':
        if(knee < 110){
            knee = (knee + 5 );
            glutPostRedisplay();}
        break;
        case 'H':
        if(knee > 0){
        knee = (knee - 5);
        glutPostRedisplay();}
        break;
        case 'j':
        if(knee2 < 110){
            knee2 = (knee2 + 5 );
            glutPostRedisplay();}
        break;
        case 'J':
        if(knee2 > 0){
        knee2 = (knee2 - 5);
        glutPostRedisplay();}
        break;
        case 'q':
        if(elbowx > -90){
        elbowx = elbowx - 5;
        elbowx2 = elbowx2 - 5;
        glutPostRedisplay();}
        break;
        case 'Q':
        if(elbowx < 0){
        elbowx = elbowx + 5;
        elbowx2 = elbowx2 + 5;
        glutPostRedisplay();}
        break;
        case 'f':
            moveForward();
            glutPostRedisplay();
            break;
        case 'b':
            moveBack();
            glutPostRedisplay();
            break;
        default:
            break;
    }
}