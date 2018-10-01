#include "bmp.h"
#include <iostream>
#include <fstream>

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

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			fout << clr_tlb[i][j].r;
			fout << clr_tlb[i][j].g;
			fout << clr_tlb[i][j].b;
		}
		fout << char(0);
		fout << char(0);
	}

	fout.close();
}


// TODO: Err when hex value < FF
void bmp::dimensions(const int &x, const int &y)
{
	bmih.biWidth[0] = x;
	bmih.biHeight[0] = y;
}

// TODO: Auto Calc size
int bmp::calculate_Size()
{
	bmfh.bfSize[0] = 39;
	bmfh.bfSize[1] = 70;

	return 0;
}

void bmp::print_Val()
{
	for (char a : bmfh.bfType)
		std::cout << int(a) << std::endl;

	for (char a : bmih.biSize)
		std::cout << int(a) << std::endl;
}
