/******************************************************************
	To compile: 	g++ -Wall -fopenmp prog2_solution.cpp -o prog2
	Filename: 		program2.cpp
	Author: 		Eddie Gannod & April Crockett & Noelle Decatur
	Last Updated:	9/24/2026
	Purpose: 		Practice with sort algorithms and compare time 
					efficiency when running the algorithms 
					sequentially and in parallel

******************************************************************/
#include <iostream>
#include <vector>				// used to create and use vectors
#include <fstream>
/*
The # include <parallel/algorithm> has been throwing this error
#include errors detected. Please update your includePath. Syntax errors for this file will not be reported until included files are found.
I am not sure why I have uninstalled and reinstalled the mingw64 however I still am having problems

*/
#include <parallel/algorithm> 	// used for sort function
#include <omp.h>              	// used for OpenMP directives
#include <ctime>             	// used for seeding randome number generator
#include <thread>				//used for calculating number of logical processors on computer
#include <cstdlib>           	// used for random number generation
#include <chrono>				//used for measuring elapsed time
#include "program2.h"

using namespace std;

int main() 
{
	//create two vectors	
    vector<int> nums;       	
    vector<string> words;  		
	string filename;
	bool success;
    
	//determine number of logical processors on your computer
	const auto processor_count = thread::hardware_concurrency();
	
    //Number of threads OpenMP will use. 
    int num_threads;
	
	//ask the user for the number of threads
	cout << "\nHow many threads do you want OpenMP to use? (Enter 1-500) ";
	cin >> num_threads;
	
	//*********************LOOK!************************************************
	//add in the code to validate the user's input
	//make sure the user entered in an integer 1 through 500 (and that they actually entered in an integer)
	
	while(!cin || (num_threads < 1 || num_threads > 500)){
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\nOops! You need to add a valid Number (1-500): ";
		cin >> num_threads;
	}
	cin.ignore(100, '\n');


	omp_set_dynamic(false);
    omp_set_num_threads(num_threads);
	cout << "\nNumber of Threads Used: " << num_threads << endl;
	cout << "Number of Processors: " << processor_count << endl;
	
	//read from files & place in vectors
	do {
		cout << "\nWhat is the name of the string (word) text file?\n(wordsSmall.txt or wordsLarge.txt)\nFILENAME: ";
		cin >> filename;
		success = readFromFile(words, filename);	
	} while(!success);
	do {
		cout << "\nWhat is the name of the string (word) text file?\n(numsSmall.txt or numsLarge.txt)\nFILENAME: ";
		cin >> filename;
		success = readFromFile(nums, filename);
	} while(!success);
	cout << "SIZE of words: " << words.size() << endl;
	cout << "SIZE of nums: " << nums.size() << endl;
	
	//prior to calling any of the sort algorithms, you need to scramble (unsort) the vectors
	scramble(nums);
    scramble(words);
	
	/*************************************************************************Parallel Sort in Algorithm Library*****************************
	
	 * For more information about this algorithm in particular, take a look at 
	 * https://www.geeksforgeeks.org/internal-details-of-stdsort-in-c/
	 * It uses the IntroSort algorithm, which is a hybrid between Quicksort, Heapsort,
	 * and Insertion Sort.
     *********************************************************************************/
	//****************************Parallel Sort in Algorithm Library*****************************/
    auto start = chrono::high_resolution_clock::now();
    __gnu_parallel::sort(nums.begin(), nums.end());
    auto end = chrono::high_resolution_clock::now();
    cout << "\n<parallel/algorithm> library sort(int): " 
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;

    start = chrono::high_resolution_clock::now();
    __gnu_parallel::sort(words.begin(), words.end());
    end = chrono::high_resolution_clock::now();
    cout << "<parallel/algorithm> library sort(words): " 
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;


    /*********************************************************************************
		BUBBLE SORT
		
		First, scramble the two vectors (call the scramble function)
		
		Start the clock
		Call the bubbleSort function here for nums vector
		Stop the clock
		Compute the runtime (see example above)
		Print out result to screen
		
		Start the clock
		Call the bubbleSort function for the words vector
		Stop the clock
		Compute the runtime
		Print out result to screen.
		
     *********************************************************************************/
	scramble(nums);
	scramble(words);
	
	start = chrono::high_resolution_clock::now();
   	bubbleSort(nums);
    end = chrono::high_resolution_clock::now();
    cout << "\nBubble sort (int): " 
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;

    start = chrono::high_resolution_clock::now();
    bubbleSort(words);
    end = chrono::high_resolution_clock::now();
    cout << "Bubble sort (words): " 
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;

    /*********************************************************************************
		MERGE SORT
		
		do all the same stuff described in bubble sort except call the 
		mergeSort function
     *********************************************************************************/
	scramble(nums);
	scramble(words);
	
	start = chrono::high_resolution_clock::now();
   	mergeSort(nums, 0, nums.size() - 1);
    end = chrono::high_resolution_clock::now();
    cout << "\nMerge sort (int): " 
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;

    start = chrono::high_resolution_clock::now();
    mergeSort(words, 0, words.size() - 1);
    end = chrono::high_resolution_clock::now();
    cout << "Merge sort (words): " 
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;

    /*********************************************************************************
		PARALLEL MERGE SORT
		
		do all the same stuff described in bubble sort except call the 
		parallelMergeSort function
     *********************************************************************************/
	scramble(nums);
	scramble(words);
	
	start = chrono::high_resolution_clock::now();
   	parallelMergSort(nums, 0, nums.size() - 1, 0);
    end = chrono::high_resolution_clock::now();
    cout << "\nParallel merge sort (int): " 
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;

    start = chrono::high_resolution_clock::now();
    parallelMergSort(words, 0, words.size() - 1, 0);
    end = chrono::high_resolution_clock::now();
    cout << "Parallel merge sort (words): " 
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;

    /*********************************************************************************
		QUICK SORT
		
		do all the same stuff described in bubble sort except call the 
		quicksort function
     *********************************************************************************/
	scramble(nums);
	scramble(words);
	
	start = chrono::high_resolution_clock::now();
   	quickSort(nums, 0, nums.size() - 1);
    end = chrono::high_resolution_clock::now();
    cout << "\nQuick sort(int): " 
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;

    start = chrono::high_resolution_clock::now();
    quickSort(words, 0, words.size() - 1);
    end = chrono::high_resolution_clock::now();
    cout << "Quick sort(words): " 
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;

    /*********************************************************************************
		PARALLEL QUICK SORT
		
		do all the same stuff described in bubble sort except call the 
		parallelQuickSort function
     *********************************************************************************/
	scramble(nums);
	scramble(words);
	
	start = chrono::high_resolution_clock::now();
   	parallelQuickSort(nums, 0, nums.size() - 1);
    end = chrono::high_resolution_clock::now();
    cout << "\nParrallel Quick Sort (int): " 
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;

    start = chrono::high_resolution_clock::now();
    parallelQuickSort(words, 0, words.size() - 1);
    end = chrono::high_resolution_clock::now();
    cout << "Parrallel Quick Sort (words): " 
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;
    return 0; 
}


