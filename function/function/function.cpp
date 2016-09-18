#include "stdafx.h"
#include "Window.h"
#include <glm/vec2.hpp>
#include <glm/vec4.hpp>
#include <SDL.h>


#ifdef _WIN32
#undef main
#endif


int main()
{
	CWindow window;
	window.ShowFixedSize({ 1200, 600 });
	window.DoGameLoop();

	return 0;
}