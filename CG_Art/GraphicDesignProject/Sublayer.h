#ifndef _SUBLAYER_H
#define _SUBLAYER_H

#include<list>
#include<string>

class Sublayer {
private:
  Pixels* pixelCache;
  std::list<Layouts::Shape> ShapesList; // List data structure storing the shapes

public:
  // structure for any shape created
  struct Shape
  {
    std::string name;
    std::size_t flags;
    // std::list<Magick::Coordinate> coordinateList; <-- Experimental, allows for user defined polygons
  };
    Layouts* layoutNumber; // pointer for layout designated for specific sublayer
    Sublayer(); // Constructor
    ~Sublayer(); // Destructor
    Magick::Pixels* Render(); // Returns a pointer to
    void Render(const string& fileName); // Parameter is a file passed by reference
};

#endif _SUBLAYER_H