/*********************************************************
 * HELPER FUNCTIONS
 * These functions help read in the data from the files
 * scramble the data, and print the data to the console.
 * You should not have to touch these.
 **********************************************************/

/*
	Function: readFromFile()
	Purpose: 
		readFromFile reads values from a file into a vector<T>. 
		It returns true if the file was successfully opened and 
		read, and false otherwise.
*/
template <typename T>
bool readFromFile(vector<T>& v, string filename)
{
    ifstream file;
    T tmp;
	
    file.open(filename);
	if(file.is_open())
	{
		//place file contents into vector
		while(file >> tmp)
		{
			v.push_back(tmp);
		}
		file.close();
		return true;
	}
	return false;
}

/*
	Function: printVector()
	Purpose: 
		printVector prints each element of the vector to the screen
*/
template <typename T>
void printVector(vector<T>& v)
{
    for (int i = 0; i < 20; i++)
    {
        cout << v[i] << endl;
    }
}

/*
	Function: scramble()
	Purpose: 
		scramble will randomly scramble the vector contents to
		make the vector unsorted
*/
template <typename T>
void scramble(vector<T>& v)
{
    srand(time(0));
    int randomIndex;
    for (unsigned int i = 0; i < v.size(); i++)
    {
        randomIndex = rand() % v.size();
        swap(v[i], v[randomIndex]);
    }
}

