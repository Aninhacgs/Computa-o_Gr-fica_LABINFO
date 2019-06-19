#include <gl/glut.h>
#include <stdio.h>

void desenha(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, 0.5);
		glVertex2f(0.5, 0.5);
	glEnd();

	glFlush();
}

void inicializa(){
	glClearColor(0.0, 0.0, 0.0, 1.0);
}

int main(){
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Minha janela");
	glutDisplayFunc(desenha);
	inicializa();
	glutMainLoop();
	return 0;
}