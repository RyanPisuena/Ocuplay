#ifndef _LAYOUTS_H_
#define _LAYOUTS_H_

class Layouts
{
private:

long fileNo; //file's "magic number"

int width;

int height;

int rectangles; //number of rectangles

int x1; //x coordinate 1

int y1; //y coordinate 1

int x2; //x coordinate 2

int y2; //y coordinate 2

public:
	Layouts();
	~Layouts();
	void readLayout(long fileNum, int w, int h, int r, int X1, int Y1, int X2, int Y2);
};

#endif