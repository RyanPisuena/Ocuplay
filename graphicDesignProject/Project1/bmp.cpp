#include "bmp.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
using namespace std;

string bmp::_intToHex(const int &x)
{
	stringstream hex;
	string _hex;

	// Using stringstream to convert int -> hex
	hex << std::hex << x;

	// Store stringstream as string
	_hex = hex.str();

	// Appends a zero to the end
	if (_hex.length() % 2)
		_hex.append("0");

	return _hex;
}

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

			fout << char(int(clr_tlb[i][j].r) / ((i % 25) + 1));
			fout << char(int(clr_tlb[i][j].g));
			fout << char(int(clr_tlb[i][j].b));
		}
	}

	fout.close();
}


// TODO: Error check negatives
// TODO: check range [0 -]

// Sets pixel width of BMP image
// Store least significant digits first (Little endian)
void bmp::width(const int &x)
{
	string s = bmp::_intToHex(x);
	string newS;

	int length = s.length() / 2;
	
	for (int i = 0; i < length; i++) {

		newS = "0x";

		for (int j = 0; j < 2; j++) {
			// Appends char from string 's' last char
			newS += s.back();

			// Removes 's' last char
			s.pop_back();
		}
		
		// Converts hex to unsigned long
		bmih.biWidth[i] = stoul(newS, nullptr, 16);
	}
}

// Sets pixel height of BMP image
// Store least significant digits first (Little endian)
void bmp::height(const int &y)
{
	string s = bmp::_intToHex(x);
	string newS;

	int length = s.length() / 2;

	for (int i = 0; i < length; i++) {

		newS = "0x";

		for (int j = 0; j < 2; j++) {
			// Appends char from string 's' last char
			newS += s.back();

			// Removes 's' last char
			s.pop_back();
		}

		bmih.biHeight[i] = stoul(newS, nullptr, 16);
	}
}

void bmp::setSize(const int &x, const int &y)
{
	bmp::width(x);
	bmp::height(y);
}