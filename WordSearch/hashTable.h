// File hashTable.h


/*
Name: hashTable.h
Author: Alex Sylvanus
Project: WordSearch
Class: Fundamentals of Algorithms
*/

#pragma once

// Includes
#include <iostream>
#include <vector>
#include <string>
#include <functional>

using namespace std;

#ifndef HASHTABLE_H
#define HASHTABLE_H

// Class Definition
template <typename T> class hashTable {
private:
	int hash_size;
	vector<vector<T>> hash_table;
public:
	hashTable();
	hashTable(int s);
	void addItem(T &item);
	void deleteItem(T &item);
	bool inList(T &item);
	int Hash(T &item);
};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MEMBER FUNCTION DEFINITIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

// Default Hash Table constructor
template <typename T> hashTable<T>::hashTable() {
	// Initialize table size to 1
	hashTable(1);
}

// Custon size Hash Table Constructor
template <typename T> hashTable<T>::hashTable(int s) {
	hash_size = s;
	hash_table.resize(hash_size);
}

template <typename T> void hashTable<T>::addItem(T &item) {
	int bucket = Hash(item); // Add item at bucket returned by hash function
	hash_table[bucket].push_back(item);
}

// Delete Item from hash Table
template <typename T> void hashTable<T>::deleteItem(T &item) {
	int bucket;
	int bucket_size;
	int k = 0;
	// Check if item is in list
	if (inList(item)) {
		bucket = Hash(item); // get index of item
		bucket_size = hash_table[bucket].size();
		while (hash_table[bucket][k] != item) {
			k++;
		}
		hash_table[bucket].erase(k); // remove item
	}
	else {
		cerr << "Item not contained in table." << endl;
	}
}

// Check if item is contained in the hash table
template <typename T>
bool hashTable<T>::inList(T &item) {
	bool ret = false;
	int bucket = Hash(item); // get bucket from hash function
	int bucket_size = hash_table[bucket].size();
	if (bucket_size != 0) {
		for (int j = 0; j < bucket_size; j++) { // loop through vector contained in bucket
			if (item == hash_table[bucket][j]) {
				ret = true; // set return as true if match found
			}
		}
	}
	return ret;
}

template <typename T>
int hashTable<T>::Hash(T &item)
// Return the hashed value for item, using the built in hash function.
// Map to a value in the right
// range for the table.
{
	hash<T> h;
	return h(item) % hash_size;
}


#endif // HASH_H