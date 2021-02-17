/*
    g++ hello_world.cpp ../_fltk/GUI.cpp ../_fltk/Window.cpp ../_fltk/Graph.cpp ../_fltk/Simple_window.cpp -o hello_world `fltk-config --ldflags --use-images` -l fltk
*/

#include "../_fltk/Simple_window.h"
#include "../_fltk/Graph.h"

int main()
{
	Point topleft{100, 100};
	Simple_window window{topleft, 600, 400, "My window"};
	window.wait_for_button();
	return 0;
}