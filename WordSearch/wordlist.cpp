// File wordlist.cpp


/*
Name: wordlist.cpp
Author: Alex Sylvanus
Project: WordSearch
Class: Fundamentals of Algorithms
*/


// Includes
#include "wordlist.h"

wordlist::wordlist() {
	cout << "Creating Wordlist . . ." << endl;
	if (readWordsFromFile()) {
		cout << "Wordlist Successfully Created" << endl;
	}
	else {
		cout << "Wordlist Creation Unsuccessful" << endl;
	}
}

ostream & operator << (ostream& output, const wordlist& W) {
	for (int i = 0; i < (int)W.word_list.size(); i++) {
		output << W.word_list[i].c_str() << endl;
	}
	return output;
}

bool wordlist::readWordsFromFile() {
	ifstream fin;
	string s;
	string fileName = "wordlist.txt";
	fin.open(fileName.c_str());
	if (!fin) {
		// error handling
		cerr << "Unable to open file" << endl;
		return false;
	}
	for (int i = 0; i < TOTAL_WORDS; i++) {
		fin >> s;
		if (fin.eof()) {
			break;
		}
		word_list.push_back(s);
	}
	fin.close();
	// heap_list = heap<string>(word_list);

	cout << "Copying words to hash table . . . ";
	copyToHash();
	cout << "Finished." << endl;
	return true;
}

void wordlist::insertionSort() {
	string temp = word_list[0];
	clock_t time_initial = clock();
	int length = (int)word_list.size();
	cout << "Sorting. . ." << endl;
	string* sp = &word_list[0];
	for (int i = 1; i < length; i++) {
		/*if (i % (length / 10) == 0) {
			cout << 100 * i / length << "%\tComplete" << endl;
		}*/
		sp = &word_list[0] + i;
		temp = *sp;
		sp = sp - 1;
		while (sp>=&word_list[0] && temp<*sp) {
			*(sp + 1) = *sp;
			sp--;
		}
		*(sp + 1) = temp;
	}
	cout << "100%\tComplete:\tFinished sorting" << endl;
	cout << "\tTime lapsed:\t" << (float)(clock() - time_initial) / CLOCKS_PER_SEC << " seconds." << endl;
}

void wordlist::selectionSort() {
	string temp = word_list[0];
	clock_t time_initial = clock();
	int length = (int)word_list.size();
	int min = 0;
	cout << "Sorting . . ." << endl;
	for (int i = 0; i < length; i++) {
		if (i % (length / 50) == 0) {
			cout << 100 * i / length << "%\tComplete" << endl;
		}
		temp = word_list[i];
		min = i;
		for (int j = i + 1; j < length; j++) {
			if (word_list[j] < word_list[min]) {
				min = j;
			}
		}
		word_list[i] = word_list[min];
		word_list[min] = temp;
	}
	cout << "100%\tComplete:\tFinished sorting" << endl;
	cout << "\tTime lapsed:\t" << (float)(clock() - time_initial) / CLOCKS_PER_SEC << " seconds." << endl;
}

void wordlist::merge(vector<string> &A, int p, int r, int q) {
	// Create increment variables
	int i, j, k;
	// Create temporary string
	vector<string> temp(r-p+1);
	i = p;
	j = q + 1;
	k = 0;

	// Compare split parts of vector, and merge into beginning of temporary vector
	while (i<=q && j<=r) {
		if (A[i] < A[j]) {
			temp[k] = A[i];
			k++;
			i++;
		}
		else {
			temp[k] = A[j];
			k++;
			j++;
		}
	}

	// Fill up rest of temp vector with unused values from beginning of original vector
	while (i <= q) {
		temp[k] = A[i];
		i++;
		k++;
	}

	// Fill up rest of temp vector with values from end of original vector
	while (j <= r) {
		temp[k] = A[j];
		j++;
		k++;
	}

	// Copy sorted temporary vector into now sorted portion of original vector
	for (i = p; i <= r; i++) {
		A[i] = temp[i - p];
	}
}

void wordlist::mergeSort_r(vector<string> &A, int p, int r) {
	int q;
	int length = (int)word_list.size();
	if (r % (length / 10) == 0) {
		cout << 100 * p / length << "%\tComplete" << endl;
	}
	if (p < r) {
		q = (p + r) / 2;
		mergeSort_r(A, p, q);
		mergeSort_r(A, q + 1, r);
		merge(A, p, r, q);
	}
}

void wordlist::mergeSort() {
	clock_t time_initial = clock();
	cout << "Sorting . . ." << endl;
	mergeSort_r(word_list, 0, word_list.size() - 1);
	cout << "100%\tComplete:\tFinished sorting" << endl;
	cout << "\tTime lapsed:\t" << (float)(clock() - time_initial) / CLOCKS_PER_SEC << " seconds." << endl;

}

void wordlist::copyToHash() {
	int length = word_list.size();
	table = hashTable<string>(length);
	for (int j = 0; j < length; j++) {
		table.addItem(word_list[j]);
	}

}

bool wordlist::binary_search_aux(vector<string> A, string w, int left, int right) {
	int mid;
	if (right < left) {
		return false;
	}
	mid = (left + right) >> 1;
	if (w == A[mid]) {
		return true;
	}
	else if (w < A[mid]) {
		return binary_search_aux(A, w, left, mid - 1);
	}
	else {
		return binary_search_aux(A, w, mid+1, right);
	}
}

bool wordlist::wordLookupBinary(string w) {
	int length = (int)word_list.size();
	bool ret = binary_search_aux(word_list, w, 0, length - 1);
	return ret;
}

bool wordlist::wordLookupHash(string w) {
	return table.inList(w);
}

void wordlist::heapsort() {
	//clock_t time_initial = clock();
	cout << "Sorting . . ." << endl;
	heap<string> H(word_list);
	clock_t time_initial = clock();
	H.heapSort();
	
	cout << "100%\tComplete:\tFinished sorting" << endl;
	cout << "\tTime lapsed:\t" << (float)(clock() - time_initial) / CLOCKS_PER_SEC << " seconds." << endl;

	word_list = H.heap_array;
}
