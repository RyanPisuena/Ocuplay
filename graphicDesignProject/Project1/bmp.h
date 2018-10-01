#ifndef _BMP_H_
#define _BMP_H_

class bmp {
private:
	struct BITMAPFILEHEADER{
		char bfType[2]		= {'B','M' };
		char bfSize[4]      = {70,0,0,0};
		
		char bfReserved1[2] = { };
		char bfReserved2[2] = { };
		
		char bfOffBits[4]   = {54,0,0,0};
	}bmfh;

	struct BITMAPINFOHEADER {
		char biSize[4]          = {40,0,0,0};

		char biWidth[4]         = {2,0,0,0};
		char biHeight[4]        = {2,0,0,0};
		
		char biPlanes[2]        = {1, 00};
		char biBitCount[2]      = {24,0};
		
		char biCompression[4]   = { };
		char biSizeImage[4]	    = {16, 0, 0, 0};
		
		char biXPelsPerMeter[4] = { };
		char biYPelsPerMeter[4] = { };
		
		char biClrUsed[4]	    = { };
		char biClrImportant[4]  = { };
	}bmih;
	
	struct COLOR{
		char r = 3;
		char g = 3;
		char b = 3;
	}clr_tlb[2][2];
public:
	
	bmp();

	void writeToFile();

	void dimensions(const int &, const int &);
	int calculate_Size();

	// Defunct
	void print_Val();

};

#endif
