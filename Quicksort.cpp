/*
 * This program takes a randomly generated array of 10 integers
 * and sorts them by using the quicksort algorithm.
 */

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

/*
 * This function swaps the values of two integer variables.
 */

void swap(int &n1, int &n2){
    int tmp = n1;
    n1 = n2;
    n2 = tmp;
}//end swap function

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
					//is less than the pivot.
	    swap(a[j], a[i]);		//If so, swap a[j] and a[i].	
	    i++;			//Finally, increment i.
	}
    }

    swap(a[i], a[end]); 		//Swap the ith and end elements

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

/*
 * This function prints an array's contents
 */ 
void print_array(int a[], int sz){
    for(int i = 0; i < sz; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
}

int main(){
    srand(time(0));       

    int arr[10];			

    for(int i = 0; i < 10; i++){
	arr[i] = rand() % 100;
    }

    int size = sizeof(arr)/sizeof(int);

    cout << "Array before quicksort: ";
    print_array(arr, size);
    
    quicksort(arr, 0, size - 1);

    cout << "\nArray after quicksort: ";
    print_array(arr, size);

    return 0;
}
