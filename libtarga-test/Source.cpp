#include <FL/FL.h>
#include "MyWindow.h"

int main(int argc, char* input[])
{
	MyWindow myWindow(400, 400, "Targa Tutorial", input[1]);
	myWindow.show();
	Fl::run();

	return 0;
}