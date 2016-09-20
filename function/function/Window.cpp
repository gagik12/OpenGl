#include "stdafx.h"
#include "Window.h"

namespace
{
	

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
