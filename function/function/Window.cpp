#include "stdafx.h"
#include <glm/vec2.hpp>
#include <glm/vec4.hpp>
#include <GL/glew.h>
#include <GL/gl.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <SDL.h>
#include "Window.h"
#include <iostream>

namespace
{

	void DrawFunction(const glm::ivec2 & size)
	{

		glBegin(GL_LINE_STRIP);
		for (float x = 0; x <= 10; x += 0.1)
		{
			float y = std::sin(x) / x;
			
				std::cout << y << std::endl;
			
			glVertex2d(x * 100.f + size.x/2, -y *100.f + size.y / 2);
		}
		glEnd();
	}

	void DrawCoordinateSystem(const glm::ivec2 & size)
	{
		glBegin(GL_LINES);

		    glVertex2f(0.0f, size.y / 2.f);
	        glVertex2f(size.x, size.y / 2.f);

		    glVertex2f(size.x / 2.f, 0.0f);
		    glVertex2f(size.x / 2.f, size.y);
		glEnd();
	}

}
CWindow::CWindow()
{
}


CWindow::~CWindow()
{
}

void CWindow::OnWindowEvent(const SDL_Event &event)
{

}

void CWindow::OnUpdateWindow(float deltaSeconds)
{
	(void)deltaSeconds;
}

void CWindow::OnDrawWindow(const glm::ivec2 & size)
{
	//CAbstractWindow::SetBackgroundColor(glm::vec4(1.0, 1.0, 1.0, 1.0));
	SetupView(size);
	glColor3f(1, 0, 0);
	DrawCoordinateSystem(size);
	glColor3f(1, 0, 0);
	DrawFunction(size);
}

void CWindow::SetupView(const glm::ivec2 & size)
{
	const glm::mat4 matrix = glm::ortho<float>(0, float(size.x), float(size.y), 0);
	glViewport(0, 0, size.x, size.y);
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(glm::value_ptr(matrix));
	glMatrixMode(GL_MODELVIEW);
}