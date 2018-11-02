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
// ADD SHAPE READ
// Optimize features


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
		{
			stream << temp << std::endl;
		}

		// Removes comments in file.
		// A valid comment must start on a newline with a '#'.
		// The whole line is then ignored.
		std::regex pattern("(^#)(.+)(\n)");
		stream.str(regex_replace(stream.str(), pattern, ""));

		std::size_t data;
		stream >> std::dec >> data;
		if (data == Layouts::fileNo)
		{
			std::size_t _HCELL;
			std::size_t _VCELL;
			std::size_t _NLAY;

			// Get cellsHorizontal, cellsVertical and numOfLayouts
			stream >> _HCELL >> _VCELL >> _NLAY;
		
			// Store cellsHorizontal, cellsVertical and numOfLayouts to object
			Layouts::cellsHorizontal = _HCELL; 
			Layouts::cellsVertical = _VCELL; 
			Layouts::numOfLayouts = _NLAY;

			Layouts::LayoutCoords _COORDS;

			// Store layout position
			for (int i = 0; i < Layouts::numOfLayouts; i++)
			{
				if (stream >> _COORDS.begin.x >> _COORDS.begin.y
						   >> _COORDS.end.x   >> _COORDS.end.y)
				{
					// Push Layout position in list
					Layouts::CoordinateLists.push_back(_COORDS);
				}
				else
				{
					// TODO: ERROR CHECK
				}
			}

			// TODO: ADDED SHAPE READ
			Layouts::Shape _SHAPE;
			for (int i = 0; i < Layouts::numOfLayouts; i++)
			{
				if (stream >> _SHAPE.name >> _SHAPE.flags)
				{
					Layouts::ShapesList.push_back(_SHAPE);
				}
				else
				{

				}
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
	Magick::Image 
		
		base(Magick::Geometry(MagickCore::Quantum(width), MagickCore::Quantum(height)), Magick::Color("red")),
			
		
		mask(Magick::Geometry(MagickCore::Quantum(width), MagickCore::Quantum(height)), 
			Magick::Color(std::size_t(0.0), std::size_t(0.0), std::size_t(0.0), std::size_t(0.0)));

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
	Magick::DrawableList layouts;
	
	for (const LayoutCoords &s : Layouts::CoordinateLists) 
	{
		// Randomnizes color layouts
		layouts.push_back(Magick::DrawableFillColor(Magick::Color(MagickCore::Quantum(dist(eng)), MagickCore::Quantum(dist(eng)), 
													MagickCore::Quantum(dist(eng)), MagickCore::Quantum(65535 * 1.0))));

		// Pushes layout to drawable list
		layouts.push_back(Magick::DrawableRectangle((s.begin.x) * (Layouts::cellHeight), 
													(s.begin.y) * (Layouts::cellWidth),
													(s.end.x + 1) * (Layouts::cellHeight),
													(s.end.y + 1) * (Layouts::cellWidth)));

		layouts.push_back(Magick::DrawableFillColor(Magick::Color(MagickCore::Quantum(dist(eng)), MagickCore::Quantum(dist(eng)),
			MagickCore::Quantum(dist(eng)), MagickCore::Quantum(65535.0 * 1.0) )));

		// Ellipse :-)
		/*
		layouts.push_back(Magick::DrawableEllipse((s.end.x + 1 + s.begin.x) * (Layouts::cellWidth) / 2,
												  (s.end.y + 1 + s.begin.y) * (Layouts::cellHeight)/ 2, 
												  (s.end.x + 1 - s.begin.x) * (0.5) * Layouts::cellWidth, 
												  (s.end.y + 1 - s.begin.y) * (0.5) * Layouts::cellHeight, 
												  0, 360));
												  */
	}
	// Draw layouts
	mask.draw(layouts);

	// Adds alpha mask 
	//mask.alpha(true);

	// Draw mask over base
	base.composite(mask, std::size_t(0.0), std::size_t(0.0), Magick::OverCompositeOp);
	
	// Lossless png
	base.compressType(Magick::NoCompression);

	// Save as img0.png
	base.write(fileName);
}