#include "Layouts.h"

#include <iostream>
#include <sstream>
#include <fstream>

#include <regex>

#include <Magick++.h>
using namespace std;

unsigned int Layouts::fileNo = 13572468;

Layouts::Layouts()
{
	width = 0;
	height = 0;
	
	microLayouts = 0;
}

Layouts::~Layouts()
{

}

// Reads a current saved layout
void Layouts::readLayout(const string &fileName)
{                                                                                                                                                                                                                                                                     
	ifstream inputFile(fileName);

	if (!inputFile) 
	{

	}
	else
	{
		stringstream stream;
		string temp;
		// Reads formatted inputfile
		while (getline(inputFile, temp))
			stream << temp << endl;

		// Removes comments in file.
		// A valid comment must start on a newline with a '#'.
		// The whole line is then ignored.
		regex pattern("(^#)(.+)(\n)");
		stream.str(regex_replace(stream.str(), pattern, ""));

		unsigned int data;
		stream >> std::dec >> data;
		if (data == Layouts::fileNo)
		{
			unsigned int width;
			unsigned int height;
			unsigned int microLayouts;

			// Get width, height and microLayouts
			stream >> width >> height >> microLayouts;
		
			// Store width, height and microLayouts to object
			Layouts::width = width; 
			Layouts::height = height; 
			Layouts::microLayouts = microLayouts;

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
				cout << Layouts::CoordinateList.size() << endl;
			}

		}
	}

	// Close file after all operations are done.
	inputFile.close();
}

// Creates a visual layout
void Layouts::createLayoutImg() {

	// !--PLACE HOLDER--!
	// Will change soon
	double px = 1000.0;
	Magick::Color clr1(0.0, 0.0, 65535.0, 65535.0 * 0.5);
	Magick::Color clr(0, 0, 65535);

	// Initialize image object with size px, and background color of red
	Magick::Image base(Magick::Geometry(px, px), Magick::Color("red")),
		mask(Magick::Geometry(500.0, 500.0), clr1);

	// Draws the microLayouts
	for (double i = 0.0; i < px; i += (px / Layouts::width))
		base.draw(Magick::DrawableLine(i, 0.0, i, px));


	for (double i = 0.0; i < px; i += (px /Layouts::height))
		base.draw(Magick::DrawableLine(0.0, i, px, i));

	// Adds alpha mask 
	mask.alpha(true);

	// Draw mask over base
	base.composite(mask, 0.0, 0.0, Magick::OverCompositeOp);

	// Save as img0.png
	base.write("img0.png");
}