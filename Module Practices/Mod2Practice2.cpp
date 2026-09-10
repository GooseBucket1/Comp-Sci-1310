#include <iostream>

using namespace std;

int getTotal(int[], int);
const int SIZE = 5;

int main() {

    int myArr[SIZE] ={7, 14, 1,5,3};
    cout << "The total of the array elements: ";

    cout << getTotal(myArr, 0) << endl << endl;
    return 0;

}
int getTotal (int arr[], int part) {

    if (SIZE > part)
        return getTotal(arr, part + 1) + arr[part];

    else
        return 0;

}