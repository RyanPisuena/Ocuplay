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
std::uniform_int_distribution<> dist(0, 65535.);

// TODO LIST
// Clear/flush function
// Clean up variables

Layouts::Layouts()
{
	width = 0;
	height = 0;
	
	numOfLayouts = 0;
}

Layouts::~Layouts()
{

}

// Reads a current saved layout
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

		unsigned int data;
		stream >> std::dec >> data;
		if (data == Layouts::fileNo)
		{
			unsigned int width;
			unsigned int height;
			unsigned int numOfLayouts;

			// Get width, height and numOfLayouts
			stream >> width >> height >> numOfLayouts;
		
			// Store width, height and numOfLayouts to object
			Layouts::width = width; 
			Layouts::height = height; 
			Layouts::numOfLayouts = numOfLayouts;

			unsigned int point_x;
			unsigned int point_y;
			unsigned int _point_x;
			unsigned int _point_y;

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

// Creates a visual layout
void Layouts::createLayoutImg(const std::string& s) {

	// !--PLACE HOLDER--!
	// Will change soon
	double px = 1000.0;

	// Initialize image object with size px, and background color of red
	Magick::Image base(Magick::Geometry(px, px), Magick::Color("red")),
		mask(Magick::Geometry(px, px), Magick::Color(0.0,0.0,0.0,0.0));

	// Create a list of Drawable elements
	Magick::DrawableList elements;

	// Pushes drawables to elements
	for (double i = 0.0; i < px; i += (px / Layouts::width))
		elements.push_back(Magick::DrawableLine(i, 0.0, i, px));

	for (double i = 0.0; i < px; i += (px /Layouts::height))
		elements.push_back(Magick::DrawableLine(0.0, i, px, i));

	// Draws elements
	base.draw(elements);

	// Create a list of drawable layouts
	// This will be for the mask.
	// !-- Consider using one Magick::Image object instead of one --!
	Magick::DrawableList layouts;

	for (const LayoutCoords &s : Layouts::CoordinateList) 
	{
		// Randomnizes color layouts
		layouts.push_back(Magick::DrawableFillColor(Magick::Color(dist(eng), dist(eng), dist(eng), 65535 * 0.7)));

		// Pushes layout to drawable list
		layouts.push_back(Magick::DrawableRectangle((s.begin.x) * (px / Layouts::width), 
													(s.begin.y) * (px / Layouts::height),
													(s.end.x + 1) * (px / Layouts::width),
													(s.end.y + 1) * (px / Layouts::height)));
	}
	// Draw layouts
	mask.draw(layouts);

	// Adds alpha mask 
	mask.alpha(true);

	// Draw mask over base
	base.composite(mask, 0.0, 0.0, Magick::OverCompositeOp);
	
	// Lossless png
	base.compressType(Magick::NoCompression);

	// Save as img0.png
	base.write(s);
}