#include <iostream>
#include <Windows.h>
#include "bmp.h"
using namespace std;

int main() {
	bmp bm;

	// ERROR
//	bm.setSize(363, 229);
	
	bm.setSize(363, 229);

//	bm.setSize(200, 500);

	bm.writeToFile();

	// TODO: Add cross-platform support
	ShellExecute(NULL, "open", "mspaint", "test.bmp", "", SW_SHOW);

	return 0;
}