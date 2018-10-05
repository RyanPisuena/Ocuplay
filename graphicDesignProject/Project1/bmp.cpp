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

	hex << std::hex << x;
	_hex = hex.str();

	return _hex;
}

string bmp::_littleEndian(const string& s)
{
	string newS = s;

	reverse(newS.begin(), newS.end());
	return newS;
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
void bmp::width(const int &x)
{/*
	string s = bmp::_littleEndian(bmp::_intToHex(x));
	
	if(s.length() % 2)
		s.append("0");

	cout << s << endl;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; i < 2; j++) {
		
		}
	}
*/
}

void bmp::height(const int &y)
{

}