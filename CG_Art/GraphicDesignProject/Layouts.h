#ifndef _LAYOUTS_H_
#define _LAYOUTS_H_

#include <list>
#include <string>

struct Coordinates
{
	unsigned long int x;
	unsigned long int y;
};

struct LayoutCoords 
{
	Coordinates begin;
	Coordinates end;
};

class Layouts
{
private:
	// Width of image in pixels
	unsigned int width;

	// Height of image in pixels
	unsigned int height;

	// Number of microLayouts
	unsigned int microLayouts;

	std::list<LayoutCoords> CoordinateList;

public:
	static unsigned int fileNo;

	Layouts();
	~Layouts();
	
	void readLayout(const std::string& fileName);

	void createLayoutImg();
};

#endif
