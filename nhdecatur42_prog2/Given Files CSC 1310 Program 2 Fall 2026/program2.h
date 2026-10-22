/******************************************************************
	To compile: 	g++ -Wall -fopenmp prog2_solution.cpp -o prog2
	Filename: 		GIVEN: program2.h
	Author: 		April Crockett & Noelle Decatur
	Last Updated:	9/24/2026
	Purpose: 		Practice with sort algorithms and compare time 
					efficiency when running the algorithms 
					sequentially and in parallel

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

void bubbleSort (int, int);
void MergeSort (int, int, int);
void Merge (int, int, int, int);
void quickSort (int, int, int);
int partition (int, int, int);
void parallelQuickSort(vector<string>&, int, int);
void parallelMergSort(vector<string>&, int, int, int);

#endif