/*************************************************
 * SORTING FUNCTIONS
 * These functions implement the sorting algorithms
 *************************************************/

// Implement all the sort algorithms below that were described in the assignment

/*
Bubble Sort: compares each pair to the next item and swaps if its in the incorect order
*/
template <typename T>
void bubbleSort(vector<T>& v){
		T tempForSwap;
		for(int i = 0; i < v.size() - 1; i++){
			for(int j = 0; j < v.size() - i - 1; j++){
				if(v[j] > v[j + 1]){
					tempForSwap = v[j];
					v[j] = v[j + 1];
					v[j + 1] = tempForSwap;
				}
			}
		}
	}

	/*
	Merg Sort: divides into 2 lists and then sorts through them and merges them back
	*/
template <typename T>
void mergeSort(vector<T>& v, int beg, int end){
	int mid = 0;

	if (beg < end){
		mid = (beg + end) / 2;

		mergeSort(v, beg, mid);
		mergeSort(v, mid + 1, end);
		merge(v, beg, mid, end);
	}
}



/*
Partition: divides and conquers for quicksort
*/
template <typename T>
int partition(vector<T>& v, int left, int right) {
   T pivot = v[left]; 
   left--;
   right++;
   while(left < right){
	   do{
		   right--;
	   }while(v[right] > pivot);
	   
	   do{
		   left++;
	   }while(v[left] < pivot);
	  
	   if(left < right)
		swap(v[left], v[right]);
   }
   return right;
} 


/*
quick sort: divides and conquers 
*/
template <typename T>
void quickSort(vector<T>& v, int left, int right) {
	int split = 0;
	if (left >= right) {
		return;
	}

	split = partition(v, left, right);
	quickSort(v, left, split); 
	quickSort(v, split + 1, right);
}
/*
Parallel quick sort: will pivot and sort at the same time
*/
template <typename T>
void parallelQuickSort(vector<T>& v, int left, int right)
{
    if (left < right)
    {
       int pivot = partition(v, left, right);
        
		#pragma omp task shared(v) if(right-left > 10000)
		parallelQuickSort(v, left, pivot - 1);
        
        #pragma omp task shared(v) if(right-left > 10000)
		parallelQuickSort(v, pivot + 1, right);

        #pragma omp taskwait
    }
}
	
	
/*
Parallel Merge Sort: divides the list and then sorts through it at the same time
*/
template <typename T>
void parallelMergSort(vector<T>& v, int left, int right, int depth)
{
	if (left < right){
		int mid = left + (right - left) / 2;
			if (depth < 4){
				#pragma omp parallel sections
				{ 
			// never put curly brases on these only on the omp parallel sections and not on the same line
					#pragma omp section
						parallelMergSort(v, left, mid, depth + 1);

					#pragma omp section
						parallelMergSort(v, mid + 1, right, depth + 1);	
				}
			}else{
				parallelMergSort(v, left, mid, depth + 1);
				parallelMergSort(v, mid + 1, right, depth + 1);
		}
	merge(v, left, mid, right);
	}
}

	/*
	Merge function: used for merg sort and parallel merge sort
	*/
template <typename T>
void merge(vector<T>& v, int left, int mid, int right) {
	int n1 = mid - left + 1; 
    int n2 = right - mid;    

    vector<T> leftV(n1);
	vector<T> rightV(n2);

    for (unsigned int i = 0; i < leftV.size(); ++i)
        leftV[i] = v[left + i];
    for (unsigned int j = 0; j < rightV.size(); ++j)
        rightV[j] = v[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftV[i] <= rightV[j])
            v[k++] = leftV[i++];
        else
            v[k++] = rightV[j++];
    }


    while (i < n1) 
		v[k++] = leftV[i++];
    while (j < n2) 
		v[k++] = rightV[j++];

}