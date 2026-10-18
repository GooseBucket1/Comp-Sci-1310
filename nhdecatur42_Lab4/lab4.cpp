/*
    File name:lab4.cpp
    nhdecatur42
    Noelle Decatur
*/
#include "lab4.h"

int main() {
    string* movies;
    int numMovies = 0;
    int maxMovies = 20;
	int choice;

    // initial allocation - array of 20 strings
    movies = new string[maxMovies];

    // read the file
    readFromFile(movies, maxMovies, numMovies);

    if (numMovies == 0) {
        cout << "No movies loaded. Exiting.\n";
        delete[] movies;
        return 1;
    }

	// Execute menu and user's choice until they choose to quit
    do{
        cout << "\n================ MENU ================\n";
        cout << "1) Print movies\n";
        cout << "2) Bubble sort (A->Z)\n";
        cout << "3) Selection sort (A->Z)\n";
        cout << "4) Insertion sort (A->Z)\n";
        cout << "5) Scramble array (randomize order)\n";
        cout << "6) Quit\n";
        cout << "Choose an option (1-6): ";
        cin >> choice;
        while (!cin || choice < 1 || choice > 6) {
            if(!cin)
                cout << "You didn't enter a number. Please try again: ";
            else
                cout << "Invalid choice. Please enter a number between 1 and 6: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> choice;
        }
        cout << endl;

        if(choice == 1){// Print
            printArray(movies, numMovies);
        }

        else if(choice == 2){ // Bubble sort with timing
            cout << "I am going to bubble sort the array of " << numMovies << " movies\n";
            auto t0 = steady_clock::now();
            //call bubble sort
            bubbleSort(movies, numMovies);
            auto t1 = steady_clock::now();
            auto ms_bubble = duration_cast<milliseconds>(t1 - t0).count();
            cout << "Bubble sort completed in " << ms_bubble << " ms.\n";
        }

        else if(choice == 3){
            cout << "I am going to selection sort the array of " << numMovies << " movies\n";
            auto t0 = steady_clock::now();
            selectionSort(movies, numMovies);
            auto t1 = steady_clock::now();
            auto ms_bubble = duration_cast<milliseconds>(t1 - t0).count();
            cout << "Selection sort compleated in " << ms_bubble << " ms.\n";
        }

        else if(choice == 4){
            cout << "I am going to insertion sort the array of " << numMovies << " movies\n";
            auto t0 = steady_clock::now();
            insertionSort(movies, numMovies);
            auto t1 = steady_clock::now();
            auto ms_bubble = duration_cast<milliseconds>(t1 - t0).count();
            cout << "insertion sort compleated in " << ms_bubble << " ms.\n";
        }

        else if(choice == 5){ // Scramble
            scramble(movies, numMovies);
            cout << "Array scrambled.\n";
        }
        else // Quit
            cout << "Goodbye!\n";
    } while(choice != 6);

    // clean up dynamic memory
    delete[] movies;

    return 0;
}

/*
	Function: readFromFile()
	Purpose: Reads movie titles from a specified text file into a dynamic array.
	Parameters:
		arr - reference to the array pointer to store movie titles
		maxSize - reference to the maximum size of the array
		curSize - reference to the current number of movies stored
	Returns: void
*/
void readFromFile(string*& arr, int& maxSize, int& curSize) {
    ifstream inFile;
    string filename, movie;
    cout << "Filename (movies.txt): ";
    cin >> filename;

    inFile.open(filename);
    if (inFile.is_open()) {
        while (getline(inFile, movie)) {
            if (curSize == maxSize) {
                maxSize = doubleArray(arr, maxSize);
            }
            arr[curSize] = movie;
            curSize++;
        }
        inFile.close();
        cout << "Loaded " << curSize << " movies from '" << filename << "'.\n";
    } else {
        cout << "Unable to open file '" << filename << "'!\n";
    }
}

/*
	Function: scramble()
	Purpose: Randomly shuffles the elements of the array.
	Parameters:
		arr - the array to shuffle
		size - number of elements in the array
	Returns: void
*/
void scramble(string* arr, int size) {
	int j;
    if (size <= 1) 
        return;
    srand(static_cast<unsigned int>(time(0)));
	for (int i = size - 1; i > 0; i--) {
		j = rand() % (i + 1);
		swap(arr[i], arr[j]);
	}
}

/*
This function goes through and bubble sorts the movies
*/
void bubbleSort(string* arr, int size){
    string swap;
    bool swapped;

    for (int i = 0; i < size - 1; i++){
        swapped = false;
        for (int j = 0; j < size - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                swap = arr[j];
                arr[j] = arr[j + 1];
                arr[j +i ] = swap;
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }
}

/*
This prints out all the movies 
*/
void printArray(string* arr, int size){
    for (int i = 0; i < size; i++){
        cout << arr [i] << endl;
    }
}

/*
this goes through selection sort and organizes them/ puts them in order
*/
void selectionSort(string* arr, int size){
    int minIndex; 
    string minValue;
    string temp;
    for (int i = 0; i < size - 1; i++){
        minIndex = i;
        minValue = arr[i];

        for (int j = i + 1; j < size; j++){
            if(arr[j] < minValue){
                minValue = arr[j];
                minIndex = j;
            }
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

/*
This uses the insertion sort method to sort/ organize the txt file
*/
void insertionSort(string* arr, int size){
    string key;
    int j;

    for(int i = 1; i < size; i++){
        key = arr[i];
        j = i-1;

        while(j >= 0 && arr[j] > key){
            arr [j + 1] = arr[j];
            j = j - 1;
        }
        arr [j + 1] = key;
    }
}

/*
creates a new array
*/
int doubleArray(string*& arr, int size){
    int newMax;
    if(size > 0){
        newMax = size * 2;
        cout << "Array size doubled from " << size << " to " << newMax << "!" << endl;

        string* newArr = new string[newMax];
        for(int i = 0; i < size; i++){
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
    return newMax;
}