#ifndef _LAYOUTS_H_
#define _LAYOUTS_H_

#include <list>

struct LayoutCoords {
	struct Coordinates
	{
		int x1;
		int y1;
	}a, b;
};

class Layouts
{
private:
	long fileNo; //file's "magic number"

	int width;

	int height;

	int rectangles; //number of rectangles

	list<LayoutCoords> CoordinateList;

public:
	Layouts();
	~Layouts();
	void readLayout(long fileNum, int Width, int Height, int Rectangles, Coordinates X1, Coordinates Y1, Coordinates X2, Coordinates Y2);

	void createLayoutImg();


};

#endif
