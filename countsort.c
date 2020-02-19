// C Program for counting sort 
#include <stdio.h> 
#include <string.h> 
#define RANGE 255 

// how to deal with negative numbers?
// add the most negative number to ++count[arr[i]]; and to this : output[--count[arr[i]]] = arr[i];


// The main function that sort the given string arr[] in 
// alphabatical order 
void countSort(char arr[], int l) 
{ 
	// The output character array that will have sorted arr 
	char output[strlen(arr)]; 

	// Create a count array to store count of inidividul 
	// characters and initialize count array as 0 
	int count[RANGE + 1], i; 
	memset(count, 0, sizeof(count)); 

	// Store count of each character 
	for(i = 0; arr[i]; ++i) 
		++count[arr[i]]; 

	// Change count[i] so that count[i] now contains actual 
	// position of this character in output array 
	for (i = 1; i <= RANGE; ++i) 
		count[i] += count[i-1]; 

	// Build the output character array 
 
	for (i = l-1; i>=0; --i) 
	{ 
		//output[count[arr[i]]-1] = arr[i]; 
		//--count[arr[i]];
		output[--count[arr[i]]] = arr[i];
	} 


	// Copy the output array to arr, so that arr now 
	// contains sorted characters 
	for (i = 0; arr[i]; ++i) 
		arr[i] = output[i]; 
} 

// Driver program to test above function 
int main() 
{ 
	char arr[] = "geeksforgeeks";//"applepp"; 
    int l = strlen(arr);
	countSort(arr, l); 

	printf("Sorted character array is %s", arr); 
	return 0; 
} 

