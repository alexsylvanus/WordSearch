// File wordlist.h
// Header file for wordlist class

/*
Name: wordlist.h
Author: Alex Sylvanus
Project: WordSearch
Class: Fundamentals of Algorithms
*/

#pragma once

// Includes
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <time.h>
#include "heap.h"
#include "hashTable.h"

using namespace std;

#ifndef WORDLIST_H
#define WORDLIST_H

// Define constants
#define TOTAL_WORDS 90000

class wordlist {
private:
	vector<string> word_list;
	hashTable<string> table;
 	// heap<string> heap_list;
	void mergeSort_r(vector<string> &A, int p, int r);
	void merge(vector<string> &A, int p, int q, int r);
	bool binary_search_aux(vector<string> A, string w, int left, int right);
	void copyToHash();
public:
	wordlist(); // Class constructor
	friend ostream & operator << (ostream& output, const wordlist& W); // Override print operator
	bool readWordsFromFile(); // Get words
	void insertionSort(); // Sort using insertion algorithm
	void selectionSort(); // Sort using selection algorithm
	void mergeSort(); // Sort using merge algorithm
	bool wordLookupBinary(string w); // Return true if word match: Binary Search algorithm
	bool wordLookupHash(string w);
	void heapsort();
};

#endif // WORDLIST_H