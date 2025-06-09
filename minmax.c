#include <stdio.h>  
// Function to perform Min-Max Sort 
void minMaxSort(int arr[], int n) {  
int start = 0, end = n - 1;  
while (start < end) {  
int minIndex = start, maxIndex = start;  
// Find min and max elements in the current range 
for (int i = start + 1; i <= end; i++) {  
if (arr[i] < arr[minIndex]) {  
minIndex = i;  
}  
if (arr[i] > arr[maxIndex]) {  
maxIndex = i;  
}  
}   
// Swap minimum element with the first element 
int temp = arr[start];  
arr[start] = arr[minIndex];  
arr[minIndex] = temp; 
// If maxIndex was at start, update it after swapping 
if (maxIndex == start) {  
maxIndex = minIndex;  
} 
// Swap maximum element with the last element 
temp = arr[end];  
arr[end] = arr[maxIndex];  
arr[maxIndex] = temp;  
// Move the bounds inward 
start++;  
end--;  
}  
}  
// Function to print the array  
void printArray(int arr[], int size) {  
for (int i = 0; i < size; i++) {  
printf("%d ", arr[i]);  
}      
printf("\n");  
}  
// Main function  
int main() {  
int n;   
// Get number of elements 
printf("Enter number of elements: ");      
scanf("%d", &n);  
int arr[n];  
// Get the elements from the user 
printf("Enter %d elements: ", n);      
for (int i = 0; i < n; i++) {  
scanf("%d", &arr[i]);  
}  
// Display the original array 
printf("Original array: ");  
printArray(arr, n);  
// Perform Min-Max Sorting  
minMaxSort(arr, n);  
// Display the sorted array 
printf("Sorted array: ");  
printArray(arr, n);  
return 0;  
}
