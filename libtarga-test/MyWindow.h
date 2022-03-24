#ifndef MY_WINDOW_H
#define MY_WINDOW_H


#include <FL/FL_Window.h>
#include <libtarga/TargaImage.h>
class MyWindow : public Fl_Window
{
	public: MyWindow(int width, int height, const char* title, const char* inputfile);
	virtual ~MyWindow();
	virtual void draw();

	TargaImage* image;
};
#endif