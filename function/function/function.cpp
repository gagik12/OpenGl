#include "stdafx.h"
#include "Window.h"

int main()
{
	CWindow window;
	window.ShowFixedSize({ 1200, 600 });
	window.DoGameLoop();

	return 0;
}