#ifndef _BMP_H_
#define _BMP_H_

#include <string>

class bmp {
private:
	struct BITMAPFILEHEADER{
		char bfType[2]		= {'B','M' };
		char bfSize[4]      = {0,0,0,0};
		
		char bfReserved1[2] = { };
		char bfReserved2[2] = { };
		
		char bfOffBits[4]   = {54,0,0,0};
	}bmfh;

	struct BITMAPINFOHEADER {
		char biSize[4]          = {40,0,0,0};

		char biWidth[4]         = {0,char(0x02),0,0};
		char biHeight[4]        = {0,char(0x02),0,0};
		
		char biPlanes[2]        = { };
		char biBitCount[2]      = {24,0};
		
		char biCompression[4]   = { };
		char biSizeImage[4]	    = { };
		
		char biXPelsPerMeter[4] = { };
		char biYPelsPerMeter[4] = { };
		
		char biClrUsed[4]	    = { };
		char biClrImportant[4]  = { };
	}bmih;
	
	struct COLOR{
		char r = 50;
		char g = 200;
		char b = 125;
	}clr_tlb[512][512];
public:
	
	bmp();

	void writeToFile();

	void readFromFile(std::string b);
};

#endif
