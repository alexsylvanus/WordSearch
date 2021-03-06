// WordSearch.cpp : Defines the entry point for the console application.


/*
Name: WordSearch.cpp
Author: Alex Sylvanus
Project: WordSearch
Class: Fundamentals of Algorithms
*/

/*_______NOTE_______
I included the definitions of the member functions for the heap and hashTable class in their header files becuase
when I separated them into cpp files, the compiler I am using output a link error, and would not run. It has something
to do with them being template functions, but I just wanted to make this clear in case there is an error compiling due to
the functions not being properly implemented.
*/

// Includes
#include "stdafx.h"
#include "wordlist.h"
#include "grid.h"
#include "heap.h"
#include "hashTable.h"

using namespace std;

// Global Functions
void findMatches(wordlist w, grid g);
void search(int n);

int main()
{
	wordlist W;
	grid G;
	cout << G << endl;
	findMatches(W, G);
	int in;
	cout << endl << "Enter any int to exit: ";
	cin >> in;
    return 0;
}

void findMatches(wordlist w, grid g) {
	int length = g.matrix_grid.size();
	int i, j, k;
	
	// variables for storing directional strings
	string curE;
	string curW;
	string curS;
	string curN;
	string curSE;
	string curSW;
	string curNE;
	string curNW;

	vector<string> matched_words;
	vector<string> words; // vector that will store the list of total character combinations

	// Start at all indexes in matrix, and add combinations of characters to possible words array 
	for (i = 0; i < length; i++) {
		for (j = 0; j < length; j++) {
			// Get all combinations of words at each position in word search
			for (k = 0; k < length; k++) {
				// E
				if (j + k >= length) {
					curE.push_back(g.matrix_grid[i][j + k - length]);
				}
				else {
					curE.push_back(g.matrix_grid[i][j+k]);
				}
				// W
				if (k > j) {
					curW.push_back(g.matrix_grid[i][length + j - k]);
				}
				else {
					curW.push_back(g.matrix_grid[i][j - k]);
				}

				// S
				if (i + k >= length) {
					curS.push_back(g.matrix_grid[i + k - length][j]);
					// SE
					if (j + k >= length) {
						curSE.push_back(g.matrix_grid[i + k - length][j + k - length]);
					}
					else {
						curSE.push_back(g.matrix_grid[i + k - length][j + k]);
					}
					// SW
					if (k > j) {
						curSW.push_back(g.matrix_grid[i + k - length][length + j - k]);
					}
					else {
						curSW.push_back(g.matrix_grid[i + k - length][j - k]);
					}
				}
				else {
					curS.push_back(g.matrix_grid[i + k][j]);
					//SE
					if (j + k >= length) {
						curSE.push_back(g.matrix_grid[i + k][j + k - length]);
					}
					else {
						curSE.push_back(g.matrix_grid[i + k][j + k]);
					}
					// SW
					if (k > j) {
						curSW.push_back(g.matrix_grid[i + k][length + j - k]);
					}
					else {
						curSW.push_back(g.matrix_grid[i + k][j - k]);
					}
				}

				// N
				if (k > i) {
					curN.push_back(g.matrix_grid[length + i - k][j]);
					// NE
					if (j + k >= length) {
						curNE.push_back(g.matrix_grid[length + i - k][j + k - length]);
					}
					else {
						curNE.push_back(g.matrix_grid[length + i - k][j + k]);
					}
					// NW
					if (k > j) {
						curNW.push_back(g.matrix_grid[length + i - k][length + j - k]);
					}
					else {
						curNW.push_back(g.matrix_grid[length + i - k][j - k]);
					}
				}
				else {
					curN.push_back(g.matrix_grid[i - k][j]);
					// NE
					if (j + k >= length) {
						curNE.push_back(g.matrix_grid[i - k][j + k - length]);
					}
					else {
						curNE.push_back(g.matrix_grid[i - k][j + k]);
					}
					// NW
					if (k > j) {
						curNW.push_back(g.matrix_grid[i - k][length + j - k]);
					}
					else {
						curNW.push_back(g.matrix_grid[i - k][j - k]);
					}
					

				}
				// When number of characters is greater than 5, start putting words into possible words vector
				if (k>=4) {
					words.push_back(curE);
					words.push_back(curW);
					words.push_back(curS);
					words.push_back(curN);
					words.push_back(curSE);
					words.push_back(curSW);
					words.push_back(curNE);
					words.push_back(curNW);
				}
			}
			// clear strings after each loop
			curE.clear();
			curW.clear();
			curS.clear();
			curN.clear();
			curSE.clear();
			curSW.clear();
			curNE.clear();
			curNW.clear();
			
		}
	}
	cout << "Number of searches: " << (int)words.size() << endl;


	length = words.size();
	clock_t ti = clock();
	for (int h = 0; h < length; h++) {
		// cout << h << "/" << length << " Comparisons"<< endl;
		// cout << "\tTime lapsed:\t" << (float)(clock() - ti) / CLOCKS_PER_SEC << " seconds." << endl;
		if (w.wordLookupHash(words[h])) {
			matched_words.push_back(words[h]);
			cout << "Found Word: " << words[h] << endl;
		}
	}

	if (matched_words.size() == 0) {
		cout << "No words from the list were found" << endl;
	}
	else {
		cout << "Words found: " << endl;
		for (int n = 0; n < (int)matched_words.size(); n++) {
			cout << "\t" << matched_words[n].c_str() << endl;
		}
	}
}

void search(int n) {
	wordlist w;
	grid g;
	clock_t time_start = clock();
	if (n == 0) {
		w.mergeSort();
	}
	else if (n == 1) {
		w.heapsort();
	}
	else if (n == 2){
		w.insertionSort();
	}
	else {
		w.selectionSort();
	}
	cout << "\tTime lapsed:\t" << (float)(clock() - time_start) / CLOCKS_PER_SEC << " seconds." << endl;
	findMatches(w, g);
	cout << "\tTime lapsed:\t" << (float)(clock() - time_start) / CLOCKS_PER_SEC << " seconds." << endl;
}

