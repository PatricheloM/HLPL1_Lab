/*
    g++ grid.cpp ../_fltk/GUI.cpp ../_fltk/Window.cpp ../_fltk/Graph.cpp ../_fltk/Simple_window.cpp -o grid `fltk-config --ldflags --use-images` -l fltk
*/

#include "../_fltk/Simple_window.h"
#include "../_fltk/Graph.h"

int main()
{
	Point topleft{100, 100};
	Simple_window window{topleft, 800, 1000, "Grid"};

	Lines grid;

	const int xAxis = 100;
	const int yAxis = 100;

	for (int i = 1; i < 9; ++i)
	{
		grid.add(Point{i*xAxis,0}, Point{i*xAxis, 800});
		grid.add(Point{0,i*yAxis}, Point{800, i*yAxis});
	}

	
	Vector_ref<Rectangle> r;

	for (int i = 0; i < 8; ++i)
	{
		r.push_back(new Rectangle{{i*100, i*100}, 100, 100});
		r[i].set_color(Color::red);
		r[i].set_style(Line_style(Line_style::solid, 4));
		window.attach(r[i]);
	}
	
	Image cat1 {Point{500,100},"cat.jpg"};
	Image cat2 {Point{300,600},"cat.jpg"};
	Image cat3 {Point{0,300},"cat.jpg"};


	window.attach(grid);
	window.attach(cat1);
	window.attach(cat2);
	window.attach(cat3);

	Image cat100 {Point{0,0},"cat100.jpeg"};
	window.attach(cat100);
	window.wait_for_button();

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			cat100.move(100, 0);
			window.wait_for_button();
		}

		cat100.move(-700, 100); //bugos de nem értim mi a rákért
		window.wait_for_button();
	}

	window.wait_for_button();

	return 0;
}