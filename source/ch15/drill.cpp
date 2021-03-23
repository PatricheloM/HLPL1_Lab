/*
    g++ drill.cpp ../_fltk/GUI.cpp ../_fltk/Window.cpp ../_fltk/Graph.cpp ../_fltk/Simple_window.cpp -o drill `fltk-config --ldflags --use-images` -l fltk
*/


#include "../_fltk/Simple_window.h"
#include "../_fltk/Graph.h"

double one(double x) {return 1;}
double slope(double x) { return x/2;}
double square(double x) { return x*x;} 
double sloping_cos(double x) { return slope(x)+cos(x);} 


int main()
{
	Point topleft{100, 100};
	Point origin{300, 300};
	Point startX{100, 300};
	Point startY{300, 500};
	Simple_window window{topleft, 600, 600, "Function graphs"};

	Axis xa{Axis::x, startX, 400, 20, "x axis"};
	Axis ya{Axis::y, startY, 400, 20, "y axis"};
	ya.set_color(Color::red);
	xa.set_color(Color::red);

	//Function first {one, -10, 11, origin, 400};
	Function constant {one, -10, 11, origin, 400, 20, 20};

	Function linear {slope, -10, 11, origin, 400, 20, 20};
	Text t {Point{100, 390}, "x/2"};

	Function squarefct {square, -10, 11, origin, 400, 20, 20};

	Function cosine {[] (double x) { return cos(x);}, -10, 11, origin, 400, 20, 20};
	cosine.set_color(Color::blue);

	Function complex {sloping_cos, -10, 11, origin, 400, 20, 20};

	window.attach(complex);
	window.attach(cosine);
	window.attach(squarefct);
	window.attach(t);
	window.attach(linear);
	window.attach(constant);
	window.attach(ya);
	window.attach(xa);
	window.wait_for_button();

	return 0;
}