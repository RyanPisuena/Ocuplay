#ifndef _LAYOUTS_H_
#define _LAYOUTS_H_

#include <vector>
#include <string>

class Layouts
{
public:
	static const unsigned int fileNo;

	Layouts();
	~Layouts();

	void readLayout(const std::string& fileName);

	void createLayoutImg(const std::string& = "img0.png");

protected:
	struct LayoutCoords
	{
		struct Coordinates
		{
			std::size_t x;
			std::size_t y;
		}begin, end;
	};

	struct Shape 
	{
		std::string name;
		int flags;
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

	std::vector<Layouts::LayoutCoords> CoordinateLists;
	std::vector<Layouts::Shape> ShapesList;
};

#endif
