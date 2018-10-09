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

	cout << _hex << endl;

	// Appends a zero to the end
	if (_hex.length() % 2)
		_hex.insert(0, "0");

	cout << _hex << endl;
	reverse(_hex.begin(), _hex.end());

	return _hex;
}

bmp::bmp() {
	p = nullptr;
}

bmp::~bmp() {
	delete[] p;
	p = nullptr;
}

void bmp::writeToFile()
{
	std::ofstream fout;
	// TODO: CHECK IF TEST.BMP EXIST
	fout.open("test.bmp");


	// TODO: Seperate function to iterate
	// BITMAPFILEHEADER
	for (const char &c : _bmfh.bfType)
		fout << c;

	for (const char &c : _bmfh.bfSize)
		fout << c;

	for (const char &c : _bmfh.bfReserved1)
		fout << c;

	for (const char &c : _bmfh.bfReserved2)
		fout << c;

	for (const char &c : _bmfh.bfOffBits)
		fout << c;

	// BITMAPINFOHEADER
	for (const char &c : _bmih.biSize)
		fout << c;
	   	  
	for (const char &c : _bmih.biWidth)
		fout << c;

	for (const char &c : _bmih.biHeight)
		fout << c;

	for (const char &c : _bmih.biPlanes)
		fout << c;

	for (const char &c : _bmih.biBitCount)
		fout << c;

	for (const char &c : _bmih.biCompression)
		fout << c;

	for (const char &c : _bmih.biSizeImage)
		fout << c;

	for (const char &c : _bmih.biXPelsPerMeter)
		fout << c;

	for (const char &c : _bmih.biYPelsPerMeter)
		fout << c;

	for (const char &c : _bmih.biClrUsed)
		fout << c;

	for (const char &c : _bmih.biClrImportant)
		fout << c;

	// THIRD ALGO
	/*
	for (int i = 0; i < _height; i++) {
		
		 for (int j = 0; j < _width; j++) {
			fout << p[(i * _width) + j].r;
			fout << p[(i * _width) + j].g;
			fout << p[(i * _width) + j].b;
		}

		 // Padding
		for (int j = 0; j < ((_width * 3) % 4); j++)
			fout << 0x00;
	}
	*/
		/*
		// SECOND ALGO
		for (int i = 0; i < _height*_width; i++) {
			fout << p[i].r;
			fout << p[i].g;
			fout << p[i].b;
			*/
	
		// FIRST ALGO
	for(int i = 0; i < _height; i++) {
		for(int j = 0; j < _width; j++) {

			fout << char(int(_clr_tlb[i][j].r) / ((i % 25) + 1));
			fout << char(int(_clr_tlb[i][j].g));
			fout << char(int(_clr_tlb[i][j].b));
		}

		for (int j = 0; j < ((_width * 3) % 4); j++) {
			fout << 0x00;
		}
	
	}

	fout.close();
}


// TODO: Input validation

// Sets pixel width of BMP image
// Store least significant digits first (Little endian)
void bmp::width(const int &x)
{
	string s = bmp::_intToHex(x);
	string newS;
	
	_width = x;

	int length = s.length() / 2;
	
	for (int i = length; i > 0; i--) {

		newS = "0x";

		for (int j = 0; j < 2; j++) {
			// Appends char from string 's' last char
			newS += s.back();

			// Removes 's' last char
			s.pop_back();
		}
		cout << newS << endl;
		cout << i-1 << endl;

		// Converts hex to unsigned long
		_bmih.biWidth[i-1] = stoul(newS, nullptr, 16);
	}
}

// Sets pixel height of BMP image
// Store least significant digits first (Little endian)
void bmp::height(const int &y)
{
	string s = bmp::_intToHex(y);
	string newS;

	_height = y;

	int length = s.length() / 2;

	for (int i = length; i > 0; i--) {

		newS = "0x";

		for (int j = 0; j < 2; j++) {
			// Appends char from string 's' last char
			newS += s.back();

			// Removes 's' last char
			s.pop_back();
		}

		// converts hex to unsigned long
		_bmih.biHeight[i-1] = stoul(newS, nullptr, 16);
	}
}

void bmp::setSize(const int &x, const int &y)
{
	// TODO: Redo clr table data structure
	
	/*
	p = new COLOR[x * y];
	
	for (int i = 0; i < (x * y); i++) {
		p[i].r = 30;
		p[i].g = 70;
		p[i].b = 80;
	}
	*/

	bmp::width(x);
	bmp::height(y);
}