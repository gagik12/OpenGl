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
	static const glm::vec2 SCALE(0.05f, 0.3f);
	static const glm::vec2 BORDER(-10.f, 10.f);

	glm::vec2 GetCenterWindow(const glm::ivec2 & size)
	{
		return glm::vec2(size.x / 2, size.y / 2);
	}

	void DrawFunction(const glm::ivec2 & center)
	{
		glBegin(GL_LINE_STRIP);
		for (float x = BORDER.x; x <= BORDER.y; x += 0.1)
		{
			float y = std::sin(x) / x;
			glVertex2d(center.x + x*SCALE.x *center.x / 2, center.y - y *SCALE.y * center.y);
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
	glm::vec2 windowCenter = GetCenterWindow(size);
	DrawFunction(windowCenter);
}

void CWindow::SetupView(const glm::ivec2 & size)
{
	const glm::mat4 matrix = glm::ortho<float>(0, float(size.x), float(size.y), 0);
	glViewport(0, 0, size.x, size.y);
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(glm::value_ptr(matrix));
	glMatrixMode(GL_MODELVIEW);
}
