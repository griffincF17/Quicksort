/*
 * This program takes a randomly generated array of 10 integers
 * and sorts them by using the quicksort algorithm.
 */

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

/*
 * This function sorts the array from the designated start point
 * to the designated end point.
 * It returns i, the index number after the last swap.
 */
int qsort(int a[], int start, int end){
    int pivot = a[end];			//The pivot element
    int i = start;			//The index number

    for(int j = start; j < end; j++){	//Iterate through the array, a
	if(a[j] < pivot){		//Check if the element at index j
	    int tmp = a[j];		//is greater than the pivot.
	    a[j] = a[i];		//If so, swap that element with
	    a[i] = tmp;			//the element at position i.
	    i++;			//Finally, increment i.
	}
    }

    int t = a[i];			//Swap the element at position i
    a[i] = a[end];			//with the end element
    a[end] = t;

    return i;
}//end qsort function

/*
 * This function checks if the start position
 * is less than the end position. If so, call qsort to
 * get a partition. This partition is then used to call
 * this function recursively. First, from the start
 * position to the element before the partition; then
 * from the element after the partition to the end.
 */
void quicksort(int a[], int start, int end){
    if(start < end){
	int part = qsort(a, start, end);
	quicksort(a, start, part-1);
	quicksort(a, part+1, end);
    }
}//end quicksort function

int main(){
    srand(time(0));       

    int arr[10];			

    for(int i = 0; i < 10; i++){
	arr[i] = rand() % 100;
    }

    cout << "Array before quicksort: ";

    for(int n: arr){
	cout << n << " ";
    }
    
    quicksort(arr, 0, (sizeof(arr)/sizeof(int)) - 1);

    cout << "\nArray after quicksort: ";

    for(int n: arr){
	cout << n << " ";
    }
    cout << endl;

    return 0;
}
