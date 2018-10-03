#include "bmp.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
bmp::bmp() {

}

void bmp::writeToFile()
{
	std::ofstream fout;
	// TODO: CHECK IF TEST.BMP EXIST
	fout.open("test.bmp");


	// TODO: Seperate function to iterate
	// BITMAPFILEHEADER
	for (const char &c : bmfh.bfType)
		fout << c;

	for (const char &c : bmfh.bfSize)
		fout << c;

	for (const char &c : bmfh.bfReserved1)
		fout << c;

	for (const char &c : bmfh.bfReserved2)
		fout << c;

	for (const char &c : bmfh.bfOffBits)
		fout << c;

	// BITMAPINFOHEADER
	for (const char &c : bmih.biSize)
		fout << c;
	   	  
	for (const char &c : bmih.biWidth)
		fout << c;

	for (const char &c : bmih.biHeight)
		fout << c;

	for (const char &c : bmih.biPlanes)
		fout << c;

	for (const char &c : bmih.biBitCount)
		fout << c;

	for (const char &c : bmih.biCompression)
		fout << c;

	for (const char &c : bmih.biSizeImage)
		fout << c;

	for (const char &c : bmih.biXPelsPerMeter)
		fout << c;

	for (const char &c : bmih.biYPelsPerMeter)
		fout << c;

	for (const char &c : bmih.biClrUsed)
		fout << c;

	for (const char &c : bmih.biClrImportant)
		fout << c;

	for (int i = 0; i < 512; i++) {
		for (int j = 0; j < 512; j++) {

			fout << char(int(clr_tlb[i][j].r)/ ((i % 25)+1));
			fout << char(int(clr_tlb[i][j].g));
			fout << char(int(clr_tlb[i][j].b));
		}
	}

	fout.close();
}

void bmp::readFromFile(string b)
{
	//ifstream fin;
	//fin.open(b);
	
//	string s;

	//fin >> s;

//	cout << s << endl;

}


