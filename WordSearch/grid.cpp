// File grid.cpp


/*
Name: grid.cpp
Author: Alex Sylvanus
Project: WordSearch
Class: Fundamentals of Algorithms
*/


// Includes
#include "grid.h"

grid::grid() {
	if (readGridFromFile()) {
		cout << "Created Successfully" << endl;
	}
	else {
		cerr << "Failed to create object" << endl;
	}
}

ostream & operator << (ostream & output, const grid &g) {
	int rows = g.matrix_grid[0].size();
	int columns = g.matrix_grid.size();
	output << endl << rows << "x" << columns << " Word Search" << endl << endl << endl;
	for (int i = 0; i < rows; i++) {
		output << "\t\t";
		for (int j = 0; j < columns; j++) {
			output << g.matrix_grid[i][j] << "  ";
		}
		output << endl;
	}
	return output;
}

bool grid::readGridFromFile() {
	int rows, columns;
	char in;
	ifstream fin;
	string fileName;
	vector<char> temp;
	cout << "Enter the name of the grid file: ";
	cin >> fileName;
	fin.open(fileName.c_str());
	if (!fin) {
		cerr << "Unable to read file" << endl;
		return false;
	}
	else {
		cout << "File opened" << endl;
	}
	fin >> rows;
	fin >> columns;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			fin >> in;
			temp.push_back(in);
		}
		matrix_grid.push_back(temp);
		temp.clear();
	}
	fin.close();
	return true;
}