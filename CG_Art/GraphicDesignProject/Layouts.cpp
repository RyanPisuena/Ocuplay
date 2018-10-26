#include "Layouts.h"
#include <iostream>
#include <fstream>

using namespace std;

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

    fin.open(filename);


while (fin >> fileNum)
{
    if (fileNum = 13572468)
    {
        fin >> Width;
        fin >> Height;
        fin >> Rectangles;
    }


    fin >> fileNum;

    if (fileNum = 13572468)
    { // if fileNum
    fin >> w;
    fin >> h;
    fin >> r;

    for(int i=0; i < r; i++)
        {
        fin >> X1;
        fin >> Y1;
        fin >> X2;
        fin >> Y2;

        if (X1 > w || Y1 > w || X2 > w || Y2 > w || X1 > h || Y1 > h || X2 > h || Y2 > h)
        cout << "Coordinates are not within range. " << endl;
    }
} // if FileNum

else
cout << "The file is not valid" << endl;

cout << "File number not valid." << endl;

    for (int i = 0; i < rectangles; i++)
    {
        fin >> temp.X1;
        VecCoordinates.push_back(temp.X1);
        fin >> temp.Y1;
        VecCoordinates.push_back(temp.Y1);
        fin >> temp.X2;
        VecCoordinates.push_back(temp.X2);
        fin >> temp.Y2;
        VecCoordinates.push_back(temp.Y2);

        if (VecCoordinates[i] > height || VecCoordinates[i] > width)

        cout << "Invalid coordinates." << endl;
    }
}

}

