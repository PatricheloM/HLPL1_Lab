/*
    g++ hello_world.cpp ../_fltk/GUI.cpp ../_fltk/Window.cpp ../_fltk/Graph.cpp ../_fltk/Simple_window.cpp -o hello_world `fltk-config --ldflags --use-images` -l fltk
*/

#include "../_fltk/Simple_window.h"
#include "../_fltk/Graph.h"

int main()
{
	Point topleft{100, 100};
	Point origin{10, 300};
	Simple_window window{topleft, 800, 450, "Uszdoda"};

	Axis xa{Axis::x, origin, 250, 10, "x axis"};
	Axis ya{Axis::y, origin, 200, 10, "y axis"};
	ya.set_color(Color::red);
	xa.set_color(Color::red);
	
	Function _sin {sin,0,100,Point{10,150},1000,50,50};
	
	Polygon poly;
	poly.add(Point{350,250});
	poly.add(Point{400,150});
	poly.add(Point{450,250});
	poly.set_style(Line_style::dot);
	poly.set_fill_color(Color::red);

	Rectangle r{Point{350, 250}, 100, 50};
	r.set_color(Color::yellow);

	Closed_polyline poly_hex;
	poly_hex.add(Point{350,390});
	poly_hex.add(Point{450,390});
	poly_hex.add(Point{550,290});
	poly_hex.add(Point{550,190});
	poly_hex.add(Point{450,90});
	poly_hex.add(Point{350,90});
	poly_hex.add(Point{250,190});
	poly_hex.add(Point{250,290});
	poly.set_style(Line_style::dash);


	Text t{Point{50,50},"Bele kellett szarni az uszodaba, hogy megentsuk Gerit"};

	Image Geri {Point{580,30},"adom.jpeg"};

	Circle c{Point{100,200},50};
	c.set_color(Color::dark_red);


	window.attach(xa);
	window.attach(ya);
	window.attach(_sin);
	window.attach(poly);
	window.attach(r);
	window.attach(poly_hex);
	window.attach(t);
	window.attach(Geri);
	window.attach(c);

	window.wait_for_button();
	return 0;
}