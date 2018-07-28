// File grid.h


/*
Name: grid.h
Author: Alex Sylvanus
Project: WordSearch
Class: Fundamentals of Algorithms
*/

#pragma once

// Includes
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

#ifndef GRID_H
#define GRID_H

class grid {
public:
	grid();
	vector<vector<char>> matrix_grid;
	friend ostream & operator << (ostream & output, const grid &g);
	bool readGridFromFile();
};

#endif // GRID_H
