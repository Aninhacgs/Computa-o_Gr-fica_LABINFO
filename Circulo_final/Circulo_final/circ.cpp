#include <GL/glut.h>
#include <math.h>
#define PI 3.14
#define NUM_PONTOS 100

void AumentaTela(int w, int h)
{
	int largura, altura;
	if(h==0)
		h=1;

	largura = w;
	altura =h;

	glViewport(0,0,largura,altura);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (largura<=altura)
		gluOrtho2D(-1.0,1.0,-1.0*altura/largura, -1.0*altura/largura);
	else
		gluOrtho2D(-1.0*largura/altura,1.0*largura/altura,-1.0,1.0);
}


void circulo()
{
	int i;
	float ang;
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	for (i=0;NUM_PONTOS;i++)
	{
		ang = 2 * PI * i/NUM_PONTOS;
		glVertex2f(cos(ang),sin(ang));
	}
	glEnd();
	glFlush();
}

void init()
{
	glClearColor(1.0,1.0,1.0,1.0);
}
int main()
{
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("Circulo");
	init();
	glutDisplayFunc(circulo);
	glutReshapeFunc(AumentaTela);
	glutMainLoop();
	return(0);
}