#include <iostream>
#include <Windows.h>
#include "bmp.h"
using namespace std;

int main() {
	bmp bm;

	bm.setSize(512, 512);

	bm.writeToFile();

	// TODO: Add cross-platform support
	ShellExecute(NULL, "open", "mspaint", "test.bmp", "", SW_SHOW);

	return 0;
}