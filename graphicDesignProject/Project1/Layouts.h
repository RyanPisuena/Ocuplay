#ifndef _LAYOUTS_H_
#define _LAYOUTS_H_

struct Coordinates
{
	int x1;

	int y1;

	int x2;

	int y2;
};

class Layouts
{
private:

long fileNo; //file's "magic number"

int width;

int height;

int rectangles; //number of rectangles

Coordinates x1; //x coordinate 1

Coordinates y1; //y coordinate 1

Coordinates x2; //x coordinate 2

Coordinates y2; //y coordinate 2

public:
	Layouts();
	~Layouts();
	void readLayout(long fileNum, int Width, int Height, int Rectangles, Coordinates X1, Coordinates Y1, Coordinates X2, Coordinates Y2);
};

#endif