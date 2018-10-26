#include "Layouts.h"

Layouts::Layouts()
{
}

Layouts::~Layouts()
{
}

void Layouts::readLayout(long fileNum, int Width, int Height, int Rectangles, Coordinates X1, Coordinates Y1, Coordinates X2, Coordinates Y2)
{
  vector<Coordinates>VecCoordinates; //vector of coordinates in groups of 4                                                                            

  Coordinates temp; //copies struct Coordinates into temp                                                                                              

  ifstream fin; //input file stream name                                                                                                               

  ofstream fout; //output file stream name                                                                                                             

  string filename; //filename inputed by user                                                                                                          

  cout << "Enter the filename: " << endl;

  cin >> filename;

  fin.open(filename.data());

  while (fin >> fileNum)
    {
      if (fileNum = 13572468)
        {
          fin >> Width;
          fin >> Height;
          fin >> Rectangles;
        }

      else

        cout << "File number not valid." << endl;

      for (int i = 0; i < rectangles; i++)
        {
          fin >> temp.x1;
          VecCoordinates.push_back(x1);
          fin >> temp.y1;
          VecCoordinates.push_back(y1);
          fin >> temp.x2;
          VecCoordinates.push_back(x2);
          fin >> temp.y2;
          VecCoordinates.push_back(y2);

          if (VecCoordinates[i].x1 > height || VecCoordinates[i].y1 > width)

            cout << "Invalid coordinates." << endl;
        }
    }
}