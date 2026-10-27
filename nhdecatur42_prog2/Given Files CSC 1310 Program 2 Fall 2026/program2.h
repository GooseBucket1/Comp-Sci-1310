/******************************************************************
	To compile: 	g++ -Wall -fopenmp prog2_solution.cpp -o prog2 
	Filename: 		GIVEN: program2.h
	Author: 		April Crockett & Noelle Decatur
	Last Updated:	9/24/2026
	Purpose: 		Practice with sort algorithms and compare time 
					efficiency when running the algorithms 
					sequentially and in parallel

	Note from Noelle: #include errors detected. Please update your includePath. Syntax errors for this file will not be reported until included files are found.
	I am getting this error in the comments that were put in here it is the entirity of line 2
******************************************************************/
#ifndef PROGRAM2_H
#define PROGRAM2_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
bool readFromFile(vector<T>&, string);
template <typename T>
void printVector(vector<T>&);
template <typename T>
void scramble(vector<T>&);

/********************************************************
 * Declare the function prototypes below for each sort
 * function 
 ********************************************************/

template <typename T>
void bubbleSort (vector<T>& v);

template <typename T>
void mergeSort (vector<T>& v, int beg, int end);

template <typename T>
void merge (vector<T>& v, int left, int mid, int right);

template <typename T>
void quickSort (vector<T>& v, int left, int right);

template <typename T>
int partition (vector<T>& v, int left, int right);

template <typename T>
void parallelQuickSort(vector<T>& v, int left, int right);

template <typename T>
void parallelMergSort(vector<T>& v, int left, int right, int depth);

#endif