#include "stdafx.h"

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