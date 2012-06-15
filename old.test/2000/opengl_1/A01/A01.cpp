#include <windows.h>
#include <GL/gl.h>
#include <GL/glaux.h>
#include <stdio.h>

//
void myinit();
void CALLBACK myReshape(GLsizei width, GLsizei height);
void CALLBACK display();

void myinit() {
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
}

//
void CALLBACK myReshape(GLsizei width, GLsizei height) {
	glViewport(0, 0, 300, 300);
}

//
void CALLBACK display() {
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
		glVertex2f(-.9, -.9);
		glVertex2f(-.9, .9);
		glVertex2f(.9, .9);
		glVertex2f(.9, -.9);
	glEnd();
	glColor3f(0.6f, 0.8f, 0.0f);
	auxWireTeapot(.28);
	glFlush();
}

//
//void main(int argc, char **argv) {
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	auxInitDisplayMode(AUX_SINGLE | AUX_RGBA);
	auxInitPosition(0, 0, 300, 300);
	auxInitWindow("Hello");
	myinit();
	auxReshapeFunc(myReshape);
	auxMainLoop(display);

	return 0;
}