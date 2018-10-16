#include "Layouts.h"

Layouts::Layouts()
{

}

Layouts::~Layouts()
{

}

void Layouts::readLayout(long fileNum, int Width, int Height, int Rectangles, int X1, int Y1, int X2, int Y2)
{
    ifstream fin;

    ofstream fout;

    string filename;

cout << "Enter the filename: " << endl;

cin >> filename;

    fin.open(filename);

    fin >> fileNum;

    if (fileNum = 13572468)
{
    fin >> Width;
    fin >> Height;
    fin >> Rectangles;
}

vector<int>Coordinates; //creates vector called "Coordinates"

    for(int i=0; i < Rectangles; i++)
    {
        fin >> X1;
        fin >> Y1;
        fin >> X2;
        fin >> Y2;

        if (X1 > Width || Y1 > Width || X2 > Width || Y2 > Width || X1 > Height || Y1 > Height || X2 > Height || Y2 > h)

        cout << "Coordinates are not within range. " << endl;
    
    
    
    }
}
else

cout << "The file is not valid"
}
