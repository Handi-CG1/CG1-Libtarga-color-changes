#include "MyWindow.h"
#include <iostream>
#include <Fl/fl_draw.H>
#include "libtarga/libtarga.h"

const char* imageinput;
MyWindow::MyWindow(int width, int height, const char* title, const char* inputfile) :
	Fl_Window(width, height, title)
{
	image = NULL;
	imageinput = inputfile;
}

MyWindow::~MyWindow()
{
	delete image;
}

void MyWindow::draw()
{
	//setup image
	static bool firstTime = true;
	if (firstTime)
	{
		//read image from the external file
		image = TargaImage::readImage(imageinput);
		if (image == NULL)
			std::cerr << "Failed to load image." << std::endl;
		else
		{
			size(image->width(), image->height());
			image->lightenImage();
		}
		firstTime = false;
	}
	if (image != NULL)
		fl_draw_image(image->pixels(), 0, 0, image->width(), image->height(), 4);
}