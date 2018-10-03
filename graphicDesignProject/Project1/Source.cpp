#include <iostream>
#include <Windows.h>
#include "bmp.h"
using namespace std;

int main() {
	bmp bm;

	bm.writeToFile();
	ShellExecute(NULL, "open", "mspaint", "test.bmp", "", SW_SHOW);
	bm.readFromFile("hello");
	/*

	const int SIZE = 100;
	int r[SIZE][SIZE], g[SIZE][SIZE], b[SIZE][SIZE];
	//This is the red pixel
	for (int i = 0; i < SIZE; i++) {
		
		for (int j = 0; j < SIZE; j++) {
			r[i][j] = 255;
			g[i][j] = 0;
			b[i][j] = 0;
		}

	}
	//This is the green pixel
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			r[i][j] = 0;
			g[i][j] = 255;
			b[i][j] = 0;
		}

	}
	//This is the blue pixel
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			r[i][j] = 0;
			g[i][j] = 0;
			b[i][j] = 255;
		}

	}
	return 0;
	*/

	return 0;
}