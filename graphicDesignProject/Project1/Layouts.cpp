#include "Layouts.h"

Layouts::Layouts()
{

}

Layouts::~Layouts()
{

}

void Layouts::readLayout(long fileNum, int w, int h, int r, int X1, int Y1, int X2, int Y2)
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
    fin >> w;
    fin >> h;
    fin >> r;

    for(int i=0; i < r, i++)
    {
        fin >> X1;
        fin >> Y1;
        fin >> X2;
        fin >> Y2;

        if (X1 > w || Y1 > w || X2 > w || Y2 > w || X1 > h || Y1 > h || X2 > h || Y2 > h)

        cout << "Coordinates are not within range. " << endl;
    }
}
else

cout << "The file is not valid"
}
