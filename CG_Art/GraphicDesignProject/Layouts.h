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
	// number of horizontal lines
	unsigned int width;

	// number of vertical lines
	unsigned int height;

	// Number of numOfLayouts
	unsigned int numOfLayouts;

	std::list<LayoutCoords> CoordinateList;

public:
	static const unsigned int fileNo;

	Layouts();
	~Layouts();
	
	void readLayout(const std::string& fileName);

	void createLayoutImg(const std::string& = "img0.png");
};

#endif
