/*
#include <iostream> // include in C++ main template
#include <fstream> // include to make use of file stream library

using namespace std; // Reduced need for :: 

int main() {

	ofstream fout; // declaration of outside stream object

	fout.open("test.ppm"); // open file to write too

	if (!fout) { // checks for true or false
		cout << endl << "Cannot open file " << endl; // error message
	}

	else {
		// Integration for source.cpp
		/******************
		fout << "p3" << endl; // file header for ppm
		fout << "255" << endl; // file header for ppm
		for (int i = 0; i < xxx; i++){
				for (int j = 0; j < xxx; j++){
		     fout << r[i][j] << " " << g[i][j] << " " << b[i][j] << " "; // write out pixel allocation 
		}
		    fout << endl;
		}
		 
	}

	fout.close(); // Always close your files
	return 0;



}*/