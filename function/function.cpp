#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
GLint Width = 512, Height = 512; //��������� ������� ����

								 //������� ��������� �� ������
void Display()
{

	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);


	glColor3d(0, 0, 0);

	glBegin(GL_LINES);
	glVertex2d(0, 0);
	glVertex2d(10, 0);
	glVertex2d(0, -1.5);
	glVertex2d(0, 1.5);
	glEnd();

	glColor3d(0, 0, 1);
	glBegin(GL_LINE_STRIP);
	for (double i = 0; i < 10; i += 0.1)
		glVertex2d(i, sin(i));
	glEnd();

	glFinish();
}

//������� ���������� ��� ��������� �������� ����
void Reshape(GLint w, GLint h)
{
	Width = w;
	Height = h;

	// ������������� ������� ������� �����������
	glViewport(0, 0, w, h);

	// ��������������� ��������
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2, 12, -2, 2, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// ������� ��������� ��������� � ����������
void Keyboard(unsigned char key, int x, int y)
{
#define ESCAPE '\033'
	if (key == ESCAPE)
		exit(0);
}

// ������� ���� ����������
void main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(Width, Height);
	glutCreateWindow("Sin(x)");

	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);

	glutMainLoop();
}