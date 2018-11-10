#ifndef _LAYOUTS_H_
#define _LAYOUTS_H_

#include <list>
#include <string>

class Layouts
{
public:
	static const unsigned int fileNo;

	Layouts(); // default constructor
	~Layouts(); // default destructor

	void readLayout(const std::string& fileName);

	void createLayoutImg(const std::string& = "img0.png");

private:
	// PixelPixelCache* = get(cellWidth, cellHeight, cellsHorizontal, cellsVertical);
	//Pixel pixelCache;
	//pixelCache.get(cellWidth, cellHeight, cellsHorizontal, cellsVertical);
	struct LayoutCoords
	{
		struct Coordinates
		{
			std::size_t x; // defines x-coordinate
			std::size_t y; // defines y-coordinate
		}begin, end;
	};

	// Cell height
	float cellHeight;

	// Cell width
	float cellWidth;

	// Number of horizontal lines
	std::size_t cellsHorizontal;

	// Number of vertical lines
	std::size_t cellsVertical;

	// Number of numOfLayouts
	std::size_t numOfLayouts;

	std::list<Layouts::LayoutCoords> CoordinateLists; // List data structure storing coordinates

};

#endif
