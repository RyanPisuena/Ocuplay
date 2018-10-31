/*
LAYOUTS
LAST EDITED: 10/31/2018
CONTRIBUTORS: CRISTIAN C., DOMINQUE M., GABRIEL F.
PURPOSE: FILE IS TO CONTAIN LAYOUTS FOR DRAWING.
*/
#include "Layouts.h"

#include <iostream>
#include <sstream>
#include <fstream>

#include <regex>
#include <random>

#include <Magick++.h>

unsigned const int Layouts::fileNo = 13572468;

// DO NOT TOUCH
// RANDOM!
// https://stackoverflow.com/questions/18726102/what-difference-between-rand-and-random-functions
std::random_device r;
std::seed_seq seed{ r(), r(), r(), r(), r(), r(), r(), r()};
std::mt19937 eng{ seed };
std::uniform_int_distribution<> dist(0, 65535);

// TODO LIST
// Clear/flush function
// Clean up variables
// Do error checking
// Document functions


// Function Parameters:
// Function Description:
Layouts::Layouts()
{
	// Constructor
	Layouts::cellWidth = 125.0;
	Layouts::cellHeight = 125.0;

	Layouts::cellsHorizontal = 0;
	Layouts::cellsVertical = 0;
	
	Layouts::numOfLayouts = 0;
}

// Function Parameters:
// Function Description:
Layouts::~Layouts()
{

}

// Function Parameters:
// Function Description:
void Layouts::readLayout(const std::string &fileName)
{                                                                                                                                                                                                                                                                     
	std::ifstream inputFile(fileName);

	if (!inputFile) 
	{
		// TODO: ERROR MSG
	}
	else
	{
		std::stringstream stream;
		std::string temp;
		// Reads formatted inputfile
		while (getline(inputFile, temp))
			stream << temp << std::endl;

		// Removes comments in file.
		// A valid comment must start on a newline with a '#'.
		// The whole line is then ignored.
		std::regex pattern("(^#)(.+)(\n)");
		stream.str(regex_replace(stream.str(), pattern, ""));

		std::size_t data;
		stream >> std::dec >> data;
		if (data == Layouts::fileNo)
		{
			std::size_t cellsHorizontal;
			std::size_t cellsVertical;
			std::size_t numOfLayouts;

			// Get cellsHorizontal, cellsVertical and numOfLayouts
			stream >> cellsHorizontal >> cellsVertical >> numOfLayouts;
		
			// Store cellsHorizontal, cellsVertical and numOfLayouts to object
			Layouts::cellsHorizontal = cellsHorizontal; 
			Layouts::cellsVertical = cellsVertical; 
			Layouts::numOfLayouts = numOfLayouts;

			std::size_t point_x;
			std::size_t point_y;
			std::size_t _point_x;
			std::size_t _point_y;

			// Store layout position
			while (stream >> point_x >> point_y >> _point_x >> _point_y)
			{
				Coordinates begin;
				Coordinates end;
				
				LayoutCoords pair;

				begin.x = point_x;
				begin.y = point_y;

				end.x = _point_x;
				end.y = _point_y;

				pair.begin = begin;
				pair.end = end;

				// Push Layout position in list
				Layouts::CoordinateList.push_back(pair);
			}

		} 
		else
		{
			// TODO: ERROR MSG
		}
	}

	// Close file after all operations are done.
	inputFile.close();
}

// Function Parameters:
// Function Description:
void Layouts::createLayoutImg(const std::string& fileName) {

	float width = Layouts::cellWidth * Layouts::cellsVertical;
	float height = Layouts::cellHeight * Layouts::cellsHorizontal;

	// Initialize image object with size, and background color of red
	Magick::Image base(Magick::Geometry(MagickCore::Quantum(width), MagickCore::Quantum(height)), Magick::Color("red")),
			mask(Magick::Geometry(MagickCore::Quantum(width), MagickCore::Quantum(height)), 
			Magick::Color(std::size_t(0.0), std::size_t(0.0), std::size_t(0.0), std::size_t(0.0)
			));

	// Create a list of Drawable elements
	Magick::DrawableList elements;

	// Pushes drawables to elements
	for (double i = 0.0; i < height; i += Layouts::cellHeight)
		elements.push_back(Magick::DrawableLine(i, 0.0, i, height));

	for (double i = 0.0; i < width; i += Layouts::cellWidth)
		elements.push_back(Magick::DrawableLine(0.0, i, width, i));

	// Draws elements
	base.draw(elements);

	// Create a list of drawable layouts
	// This will be for the mask.
	// !-- Consider using one Magick::Image object instead of one --!
	Magick::DrawableList layouts;

	for (const LayoutCoords &s : Layouts::CoordinateList) 
	{
		// Randomnizes color layouts
		layouts.push_back(Magick::DrawableFillColor(Magick::Color(MagickCore::Quantum(dist(eng)), MagickCore::Quantum(dist(eng)), 
													MagickCore::Quantum(dist(eng)), MagickCore::Quantum(65535 * 0.7))));

		// Pushes layout to drawable list
		layouts.push_back(Magick::DrawableRectangle((s.begin.x) * (Layouts::cellHeight), 
													(s.begin.y) * (Layouts::cellWidth),
													(s.end.x + 1) * (Layouts::cellHeight),
													(s.end.y + 1) * (Layouts::cellWidth)));
	}
	// Draw layouts
	mask.draw(layouts);

	// Adds alpha mask 
	mask.alpha(true);

	// Draw mask over base
	base.composite(mask, std::size_t(0.0), std::size_t(0.0), Magick::OverCompositeOp);
	
	// Lossless png
	base.compressType(Magick::NoCompression);

	// Save as img0.png
	base.write(fileName);
}